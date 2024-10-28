//
// Created by fumosoftware on 10/27/2024.
//

#include <fmt/core.h>
#include "app_settings.h"
#include "sdl_init.h"

using namespace std::string_literals;
std::expected<SDLContext, AppError> initialize_sdl(AppSettings const& settings) {
  auto const initialize =
    []() -> std::expected<void, AppError> {
      if(SDL_WasInit(0) != 0) return std::unexpected<AppError>("SDL already initialized!"s);
      if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        return std::unexpected<AppError>(fmt::format("SDL could not be initialized: {}", SDL_GetError()));
      }
      return {};
  };

  auto const create_sdlcontext =
    [settings]() -> std::expected<SDLContext, AppError> {
      SDLContext sdlcontext{};
      if(!SDL_CreateWindowAndRenderer(settings.app_title.c_str(),
                                          settings.window_width,
                                          settings.window_height,
                                          0,
                                          &sdlcontext.window,
                                          &sdlcontext.renderer)) {
        return std::unexpected{AppError{fmt::format("Failed to create SDLContext: {}", SDL_GetError())}};
      }

      return sdlcontext;
  };

  auto const teardown_on_error =
    [](AppError const& error) -> std::expected<SDLContext, AppError> {
      SDL_Quit();
      return std::unexpected{error};
  };


  return initialize()
  .and_then(create_sdlcontext)
  .or_else(teardown_on_error);
}

void teardown_sdl(SDLContext const& context) {
  SDL_DestroyRenderer(context.renderer);
  SDL_DestroyWindow(context.window);
  SDL_Quit();
}
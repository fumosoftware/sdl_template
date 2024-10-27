//
// Created by fumosoftware 10/23/2024.
//

#include <iostream>
#include <expected>
#include "SDL3/SDL.h"

struct Context {
  SDL_Window* window{nullptr};
  SDL_Renderer* renderer{nullptr};
};

struct Error {
  std::string reason{};
};

std::expected<Context, Error> initialize();
void render(Context const& context);
void shutdown_sdl(Context const& context);

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {

  auto maybe_context = initialize();
  if(!maybe_context) return EXIT_FAILURE;
  auto context = *maybe_context;

  bool is_running = true;
  SDL_Event event{};
  while(is_running) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        is_running = false;
      }
    }

    render(context);
  }

  shutdown_sdl(context);
  return EXIT_SUCCESS;
}

std::expected<void, Error> initialize_sdl() {
  if(SDL_WasInit(0) == 0) {
    return std::unexpected{Error{"SDL was already initialized!"}};
  }

  if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
    return std::unexpected{Error{SDL_GetError()}};
  }

  return {};
}

std::expected<Context, Error> create_context() {
  Context context;
  if(!SDL_CreateWindowAndRenderer("sdl_template", 600, 380, 0, &context.window, &context.renderer)) {
    return std::unexpected{Error{SDL_GetError()}};
  }

  return context;
}

std::expected<Context, Error> quit_sdl(Error const& error) {
  SDL_Quit();
  return std::unexpected{error};
}

std::expected<Context, Error> initialize() {
  return initialize_sdl()
          .and_then(create_context)
          .or_else(quit_sdl);
}

void render(Context const& context) {
  SDL_RenderClear(context.renderer);
  SDL_RenderPresent(context.renderer);
}

void shutdown_sdl(Context const& context) {
  SDL_DestroyRenderer(context.renderer);
  SDL_DestroyWindow(context.window);
  SDL_Quit();
}

//
// Created by fumosoftware on 10/27/2024.
//

#include "app_main.h"
#include "sdl_init.h"

namespace {
  void render(SDLContext const& context) {
    SDL_RenderClear(context.renderer);
    SDL_RenderPresent(context.renderer);
  }
}

int app_main(AppSettings const& settings) {
  auto maybe_context = initialize_sdl(settings);
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

  teardown_sdl(context);
  return EXIT_SUCCESS;
}
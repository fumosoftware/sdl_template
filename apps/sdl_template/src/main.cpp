//
// Created by fumosoftware 10/23/2024.
//

#include "sdl/context.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {
  //TODO: Create settings from a config file or command line arguments

  auto maybe_context = setup_sdl();
  if(!maybe_context) {
    SDL_Log("%s", maybe_context.error().c_str());
    return 1;
  }
  auto context = *maybe_context;

  bool is_running{true};
  while(is_running) {
    SDL_Event event{};
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        is_running = false;
      }
    }

    if(!is_running) { break; }

    render(context.video);
  }

  teardown_sdl(context);
  return 1;
}
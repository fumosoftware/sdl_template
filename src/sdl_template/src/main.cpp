//
// Created by fumosoftware 10/23/2024.
//

#include <cstdlib>
#include <SDL3/SDL.h>

int main([[maybe_unused]]int argc, [[maybe_unused]]char *argv[]) {

  if(!SDL_Init(SDL_INIT_VIDEO)) {
    return EXIT_FAILURE;
  }

  SDL_Window* window{nullptr};
  SDL_Renderer* renderer{nullptr};
  if(!SDL_CreateWindowAndRenderer("sdl_template", 640, 480, 0, &window, &renderer)) {
    return EXIT_FAILURE;
  }

  SDL_Event event{};
  bool is_running{true};
  while(is_running) {
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_EVENT_QUIT: is_running = false; break;
        default: break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
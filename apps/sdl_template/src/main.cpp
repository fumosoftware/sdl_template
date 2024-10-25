//
// Created by fumosoftware 10/23/2024.
//

#include <iostream>
#include "SDL3/SDL.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != true) {
    return EXIT_FAILURE;
  }

  SDL_Window* window = SDL_CreateWindow("sdl_template", 600, 380, 0);
  if(window == nullptr) {
    SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }
  SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
  if(renderer == nullptr) {
    SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }

  bool is_running = true;
  SDL_Event event{};
  while(is_running) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_EVENT_QUIT) {
        is_running = false;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
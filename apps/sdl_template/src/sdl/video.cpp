//
// Created by fumosoftware on 10/28/2024.
//

#include "video.h"

#include "SDL3/SDL.h"

void render(sdl::Video const& video) noexcept {
  auto& [renderer, _] = video.graphics_context;
  SDL_assert(renderer != nullptr);

  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
}
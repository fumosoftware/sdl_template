//
// Created by fumosoftware on 10/27/2024.
//

#ifndef SDL_CONTEXT_H
#define SDL_CONTEXT_H

#include "SDL3/SDL.h"

struct SDLContext {
  SDL_Window* window{nullptr};
  SDL_Renderer* renderer{nullptr};
};
#endif //SDL_CONTEXT_H

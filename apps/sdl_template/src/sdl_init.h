//
// Created by fumosoftware on 10/27/2024.
//

#ifndef SDL_INIT_H
#define SDL_INIT_H

#include <expected>
#include "sdl_context.h"
#include "app_error.h"

struct AppSettings;
std::expected<SDLContext, AppError> initialize_sdl(AppSettings const& settings);
void teardown_sdl(SDLContext const& context);


#endif //SDL_INIT_H

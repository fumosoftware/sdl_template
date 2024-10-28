//
// Created by fumosoftware on 10/27/2024.
//

#ifndef APP_SETTINGS_H
#define APP_SETTINGS_H

#include <string>
#include <cstdint>

struct AppSettings {
  std::string app_title{"sdl_template"};
  std::int32_t window_width{600};
  std::int32_t window_height{380};
};

#endif //APP_SETTINGS_H

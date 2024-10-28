//
// Created by fumosoftware 10/23/2024.
//

#include "app_main.h"
#include "app_settings.h"

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {
  //TODO: Create settings from a config file or command line arguments
  return app_main(AppSettings{});
}
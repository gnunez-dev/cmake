#include <iostream>

#include <cxxopts.hpp>
#include <nlohmann/json.hpp>
#include <fmt/format.h>
#include <spdlog/spdlog.h>

#include "my_lib.h"
#include "config.hpp"

int main(){

    std::cout << project_name << std::endl;
    std::cout << project_VERSION << std::endl << std::endl;
    printHello();

    std::cout << "JSON Lib Version:" << std::endl
              << NLOHMANN_JSON_VERSION_MAJOR << "."
              << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << std::endl << std::endl;

    std::cout << "FMT Lib Version:" << std::endl
              << FMT_VERSION << std::endl << std::endl;

    std::cout << "CXXOPTS Lib Version:" << std::endl
              << CXXOPTS__VERSION_MAJOR << "."
              << CXXOPTS__VERSION_MINOR << "."
              << CXXOPTS__VERSION_PATCH << std::endl << std::endl;

    std::cout << "SPDLOG Lib Version:" << std::endl
              << SPDLOG_VER_MAJOR << "."
              << SPDLOG_VER_MINOR << "."
              << SPDLOG_VER_PATCH << std::endl << std::endl;

    return 0;
}

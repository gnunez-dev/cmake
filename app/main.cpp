#include <iostream>

#include <nlohmann/json.hpp>
#include "my_lib.h"
#include "config.hpp"

int main(){

    std::cout << project_name << std::endl;
    std::cout << project_VERSION << std::endl;
    printHello();

    std::cout << "JSON Lib Version:" << std::endl
              << NLOHMANN_JSON_VERSION_MAJOR << "."
              << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << "." << std::endl;
    return 0;
}

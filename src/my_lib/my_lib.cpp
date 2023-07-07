#include <iostream>
#include <nlohmann/json.hpp>
#include "my_lib.h"

void printHello(){
    std::cout << "Hello World\n";

    std::cout << "JSON Lib Version:" << std::endl
              << NLOHMANN_JSON_VERSION_MAJOR << "."
              << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << "." << std::endl;
}

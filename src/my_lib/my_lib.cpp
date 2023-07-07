#include <iostream>
#include <nlohmann/json.hpp>
#include "my_lib.h"

/**
 * @brief Prints out hello world and testing JSON library.
 *
 */
void printHello(){
    std::cout << "Hello World\n";

    std::cout << "JSON Lib Version:" << std::endl
              << NLOHMANN_JSON_VERSION_MAJOR << "."
              << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << "." << std::endl;
}

std::uint32_t factorial( std::uint32_t num) {
    return num <= 1 ? 1 : factorial(num - 1) * num;
}

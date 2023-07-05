# 1- Create source and CMakeFile
# 2- mkdir build
# 3- cd build
# 4- cmake ..  //Generating the build files / Configure the project
# 5- cmake --build .
# 6- ./Executable

cmake_minimum_required(VERSION 3.22)

project(
    CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX) #CXX is equal to C++

add_executable(Executable src/main.cpp)

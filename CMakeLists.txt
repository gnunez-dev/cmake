# 1- Create source and CMakeFile
# 2- mkdir build
# 3- cd build
# 4- cmake ..  //Generating the build files / Configure the project
# 5- cmake --build .
# 6- ./Executable

cmake_minimum_required(VERSION 3.22)

#Name of the project.
#Version of the project.
#Lenguages used in the project.
project(
    CppProjectTemplate
    VERSION 1.0.0
    LANGUAGES C CXX) #CXX is equal to C++

#added a library, name of the library - type - file
add_library(Library STATIC src/my_lib.cpp)

#creating a executable, name of the out file - path to the source file
add_executable(Executable src/main.cpp)

#linking the library with the main file, name of the out file (executable.exe) - type - name of the library
target_link_libraries(Executable PUBLIC Library)

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

#Variables

#Default variables
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#Creating a variable. Name - Value
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

#option(COMPILE_EXECUTABLE "Whether to compile the executable" OFF)

#to add other CMakeList files
add_subdirectory(configured)
add_subdirectory(src) #this is first because it has the library
add_subdirectory(app)
#if(COMPILE_EXECUTABLE)
#    add_subdirectory(app)
#else()
#    message("Without executable compiling")
#endif()

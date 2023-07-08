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

option(USE_CPM "ENABLE CPM" OFF)
option(USE_CONAN "ENABLE CONAN" OFF)
option(USE_VCPKG "ENABLE VCPKG" ON)

option(ENABLE_TESTING "Enable a Unit Testing Build" ON)

option(ENABLE_WARNINGS "Enable warnings" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable warnings as errors" OFF)

option(ENABLE_SANITIZER_ADDRESS "Enable sanitizer" ON)
option(ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" ON)

option(ENABLE_LTO "Enable LTO" ON)

#Creating a variable. Name - Value
set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule) #can be used when the repo doesn't have CMakeLists file
include(FetchContent)
include(Docs)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

if(ENABLE_SANITIZER_ADDRESS OR ENABLE_SANITIZER_UNDEFINED)
    include(Sanitizers)
    add_sanitizer_flags()
endif()

if(ENABLE_LTO)
    include(LTO)
endif()

if(USE_CPM)
    message(STATUS "Using CPM")
    include(CPM)
    cpmaddpackage("gh:nlohmann/json#v3.11.2") #gh(github):username/repo#version
    cpmaddpackage("gh:fmtlib/fmt#9.1.0")
    cpmaddpackage("gh:gabime/spdlog#v1.11.0")
    cpmaddpackage("gh:jarro2783/cxxopts#v3.0.0")
    cpmaddpackage("gh:catchorg/Catch2#v2.13.9")
elseif(USE_VCPKG)
    message(STATUS "Using VCPKG")
    include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)
    find_package(nlohmann_json REQUIRED)
    find_package(fmt REQUIRED)
    find_package(spdlog REQUIRED)
    find_package(Catch2 REQUIRED)
    find_package(cxxopts REQUIRED)
elseif(USE_CONAN)
    message(STATUS "Using Conan")
    include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
    find_package(nlohmann_json REQUIRED)
    find_package(fmt REQUIRED)
    find_package(spdlog REQUIRED)
    find_package(cxxopts REQUIRED)
    find_package(Catch2 REQUIRED)
else()
    message(STATUS "Using FetchContent")
    #To use FetchContent_Declare, the repo has to have a CMakeLists
    #this clone of the repo
    FetchContent_Declare( #Repo in GitHub
        nlohmann_json #name of the project - CMakeLists.txt
        GIT_REPOSITORY https://github.com/nlohmann/json #link of repo
        GIT_TAG v3.11.2 #version
        GIT_SHALLOW TRUE #true -> It means that only a limited depth of Git history is fetched
    )
    FetchContent_MakeAvailable(nlohmann_json) #this made the library available in the project

    FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 9.1.0
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(fmt)

    FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog
        GIT_TAG v1.11.0
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(spdlog)

    FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts
        GIT_TAG v3.0.0
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(cxxopts)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v2.13.9
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)
endif()
#option(COMPILE_EXECUTABLE "Whether to compile the executable" OFF)

#to add other CMakeList files
add_subdirectory(configured)
add_subdirectory(external)
add_subdirectory(src) #this is first because it has the library
add_subdirectory(app)
add_subdirectory(tests)
#if(COMPILE_EXECUTABLE)
#    add_subdirectory(app)
#else()
#    message("Without executable compiling")
#endif()

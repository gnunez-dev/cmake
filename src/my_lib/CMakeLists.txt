#added a library, name of the library - type - file
add_library(Library STATIC my_lib.cpp)
target_include_directories(Library PUBLIC "./")

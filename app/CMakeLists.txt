#creating an executable, name of the out file - path to the source file
add_executable(Executable main.cpp)
#linking the library with the main file, name of the out file (executable.exe) - type - name of the library
target_link_libraries(Executable PUBLIC Library)

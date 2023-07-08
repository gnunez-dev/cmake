### To build

- cmake --build .
- cmake --build . --target Executable

### -
- cmake .. -DCOMPILE_EXECUTABLE=ON

### Git
- git submodule add https://github.com/nlohmann/json external/json
- git clone --recursive https://...
- 

### Doxygen
- doxygen -g
- mkdir docs
- cd docs
- doxygen


## Package Manage
### CPM
- https://github.com/cpm-cmake/CPM.cmake
    - go to releases -> https://github.com/cpm-cmake/CPM.cmake/releases/tag/v0.38.1
    - Download CPM.cmake file
    - Copy into cmake folder in the project
    - Add the configuration in the main CMakeLists.txt

### Conan 
    - conan.io
    - How to install:
      - Install Python (3.7+)
      - Into the terminal: pip install --user -U conan
      - To Unix users: source ~/.profile
      - Run the conan command: conan
      - conan profile detect --force
      - conan profile path default

### vcpkg
  - https://vcpkg.io/
  - How to install
    - git submodule add https://github.com/Microsoft/vcpkg.git
    - .\vcpkg\bootstrap-vcpkg.bat
    
    - https://vcpkg.io/en/getting-started.html

set(LIBRARY_SOURCES
    "my_lib.cpp")
set(LIBRARY_HEADERS
    "my_lib.h")
set(LIBRARY_INCLUDES PUBLIC
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

#added a library, name of the library - type - file
add_library(${LIBRARY_NAME} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_NAME} PUBLIC
    ${LIBRARY_INCLUDES})
target_link_libraries(${LIBRARY_NAME} PUBLIC
    nlohmann_json::nlohmann_json
    fmt::fmt
    spdlog::spdlog
    cxxopts::cxxopts)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        ${LIBRARY_NAME}
        ${ENABLE_WARNINGS}
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()

if(${ENABLE_LTO})
    target_enable_lto(${LIBRARY_NAME} ${ENABLE_LTO})
endif()

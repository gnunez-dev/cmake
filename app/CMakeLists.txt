set(EXE_SOURCES
    "main.cpp")

#creating an executable, name of the out file - path to the source file
add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})
#linking the library with the main file, name of the out file (executable.exe) - type - name of the library
target_link_libraries(${EXECUTABLE_NAME} PUBLIC
    ${LIBRARY_NAME}
    nlohmann_json)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        ${EXECUTABLE_NAME}
        ${ENABLE_WARNINGS}
        ${ENABLE_WARNINGS_AS_ERRORS}
    )
endif()

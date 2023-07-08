
function(add_sanitizer_flags)
    if(NOT ${ENABLE_SANITIZER_ADDRESS} AND NOT ${ENABLE_SANITIZER_UNDEFINED})
        message(STATUS "Sanitizer deactivated")
        return()
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "CLANG" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")

        add_compile_options("-fno-omit-frame-pointer")
        add_link_options("-fno-omit-frame-pointer")

        if(${ENABLE_SANITIZER_ADDRESS})
            add_compile_options("-fsanitize=address")
            add_link_options("-fsanitize=address")
        endif()

        if(${ENABLE_SANITIZER_UNDEFINED})
            add_compile_options("-fsanitize=undefined")
            add_link_options("-fsanitize=undefined")
        endif()

    elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        if(${ENABLE_SANITIZER_ADDRESS})
            add_compile_options("-fsanitize=address")
            add_link_options("-fsanitize=address")
        endif()

        if(${ENABLE_SANITIZER_UNDEFINED})
            message(STATUS "Undefined sanitizer not impl. for MSVC")
        endif()
    else()
        message(STATUS "Compiler not supported for Sanitizers")
    endif()
endfunction()

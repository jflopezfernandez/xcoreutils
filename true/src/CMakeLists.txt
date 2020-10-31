ADD_EXECUTABLE(true main.c)

SET_TARGET_PROPERTIES(true
    PROPERTIES
        LANGUAGE C
        C_STANDARD 99
        C_STANDARD_REQUIRED TRUE
        C_EXTENSIONS FALSE
)

TARGET_INCLUDE_DIRECTORIES(true
    PUBLIC
        ${CMAKE_BINARY_DIR}/include
)

TARGET_COMPILE_OPTIONS(true
    PUBLIC    
        # Clang Compiler Options
        $<$<AND:$<C_COMPILER_ID:Clang>,$<BOOL:${DEBUG}>>:-ggdb>

        # GCC Compiler Options
        $<$<C_COMPILER_ID:Clang,GNU>:-Wall -Wextra -Wpedantic>
        $<$<AND:$<C_COMPILER_ID:GNU>,$<BOOL:${DEBUG}>>:-fanalyzer -ggdb3>

        # Clang and GCC Compiler Options
        $<$<AND:$<C_COMPILER_ID:Clang,GNU>,$<BOOL:${DEBUG}>>:-Og>
        $<$<AND:$<C_COMPILER_ID:Clang,GNU>,$<NOT:$<BOOL:${DEBUG}>>>:-O3>
)

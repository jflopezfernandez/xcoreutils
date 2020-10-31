ADD_EXECUTABLE(cat main.c)

TARGET_INCLUDE_DIRECTORIES(cat PUBLIC ${CMAKE_BINARY_DIR}/include)

SET_TARGET_PROPERTIES(cat
    PROPERTIES
        LANGUAGE C
        C_STANDARD 99
        C_STANDARD_REQUIRED TRUE
        C_EXTENSIONS FALSE
)

TARGET_COMPILE_OPTIONS(cat
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

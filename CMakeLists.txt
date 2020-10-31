CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
CMAKE_POLICY(SET CMP0048 NEW)
PROJECT(xcoreutils
    VERSION
        1.0.1.1
    DESCRIPTION
        "Cross-platform re-implementation of the GNU coreutils in modern C."
    HOMEPAGE_URL
        "https://github.com/jflopezfernandez/xcoreutils"
    LANGUAGES
        C
)

SET(CMAKE_CONFIGURATION_TYPES "Release" "Debug")

OPTION(DEBUG "Enable debugging options and code." OFF)

MESSAGE(STATUS "Debugging options and code: ${DEBUG}")

ADD_SUBDIRECTORY(include)

SET(UTILITIES
    cat
    false
    true
    yes
)

FOREACH(UTILITY ${UTILITIES})
    ADD_SUBDIRECTORY(${UTILITY})
ENDFOREACH()

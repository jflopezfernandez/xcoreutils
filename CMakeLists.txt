CMAKE_MINIMUM_REQUIRED(VERSION 3.18 FATAL_ERROR)
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

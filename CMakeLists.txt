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

# Enable debugging-specific settings and compilation options
#
# This setting defines the DEBUG preprocessor macro, which
# does several things.
#
# First, the presence of this macro disables the NDEBUG
# macro, so all runtime assert statements within the project
# are executed.
#
# Second, the verbosity of the program output(s) is
# significantly higher than it would be otherwise, to allow
# for easier program execution tracing.
#
# And finally, sub-project compilation settings are modified
# in a platform- and compiler-specific way, requesting
# detailed debugging information from the compiler, and
# invoking additional compiler-specific diagnostics and
# analyzer utilities.
#
OPTION(DEBUG "Enable debugging options and code." OFF)

# Process the project-wide include directory.
#
# This directory contains the top-level configuration file
# in which system- and configuration-specific settings and
# values are set, making them available to all of the sub-
# projects during compilation.
#
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

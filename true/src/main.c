/**
 * xcoreutils - GNU coreutils reimplementation in modern C
 * Copyright (C) Jose Fernando Lopez Fernandez, 2020.
 * 
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * 
 * You should have received a copy of the GNU General
 * Public License along with this program.  If not, see
 * <https://www.gnu.org/licenses/>.
 *
 */

#include "config.h"

/**
 * Define the program name to display in the program's help
 * and version information when the program is invoked with
 * the --help or --version command-line options.
 *
 */
#define PROGRAM_NAME "true"

/**
 * This is the format string containing the program help
 * menu that will be displayed when the user invokes the
 * program with the '--help' option.
 *
 */
static const char* program_help =
"Usage: %s [ignored command line arguments]\n"
"\n"
"Exit with a status code indicating success.\n"
"\n"
"      --help     display this help and exit\n"
"      --version  output version information and exit\n"
"\n"
"NOTE: your shell may have its own version of true, which\n"
"usually supersedes the version described here.\n"
"Please refer to your shell's documentation\n"
"for details about the options it supports.\n";

/**
 * This enum defines the only acceptable parameters to the
 * print_program_info() function.
 *
 */
typedef enum {
    PROGRAM_HELP,
    PROGRAM_VERSION
} program_info_t;

/**
 * Simple string typedef to stand in place of const char*
 *
 */
typedef const char* string_t;

/**
 * Return the specified program information string
 *
 * This function returns the format string corresponding to
 * the specified program information parameter. The switch
 * statement accepts only help and version options, but if
 * neither match somehow, the default is to simply return
 * the program's help string. A normal program would
 * normally issue some kind of error or warning in that
 * situation, but the whole point of this program is to
 * never fail, so we obviously can't do that.
 *
 */
string_t get_program_info(program_info_t program_info) {
    switch (program_info) {
        case PROGRAM_VERSION: return program_version;
        case PROGRAM_HELP: return program_help;
    }

    return program_help;
}

/**
 * Print program information to standard output
 *
 * This function prints the requested program information
 * to standard out by first getting the corresponding format
 * string via a call to get_program_info(), and then passing
 * the result as the format string in the call to printf(3).
 *
 */
void print(program_info_t program_info) {
    printf(get_program_info(program_info), PROGRAM_NAME);
}

/**
 * This is the entry point of the program.
 *
 * For additional information on why this program accepts
 * input arguments, please see the documentation of the
 * argument vector processing below.
 *
 * @param int argc The number of arguments in argv
 * @param char*[] Null-terminated argument vector
 *
 * @returns Success exit code, represented as a 0.
 *
 */
int main(int argc, char *argv[])
{
    /**
     * Iterate over the argument vector to see whether the
     * user passed in any options. The following list
     * contains all of the options recognized as such.
     *
     *  --help          Display the program help menu
     *  --version       Display program version information
     *
     * All other strings in the argument vector will be
     * assumed to be throwaway input, to allow for more
     * flexibility when the program is invoked within script
     * files.
     *
     */
    for (int i = 1; i < argc; ++i) {
        if (strings_match(argv[i], "--help")) {
            print(PROGRAM_HELP);
            return EXIT_SUCCESS;
        }

        if (strings_match(argv[i], "--version")) {
            print(PROGRAM_VERSION);
            return EXIT_SUCCESS;
        }
    }
    
    /**
     * Aways return an exit status indicating successful
     * completion.
     *
     */
    return EXIT_SUCCESS;
}

/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** define
*/

#include "const_values.h"

const int SUCCESS = 0;
const int ERROR = -1;
const int VALID = 1;
const int FAILURE = 84;
const char *ERR_MSG1 = "env: cannot specify --null (-0) with command\n";
const char *ERR_MSG2 = "Try 'env --help' for more information.";

const char *VERSION_MSG1 = "env (GNU coreutils) 8.28\nCopyright (C) 2017 Free\
 ";
const char *VERSION_MSG2 = "Software Foundation, Inc.\nThis is free\
 software: you are";
const char *VERSION_MSG3 = " free to change and redistribute it.\nThere is NO\
 ";
const char *VERSION_MSG4 = "WARRANTY, to the extent permitted by law.\
\n\nWritten by";
const char *VERSION_MSG5 = " Angela Martoccia Boyadjian.";
const char *HELP_MSG1 = "Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND ";
const char *HELP_MSG2 = "[ARG]...]\nSet each NAME to VALUE in the environment\
 and ";
const char *HELP_MSG3 = "run COMMAND.\n\nMandatory arguments to long\
 options are ";
const char *HELP_MSG4 = "mandatory for short options too.\n\t-i,\
 --ignore-environment";
const char *HELP_MSG5 = "  start with an empty environment\n\t-0, --null\
            ";
const char *HELP_MSG6 = "end each output line with NUL, not newline\n";
const char *HELP_MSG7 = "\t-u, --unset=NAME     remove variable\
 from the environment";
const char *HELP_MSG8 = "\n\t-C, --chdir=DIR      change working directory\
 to DIR\n";
const char *HELP_MSG9 = "\t--help     display this help and exit\n";
const char *HELP_MSG10 = "\t--version  output version information and exit\
\n\n";
const char *HELP_MSG11 = "A mere - implies -i.  If no COMMAND, print the\
 resulting ";
const char *HELP_MSG12 = "environment.";

const char *RED     = "\x1b[31m";
const char *GREEN   = "\x1b[32m";
const char *YELLOW  = "\x1b[33m";
const char *BLUE    = "\x1b[34m";
const char *MAGENTA = "\x1b[35m";
const char *CYAN    = "\x1b[36m";
const char *RESET   = "\x1b[0m";
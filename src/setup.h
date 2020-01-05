#ifndef SETUP_H
#define SETUP_H

int parse_clargs(int argc, const char *argv[], struct Settings *settings, char *input);
int single_arg_parse(int argnum, int startIndex, const char *argv[], char arg, struct Settings *settings);

#endif

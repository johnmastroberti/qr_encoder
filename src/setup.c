#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "settings.h"
#include "setup.h"

int parse_clargs(int argc, const char *argv[], struct Settings *settings,
    char *input) {
  // Parses command line arguments to get settings to be used
  // for the qr encoding
  // Default settings: Low error correction,
  // byte encoding mode
  // stdin input source
  // Valid command line keys:
  //      -c#, --correction_level=#
  //      -e#, --encoding_mode=#
  //      -i#, --input_source=#
  // If the text to be encoded is passed as an argument, this function
  // will copy it into the input array

  // Start by filling default settings
  //*settings = {.ecl = L, .em = byte, .is = standardin, .version = 0};
  settings->ecl = L;
  settings->em = byte;
  settings->is = standardin;
  settings->version = 0;

  // Base case: no arguments whatsoever
  if (argc==1) {
    return 0;
  }

  // Read command line arguments
  int i, arglen;
  for (i=1; i<argc; i++) {
    arglen = strlen(argv[i]);
    if (arglen==0) continue; // ignore 0 length argument
    else if (arglen>2) {
      if (argv[i][0] == '-') {
        switch (argv[i][1]) {
          case 'c':
            if(!single_arg_parse(i, 2, argv, 'c', settings))
              goto READ_INPUT;

          case 'e':
            if(!single_arg_parse(i, 2, argv, 'e', settings))
              goto READ_INPUT;

          case 'i':
            if(!single_arg_parse(i, 2, argv, 'i', settings))
              goto READ_INPUT;

          case '-': // -- argument
            if (strcmp(argv[i], "--correction_level=") >= 0)
              if(!single_arg_parse(i, strlen("--correction_level="), argv, 'c', settings))
                goto READ_INPUT;
            else {
              if (strcmp(argv[i], "--encoding_mode=") >= 0)
                if(!single_arg_parse(i, strlen("--encoding_mode="), argv, 'e', settings))
                  goto READ_INPUT;
            }
            else {
              if (strcmp(argv[i], "--input_source=") >= 0)
                if(single_arg_parse(i, strlen("--input_source="), argv, 'i', settings))
                  goto READ_INPUT;
            }
        }
      } else
        goto READ_INPUT;
    }
  }

READ_INPUT: ;
  int offset = 0;
  for (; i<argc; i++) {
    strcpy(input+offset, argv[i]);
    offset += strlen(argv[i]);
    input[offset] = ' ';
  }
  input[offset] = '\0';
  return 0;
}

int single_arg_parse(int argnum, int startIndex, const char *argv[], char arg, struct Settings *settings) {
  // parses &argv[argnum][startIndex] for argument arg into settings
  // arg must be 'c', 'e', or 'i'
  // Returns 0 if successful and 1 otherwise
  switch (arg) {
    case 'c':
      if (!strcmp(&argv[argnum][startIndex], "L"))
        settings->ecl = L;
      else if (!strcmp(&argv[argnum][startIndex], "M"))
        settings->ecl = M;
      else if (!strcmp(&argv[argnum][startIndex], "M"))
        settings->ecl = M;
      else if (!strcmp(&argv[argnum][startIndex], "M"))
        settings->ecl = M;
      else
        return 1;

    case 'e':
      if (!strcmp(&argv[argnum][startIndex], "numeric"))
        settings->em = numeric;
      else if (!strcmp(&argv[argnum][startIndex], "alphanumeric"))
        settings->em = alphanumeric;
      else if (!strcmp(&argv[argnum][startIndex], "byte"))
        settings->em = byte;
      else if (!strcmp(&argv[argnum][startIndex], "kanji"))
        settings->em = kanji;
      else
        return 1;

    case 'i':
      if (!strcmp(&argv[argnum][startIndex], "standardin"))
        settings->is = numeric;
      else if (!strcmp(&argv[argnum][startIndex], "commandLineArg"))
        settings->is = commandLineArg;
      else if (!strcmp(&argv[argnum][startIndex], "file"))
        settings->is = file;
      else
        return 1;

    default:
      return 1;
  }
  return 0;
}

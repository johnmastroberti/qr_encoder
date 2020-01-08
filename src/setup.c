#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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

  int opt;
  while ((opt = getopt(argc, argv, ":c:e:i:")) != -1) {
    switch(opt) {
      // error correction level
      case 'c':
        if (!strcmp(optarg, "L")) {
          settings->ecl = L;
        } else if (!strcmp(optarg, "M")) {
          settings->ecl = M;
        } else if (!strcmp(optarg, "Q")) {
          settings->ecl = Q;
        } else if (!strcmp(optarg, "H")) {
          settings->ecl = H;
        } else {
          printf("Error correction level must be L,M,Q, or H\n");
          return 1;
        } break;
      case 'e':
        if (!strcmp(optarg, "numeric")) {
          settings->em = numeric;
        } else if (!strcmp(optarg, "alphanumeric")) {
          settings->em = alphanumeric;
        } else if (!strcmp(optarg, "byte")) {
          settings->em = byte;
        } else if (!strcmp(optarg, "kanji")) {
          settings->em = kanji;
        } else {
          printf("Encoding mode must be ");
          printf("numeric, alphanumeric, ");
          printf("byte, or kanji\n");
          return 1;
        } break;
      case 'i':
        break; // skip for now
      case ':':
        printf("-%c requires an argument\n", optopt);
        return 1;
      case '?':
        printf("Unknown option: -%c", optopt);
        return 1;
    }
  }
  return 0;
}


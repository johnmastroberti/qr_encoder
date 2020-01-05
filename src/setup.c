#include <stdio.h>
#include <stdlib.h>

int parse_input(int argc, char* argv[]) {
  // Parses command line arguments to get settings to be used
  // for the qr encoding

  if (argc==0) {
    // Use stdin for encoding


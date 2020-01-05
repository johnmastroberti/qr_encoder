#include <stdio.h>
#include <stdlib.h>
#include "settings.h"
#include "setup.h"
#define MAX_INPUT_LEN 2953

int main(int argc, const char* argv[]) {
  // Step 0: allocate memory
  char* input = malloc((MAX_INPUT_LEN+1) * sizeof(char));
  struct Settings settings;

  // Step 1: parse settings and get input to encode
  parse_clargs(argc, argv, &settings, input);
  int i,c;
  if (settings.is == standardin) {
    for (i=0; i<MAX_INPUT_LEN; i++) {
      c = getchar();
      if (c == EOF) {
        input[i] = '\0';
        break;
      }
      input[i] = c;
    }
  }


  return 0;
}


#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT_LEN 2953

int main(int argc, char* argv[]) {
  // Step 0: allocate memory
  char* input = malloc((MAX_INPUT_LEN+1) * sizeof(char));

  // Step 1: parse settings and get input to encode
  int i,c;
  for (i=0; i<MAX_INPUT_LEN; i++) {
    c = getchar();
    if (c == EOF) {
      input[i] = '\0';
      break;
    }
    input[i] = c;
  }


  return 0;
}


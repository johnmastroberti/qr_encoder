#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../settings.h"

#define BUFFER_SIZE 128

int findVersion(int limits[4][4][41], enum errorCorrectionLevel level, enum encodingMode mode, int size) {
  for(int i = 1; i < 41; i++) {
    if(limits[level][mode][i] >= size) {
      return i;
    }
  }

  return -1;
}

// limits[4][4][41]: error correction level, mode, version -> limit
int loadLimitsCSV(int limits[4][4][41], const char *filename) {
  char buff[BUFFER_SIZE];

  FILE *csv = fopen(filename, "r");
  if(!csv) {
    return 1;
  }
  
  // skip the first header line
  fgets(buff, BUFFER_SIZE, csv);

  int counter = 0;

  while(fgets(buff, BUFFER_SIZE, csv)) {
    char* token = strtok(buff, ",");

    // skip version
    if(counter % 4 == 0) {
      token = strtok(NULL, ","); 
    }

    for(int i = 0; i < 4; i++) {
      // skip level in csv
      token = strtok(NULL, ",");

      limits[counter % 4][i][counter / 4 + 1] = atoi(token);
    }

    counter++;
  }

  return counter == 160; 
}

int main(int argc, char **argv) {
  const char *filename = "version_limits.csv";

  int limits[4][4][41];

  loadLimitsCSV(limits, filename);

  printf("%d\n", findVersion(limits, Q, byte, 120));

  return 0;
}


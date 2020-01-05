#ifndef SETTINGS_H
#define SETTINSG_H

enum errorCorrectionLevel {L, M, Q, H};
enum encodingMode {numeric, alphanumeric, byte, kanji};

typedef struct Settings {
  enum errorCorrectionLevel ecl;
  enum encodingMode em;
  int version;
};

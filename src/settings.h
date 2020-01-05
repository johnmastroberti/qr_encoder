#ifndef SETTINGS_H
#define SETTINSG_H

enum errorCorrectionLevel {L, M, Q, H};
enum encodingMode {numeric, alphanumeric, byte, kanji};
enum inputSource {standardin, commandLineArg, file};

typedef struct Settings {
  enum errorCorrectionLevel ecl;
  enum encodingMode em;
  enum inputSource is;
  int version;
};
#endif

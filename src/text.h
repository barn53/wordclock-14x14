#pragma once
#include <Arduino.h>

#define WIDTH 14
#define HEIGHT 14
#define PIXELS (WIDTH * HEIGHT)

// clang-format off
static std::string letters(
  // 0    5       13
    "ES IST DREINE " // 0
    "VIERZWEI ACHTE" // 1
    "SECHSIEBENEUNL" // 2
    "ZEHN FuNFZWoLF" // 3
    "MINUTEN NACH  " // 4
    "VOR HALB DREI " // 5
    "VIERTEL ZWoLF " // 6
    "ZWEINEUNULLELF" // 7
    "SECHSIEBENACHT" // 8
    "DREIVIER FuNF " // 9
    "ZEHNUNDZWANZIG" // 10
    "UHR VOR NACHAM" // 11
    "MITTAGSMORGENS" // 12
    "ABENDS 1234505" // 13
);
// clang-format on

void clear(bool* indexes);
void createText(time_t startTime, std::string& text);
void indexesForText(const std::string& text, bool* indexes);

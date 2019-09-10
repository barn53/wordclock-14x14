#include "defines.h"
#include <Arduino.h>

using namespace std;

// clang-format off
char chars[PIXELS] = {
    ' ','E','S',' ','I','S','T',' ','Z','W','E','I','N','E',
    'A','D','R','E','I','V','I','E','R','T','E','L','F',' ',
    'C','S','E','C','H','S','I','E','B','E','N','E','U','N',
    'H','Z','W','o','L','F','u','N','F','-','Z','E','H','N',
    'T',' ','M','I','N','U','T','E','N',' ','N','A','C','H',
    ' ','V','O','R',' ','H','A','L','B',' ','D','R','E','I',
    '-','V','I','E','R','T','E','L',' ','A','C','H','T','F',
    'Z','W','E','I','S','I','E','B','E','N','U','L','L','u',
    'D','R','E','I','N','U','N','D','S','E','C','H','S','N',
    'Z','W','o','L','F','V','I','E','R','U',' ','E','L','F',
    '-','Z','W','A','N','Z','I','G','-','N','Z','E','H','N',
    'U','H','R',' ','V','O','R',' ','N','A','C','H','A','M',
    'M','I','T','T','A','G','S','M','O','R','G','E','N','S',
    'A','B','E','N','D','S',' ','1','2','3','4','5','0','5',
};
// clang-format on

bool display[PIXELS];

void clear()
{
    size_t s(0);
    for (const auto& d : display) {
        (void)d;
        display[s] = false;
        ++s;
    }
}

void orit(const std::initializer_list<bool>& bits)
{
    size_t s(0);
    for (const auto& b : bits) {
        display[s] = display[s] | b;
        ++s;
    }
}

void printDisplay()
{
    for (size_t i = 0; i < PIXELS; ++i) {
        Serial.println();
    }
    size_t s(0);
    for (const auto& d : display) {
        if (s % WIDTH == 0) {
            Serial.println();
        }
        if (d) {
            String c(chars[s]);
            if (c == "o") {
                c = "Ö";
            } else if (c == "u") {
                c = "Ü";
            } else if (c == "a") {
                c = "Ä";
            }
            Serial.print(c);
            Serial.print(" ");
        } else {
            Serial.print("  ");
        }
        ++s;
    }
}

void setSecond(uint8_t second)
{
    if (second / 10 >= 5) {
        orit(S_Z_5);
    } else if (second / 10 >= 4) {
        orit(S_Z_4);
    } else if (second / 10 >= 3) {
        orit(S_Z_3);
    } else if (second / 10 >= 2) {
        orit(S_Z_2);
    } else if (second / 10 >= 1) {
        orit(S_Z_1);
    }
    if (second % 10 >= 5) {
        orit(S_E_5);
    } else if (second / 10 >= 1) {
        orit(S_E_0);
    }
}

void setMinute(uint8_t minute)
{
    switch (minute) {
    case 0:
        orit(H_NULL);
        break;
    case 1:
        orit(M_EINE);
        orit(M_MINUTE);
        break;
    case 2:
        orit(M_ZWEI);
        orit(M_MINUTEN);
        break;
    case 3:
        orit(M_DREI_1);
        orit(M_MINUTEN);
        break;
    case 4:
        orit(M_VIER);
        orit(M_MINUTEN);
        break;
    case 5:
        orit(M_FUENF);
        orit(M_MINUTEN);
        break;
    case 6:
        orit(M_SECHS);
        orit(M_MINUTEN);
        break;
    case 7:
        orit(M_SIEBEN);
        orit(M_MINUTEN);
        break;
    case 8:
        orit(M_ACHT);
        orit(M_MINUTEN);
        break;
    case 9:
        orit(M_NEUN);
        orit(M_MINUTEN);
        break;
    case 10:
        orit(M_ZEHN);
        orit(M_MINUTEN);
        break;
    case 11:
        orit(M_ELF);
        orit(M_MINUTEN);
        break;
    case 12:
        orit(M_ZWOELF);
        orit(M_MINUTEN);
        break;
    case 13:
        orit(M_DREI_1);
        orit(M_DASH_ZEHN);
        orit(M_MINUTEN);
        break;
    case 14:
        orit(M_VIER);
        orit(M_DASH_ZEHN);
        orit(M_MINUTEN);
        break;
    case 15:
        break;
    case 16:
        orit(M_EINE);
        orit(M_MINUTE);
        break;
    case 17:
        orit(M_ZWEI);
        orit(M_MINUTEN);
        break;
    case 18:
        orit(M_DREI_1);
        orit(M_MINUTEN);
        break;
    case 19:
        orit(M_VIER);
        orit(M_MINUTEN);
        break;
    case 20:
        orit(M_ZEHN);
        orit(M_MINUTEN);
        break;
    case 21:
        orit(M_NEUN);
        orit(M_MINUTEN);
        break;
    case 22:
        orit(M_ACHT);
        orit(M_MINUTEN);
        break;
    case 23:
        orit(M_SIEBEN);
        orit(M_MINUTEN);
        break;
    case 24:
        orit(M_SECHS);
        orit(M_MINUTEN);
        break;
    case 25:
        orit(M_FUENF);
        orit(M_MINUTEN);
        break;
    case 26:
        orit(M_VIER);
        orit(M_MINUTEN);
        break;
    case 27:
        orit(M_DREI_1);
        orit(M_MINUTEN);
        break;
    case 28:
        orit(M_ZWEI);
        orit(M_MINUTEN);
        break;
    case 29:
        orit(M_EINE);
        orit(M_MINUTE);
        break;
    case 30:
        break;
    case 31:
        orit(M_EINE);
        orit(M_MINUTE);
        break;
    case 32:
        orit(M_ZWEI);
        orit(M_MINUTEN);
        break;
    case 33:
        orit(M_DREI_1);
        orit(M_MINUTEN);
        break;
    case 34:
        orit(M_VIER);
        orit(M_MINUTEN);
        break;
    case 35:
        orit(M_FUENF);
        orit(M_MINUTEN);
        break;
    case 36:
        orit(M_SECHS);
        orit(M_MINUTEN);
        break;
    case 37:
        orit(M_SIEBEN);
        orit(M_MINUTEN);
        break;
    case 38:
        orit(M_ACHT);
        orit(M_MINUTEN);
        break;
    case 39:
        orit(M_NEUN);
        orit(M_MINUTEN);
        break;
    case 40:
        orit(M_ZEHN);
        orit(M_MINUTEN);
        break;
    case 41:
        orit(M_VIER);
        orit(M_MINUTEN);
        break;
    case 42:
        orit(M_DREI_1);
        orit(M_MINUTEN);
        break;
    case 43:
        orit(M_ZWEI);
        orit(M_MINUTEN);
        break;
    case 44:
        orit(M_EINE);
        orit(M_MINUTE);
        break;
    case 45:
        break;
    case 46:
        orit(M_EINE);
        orit(M_MINUTE);
        break;
    case 47:
        orit(M_ZWEI);
        orit(M_MINUTEN);
        break;
    case 48:
        orit(M_DREI_1);
        orit(M_MINUTEN);
        break;
    case 49:
        orit(M_VIER);
        orit(M_MINUTEN);
        break;
    case 50:
        orit(M_ZEHN);
        orit(M_MINUTEN);
        break;
    case 51:
        orit(M_NEUN);
        orit(M_MINUTEN);
        break;
    case 52:
        orit(M_ACHT);
        orit(M_MINUTEN);
        break;
    case 53:
        orit(M_SIEBEN);
        orit(M_MINUTEN);
        break;
    case 54:
        orit(M_SECHS);
        orit(M_MINUTEN);
        break;
    case 55:
        orit(M_FUENF);
        orit(M_MINUTEN);
        break;
    case 56:
        orit(M_VIER);
        orit(M_MINUTEN);
        break;
    case 57:
        orit(M_DREI_1);
        orit(M_MINUTEN);
        break;
    case 58:
        orit(M_ZWEI);
        orit(M_MINUTEN);
        break;
    case 59:
        orit(M_EINE);
        orit(M_MINUTE);
        break;
    }

    if ((minute >= 1 && minute <= 14)
        || (minute >= 16 && minute <= 19)
        || (minute >= 31 && minute <= 40)
        || (minute >= 46 && minute <= 49)) {
        orit(M_NACH);
    }
    if ((minute >= 20 && minute <= 29)
        || (minute >= 41 && minute <= 44)
        || (minute >= 50 && minute <= 59)) {
        orit(M_VOR);
    }
    if ((minute >= 20 && minute <= 40)) {
        orit(M_HALB);
    }
    if ((minute >= 15 && minute <= 19)) {
        orit(M_VIERTEL_2);
    }
    if ((minute >= 41 && minute <= 49)) {
        orit(M_DREI_2);
        orit(M_DASH_VIERTEL_2);
    }
}

void setup()
{
    Serial.begin(115200);
}

size_t second(0);
size_t minute(0);
size_t hour(0);
void loop()
{
    clear();
    if (second == 60) {
        second = 0;
        ++minute;
    }
    if (minute == 60) {
        minute = 0;
        ++hour;
    }
    if (hour == 24) {
        hour = 0;
    }

    setSecond(second);

    setMinute(minute);

    orit(ES_IST);
    orit(H_UHR);

    printDisplay();
    Serial.println();
    Serial.printf("%02u:%02u:%02u\n", hour, minute, second);

    ++second;
    delay(300);
}

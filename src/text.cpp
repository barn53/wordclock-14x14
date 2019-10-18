#include "text.h"

using namespace std;

void clear(bool* indexes)
{
    for (size_t i = 0; i < PIXELS; ++i) {
        indexes[i] = false;
    }
}

void createText(time_t startTime, string& text)
{
    time_t t(startTime + (millis() / 1000));
    tm* currentTime(localtime(&t));

    auto& hour(currentTime->tm_hour);
    auto& minute(currentTime->tm_min);
    auto& second(currentTime->tm_sec);

    text = "ES IST";

    switch (minute) {
    case 0:
        text.append(" ");
        break;
    case 1:
    case 16:
    case 29:
    case 31:
    case 44:
    case 46:
    case 59:
        text.append(" EINE MINUTE");
        break;
    case 2:
    case 17:
    case 28:
    case 32:
    case 43:
    case 47:
    case 58:
        text.append(" ZWEI MINUTEN");
        break;
    case 3:
    case 18:
    case 27:
    case 33:
    case 42:
    case 48:
    case 57:
        text.append(" DREI MINUTEN");
        break;
    case 4:
    case 19:
    case 26:
    case 34:
    case 41:
    case 49:
    case 56:
        text.append(" VIER MINUTEN");
        break;
    case 5:
    case 25:
    case 35:
    case 55:
        text.append(" FuNF MINUTEN");
        break;
    case 6:
    case 24:
    case 36:
    case 54:
        text.append(" SECHS MINUTEN");
        break;
    case 7:
    case 23:
    case 37:
    case 53:
        text.append(" SIEBEN MINUTEN");
        break;
    case 8:
    case 22:
    case 38:
    case 52:
        text.append(" ACHT MINUTEN");
        break;
    case 9:
    case 21:
    case 39:
    case 51:
        text.append(" NEUN MINUTEN");
        break;
    case 10:
    case 20:
    case 40:
    case 50:
        text.append(" ZEHN MINUTEN");
        break;
    case 11:
        text.append(" ELF MINUTEN");
        break;
    case 12:
        text.append(" ZWoLF MINUTEN");
        break;
    case 13:
        text.append(" DREI ZEHN MINUTEN");
        break;
    case 14:
        text.append(" VIER ZEHN MINUTEN");
        break;
    case 15:
        break;
    case 30:
        break;
    case 45:
        break;
    }

    if ((minute >= 1 && minute <= 14)
        || (minute >= 16 && minute <= 19)
        || (minute >= 31 && minute <= 40)
        || (minute >= 46 && minute <= 49)) {
        text.append(" NACH");
    }
    if ((minute >= 20 && minute <= 29)
        || (minute >= 41 && minute <= 44)
        || (minute >= 50 && minute <= 59)) {
        text.append(" VOR");
    }
    if ((minute >= 20 && minute <= 40)) {
        text.append(" HALB");
    }
    if ((minute >= 15 && minute <= 19)) {
        text.append(" VIERTEL");
    }
    if ((minute >= 41 && minute <= 49)) {
        text.append(" DREI VIERTEL");
    }

    uint8_t hour12(hour % 12);
    uint8_t hour24(hour);

    if (minute >= 15 && minute <= 49) {
        hour = hour12 + 1;
        hour24 = hour24 + 1;
    } else if (minute >= 50) {
        hour = hour24 + 1;
        hour24 = hour24 + 1;
    }
    if (hour == 24) {
        hour = 0;
    }
    if (hour24 == 24) {
        hour24 = 0;
    }

    switch (hour) {
    case 0:
        text.append(" NULL");
        break;
    case 1:
    case 21:
        text.append(" EIN");
        break;
    case 2:
    case 22:
        text.append(" ZWEI");
        break;
    case 3:
    case 13:
    case 23:
        text.append(" DREI");
        break;
    case 4:
    case 14:
        text.append(" VIER");
        break;
    case 5:
    case 15:
        text.append(" FuNF");
        break;
    case 6:
        text.append(" SECHS");
        break;
    case 7:
        text.append(" SIEBEN");
        break;
    case 8:
    case 18:
        text.append(" ACHT");
        break;
    case 9:
    case 19:
        text.append(" NEUN");
        break;
    case 10:
        text.append(" ZEHN");
        break;
    case 11:
        text.append(" ELF");
        break;
    case 12:
        text.append(" ZWoLF");
        break;
    case 16:
        text.append(" SECH");
        break;
    case 17:
        text.append(" SIEB");
        break;
    case 20:
        text.append(" ZWANZIG");
        break;
    }

    if (hour >= 13 && hour <= 19) {
        text.append(" ZEHN");
    }

    if (hour >= 21 && hour <= 23) {
        text.append(" UNDZWANZIG");
    }

    text.append(" UHR");

    if (hour24 >= 1 && hour24 <= 8) {
        text.append(" AM MORGEN");
    } else if (hour24 >= 9 && hour24 <= 11) {
        text.append(" VOR MITTAGS");
    } else if (hour24 >= 12 && hour24 <= 13) {
        text.append(" MITTAGS");
    } else if (hour24 >= 18 && hour24 <= 23) {
        text.append(" NACH MITTAGS");
    }

    char s[10];
    text.append(" ");
    text.append(itoa(second / 10, s, 10));

    if (second % 10 < 5) {
        text.append(" 0");
    } else {
        text.append(" 5");
    }
}

void indexesForWord(const string& word, size_t& displayIndex, bool* indexes)
{
    size_t displayWordBegin(letters.find(word, displayIndex));
    if (word == "ELF" && displayIndex < ((WIDTH * 3) + (WIDTH - 1))) {
        indexes[(WIDTH * 1) + (WIDTH - 1)] = true;
        indexes[(WIDTH * 2) + (WIDTH - 1)] = true;
        indexes[(WIDTH * 3) + (WIDTH - 1)] = true;
        displayIndex = (WIDTH - 1) * 4;
    } else if (displayWordBegin != string::npos) {
        size_t wordSize(word.size());
        string displayWord;
        displayWord = letters.substr(displayWordBegin, wordSize);
        // Serial.printf("\n  %u -%s-\n", displayIndex, displayWord.c_str());
        for (size_t i = displayWordBegin; i < displayWordBegin + wordSize; ++i) {
            indexes[i] = true;
            // Serial.print(' ');
            // Serial.print(i);
        }
        displayIndex = displayWordBegin + wordSize;
    } else {
        displayIndex = letters.size();
        // Serial.printf("\n  Fähler!");
    }
    // Serial.println();
}

void indexesForText(const string& text, bool* indexes)
{
    size_t wordBegin(0);
    size_t wordEnd(text.find(' '));
    string word;
    size_t displayIndex(0);
    while (wordBegin <= text.size()) {
        word = text.substr(wordBegin, wordEnd - wordBegin);
        // Serial.printf("\n%u, %u, '%s'", wordBegin, wordEnd, word.c_str());
        indexesForWord(word, displayIndex, indexes);
        wordBegin = wordEnd + 1;
        wordEnd = text.find(' ', wordBegin);
        if (wordEnd == string::npos) {
            wordEnd = text.size();
        }
    }
}

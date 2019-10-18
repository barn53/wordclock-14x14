#include "display.h"
#include "text.h"
#include "wifi.h"

#include <Arduino.h>

using namespace std;

void printDisplay(const bool* indexes)
{
    Serial.println("-------------------------------------------");

    size_t s(0);
    for (size_t i = 0; i < PIXELS; ++i) {
        if (s % WIDTH == 0) {
            Serial.println();
        }
        if (indexes[i]) {
            string c(1, letters[s]);
            if (c == "o") {
                c = "Ö";
            } else if (c == "u") {
                c = "Ü";
            } else if (c == "a") {
                c = "Ä";
            }
            Serial.print(c.c_str());
            Serial.print(" ");
        } else {
            Serial.print("  ");
        }
        ++s;
    }
}

// https://arduinojson.org/v6/assistant/
DynamicJsonDocument timeDoc(JSON_OBJECT_SIZE(15) + 350);

time_t startTime;
bool indexes[PIXELS];
string text;

Display display(WIDTH, HEIGHT);

void printTime()
{
    time_t t(startTime + (millis() / 1000));
    tm* currentTime(localtime(&t));
    Serial.printf("%u.%u.%u %02u:%02u:%02u\n",
        currentTime->tm_mday, currentTime->tm_mon + 1, currentTime->tm_year + 1900,
        currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);
}

void setup()
{
    Serial.begin(115200);
    display.begin();
    setupWiFi();
    getTime(timeDoc, startTime);
    wifiSleep();
}

void loop()
{
    clear(indexes);
    createText(startTime, text);
    indexesForText(text, indexes);
    //printDisplay(indexes);
    display.toPixels(indexes);
    printTime();

    delay(1000);
}

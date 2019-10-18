#pragma once
#include <ArduinoJson.h>

void wifiSleep();
void wifiWake();
void setupWiFi();
void getTime(DynamicJsonDocument& doc, time_t& startTime);

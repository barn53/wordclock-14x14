#pragma once
#include <Arduino.h>

class State {
public:
    State();

    void loop();

    time_t& getStartTime() { return m_start_time; }

    bool displayOff() const;
    void clearDisplay();
    time_t secondsSinceLastMove() const;
    bool displayCleared() const { return m_display_cleared; }

    bool refreshText(const std::string& text);

private:
    time_t m_last_move;
    bool m_display_cleared;
    std::string m_last_text;
    time_t m_start_time;
};

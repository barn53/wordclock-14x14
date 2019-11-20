#include "state.h"

using namespace std;

State::State()
    : m_last_move(millis())
    , m_display_cleared(false)
{
}

void State::loop()
{
    digitalWrite(D2, digitalRead(D6));
    if (digitalRead(D6)) {
        m_last_move = millis() / 1000;
        m_display_cleared = false;
    }
}

bool State::displayOff() const
{
    return secondsSinceLastMove() > 5;
}
void State::clearDisplay()
{
    m_display_cleared = true;
    m_last_text.clear();
}
time_t State::secondsSinceLastMove() const
{
    return (millis() / 1000) - m_last_move;
}

bool State::refreshText(const string& text)
{
    if (m_last_text != text) {
        m_last_text = text;
        return true;
    }
    return false;
}

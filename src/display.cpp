#include "display.h"

Display::Display(size_t width, size_t height)
    : m_width(width)
    , m_height(height)
    , m_pixels(width * height)
    , m_animations(1)
    , m_random_seeded(false)
{
}

void Display::begin()
{
    m_pixels.Begin();
    m_pixels.ClearTo(RgbColor(0x0, 0x0, 0x0));
    m_pixels.Show();
}

void Display::toPixels(bool* indexes)
{
    m_animations.StopAll();

    for (size_t index = 0; index < (m_width * m_height); ++index) {

        auto displayIndex(index);
        size_t row(index / m_width);
        if (row % 2 == 1) {
            size_t rowIndex(index - (row * m_width));
            size_t mirroredRowIndex(m_width - 1 - rowIndex);
            displayIndex = (row * m_width) + mirroredRowIndex;
        }

        if (indexes[index]) {
            //m_pixels.SetPixelColor(displayIndex, RgbColor(255, 255, 255));
            //m_pixels.SetPixelColor(displayIndex, getRandomColor());
            m_pixels.SetPixelColor(displayIndex, RgbColor(200, 255, 255));
        } else {
            m_pixels.SetPixelColor(displayIndex, RgbColor(0, 0, 0));
        }
    }
    m_pixels.Show();
}

RgbColor Display::getRandomColor() const
{
    return RgbColor(random(256), random(256), random(256));
}

#if 0
void Display::blinkyBlinkyAnimation(const AnimationParam& param)
{
    RgbColor c;
    if (m_counters[param.index] % 2 == 0) {
        c = RgbColor::LinearBlend(m_colors_1[param.index], m_colors_2[param.index], param.progress);
    } else {
        c = RgbColor::LinearBlend(m_colors_2[param.index], m_colors_1[param.index], param.progress);
    }

    m_pixels.SetPixelColor(param.index, m_state.correctColor(c));

    if (param.state == AnimationState_Completed) {
        if (m_counters[param.index] % 2 == 0) {
            m_colors_1[param.index] = getRandomColor();
        } else {
            m_colors_2[param.index] = getRandomColor();
        }
        ++m_counters[param.index];
        m_animations.RestartAnimation(param.index);
    }
}
#endif

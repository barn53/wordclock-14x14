#pragma once

#include <NeoPixelAnimator.h>
#include <NeoPixelBus.h>
#include <vector>

using Feature = NeoGrbFeature;
//using Feature = NeoRgbFeature;

class Display {
public:
    Display(size_t width, size_t height);

    void begin();
    void toPixels(bool* indexes);

private:
    void blinkyBlinkyAnimation(const AnimationParam& param);

    RgbColor getRandomColor() const;

    const size_t m_width;
    const size_t m_height;

    NeoPixelBus<Feature, Neo800KbpsMethod> m_pixels;
    NeoPixelAnimator m_animations;
    bool m_random_seeded;
};

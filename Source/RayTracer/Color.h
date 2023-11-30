#pragma once
#include "glm/glm.hpp"

using color3_t = glm::vec3;
using color4_t = glm::vec4;
using rgba_t = uint32_t;

class Color
{
};

inline color4_t RGBAToColor(const rgba_t& rgba)
{
    float r = (float) ((rgba >> 24) & 0xFF) / 255.0f;
    float g = (float) ((rgba >> 16) & 0xFF) / 255.0f;
    float b = (float) ((rgba >> 8) & 0xFF) / 255.0f;
    float a = (float) (rgba & 0xFF) / 255.0f;

    return color4_t(r, g, b, a);
}

inline rgba_t ColorToRGBA(const color4_t& color) {
    rgba_t rgba = 0;

    rgba |= uint8_t(glm::clamp(color.r, 0.0f, 1.0f) * 255.0f) << 24;
    rgba |= uint8_t(glm::clamp(color.g, 0.0f, 1.0f) * 255.0f) << 16;
    rgba |= uint8_t(glm::clamp(color.b, 0.0f, 1.0f) * 255.0f) << 8;
    rgba |= uint8_t(glm::clamp(color.a, 0.0f, 1.0f) * 255.0f) << 0;

    return rgba;
}
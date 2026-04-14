#pragma once
#include <cmath>

struct Vec2 {
    float x, y;
};

inline Vec2 applyHeadWarp(Vec2 uv, float yaw, float pitch) {
    // simple perspective illusion warp
    uv.x += yaw * (uv.y - 0.5f);
    uv.y += pitch * (uv.x - 0.5f);
    return uv;
}

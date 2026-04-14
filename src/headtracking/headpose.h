#pragma once

#include <cstdint>

struct HeadPose {
    float x;
    float y;
    float z;

    float pitch;
    float yaw;
    float roll;

    uint64_t timestamp;
};

#pragma once

#include "headpose.h"

class WarpLayer {
public:
    void update(const HeadPose& pose);

    float yaw() const;
    float pitch() const;

private:
    float m_yaw = 0.0f;
    float m_pitch = 0.0f;
};

#include "warp_layer.h"

void WarpLayer::update(const HeadPose& pose) {
    m_yaw   = pose.yaw;
    m_pitch = pose.pitch;
}

float WarpLayer::yaw() const {
    return m_yaw;
}

float WarpLayer::pitch() const {
    return m_pitch;
}

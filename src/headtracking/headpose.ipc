#pragma once
#include "headpose.h"

class HeadPoseIPC {
public:
    HeadPoseIPC();
    ~HeadPoseIPC();

    bool isValid() const;

    HeadPose getPose();

private:
    int fd;
    HeadPose* ptr;
};

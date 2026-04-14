#include "headpose_ipc.h"

#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

HeadPoseIPC::HeadPoseIPC() {
    fd = shm_open("/gamescope_headpose", O_RDONLY, 0666);
    if (fd < 0) {
        ptr = nullptr;
        return;
    }

    ptr = (HeadPose*) mmap(
        nullptr,
        sizeof(HeadPose),
        PROT_READ,
        MAP_SHARED,
        fd,
        0
    );
}

HeadPoseIPC::~HeadPoseIPC() {
    if (ptr) munmap(ptr, sizeof(HeadPose));
    if (fd >= 0) close(fd);
}

bool HeadPoseIPC::isValid() const {
    return ptr != nullptr;
}

HeadPose HeadPoseIPC::getPose() {
    if (!ptr) return {};
    return *ptr;
}

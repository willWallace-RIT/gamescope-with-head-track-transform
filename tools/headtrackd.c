#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

typedef struct {
    float x, y, z;
    float pitch, yaw, roll;
    unsigned long long timestamp;
} HeadPose;

int main() {
    int fd = shm_open("/gamescope_headpose", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(HeadPose));

    HeadPose* pose = mmap(0, sizeof(HeadPose),
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED, fd, 0);

    while (1) {
        struct timespec t;
        clock_gettime(CLOCK_MONOTONIC, &t);

        float time = t.tv_nsec * 1e-9f;

        pose->yaw   = sinf(time) * 0.25f;
        pose->pitch = cosf(time) * 0.15f;

        pose->roll = 0.0f;
        pose->timestamp = t.tv_nsec;

        usleep(1000);
    }
}

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

    HeadPose *pose = mmap(0, sizeof(HeadPose),
                          PROT_READ | PROT_WRITE,
                          MAP_SHARED, fd, 0);

    while (1) {
        // TEMP MOCK MOTION (replace with real tracking later)
        struct timespec t;
        clock_gettime(CLOCK_MONOTONIC, &t);

        pose->yaw = sin(t.tv_nsec * 1e-9) * 0.2f;
        pose->pitch = cos(t.tv_nsec * 1e-9) * 0.1f;

        pose->timestamp = t.tv_nsec;

        usleep(1000); // ~1kHz update
    }
}

#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc, char* argv[]) {
    // initBarrier();
    // barrier();
    int pid;
    int delay = 10000000;
    pid = fork();

    if (pid > 0) {
        pid = fork();
        if (pid > 0) {
            pid = fork();
            if (pid > 0) {
                pid = fork();
            }
            else while (delay > 0)
                delay--;
        }
        else while (delay > 0)
            delay--;
    }
    else while (delay > 0)
        delay--;

    for (int i = 0; i < 5; i++)
        wait();
}
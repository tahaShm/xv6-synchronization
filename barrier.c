#include "types.h"
#include "stat.h"
#include "user.h"

int fib(int n) {
    if (n == 0 || n == 1)
        return 1;
    else 
        return(fib(n - 1) + fib(n - 2));
}

int main (int argc, char* argv[]) {
    int pid;

    initBarrier();

    pid = fork();
    if (pid > 0) {
        pid = fork();
        if (pid > 0) {

            pid = fork();
            if (pid > 0) {
    
                pid = fork();
                if (pid == 0) {
                    fib(15);
                    barrier();
                }
            }
            else  {
                fib(22);
                barrier();
            }
        }
        else  {
            fib(18);
            barrier();
        }
    }
    else {
        fib(7);
        barrier();
        
    }

    for (int i = 0; i < 4; i++)
        wait();
    // barrier();

    exit();
}
#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"

#define MAXBARRIERS 10

int fib(int n) {
    if (n == 0 || n == 1)
        return 1;
    else 
        return(fib(n - 1) + fib(n - 2));
}

int main (int argc, char* argv[]) {
    int pid, idx = 0;

    for (idx = 0; idx < MAXBARRIERS - 1; idx++) {
        pid = fork();
        if (pid == 0)
            break;
    }

    fib(idx * 4);
    barrier();

    for (int i = 0; i < MAXBARRIERS - 1; i++)
        wait();

    exit();
}
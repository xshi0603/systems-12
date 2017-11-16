#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    printf("PARENT PID: %d\n", getpid());
    printf("Forking\n");
    int child1 = fork();
    int child2 = 0;
    if (child1 != 0) {
        child2 = fork();
    }
    if (child1 && child2) {
        int status;
        int cpid = waitpid(-1, &status, 0);
        unsigned char *ret = (unsigned char *) &status;
        ret++;
        printf("Child PID after finished: %d\n", cpid);
        printf("Child waited %d secs\n", *ret);
        printf("Parent finished!\n");
        return 0;
    } else {
        printf("Child PID: %d\n", getpid());
        srand(time(NULL));
        int num = rand() % 15 + 5;
        sleep(num);
        printf("Child finished!\n");
        return num;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    printf("PARENT PID: %d\n", getpid());
    printf("Forking\n");
    srand(time(NULL));
    int num1 = rand() % 15 + 5;
    int num2 = rand() % 15 + 5;
    //printf("t1: %d\t t2: %d\n", num1, num2);
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
	if (child1 == child2) {
	  sleep(num1);
	  printf("Child %d finished!\n", getpid());
	  return num1;
	}
	else {
	  sleep(num2);
	  printf("Child %d finished!\n", getpid());
	  return num2;
	}

    }
    return 0;
}

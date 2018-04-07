//me     : Weishi Wang, 260540022
//partner: Shihao Miao, 260562570

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"


int main(void) {
    int pid;
    // Create and initiate
    FILE * fp1 = fopen("TURN.txt", "w");
    if (fp1 == NULL) {
        fprintf(stderr, "%s", "TURN.txt is not found\n");
        exit(1);
    }
    // Initiate as 0 to let producer start first
    fputc('0', fp1);
    fclose(fp1);
    // Multi-process by using fork()
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "%s", "Wrong pid number");
        exit(1);
    }
    else if (pid == 0) {
        consumer();
    }
    else {
        producer();
    }
    return 0;
}


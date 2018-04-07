//me     : Weishi Wang, 260540022
//partner: Shihao Miao, 260562570

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"


void consumer(void) {
    // Initiate two char types variable
    char turn;
    char Output;
    /* infinite loop will terminated
     when no input be found in DATA.txt at its turn*/
    while (1) {
        // Same but opposite with the method in producer
        do {
            FILE * fp1 = fopen("TURN.txt", "r");
            if (fp1 == NULL) {
                fprintf(stderr, "%s", "TURN.txt is not accessible\n");
                exit(2);
            }
            turn = fgetc(fp1);
            fclose(fp1);
        } while (turn != '1');
        // Check and open DATA.txt
        FILE * fp2 = fopen("DATA.txt", "r");
        if (fp2 == NULL) {
            fprintf(stderr, "%s", "DATA.txt is not accessible\n");
            exit(2);
        }
        // Get one char from DATA.txt
        Output = fgetc(fp2);
        // Stop condition
        if (Output == EOF) {
            fclose(fp2);
            exit(0);
        }
        // Print on the screen
        putc(Output, stdout);
        // Close DATA.txt
        fclose(fp2);
        // Same but opposite with the method in producer
        FILE * fp1 = fopen("TURN.txt", "w");
        if (fp1 == NULL) {
            fprintf(stderr, "%s", "TURN.txt is not accessible\n");
            exit(2);
        }
        fputc('0', fp1);
        fclose(fp1);
    }
}

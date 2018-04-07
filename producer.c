//me     : Weishi Wang, 260540022
//partner: Shihao Miao, 260562570

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

void producer(void) {
    // Initiate two char types variable
    char turn;
    char Input;
    // Open the mydata.txt
    FILE * fp = fopen("mydata.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "%s", "mydata.txt is not accessible\n");
        exit(2);
    }
    // Loop
    while (Input != EOF) {
        // Inner loop to check the signal
        // If the signal become 0, then the inner loop terminated
        do {
            FILE * fp1 = fopen("TURN.txt", "r");
            if (fp1 == NULL) {
                fprintf(stderr, "%s", "TURN.txt not accessible\n");
                exit(2);
            }
            turn = fgetc(fp1);
            fclose(fp1);
        } while (turn != '0');
        // As the previous loop terminated
        // Copy one character from mydata.txt to DATA.txt
        FILE * fp2 = fopen("DATA.txt", "w");
        if (fp2 == NULL) {
            fprintf(stderr, "%s", "DATA.txt not accessible\n");
            exit(2);
        }
        Input = fgetc(fp);
        fputc(Input, fp2);
        fclose(fp2);
        
        // After the new data be entered into the DATA.txt
        // Turn the value to be 1 to let consumer know that
        FILE * fp3 = fopen("TURN.txt", "w");
        if (fp3 == NULL) {
            fprintf(stderr, "%s", "TURN.txt not accessible\n");
            exit(2);
        }
        fputc('1', fp3);
        fclose(fp3);
        
    }
    // Close the mydata.txt file
    fclose(fp);
}


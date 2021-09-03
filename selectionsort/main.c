#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// Existing problem: line 26 is hard code (int file[size] not working)

int main() {
    // read from file
    char filename[100]; // i.e. numbers.txt
    int numbers;

    FILE* fp;
    printf("Please enter the name of the file: \n");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Fail to open file.");
        return;  // exit
    }

    fscanf(fp, "%d", &numbers);
    int size = numbers; // get the first line, which is size of the file

    int i = 0;
    char file[10]; // to store 10 numbers
    while (fscanf(fp, "%d", &numbers) != EOF) {
        file[i] = numbers;
        i++;
    }

    for (int k = 0; k < size; k++) {
        printf("%d\n", file[k]);
    }
    fclose(fp);
    
    // selection sorting

    /*
    int size = sizeof file / sizeof file[0];
    printf("%d", size);
    */


    /*
    for (int k = 0; k < 10; k++) {
        printf("%d  ", file[k]);
    }*/
}
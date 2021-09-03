#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// TODO: sorting part
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
    char numberList[10]; // to store 10 numbers
    while (fscanf(fp, "%d", &numbers) != EOF) {
        numberList[i] = numbers;
        i++;
    }
    fclose(fp);
    





    // currently working on


    // selection sorting
    int current = 0;
    int minimum = 0;
    int temp = 0; 

    for (int j = 0; j < size; j++) {
        minimum = j;
        for (int k = j; k < size; k++) {
            if (numberList[k] < minimum) {
                minimum = k;
                temp = numberList[k];
                numberList[k] = minimum;
            }
        }
    }
}
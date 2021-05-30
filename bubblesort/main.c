#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// TODO: make the array "char file[100] to malloc(?), i.e. dynamic array with no fixed size"
// testing 
int main() {
    // read from file
    //char filename[100];
    int* filename = (int*)malloc(10*sizeof(int));
    int numbers;
    //char file[100];
    int* file = (int*)malloc(10*sizeof(int));   // what if 10 is not given?

    FILE* fp;
    printf("Please enter the name of the file: \n");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Fail to open file.");
        return;  // exit
    }

    int i = 0;
    while (fscanf(fp, "%d", &numbers) != EOF) {
        file[i] = numbers;
        i++;
    }

    // bubble sorting
    /*
    int size = sizeof file / sizeof file[0];
    printf("%d", size);
    */
    int size = 10; // hard code
    int temp;
    for (int tail = 9; tail > 0; tail--) {
        for (int j = 0; j < tail; j++) {
            if (file[j] > file[j + 1]) {
                temp = file[j + 1];
                file[j + 1] = file[j];
                file[j] = temp;
            }
        }
    }

    for (int k = 0; k < 10; k++) {
        printf("%d  ", file[k]);
    }
}
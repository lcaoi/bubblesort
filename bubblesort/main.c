#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main() {
    // read from file
    //char filename[100];
    int* filename = (int*)malloc(10 * sizeof(int));
    int numbers;
    //char file[100];
    int* file = (int*)malloc(10 * sizeof(int));   // what if 10 is not given?

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

    // for testing
    int size = sizeof file / sizeof file[0];
    printf("\n%d", size);   // output = 1
    int size2 = sizeof filename / sizeof filename[0];
    printf("\n%d\n", size2);   // output = 1

    // bubble sorting
    //int size = 10; // hard code
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

    // for testing
    int size3 = sizeof file / sizeof file[0];
    printf("\n%d", size3);   // output = 1
    int size4 = sizeof filename / sizeof filename[0];
    printf("\n%d", size4);   // output = 1
}
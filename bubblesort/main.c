#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main() {
    // read from file
    char filename[100];
    int numbers;

    FILE* fp;
    printf("Please enter the name of the file: \n");
    scanf("%s", filename);    
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Fail to open file.");
        return;  // exit
    }

    //count the number of integers
    int count = 0;
    while (fscanf(fp, "%d", &numbers) !=EOF) {
        count++;
    }

    //reset pointer after first loop
    rewind(fp);

    //generate array by using malloc
    int* file = (int*)malloc(count * sizeof(int)); // file is a pointer

    //read the file again to get the integers
    int i = 0;
    while (fscanf(fp, "%d", &numbers) != EOF) {
        file[i] = numbers;
        i++;
    }

    fclose(fp);

    // bubble sorting
    int temp;
    for (int tail = count-1; tail > 0; tail--) {
        for (int j = 0; j < tail; j++) {
            if (file[j] > file[j + 1]) {
                temp = file[j + 1];
                file[j + 1] = file[j];
                file[j] = temp;
            }
        }
    }

    //print the result
    for (int k = 0; k < count; k++) {
        printf("%d  ", file[k]);
    }
}
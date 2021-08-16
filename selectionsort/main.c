#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// Done: read the first line of the file
// Todo: 1. make it the size of the file 2. read the rest of the file 3. write the sorting part

int main() {
    // read from file
    char filename[100];
    int size = 0;
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
    size = numbers;
    /*
    while (fscanf(fp, "%d", &numbers) != EOF) {
        file[i] = numbers;
        i++;
    }*/
    fclose(fp);

    printf("%d", size);
    
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
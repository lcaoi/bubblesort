#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
	int numbers;
    char file;

	FILE* fp;
    printf("Please enter the name of the file: \n");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Fail to open file.");
        return;  // exit
    }

    while (fscanf(fp, "%d", &numbers) != EOF) {
        printf("%d\n", numbers);
    }
}

//
// Created by M.Ghelichkhani on 5/12/2025.
//


#include <stdio.h>

int main(){
    FILE *fptr = fopen("1.txt", "w");

    if (fptr == NULL) {
        puts("error opening file!");
        return 1;
    }

    fprintf(fptr, "first file fffff");
    fclose(fptr);

    FILE *file = fopen("14.txt", "r");
    if (file == NULL) {
        puts("error on read file");
        return 1;
    }

    char buffer[1000];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}
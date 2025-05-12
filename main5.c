//
// Created by M.Ghelichkhani on 5/12/2025.
//


#include <stdio.h>

int main(){
    FILE *fptr = fopen("1.txt","w");

    if(fptr == NULL){
        puts("error opening file!");
        return 1;
    }

    fprintf(fptr,"first file fffff");

    fclose(fptr);
    return 0;
}
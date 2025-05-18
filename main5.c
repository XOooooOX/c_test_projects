//
// Created by M.Ghelichkhani on 5/12/2025.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "exit_codes.h"

#define ALI 5

#define PRINT_NUMBER(i) printf("%d\n",i);

#define LOOP(v,s,e) for(int v=s;v<=e;v++){
#define ENDLOOP }

#define CMD(NAME) char NAME ## _cmd[256] = "";strcpy(NAME ## _cmd,#NAME);

#define LOG_ERROR(format, ...) fprintf(stderr,format,__VA_ARGS__)

#define LOOP_3(X, ...) printf("%s\n", #X);

#define LOOP_2(X, ...) printf("%s\n", #X);LOOP_3(__VA_ARGS__)

#define LOOP_1(X, ...) printf("%s\n", #X);LOOP_2(__VA_ARGS__)

#define LOOP5(...)LOOP_1(__VA_ARGS__)


int main(){

    LOOP5(copy paste cut)
    LOOP5(copy,paste,cut)
    LOOP5(copy,paste,cut,select)

    //exit(EXIT_OK);
    LOG_ERROR("Invalid number of arguments %d\n",255);
    printf("%d\n",ALI);

    CMD(copy);
    CMD(paste)
    CMD(cut)

    char cmd[256];
    scanf("%s",cmd);

    if(strcmp(cmd,copy_cmd) == 0){
        puts("copy");
    }

    int i = 0;

    LOOP(i,1,10)
        PRINT_NUMBER(i)
    ENDLOOP

    PRINT_NUMBER(4);
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


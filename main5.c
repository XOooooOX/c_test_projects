//
// Created by M.Ghelichkhani on 5/12/2025.
//

// agar dar file header gozashte shavad va in file chand bar ham dar yek file digar inject shavad moshkerli pish nemiad
#pragma once
// ravesh sonaty
#ifndef MYHEADER_H
#define MYHEADER_H

int sum(int a, int b);

#endif // MYHEADER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "exit_codes.h"

#define CONDITION
// gcc -D CONDITION -E main.c

#define CREATE_TRACE_POINTS

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

// like null in C++
#define nullptr ((void *)0)

int main5(){

    // all type is valid

    int* ptr1 = NULL;
    int * ptr2 = NULL;
    int *ptr3 = nullptr;

#ifdef CONDITION
    puts("condition");
#elif
    puts("no condition");
#endif

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

    // zamany ke pointer ra ++ mikonim baraye mesal
    // bar asad no type jelo miravad, agar int bashad 4 byte jelo miravad, agar char bashad 1 byte

    int var = 1;

    int * int_ptr = NULL;
    int_ptr = &var;

    char * char_ptr = NULL;
    char_ptr = (char*)&var;

    printf("befor -> intptr = %u,charptr = %u\n",(unsigned int)int_ptr,(unsigned int)char_ptr);

    int_ptr++;
    char_ptr++;

    printf("after -> intptr = %u,charptr = %u\n",(unsigned int)int_ptr,(unsigned int)char_ptr);
    return 0;
}


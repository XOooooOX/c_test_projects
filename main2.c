#include <malloc.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//
// Created by M.Ghelichkhani on 5/12/2025.
//

typedef struct {
    int id;
    char *name;
    int age;
} student;

typedef struct {
    int id;
    char name[10];
    int age;
} man;


// ijad yek method va seda zadan an ba pointer mesl delagate
int add(int a,int b) { return  a + b;}
int subtract(int a,int b) { return  a - b;}

int main(){

    int (*func_ptr)(int,int);

    func_ptr = add;

    printf("jam %d\n",func_ptr(5,6));

    func_ptr = subtract;

    printf("tafrigh %d\n",func_ptr(8,4));


    man m;
    strcpy(m.name,"hosein");
    m.id = 90;
    m.age = 90;


    student s1;
    s1.age = 1;
    // intory khely behine tare , vaghti tol arraye ro moshakas mikonim mesl model man
    // agar hata yek char meghdar begire baghi khone ha ham khali mimonan
    // vall to model char *name vaghti ba malloc behesh meghdar midim aval be tedead ma faza mide
    // vali bad az meghdar dehi ba string size dorost mishe
    s1.name = malloc(100 * sizeof (char));
    if(s1.name == NULL){
        perror("malloc");
        return 1;
    }
    strcpy(s1.name,"ali");
    s1.id =6;

    student s2;
    student *ptrstudent = &s2;

    // mesl generic ya object
    void  *ptrtostudentbyvoid = &s2;

    ((student*)ptrtostudentbyvoid)->id = 44;

    student **ptrtoptrstudent = &ptrstudent;

    (*ptrtoptrstudent)->id = 3;

    ptrstudent->id =2;
    ptrstudent->age =90;
    ptrstudent->name = malloc(100 * sizeof (char));
    strcpy(ptrstudent->name,"reza");

    int a = 10;
    int b = a + 4;


    // takhsis hafeze
    int *arr = (int*)malloc(50 * sizeof (int));
    // masalan vaghti tedad ozv haye arraye ro nemidonim va mikhaim
    // tedad dynamic bashe in kar ro mikonim


    for (int i = 0; i < 50; ++i) {
        *(arr + i) = i;  // مقداردهی به خانه iام از طریق pointer
        printf("number in array: %d\n", *(arr + i));
        printf("pointer in array: %p (hexadecimal)\n", (void*)(arr + i));

        uintptr_t address = (uintptr_t)(arr + i);
        printf("pointer in array: %lu (decimal)\n\n", (unsigned long)address);
    }

    for (int i = 0; i < 50; ++i) {
        arr[i]= i;
        printf("number in array %d\n",arr[i]);
        printf("pointer in array %p hexadecimal\n",&arr[i]);
        uintptr_t address = (uintptr_t)&arr[i];
        printf("pointer in array %lu decimal \n ",(unsigned long)address);
    }

    return  0;
}
//
// Created by M.Ghelichkhani on 5/21/2025.
//
#include <stdio.h>
#include <stdbool.h>

bool match(const char* pattern, const char* text);

int main(void){

    printf("%d\n", match("a*b", "aaab"));   // 1
    printf("%d\n", match(".*", "hello"));   // 1
    printf("%d\n", match("c*", ""));        // 1
    printf("%d\n", match("ab*", "a"));      // 1
    printf("%d\n", match("ab*", "abbb"));   // 1

    int counter = 0;

    char string[20];

    char * stringPtr = string;// or string

    while (counter < 20){
        *stringPtr = counter;
        printf("%d\n",*stringPtr);
        counter++;
        stringPtr++;
    }

    return 0;
}

bool match_star(char c,const char * pattern,const char * text){
    do {
        if(match(pattern,text)) return true;
    } while (*text != '\0' && (*text == c || c == '.') && text ++);

    return false;
}

bool match(const char * pattern,const char * text){
    if(*pattern == '\0') return *text == '\0';

    if(*(pattern +1) == '*'){
        return match_star(*pattern,pattern +2 ,text);
    }

    if(*pattern == '.' || *pattern == *text){
        return match(pattern+1,text+1);
    }
    return false;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

typedef struct{
    char** parole;
    int cnt;
}ArrayParole;

int inserisci(ArrayParole* array, const char* str);

int main() {
    ArrayParole words;
    words.parole = (char**)calloc(SIZE, sizeof(char*));
    words.cnt = 0;
    return 0;
}

int inserisci(ArrayParole* array, const char* str) {
    if (array->cnt > 99) return -1;
    int len = strlen(str);
    array->parole[array->cnt] = (char*)malloc(len*sizeof(char));
    strcpy(array->parole[array->cnt], str);
    array->cnt++;
    return len;
}
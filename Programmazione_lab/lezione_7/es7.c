#include<stdio.h>

int occ(const char* str, char c);

int main() {
    char* str;
    char c;
    printf("Inserire una stringa: ");
    scanf("%s", str);
    getchar();
    printf("Inserire carattere da contare: ");
    scanf("%c", &c);
    printf("Occorrenze di %c in '%s': %d", c, str, occ(str, c));
    return 0;
}

int occ(const char* str, char c) {
    if(str == NULL) return -1;
    if(str[0] == '\0') return 0;
    if(str[0] == c) return occ(str+1, c) + 1;
    else return occ(str+1, c);
}
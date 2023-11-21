#include<stdio.h>

int lung(const char* s);

int main() {
    char* str;
    scanf("%s", str);
    printf("lunghezza di '%s': %d\n", str, lung(str));
    return 0;
}

int lung(const char* s) {
    if(s == NULL) return -1;
    if (s[0] == '\0') return 0;
    else return lung(s+1)+1;
}
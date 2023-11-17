#include<stdio.h>
#include<string.h>

void clean(char* _s, char* _t, char _c);

int main() {
    char str[BUFSIZ], cleaned[BUFSIZ];
    char c;
    if(fgets(str, BUFSIZ, stdin) == NULL) {
        printf("Error while reading user input\n");
        return -1;
    }
    printf("Character to remove: ");
    scanf("%c", &c);
    str[strlen(str)-1] = '\0'; //remove the last \n saved by fgets
    clean(str, cleaned, c);
    printf("Cleaned string: %s\n", cleaned);
}

void clean(char* _s, char* _t, char _c) {
    if (_s == NULL || _t == NULL) return;
    int i = 0, j = 0;
    for (i = 0; i <= strlen(_s); i++) {
        if (_s[i] != _c) _t[j++] = _s[i];
    }
}
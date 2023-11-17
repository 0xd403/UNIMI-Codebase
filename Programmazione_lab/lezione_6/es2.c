#include<stdio.h>
#include<string.h>

int equals(char *s, char* t);

int main() {
    char str1[BUFSIZ], str2[BUFSIZ];
    if(fgets(str1, BUFSIZ, stdin) == NULL) {
        printf("Error while reading user input\n");
        return -1;
    }
    if(fgets(str2, BUFSIZ, stdin) == NULL) {
        printf("Error while reading user input\n");
        return -1;
    }
    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';
    switch(equals(str1, str2)) {
        case 1:
            printf("Supplied strings are equals\n");
            break;
        case 0:
            printf("Supplied strings are not equals\n");
            break;
        default:
            printf("Error");
            break;
    }
    return 0;
}

// @desc check if the two given strings are equals
// @returns 1 if equals 0 otherwhise
int equals(char *s, char* t) {
    if (s == NULL || t == NULL) return 0;
    if (strlen(s) != strlen(t)) return 0;
    int eq = 1, i = 0;
    while (s[i] != '\0' && t[i] != '\0') {
        if (s[i] != t[i]) eq = 0;
        i++;
    }
    return eq;
}
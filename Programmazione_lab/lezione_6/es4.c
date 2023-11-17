#include<stdio.h>
#include<string.h>
#include<ctype.h>

// @desc confronts the supplied strings lexicographically
// @return 1 _s > t
// @return 0 _s == t
// @return -1 _s < t
int lex(char* _s, char* _t);

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
    switch(lex(str1, str2)) {
        case 1:
            printf("str1 > str2\n");
            break;
        case 0:
            printf("str1 == str2\n");
            break;
        case -1:
            printf("str1 < str2\n");
            break;
        default:
            printf("error\n");
            break;
    }
    return 0;
}

int lex(char* _s, char* _t) {
    if (_s == NULL || _t == NULL) return 0;
    int lens = strlen(_s), lent = strlen(_t);
    if (lens == lent) {
        for(int i = 0; i < lens; i++) {
            char c1 = tolower(_s[i]), c2 = tolower(_t[i]);
            if (c1 < c2) return -1;
            if (c1 > c2) return 1;
        }
        return 0;
    }
    else return lens < lent ? -1 : 1;
    
}
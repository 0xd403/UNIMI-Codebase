#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void ordina(char** _s, int _len);
int lex(char* _s, char* _t);

int main() {
    char **s = (char**)malloc(5*sizeof(char*));
    for (int i = 0; i < 5; i++) s[i] = (char*)malloc(BUFSIZ*sizeof(char));

    // Take the user input
    for (int i = 0; i < 5; i++) {   
        if (fgets(s[i], BUFSIZ, stdin) == NULL) {
            printf("Error while reading\n");
            return -1;
        }
        s[i][strlen(s[i])-1] = '\0';
    }

    ordina(s, 5);

    for (int i = 0; i < 5; i++) {
        printf("[%i] %s\n", i, s[i]);
    }

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

void ordina(char** _s, int _len) {
    char *aux;
    for (int i = 0; i < _len-1; i++) {
        for (int j = 0; j < _len-i-1; j++) {
            if (lex(_s[j],_s[j+1])) {
                aux = _s[j];
                _s[j] = _s[j+1];
                _s[j+1] = aux;
            }
        }
    }
}
#include<stdio.h>
#include<string.h>

int contains(char _trg, char* _cs, int _len);
void clean(char* _s, char* _t, char *_cs);

int main() {
    char str[BUFSIZ], cleaned[BUFSIZ], cs[5] = {'a','e','i','o','u'};
    char c;
    if(fgets(str, BUFSIZ, stdin) == NULL) {
        printf("Error while reading user input\n");
        return -1;
    }
    str[strlen(str)-1] = '\0'; //remove the last \n saved by fgets
    clean(str, cleaned, cs);
    printf("Cleaned string: %s\n", cleaned);
}

int contains(char _trg, char* _cs, int _len) {
    for (int i = 0; i < _len; i++) {
        if (_trg == _cs[i]) return 1;
    }
    return 0;
}

void clean(char* _s, char* _t, char* _cs) {
    if (_s == NULL || _t == NULL) return;
    int i = 0, j = 0;
    for (i = 0; i <= strlen(_s); i++) {
        if (!contains(_s[i], _cs, 5)) _t[j++] = _s[i];
    }
}
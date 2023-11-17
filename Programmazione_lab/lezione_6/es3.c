#include<stdio.h>
#include<string.h>

int palindroma(char* _s);

int main() {
    char str[BUFSIZ];
    if(fgets(str, BUFSIZ, stdin) == NULL) {
        printf("Error while reading user input\n");
        return -1;
    }
    str[strlen(str)-1] = '\0'; //remove the last \n saved by fgets
    if (palindroma(str)) printf("%s is palidrome\n", str);
    else printf("%s isn't palindrome\n", str);
    return 0;
}

// @desc checks if the supplied string is palindrome
// @return 1 if it is 0 otherwise
int palindroma(char* _s) {
    if (_s == NULL | _s[0] == '\0') return 0;
    int i = 0, j = strlen(_s)-1, isPal = 1;
    while (i < j && isPal) {
        if (_s[i] != _s[j]) isPal = 0;
        i++;
        j--;
    }
    return isPal;
}
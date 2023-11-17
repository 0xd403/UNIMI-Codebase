#include<stdio.h>
#include<string.h>

void reverse(char* s, char* t);

int main()
{
    char input[BUFSIZ], rev[BUFSIZ];
    if(fgets(input, BUFSIZ, stdin) == NULL) {
        printf("Error while reading user input\n");
        return -1;
    }
    else {
        input[strlen(input)-1] = '\0';
        reverse(input, rev);
        printf("Stringa invertita: %s\n", rev);
    }
    return 0;
}

void reverse(char* s, char* t) {
    int i = 0, j = strlen(s)-1;
    while (j >= 0) {
        t[i] = s[j];
        i++;
        j--;
    }
    t[i] = '\0';
}
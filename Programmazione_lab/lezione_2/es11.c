#include<stdio.h>
#include<ctype.h>

int main(int argc, char const *argv[])
{
    char c;
    printf("Inserisci un carattere minuscolo: ");
    scanf("%c", &c);
    if (isalpha(c)) 
        printf("in maiuscolo: %c\n", toupper(c));
    else 
        printf("%c\n", c);
    return 0;
}
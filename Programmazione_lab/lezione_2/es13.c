#include<stdio.h>
#include<ctype.h>

int main(int argc, char const *argv[])
{
    char c;
    int cm;
    printf("Inserisci un carattere: ");
    scanf("%c", &c);
    if (isalpha(c)) {
        printf("Conversione in maiuscola (0) o in minuscola (1): ");
        scanf("%d", &cm);
        if (cm == 0) printf("in maiuscola: %c\n", toupper(c));
        else printf("in minuscola: %c\n", tolower(c));
    }
    else 
        printf("Il carattere inserito non è una lettera alfabetica");
    return 0;
}
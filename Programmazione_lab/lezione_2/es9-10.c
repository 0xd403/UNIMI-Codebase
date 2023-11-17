#include<stdio.h>
#include<ctype.h>

int main(int argc, char const *argv[])
{
    char c;
    do {
        printf("Inserisci un carattere: ");
        scanf("%c", &c);
        if (!isalpha(c)) {
            printf("%c non è un carattere alfabetico\n", c);
        }
        else {
            if (isupper(c))
                printf("%c è una lettera maiuscola\n", c);
            else
                printf("%c è una lettera minuscola\n", c);
        }
        getchar();
    }while(c != '\n');
    return 0;
}
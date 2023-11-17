#include <stdio.h>

int main(int argc, char const *argv[])
{
    double a, b, ris;
    unsigned short op, running = 1;

    while (running)
    {
        printf("Inserisci l'operando a: ");
        scanf("%lf", &a);
        printf("Inserisci l'operando b: ");
        scanf("%lf", &b);
        do
        {
            printf("Operazione da eseguire (0-4): ");
            scanf("%hu", &op);
        } while (op > 4);
        switch (op)
        {
            case 0:
                printf("Chiusura del programma...\n");
                running = 0;
                break;
            case 1:
                ris = a + b;
                printf("%lf + %lf = %lf\n", a, b, ris);
                break;
            case 2:
                ris = a - b;
                printf("%lf - %lf = %lf\n", a, b, ris);
                break;
            case 3:
                ris = a * b;
                printf("%lf * %lf = %lf\n", a, b, ris);
                break;
            case 4:
                if (b == 0) {
                    printf("Impossibile dividere per 0\n");
                }
                else {
                    ris = a / b;
                    printf("%lf / %lf = %lf\n", a, b, ris);
                }    
                break;
            default:
                printf("Operazione non supportata\n");
                break;
            }
    }

    return 0;
}
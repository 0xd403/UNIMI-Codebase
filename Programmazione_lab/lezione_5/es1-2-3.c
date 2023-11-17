#include<stdio.h>

void updateOperands(double *_op1, double *_op2);
void printMenu();

int main(int argc, char const *argv[])
{
    double op1, op2, ris;
    char choice;
    int running = 1, hasSetOperands = 0;
    while(running) {
        printMenu();
        scanf("%c", &choice);
        getchar();
        if (hasSetOperands) {
            switch (choice)
            {
                case '0':
                    updateOperands(&op1, &op2);
                    hasSetOperands = 1;
                    break;
                case '1':
                    ris = op1 + op2;
                    break;
                case '2':
                    ris = op1 - op2;
                    break;
                case '3':
                    ris = op1 * op2;
                    break;
                case '4':
                    if (op2 != 0) ris = op1 / op2;
                    else printf("Il divisore dev'essere diverso da 0\n");
                    break;
                case '5':
                    printf("Programma terminato....\n");
                    running = 0;
                    break;
                default:
                    printf("Inserisci un caso da 0 a 5\n");
                    break;
            }
            if (hasSetOperands && choice != '0' && choice != '5')
                printf("Risultato: %lf\n", ris);
        }
        else {
            updateOperands(&op1, &op2);
            hasSetOperands = 1;
        }
    }
    return 0;
}

void updateOperands(double *_op1, double *_op2) {
    printf("Operando 1: ");
    scanf("%lf", _op1);
    printf("Operando 2: ");
    scanf("%lf", _op2);
    getchar();
    return;
}

void printMenu() {
    printf("\n--- MENU ---\n");
    printf("0) Inserisci operandi\n1)Addizione\n2)Sottrazione\n3)Moltiplicazione\n4)Divisione\n5)Esci\n>");
    return;
}
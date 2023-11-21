#include<stdio.h>
#include<stdlib.h>

double* allocVect(int len);
void printVect(const double* vect, int len);
void bubbleSort(double* vect, int len);

int main()
{
    int running = 1, choice, len;
    double* vect = NULL;
    while (running) {
        printf("**** MENU ****\n1)Inserisci elenco di double\n2)Ordina elenco\n3)Visualizza elenco\n4)Termina\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(vect != NULL) free(vect);
                printf("Numero di elementi da inserire: ");
                scanf("%d", &len);
                vect = allocVect(len);
                if(vect == NULL) printf("Errore durante l'allocazione\n");
                break;
            case 2:
                if(vect != NULL) {
                    bubbleSort(vect, len);
                }
                else printf("Vettore non ancora allocato\n");
                break;
            case 3:
                if(vect != NULL) {
                    printVect(vect, len);
                }
                else printf("Vettore non ancora allocato\n");
                break;
            case 4:
                printf("Programma terminato!\n");
                running = 0;
                break;
            default:
                printf("Inserisci un numero tra 1 e 4\n");
                break;
        }
    }
}

double* allocVect(int len) {
    double* vect = (double*)malloc(len * sizeof(double));
    if (vect != NULL) {
        for(int i = 0; i < len; i++) {
            printf("v[%d]: ", i);
            scanf("%lf", &vect[i]);
        }
    }
    return vect;
}

void printVect(const double* vect, int len) {
    printf("[");
    for(int i = 0; i < len; i++) { 
        printf("%lf, ", vect[i]); 
    }
    printf("]\n");
    return;
}

void bubbleSort(double* vect, int len) {
    double aux;
    for(int i = 0; i < len-1; i++) {
        for(int j = 0; j < len-i-1; j++) {
            if(vect[j]>vect[j+1]) {
                aux = vect[j];
                vect[j] = vect[j+1];
                vect[j+1] = aux;
            }
        }
    }
}
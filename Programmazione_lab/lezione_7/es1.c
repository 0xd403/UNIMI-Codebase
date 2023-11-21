#include<stdio.h>
#include<stdlib.h>

void printVect(const double* vect, int len);
void bubbleSort(double* vect, int len);

int main()
{
    int numOfElements;
    printf("Numero elementi da inserire: ");
    scanf("%d", &numOfElements);
    double* vect = (double*)malloc(numOfElements * sizeof(double));
    for(int i = 0; i < numOfElements; i++) {
        printf("vect[%d]: ", i);
        scanf("%lf", &vect[i]);
    }
    printf("Vettore prima dell'ordinamento:\n");
    printVect(vect, numOfElements);

    bubbleSort(vect, numOfElements);

    printf("Vettore dopo l'ordinamento:\n");
    printVect(vect, numOfElements);

    free(vect);

    return 0;
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
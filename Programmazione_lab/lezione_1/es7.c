#include<stdio.h>
#include<limits.h>

/*
    Scrivete un programma che assegni alla variabile intera num il valore INT_MAX 
    definito in limits.h. Visualizzate il valore di num. 
    Sommate la costante 1 a num. Visualizzate di nuovo il valore di num. 
    Datevi una spiegazione del risultato.
*/

int main(int argc, char const *argv[])
{
    int num = INT_MAX;
    printf("num: %d\n", num);
    num++;
    printf("num: %d\n", num);
    return 0;
}

/*
Spiegazione risultato: dato che gli int sono rappresentati in complemento a 2, sommando 1 al
massimo numero positivo, ricomincio dal più piccolo numero negativo
*/
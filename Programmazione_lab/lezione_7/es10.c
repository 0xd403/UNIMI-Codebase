/*
Scrivete un programma ricorsivo che legga in ingresso due interi m, n ⩾ 0 e calcoli e visualizzi il numero di Delannoy D(m, n).
Nel caso in cui l’utente inserisca valori che non soddisfano la condizione m, n ⩾ 0, forzate il reinserimento

I numeri di Delannoy soddisfano la seguente relazione ricorsiva: 
D(m, n) = D(m − 1, n) + D(m, n − 1) + D(m − 1, n − 1)
*/

#include<stdio.h>

int delannoy(int m, int n);

int main() {
    int m, n;
    do
    {
        printf("m: ");
        scanf("%d", &m);
        printf("n: ");
        scanf("%d", &n);
    } while (m < 0 && n < 0);
    printf("Delannoy(%d, %d) = %d\n", m, n, delannoy(m,n));
    return 0;
}

int delannoy(int m, int n) {
    if (m == 0 || n == 0) return 1; // base case
    return delannoy(m-1, n) + delannoy(m, n-1) + delannoy(m-1, n-1);
}
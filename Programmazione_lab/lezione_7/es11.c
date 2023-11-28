/*
Scrivete un programma che legga in ingresso due interi m, n ⩾ 0 e calcoli e visualizzi una tabella rettangolare 
di dimensioni m × n il cui elemento di posto (i, j) sia il numero di Delannoy D(i, j).
Nel caso in cui l’utente inserisca valori che non soddisfano la condizione m, n ⩾ 0, forzate il reinserimento.

I numeri di Delannoy soddisfano la seguente relazione ricorsiva: 
D(m, n) = D(m − 1, n) + D(m, n − 1) + D(m − 1, n − 1)
*/

#include<stdio.h>
#define SIZE 10

void printMatrix(int mat[][SIZE], int rows, int cols);
int dellanoy(int mat[][SIZE], int m, int n);

int main() {
    int m, n, res;
    int mat[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            mat[i][j] = 0;
        }
    }

    do
    {
        printf("m: ");
        scanf("%d", &m);
        printf("n: ");
        scanf("%d", &n);
    } while (m < 0 && n < 0);

    res = dellanoy(mat, m, n);
    printf("Dellanoy(%d,%d) = %d\n", m, n, res);

    printMatrix(mat, m, n);

    return 0;
}

void printMatrix(int mat[][SIZE], int m, int n) {
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int dellanoy(int mat[][SIZE], int m, int n) {
    if(m == 0 || n == 0) mat[m][n] = 1; // base case
    if(mat[m][n] == 0) { // if 0 this one hasn´t been computed before
        mat[m][n] = dellanoy(mat, m-1, n) + dellanoy(mat, m, n-1) + dellanoy(mat, m-1, n-1); // compute Dellanoy(m,n)
    }
    return mat[m][n]; // return the computed value
}
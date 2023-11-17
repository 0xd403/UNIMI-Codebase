#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i,j,n, flag;
    do {
        printf("Inserisci una cifra massima per calcolare i numeri primi: ");
        scanf("%d", &n);
    } while (n<2);
    printf("Numeri primi fino a %d: ", n);
    
    printf("2, ");
    for (i = 3; i <= n; i+=2) {
        flag = 0;
        for (j=2;j<i;j++) {
            if (i % j == 0) flag = 1;
        }
        if (flag == 0) printf("%d, ", i); 
    }
    printf("\n");
    return 0;
}
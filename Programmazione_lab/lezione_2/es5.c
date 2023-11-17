#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n, f, c = 0;

    do {
        printf("Inserisci n: ");
        scanf("%d", &n);
    }while(n < 1);

    f = (n*(n+1))/2;
    for(int i = 1; i <= n; c+=i, i++);

    printf("Formula: %d\nFor: %d\n", f, c);

    return 0;
}
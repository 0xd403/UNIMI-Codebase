#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, aux, cnt = 0;
    printf("Inserisci a: ");
    scanf("%d", &a);
    printf("Inserisci b: ");
    scanf("%d", &b);
    if (a <= 0 || b <= 0) {
        printf("ERRORE - a e b devono essere > 0\n");
        return -1;
    }
    printf("MCD(%d,%d)= ", a, b);
    while (b != 0) {
        aux = b;
        b = a % b;
        a = aux;
        cnt++;
    }
    printf("%d\n", a);
    printf("Divisioni eseguite: %d\n", cnt);
    return 0;
}
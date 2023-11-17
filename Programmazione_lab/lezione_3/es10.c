#include<stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int f1 = 1, f2 = 1, app;
    unsigned short n;

    printf("Inserisci n: ");
    scanf("%hu", &n);

    printf("%hd %hd ", f1, f2);
    for (int i = 3; i <= n; i++) {
        app = f2;
        f2 += f1;
        f1 = app;
        printf("%hd ", f2);
    }

    return 0;
}
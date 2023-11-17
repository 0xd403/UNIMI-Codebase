#include<stdio.h>
#include<math.h>

int main(int argc, char const *argv[])
{
    double a, b, c, disc, sol1, sol2;

    do {
        printf("Inserisci a (diversa da 0): ");
        scanf("%lf", &a);
    }while(a == 0);

    printf("Inserisci b: ");
    scanf("%lf", &b);

    printf("Inserisci c: ");
    scanf("%lf", &c);

    disc = pow(b, 2)-(4*a*c); // discriminante

    if (disc < 0)
        printf("Non ci sono soluzioni reali\n");
    else if (disc == 0)
        printf("1 soluzione reale\n");
    else {
        sol1 = (-b+(sqrt(disc)))/2*a;
        sol2 = (-b-(sqrt(disc)))/2*a;
        printf("2 soluzioni reali %lf e %lf", sol1, sol2);
    }

    return 0;
}
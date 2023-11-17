#include<stdio.h>

// Esercizi 1,2,3,4

int main(int argc, char const *argv[])
{
    int a, b,cnt=0;
    
    printf("Inserisi a b: ");
    scanf("%d %d", &a, &b);

    if (a < 0 || b < 0) {
        printf("a e b devono essere maggiori di 0\n");
        return -1;
    }
    else {
        while (a != b) {
            if (a > b)
                a -= b;
            else
                b -= a;
            cnt++;
        }
        printf("MCD: %d\nIterazioni: %d\n", a, cnt);
    }
    return 0;
}
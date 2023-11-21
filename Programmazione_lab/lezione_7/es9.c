#include<stdio.h>

int catalan(int n);

int main() {
    int n;
    printf("N: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        printf("C(%d) = %d\n", i, catalan(i));
    }
}

int catalan(int n) {
    if (n == 0) return 1;
    return (2*(2*n-1)*catalan(n-1))/(n+1);
}
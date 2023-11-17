#include<stdio.h>

int main(int argc, char const *argv[])
{
    int *px, *py, *tmp;
    *px = 0;
    *py = 1;
    printf("Prima dello scambio px=%d, py=%d", *px, *py);
    *tmp = *px;
    *px = *py;
    *py = *tmp;
    printf("Dopo lo scambio px=%d, py=%d", *px, *py);
    return 0;
}
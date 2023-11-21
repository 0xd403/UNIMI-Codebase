#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int* merge(const int* v1, int lenv1, const int* v2, int lenv2);

int main() {
    int v1[SIZE], v2[SIZE];
    int lenv1, lenv2;
    int* merged = NULL;
    printf("Elementi primo array: ");
    scanf("%d", &lenv1);
    for(int i = 0; i < lenv1; i++) {
        printf("v1[%d]: ", i);
        scanf("%d", &v1[i]);
    }
    printf("Elementi secondo array: ");
    scanf("%d", &lenv2);
    for(int i = 0; i < lenv2; i++) {
        printf("v2[%d]: ", i);
        scanf("%d", &v2[i]);
    }
    merged = merge(v1, lenv1, v2, lenv2);
    printf("\n");
    for(int i = 0; i < (lenv1+lenv2); i++) {
        printf("merged[%d]: %d\n", i, merged[i]);
    }
    return 0;
}

int* merge(const int* v1, int lenv1, const int* v2, int lenv2) {
    int newlen = lenv1 + lenv2;
    int* merged = (int*)malloc(newlen*sizeof(int));
    for(int i = 0; i < lenv1; i++) {
        merged[i] = v1[i];
    }
    for(int i = lenv1, j = 0; i < newlen; i++, j++) {
        merged[i] = v2[j];
    }
    return merged;
}
#include<stdio.h>
#include<math.h>

typedef struct {
    double x;
    double y;
} Vett;

double dist(Vett* p1, Vett* p2);

int main() {
    Vett p1, p2;
    printf("p1.x: ");
    scanf("%lf", &p1.x);
    printf("p1.y: ");
    scanf("%lf", &p1.y);
    printf("p2.x: ");
    scanf("%lf", &p2.x);
    printf("p2.y: ");
    scanf("%lf", &p2.y);
    printf("Distanza tra p1 e p2: %lf", dist(&p1, &p2));
}

double dist(Vett* p1, Vett* p2) {
    return sqrt(pow((p1->x-p2->x),2)+pow((p1->y-p2->y),2));
}
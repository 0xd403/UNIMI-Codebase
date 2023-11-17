#include<stdio.h>

typedef struct {
    double x;
    double y;
} Vett;

Vett* somma(Vett* p1, Vett* p2);
void invadd(Vett* p);
Vett* sott(Vett* p1, Vett* p2);
Vett* pscal(Vett* p);
Vett* pint(Vett* p1, Vett* p2);

int main() {

}

Vett* somma(Vett* p1, Vett* p2) {
    Vett* result = (Vett*)malloc(sizeof(Vett));
    result->x = p1->x + p2->x;
    result->y = p1->y + p2->y;
    return result;
}

void invadd(Vett* p) {
    p->x *= -1;
    p->y *= -1;
    return;
}

Vett* sott(Vett* p1, Vett* p2) {
    Vett* result = (Vett*)malloc(sizeof(Vett));
    result->x = p1->x - p2->x;
    result->y = p1->y - p2->y;
    return result;
}
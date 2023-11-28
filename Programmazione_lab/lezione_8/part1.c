#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node* next;
}node;

void stampaLista(node* head);
int inserisciInTesta(node** head, int value);
int inserisciInCoda(node** head, int value);
int rimuoviInTesta(node** head);
int rimuoviInCoda(node* head);
int cancella(node** head);
void cancellaRicorsivo(node** head);

int main() {
    node* head = NULL;
    inserisciInTesta(&head, 1);
    inserisciInCoda(&head, 2);
    inserisciInCoda(&head, 3);
    cancellaRicorsivo(&head);
    stampaLista(head);
}

void stampaLista(node* head) {
    node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    } 
    printf("NULL\n");
}

int inserisciInTesta(node** head, int value) {
    if ((*head) == NULL) {
        node* newhead = (node*)malloc(sizeof(node));
        newhead->value = value;
        newhead->next = NULL;
        (*head) = newhead;
    } else {
        node* newhead = (node*)malloc(sizeof(node));
        newhead->value = value;
        newhead->next = (*head);
        (*head) = newhead;
    }
    return (*head)->value;
}

int inserisciInCoda(node** head, int value) {
    if ((*head) == NULL) {
        node* newhead = (node*)malloc(sizeof(node));
        newhead->value = value;
        newhead->next = NULL;
        (*head) = newhead;
        return (*head)->value;
    }
    node* cnt = (*head);
    while (cnt->next != NULL) {
        cnt = cnt->next;
    }
    node* newtail = (node*)malloc(sizeof(node));
    newtail->value = value;
    newtail->next = NULL;
    cnt->next = newtail;
    return newtail->value;
}

int rimuoviInTesta(node** head) {
    if ((*head) == NULL) return -1;
    node* prevhead = (*head);
    (*head) = (*head)->next;
    free(prevhead);
    return 1;
}

int rimuoviInCoda(node* head) {
    if (head == NULL) return -1;
    node* cnt = head->next;
    node* prev = head;
    while (cnt->next != NULL) {
        cnt = cnt->next;
        prev = prev->next;
    }
    prev->next = NULL;
    free(cnt);
    return 0;
}

int cancella(node** head) {
    node* cnt = (*head);
    node* nx;
    while (cnt != NULL) {
        nx = cnt->next;
        free(cnt);
        cnt = nx;
    }
    (*head) = NULL;
    return 0;
}

void cancellaRicorsivo(node** head) {
    if ((*head) == NULL) return;
    cancellaRicorsivo(&((*head)->next));
    free((*head));
    (*head) = NULL; // conta come deallocata?
}
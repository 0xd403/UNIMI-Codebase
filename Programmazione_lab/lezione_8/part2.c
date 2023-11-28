#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node* next;
}node;

void stampaMenu();
void stampaLista(node* head);
int inserisciInTesta(node** head, int value);
int inserisciInCoda(node** head, int value);
int rimuoviInTesta(node** head);
int rimuoviInCoda(node* head);
void cancella(node** head);
void cancellaRicorsivo(node** head);
int salva(node* head, char* filename);
int carica(node** head, char* filename);
int rimuovi(node** head, int value);
void stampaRicorsiva(node* head);

int main() {
    node* head = NULL;
    char buf[30];
    int choice, val, opris;
    do {
        stampaMenu();
        do {
            printf("> ");
            scanf("%d", &choice);
        }while (choice < 0 && choice > 10);
        switch (choice) {
            case 0:
                printf("Programma terminato...\n");
                break;
            case 1:
                printf("Valore elemento da aggiungere: ");
                scanf("%d", &val);
                inserisciInTesta(&head, val);
                break;
            case 2:
                rimuoviInTesta(&head);
                break;
            case 3:
                printf("Valore elemento da aggiungere: ");
                scanf("%d", &val);
                inserisciInCoda(&head, val);
                break;
            case 4:
                rimuoviInCoda(head);
                break;
            case 5:
                printf("Valore elemento da rimuovere: ");
                scanf("%d", &val);
                opris = rimuovi(&head, val);
                if (opris == -1) {
                    printf("Elemento non presente\n");
                }
                break;
            case 6:
                printf("Nome file: ");
                scanf("%s", &buf);
                opris = carica(&head, buf);
                if (opris == -1) {
                    printf("File non esistente\n");
                }
                break;
            case 7:
                printf("Nome file: ");
                scanf("%s", &buf);
                opris = salva(head, buf);
                if (opris == -1) {
                    printf("Errore durante il salvataggio\n");
                }
                break;
            case 8:
                stampaLista(head);
                break;
            case 9:
                stampaRicorsiva(head);
                printf("\n");
                break;
            case 10:
                cancellaRicorsivo(&head);
                break;
            default:
                break;
        }
    }while (choice > 0);
    return 0;
}

void stampaMenu() {
    printf("\n1) Aggiungi un elemento in testa\n2)Rimuovi un elemento dalla testa\n3)Aggiungi un elemento in coda\n");
    printf("4)Rimuovi un elemento dalla coda\n5)Rimuovi un elemento dalla lista\n6)Carica lista da file\n7) Salva lista su file\n");
    printf("8)Stampa\n9) Stampa la lista in ordine inverso\n10) Cancella tutti gli elementi della lista\n0) Esci\n");
    return;
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

void cancella(node** head) {
    node* cnt = (*head);
    node* nx;
    while (cnt != NULL) {
        nx = cnt->next;
        free(cnt);
        cnt = nx;
    }
    (*head) = NULL;
    return;
}

void cancellaRicorsivo(node** head) {
    if ((*head) == NULL) return;
    cancellaRicorsivo(&((*head)->next));
    free((*head));
    (*head) = NULL; // conta come deallocata?
}

int salva(node* head, char* filename) {
    FILE* pf = fopen(filename, "w");
    if (pf != NULL) {
        node* curr = head;
        while (curr != NULL) {
            fprintf(pf, "%d->", curr->value);
            curr = curr->next;
        }
        fputs("NULL", pf);
        fclose(pf);
        return 1;
    } else {
        return -1;
    }
}

int carica(node** head, char* filename) {
    FILE* pf = fopen(filename, "r");
    int val;
    if (pf != NULL) {
        while (fscanf(pf, "%d->", &val) > 0) {
            inserisciInTesta(head, val);
        }
        fclose(pf);
        return 1;
    } else {
        return -1;
    }
}

int rimuovi(node** head, int value) {
    if ((*head)->value == value) { 
        rimuoviInTesta(head);
        return value;
    }
    node* prev = (*head);
    node* nxt = (*head)->next;
    int flag = 1;
    while (nxt != NULL && flag) {
        if (nxt->value == value) {
            prev->next = nxt->next;
            free(nxt);
            flag = 0;
        } else {
            prev = prev->next;
            nxt = nxt->next;
        }
    }
    return flag == 1 ? -1 : value;
}

void stampaRicorsiva(node* head) {
    if (head == NULL) return;
    stampaRicorsiva(head->next);
    printf("%d, ", head->value);
}
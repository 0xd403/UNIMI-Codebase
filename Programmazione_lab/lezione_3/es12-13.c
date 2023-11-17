#include<stdio.h>
#define SI 'S'
#define NO 'N'
typedef enum { false, true } bool;

int main(int argc, char const *argv[])
{
    bool d1, d2, d3, d4;
    char inp;

    do { 
        printf("1) Oggi piove? ");
        scanf("%1c", &inp);
        getchar();
        if (inp == SI) d1 = true;
        else d1 = false;
    } while(inp != SI && inp != NO);

    do {
        printf("2) Oggi è domenica? ");
        scanf("%1c", &inp);
        getchar();
        if (inp == SI) d2 = true;
        else d2 = false;
    } while(inp != SI && inp != NO);

    do {
        printf("3) Il giorno di oggi è un numero pari? ");
        scanf("%1c", &inp);
        getchar();
        if (inp == SI) d3 = true;
        else d3 = false;
    } while(inp != SI && inp != NO);

    do {
        printf("4) Le condizioni metereologiche sono buone? ");
        scanf("%1c", &inp);
        getchar();
        if (inp == SI) d4 = true;
        else d4 = false;
    } while(inp != SI && inp != NO);

    if ((d1 && d2) || (!d1 && d2)) { 
        if (d1 || !d4) printf("Il signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un ombrello.\n");
        else printf("Il signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un parasole.\n");
    }
    else if (!d1 && !d2) {
        if (d3) printf("Il signor Pignolino oggi e' uscito per recarsi ai giardini pubblici. Ha portato con se' un libro.\n");
        else printf("Il signor Pignolino oggi e' uscito per recarsi al Caffe'. Ha portato con se' il suo diario.\n");
    }
    else { 
        printf("Il signor Pignolino oggi non e' uscito.\n");
    }

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

char* mergeWords(char** words, int lenWords);

int main() {
    int lenWords;
    printf("Numero di parole da inserire: ");
    scanf("%d", &lenWords);
    getchar();

    char **words = (char**)malloc(lenWords*sizeof(char*));
    for (int i = 0; i < lenWords; i++) words[i] = (char*)malloc(N*sizeof(char));

    // Take the user input
    for (int i = 0; i < lenWords; i++) {
        printf("parola %d: ", i);  
        if (fgets(words[i], N, stdin) == NULL) {
            printf("Error while reading\n");
            return -1;
        }
        words[i][strlen(words[i])-1] = '\0';
    }

    printf("Parole inserite:\n");
    for (int i = 0; i < lenWords; i++) {
        printf("words[%i]: %s\n", i, words[i]);
    }

    char* merged = mergeWords(words, lenWords);

    printf("Stringa risultante: %s\n", merged);

}

char* mergeWords(char** words, int lenWords) {
    char* merged_str = (char*)malloc((lenWords*N)*sizeof(int));
    int k = 0;
    for(int i = 0; i < lenWords; i++) { // scorro le parole
        for(int j = 0; j < strlen(words[i]); j++, k++) merged_str[k] = words[i][j];
    }
    return merged_str;
}
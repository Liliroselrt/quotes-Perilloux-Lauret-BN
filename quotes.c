//
// Created by epope on 25/03/2025.
//
#include "quotes.h"

void print_quote(char ** quotes, int index) {
 printf("%s\n", quotes[index]);
}

void print_random_quote(char ** quotes) {
  int index = rand() % MAX_QUOTES;
  print_quote(quotes, index);
 }

typedef struct {
    char **citations;
    int count;
} CitationList;

void loadCitations(CitationList *list) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Fichier non trouvé. Création d'un nouveau fichier.\n");
        return;
    }
    char buffer[MAX_CITATION_LENGTH];
    while (fgets(buffer, MAX_CITATION_LENGTH, file)) {
        buffer[strcspn(buffer, "\n")] = 0;  // Supprimer le saut de ligne
        list->citations = realloc(list->citations, (list->count + 1) * sizeof(char*));
        list->citations[list->count] = strdup(buffer);
        list->count++;
    }
    fclose(file);
}

void saveCitations(CitationList *list) {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier pour écriture.\n");
        return;
    }
    for (int i = 0; i < list->count; i++) {
        fprintf(file, "%s\n", list->citations[i]);
    }
    fclose(file);
}

void addCitation(CitationList *list) {
    char buffer[MAX_CITATION_LENGTH];
    printf("Entrez une nouvelle citation : ");
    getchar();
    fgets(buffer, MAX_CITATION_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    list->citations = realloc(list->citations, (list->count + 1) * sizeof(char*));
    list->citations[list->count] = strdup(buffer);
    list->count++;
    saveCitations(list);
}

void deleteCitation(CitationList *list) {
    int index;
    printf("Entrez l'index de la citation à supprimer (1-%d) : ", list->count);
    scanf("%d", &index);
    if (index < 1 || index > list->count) {
        printf("Index invalide.\n");
        return;
    }
    free(list->citations[index - 1]);
    for (int i = index - 1; i < list->count - 1; i++) {
        list->citations[i] = list->citations[i + 1];
    }
    list->count--;
    list->citations = realloc(list->citations, list->count * sizeof(char*));
    saveCitations(list);
}

void displayCitations(CitationList *list) {
    printf("\nListe des citations :\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d. %s\n", i + 1, list->citations[i]);
    }
}

void freeCitations(CitationList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->citations[i]);
    }
    free(list->citations);
}

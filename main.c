//
// Created by lilir on 25/03/2025.
//
#include "quotes.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITATION_LENGTH 256
#define FILENAME "citations.txt"


int main() {
    char * quotes[MAX_QUOTES] = {
        "Programmer - An organism that turns caffeine into code",
        "Why do programmers prefer dark mode? Because light attracts bugs.",
        "If debugging is the process of removing software bugs, then programming must be the process of putting them in.",
        "I don't always test my code, but when I do, I do it in production.",
        "Why do programmers always mix up Christmas and Halloween? Because Oct 31 == Dec 25!",
        "Why did the programmer quit his job? Because he didn't get arrays.",
        "Why do programmers prefer iOS development? Because the Swift.",
        "Why do programmers prefer dogs over cats? Because dogs have fetch and cats have catch.",
        "Why do programmers hate nature? It has too many bugs.",
        "There are only 10 types of people in the world: Those who understand binary and those who don't."
    };

    srand(time(NULL));
    print_random_quote(quotes);

    CitationList list = {NULL, 0};
    loadCitations(&list);
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Ajouter une citation\n");
        printf("2. Supprimer une citation\n");
        printf("3. Afficher toutes les citations\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCitation(&list);
                break;
            case 2:
                deleteCitation(&list);
                break;
            case 3:
                displayCitations(&list);
                break;
            case 4:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choice != 4);
    freeCitations(&list);
    return 0;
}

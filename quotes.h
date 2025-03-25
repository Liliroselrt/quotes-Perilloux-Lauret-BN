//
// Created by epope on 25/03/2025.
//

#ifndef QUOTES_H
#define QUOTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUOTES 10

void print_quote(char **quotes, int index);

void print_random_quote(char **quotes);

void loadCitations(CitationList *list);

void saveCitations(CitationList *list);

void addCitation(CitationList *list);

void deleteCitation(CitationList *list);

void displayCitations(CitationList *list);

void freeCitations(CitationList *list);


#endif

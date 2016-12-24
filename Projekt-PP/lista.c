#include <stdio.h>
#include "lista.h"
#define MAX 35


void add(Lista beg, int count){
    int i = 0;
    Lista nowy;
    if(beg == NULL){
        beg = (Lista)malloc(sizeof(ELEMENT));
        beg->word_eng = (char*)malloc(sizeof(char)*MAX);
        beg->word_pol[0] = (char*)malloc(sizeof(char)*MAX);
        beg->word_pol[1] = (char*)malloc(sizeof(char)*MAX);
        beg->word_pol[2] = (char*)malloc(sizeof(char)*MAX);
        beg->next = NULL;
        i++;
    }
    for(; i<count; i++){
        nowy = (Lista)malloc(sizeof(ELEMENT));
        beg->next = nowy;
        nowy->word_eng = (char*)malloc(sizeof(char)*MAX);
        nowy->word_pol[0] = (char*)malloc(sizeof(char)*MAX);
        nowy->word_pol[1] = (char*)malloc(sizeof(char)*MAX);
        nowy->word_pol[2] = (char*)malloc(sizeof(char)*MAX);
        nowy->next = NULL;
        beg = nowy;
    }
}

int liczba_elementow(Lista beg){
    int count = 0;
    while(beg != NULL){
        count++;
        beg = beg->next;
    }
    return count;
}

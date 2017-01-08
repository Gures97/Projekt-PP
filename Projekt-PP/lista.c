#include <stdio.h>
#include <string.h>
#include "lista.h"

void dodaj_slowo(Lista *beg, char ang[], char pol[][MAX]){
    Lista ost = last(*beg);
    Lista nowy = (Lista)malloc(sizeof(ELEMENT));
    int i, j = 0;
    strcpy(nowy->word_eng, ang);
    for(i = 0; i<3; i++){
        if(strlen(pol[i]) > 0)
            strcpy(nowy->word_pol[j], pol[i]);
        j++;
    }
    nowy->next = NULL;
    if(*beg == NULL)
        *beg = nowy;
    else
        ost->next = nowy;
}

Lista last(Lista beg){
    if(beg == NULL)
        return NULL;
    while(beg->next != NULL)
        beg = beg->next;
    return beg;
}

Lista prev(Lista beg, Lista cur){
    if(cur == NULL || beg == NULL || beg->next == NULL)
        return NULL;
    while(beg->next != NULL){
        if(beg->next == cur)
            return beg;
        beg = beg->next;
    }
    return NULL;
}

int liczba_elementow(Lista beg){
    int count = 0;
    while(beg != NULL){
        count++;
        beg = beg->next;
    }
    return count;
}

void wyswietl_slowo(Lista slowo){
    int i;
    printf("%s\n",slowo->word_eng);
    for(i = 0;i<3;i++){
        if(strlen(slowo->word_pol[i])>0)
            printf(" - %s\n", slowo->word_pol[i]);
    }
    printf("\n\n");
}

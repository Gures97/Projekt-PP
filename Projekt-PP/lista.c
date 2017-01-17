#include <stdio.h>
#include <string.h>
#include "lista.h"

void dodaj_slowo(Lista *beg, char ang[], char pol[][MAX]){
    Lista ost = last(*beg);
    Lista nowy = (Lista)malloc(sizeof(ELEMENT));
    int i;
    strcpy(nowy->word_eng, ang);
    for(i = 0; i<3; i++)
        strcpy(nowy->word_pol[i], pol[i]);

    nowy->next = NULL;
    if(*beg == NULL)
        *beg = nowy;
    else
        ost->next = nowy;
}


void usun_slowo_ang(Lista *beg, char word[]){
    Lista slowko = czy_jest_ang(*beg, word);
    if(slowko == NULL)
        printf("Nie ma takiego slowa w slowniku.");
    else{
        usun_element(beg, slowko);
        printf("Slowo zostalo usuniete.");
    }
}

void usun_slowo_pol(Lista *beg, char word[]){
    int i;
    Lista slowko = czy_jest_pol(*beg, word);
    if(slowko == NULL)
        printf("Nie ma takiego slowa w slowniku.");
    else if(ile_pol(slowko) == 1){
        usun_element(beg, slowko);
    }
    else{
        for(i = 0; i<3; i++){
            if(!strcmp(slowko->word_pol[i], word)){
                strcpy(slowko->word_pol[i], "");
            }
        }
    }

    printf("Slowo zostalo usuniete.");
}

void usun_element(Lista *beg, Lista el){
    if(*beg == el){
        Lista newbg = (*beg)->next;
        free(*beg);
        *beg = newbg;
        return;
    }
    Lista prv = prev(*beg, el), nxt = el->next;
    free(el);
    prv->next = nxt;
}

Lista czy_jest_ang(Lista beg, char slowo[]){
    if(beg == NULL)
        return NULL;
    if(!strcmp(beg->word_eng, slowo))
        return beg;
    else
        czy_jest_ang(beg->next, slowo);
}

int ile_pol(Lista cur) {
    int i, suma = 0;
    for (i = 0; i<3; i++){
        if(strcmp(cur->word_pol[i], ""))
            suma++;
    }
    return suma;
}

Lista czy_jest_pol(Lista beg, char slowo[]){
    int i;
    if(beg == NULL)
        return NULL;
    for(i = 0; i<3; i++)
        if(!strcmp(beg->word_pol[i], slowo))
            return beg;
    czy_jest_pol(beg->next, slowo);
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

void destruktor(Lista beg){
    if(beg != NULL){
        Lista nast = beg->next;
        free(beg);
        destruktor(nast);
    }
}

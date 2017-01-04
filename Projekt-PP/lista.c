#include <stdio.h>
#include <string.h>
#include "lista.h"

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

Lista init_list(int count){
    int i;
    Lista beg = NULL, kon;
    if(count <= 0)
        return NULL;
    beg = (Lista)malloc(sizeof(ELEMENT));
    kon = beg;
    for(i = 1; i<count;i++){
        kon->next = (Lista)malloc(sizeof(ELEMENT));
        kon = kon->next;
    }
    kon->next = NULL;
    return beg;
}

int liczba_elementow(Lista beg){
    int count = 0;
    while(beg != NULL){
        count++;
        beg = beg->next;
    }
    return count;
}

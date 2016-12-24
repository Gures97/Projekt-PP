#include <stdio.h>
#include "lista.h"

Lista init(){
    Lista pocz = (Lista)malloc(sizeof(ELEMENT));
    pocz->next = NULL;
    return pocz;
}

void add_empty(Lista beg){
    Lista nowy = (Lista)malloc(sizeof(ELEMENT));
    if(beg == NULL)
        return;
    beg->next = nowy;
    nowy->next = NULL;

}

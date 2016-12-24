#include "lista.h"

Lista init(){
    Lista pocz = (Lista)malloc(sizeof(ELEMENT));
    pocz->next = NULL;
    return pocz;
}

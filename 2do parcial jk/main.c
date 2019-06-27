#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "entregas.h"

int main()
{
    LinkedList* listaEntregas = ll_newLinkedList();

    ent_menu(listaEntregas);

    return 0;
}

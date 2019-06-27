#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "entregas.h"
#include "controller.h"

/** \brief Parsea los datos los datos de los entregas desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pLinkedListEntregas LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile , LinkedList* pLinkedList)
{
    Entregas* this; //Creo un nuevo entrega
    int datosLeidos; //Contador de lectura
    char auxId[50], auxTipo[50], auxCantidad[50], auxImporte[50]; //Variables buffer
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTipo, auxCantidad, auxImporte); //Hago una primera lectura "fantasma" para leer el titulo el cual no voy a almacenar y le asigno a "datosLeidos" el retorno de la lectura "fscanf"
    while(!feof(pFile)) //Mientras no se llege al final del archivo
    {
        datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxTipo, auxCantidad, auxImporte); //Le asigno a "datosLeidos" el retorno de la lectura "fscanf"
        if(datosLeidos == 4) //Si datosLeidos es igual a los 4 datos pedidos a leer
        {
            this = ent_newParametros(auxId, auxTipo, auxCantidad, auxImporte); //Le asigno a "this" las variables leidas casteadas en la funcion
            ll_add(pLinkedList, this); //Agrego "this" al final del array de entregas
        }
        else if(datosLeidos != 4 && this != NULL) //Si datosLeidos es distinto a los 4 datos pedidos a leer
        {
            if(!feof(pFile)) //Si aun no se llego al final del archivo lo informo
            {
                printf("\nError al leer el ultimo dato.");
                break;
            }
            else //Si se leyo todo el archivo sin problemas lo informo
            {
                printf("\nSe leyo todo el archivo.");
            }
        }
    }
    printf("\n --> Empleados cargados correctamente.\n\n");
    fclose(pFile); //Cierro el archivo
    return 1;
}

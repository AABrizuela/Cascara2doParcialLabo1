#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "entregas.h"
#include "controller.h"

int inf_cantEnt(LinkedList* listaEntregas, int* cantEntregas)
{
    int ret = -1;
    int cantidadEntregas;

    if(cantEntregas != NULL)
    {
        cantidadEntregas = listaEntregas->size;
        *cantEntregas = cantidadEntregas;
        printf("%d\n", cantidadEntregas);
        ret = 0;
    }

    return ret;
}

/*int inf_cantEntTipo(LinkedList* listaEntregas, int* pContadorPlus, int* pContadorRegular, int* pContadorGold)
{
    Entregas* this;

    int i;
    int ret = -1;
    char tipo[10];

    int contadorPlus = 0;
    int contadorRegular = 0;
    int contadorGold = 0;

    if(ContadorGold != NULL && pContadorPlus != NULL && pContadorRegular != NULL)
    {
        for(i = 0; i < ll_len(listaEntregas); i++)
        {
            this = (Entregas*)ll_get(listaEntregas, i);
            ent_getTipo(this, tipo);

            if(strncmp(tipo, "PLUS", 10) == 0)
            {
                contadorPlus++;
            }
            else if(strncmp("REGULAR", tipo, 10) == 0)
            {
                contadorRegular++;
            }
            else if(strncmp("GOLD", tipo, 10) == 0)
            {
                contadorGold++;
            }
        }
        *pContadorPlus = contadorPlus;
        *pContadorRegular = contadorRegular;
        *pContadorGold = contadorGold;
        ret = 0;
    }

    return ret;
}*/

int inf_contGold(Entregas* this)
{
    int ret = -1;
    Entregas* aux = this;

    if(strncmp("GOLD", aux->tipo, 10) == 0)
    {
        ret = 0;
    }

    return ret;
}

int inf_contPlus(Entregas* this)
{
    int ret = -1;
    Entregas* aux = this;

    if(strncmp("PLUS", aux->tipo, 10) == 0)
    {
        ret = 0;
    }

    return ret;
}

int inf_contRegular(Entregas* this)
{
    int ret = -1;
    Entregas* aux = this;

    if(strncmp("REGULAR", aux->tipo, 10) == 0)
    {
        ret = 0;
    }

    return ret;
}

int inf_cantBultosEnt(LinkedList* listaEntregas, int* pSumaCant)
{
    Entregas* this;

    int i;
    int cantidad = 0;
    int ret = -1;
    int sumaCant = 0;

    if(pSumaCant != NULL)
    {
        for(i = 0; i < ll_len(listaEntregas); i++)
        {
            this = (Entregas*)ll_get(listaEntregas, i);
            cantidad = this->cantidad;

            sumaCant = sumaCant + cantidad;
        }
        *pSumaCant = sumaCant;
        ret = 0;
    }

    printf("%d\n", sumaCant);

    return ret;
}

int inf_promedioImporteEnt(LinkedList* listaEntregas, float* pPromedio)
{
    Entregas* this;

    int i;
    int ret = -1;
    float importe = 0;
    float sumaImporte = 0;

    for(i = 0; i < ll_len(listaEntregas); i++)
    {
        this = (Entregas*)ll_get(listaEntregas, i);
        importe = this->importe;

        sumaImporte = sumaImporte + importe;
    }

    printf("%.2f\n", sumaImporte);

    *pPromedio = sumaImporte / (float)listaEntregas->size;

    return ret;
}

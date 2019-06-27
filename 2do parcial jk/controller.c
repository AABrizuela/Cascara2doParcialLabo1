#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "entregas.h"
#include "controller.h"
#include "informes.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEntregas)
{
    int retorno = -1; //Variable que retorna la funcion (1 - TodoOK // 0 - Error)
    FILE* pArchivo; //Variable puntero al archivo
    if((pArchivo = fopen(path, "r")) != NULL) //Condicional, verifico si la lectura del archivo, si no retorna NULL accedo al parse_Entregas
    {
        parser_FromText(pArchivo, pArrayListEntregas); //Funcion parser empleados modo texto
    }
    else  //Si retorna NULL no encontro el archivo, por lo tanto lo creo e informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "w")) != NULL)
        {
            printf("\n --> No se encontro el archivo. Se creo uno nuevo con el tipo \"%s\"\n\n", path);
            retorno = 0; //Cambio el el valor del retorno
        }
    }
    return retorno; //Retorno a la varaible
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* listaEntregas)
{
    FILE* pArchivo; //Puntero al archivo
    //Entregas* this; //Creo puntero a estructura empleado
    int retorno = -1; //Variable retorno
    //Variables buffer -->
    int cantEntregas = 0;
    int cantPlus = 0;
    int cantRegular = 0;
    int cantGold = 0;
    int cantBultos = 0;
    float promedioBultos = 0;
    float importePromedio = 0;
    //<---

    inf_cantEnt(listaEntregas, &cantEntregas);
//  inf_cantEntTipo(listaEntregas, &cantPlus, &cantRegular/*, &cantGold*/);
    ll_count(listaEntregas, (void*)inf_contGold, &cantGold);
    ll_count(listaEntregas, (void*)inf_contPlus, &cantPlus);
    ll_count(listaEntregas, (void*)inf_contRegular, &cantRegular);
    inf_cantBultosEnt(listaEntregas, &cantBultos);

    promedioBultos = (float)cantBultos / (float)cantEntregas;

    inf_promedioImporteEnt(listaEntregas, &importePromedio);

    pArchivo = fopen(path, "w"); //Abro el archivo en modo escritura
    if(pArchivo != NULL && listaEntregas != NULL) //Condicional, verifico que la apertura del archivo y el array de empelados no sea NULL, si no lo es ingreso
    {
        fprintf(pArchivo, "********************\nInforme de ventas\n********************\n");
        fprintf(pArchivo, "- Cantidad total de entregas: %d\n", cantEntregas);
        fprintf(pArchivo, "- Cantidad de entregas por tipo: %d (GOLD) - %d (REGULAR) - %d (PLUS)\n", cantGold, cantRegular, cantPlus);
        fprintf(pArchivo, "- Cantidad total de bultos entregados: %d\n", cantBultos);
        fprintf(pArchivo, "- Promedio de bultos por entrega: %.2f\n", promedioBultos);
        fprintf(pArchivo, "- Importe promedio por entrega: %.2f\n", importePromedio);
        fprintf(pArchivo, "********************\n");

        printf("\n --> Datos guardados con exito.\n\n");
        retorno = 0; //Cambio el valor de la variable que retorna la funcion
    }
    fclose(pArchivo); //Cierro el archivo
    return retorno; //Retorno el valor de la variable
}

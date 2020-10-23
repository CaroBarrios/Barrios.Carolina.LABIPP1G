#include "bicicleta.h"
#include "servicio.h"
#include "fecha.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

int initTrabajos(eTrabajo* list, int len);
int getEmptyIndexTrabajos(eTrabajo* list,int len);
int trabajoPrint(eTrabajo* pElement, eBicicleta* listBicicleta, int lenBicicleta, eServicio* listServicio, int lenServicio);
int printTrabajos(eTrabajo* list, int length, eBicicleta* listBicicleta, int lenBicicleta, eServicio* listServicio, int lenServicio);
int addTrabajo(eTrabajo* list, int len, int index, int* id, eBicicleta* listBicicleta, int length, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor);

#endif // TRABAJO_H_INCLUDED

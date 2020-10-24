#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED
#include "tipo.h"
#include "color.h"
#include "cliente.h"

#define MARCA_LEN 20

typedef struct{
    int id;
    char marca[MARCA_LEN];
    int idTipo;
    int idColor;
    int rodado;
    int idCliente;
    int isEmpty;
}eBicicleta;

int initBicicletas(eBicicleta* list, int len);
int hardcodearBicicleta(eBicicleta* list, int len, int cantidad);
int getEmptyIndexBicicletas(eBicicleta* list,int len);
int addBicicletas(eBicicleta* list, int len, int index, int* id, eCliente* listCliente, int lenCliente);
int bicicletaPrint(eBicicleta* pElement, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente);
int printBicicletas(eBicicleta* list, int length, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente);
int findBicicletaById(eBicicleta* list, int len, int id, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente);
int removeBicicleta(eBicicleta* list,int len, int id);
int menuModifyBicicletas (eBicicleta* list, int len, int index);

#endif // BICICLETA_H_INCLUDED

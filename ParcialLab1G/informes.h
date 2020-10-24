#include "bicicleta.h"
#include "color.h"
#include "tipo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int menuModifyInformes(eBicicleta* list, int len, eColor* listColor, int lenColor, eTipo* listTipo, int lenTipo, eCliente* listCliente, int lenCliente);
int listarBicicletasPorColor(eBicicleta* list, int len, eColor* listColor, int lenColor, eTipo* listTipo, int lenTipo, eCliente* listCliente, int lenCliente);
int listarBicicletasPorTipo(eBicicleta* list, int len, eColor* listColor, int lenColor, eTipo* listTipo, int lenTipo, eCliente* listCliente, int lenCliente);
int listarBicicletasDeCadaTipo(eBicicleta* list, int len, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente);

#endif // INFORMES_H_INCLUDED

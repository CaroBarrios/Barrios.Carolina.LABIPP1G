#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "bicicleta.h"
#include "color.h"
#include "tipo.h"
#include "utn.h"


int listarBicicletasDeCadaTipo(eBicicleta* list, int len, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente)
{
    int answer=-1;
    int flag=0;
    char tipo[20];


    if(list!=NULL && listTipo!=NULL && listColor!=NULL && listCliente!=NULL && len>0 && lenTipo>0 && lenColor>0 && lenCliente>0)
    {
        system("cls");
        printf("****Listado de bicicletas de cada tipo****\n");
        for(int d = 0; d<lenTipo; d++)
        {
            flag=0;
            obtenerDescripcionTipo(listTipo, lenTipo, list[d].id, tipo);
            printf("tipo: %s\n", tipo);
            for(int i=0; i<len; i++)
            {
                if(list[i].isEmpty == 0 && list[i].idTipo == listTipo[d].id)
                {
                    bicicletaPrint(&list[i], listTipo, lenTipo, listColor, lenColor, listCliente, lenCliente);
                    flag = 1;
                }
            }
            if(flag==0)
            {
                printf("No hay biciletas de tipo %s\n\n", tipo);
            }

        }
        answer=0;
    }
    return answer;
}

int listarBicicletasPorTipo(eBicicleta* list, int len, eColor* listColor, int lenColor, eTipo* listTipo, int lenTipo, eCliente* listCliente, int lenCliente)
{
    int answer=-1;
    int idTipo=0;
    int flag = 0;
    char tipo[20];

    if(list!=NULL && listColor!=NULL && listTipo!=NULL && len>0 && lenColor>0 && lenTipo>0)
    {
        system("cls");
        printTipos(listTipo, lenTipo);
        if (utn_getNumero(&list->idTipo,"\nIngrese el id del tipo de bicicleta: ",
                          "\nERROR, el dato ingresado no es un tipo de bicicleta. Solo puede ingresar tipos del 5000 al 5004 sin letras ni caracteres especiales.\n",1000,1003,2) == 0)
        {
            obtenerDescripcionTipo(listTipo, lenTipo, list->idTipo, tipo);
            printf("\nBicicletas que tienen el tipo %s\n", tipo);
            for(int i=0; i<len; i++)
            {
                if(list[i].isEmpty == 0 && list[i].idTipo == idTipo)
                {
                    bicicletaPrint(&list[i], listTipo, lenTipo, listColor, lenColor, listCliente, lenCliente);
                    flag = 1;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay bicletas con el tipo %s\n\n", tipo);
            }

        }

        answer=0;
    }
    return answer;
}

int listarBicicletasPorColor(eBicicleta* list, int len, eColor* listColor, int lenColor, eTipo* listTipo, int lenTipo, eCliente* listCliente, int lenCliente)
{
    int answer=-1;
    int idColor=0;
    int flag = 0;
    char color[20];

    if(list!=NULL && listColor!=NULL && listTipo!=NULL && listCliente!=NULL && len>0 && lenColor>0 && lenTipo>0 && lenCliente>0)
    {
        system("cls");
        printColores(listColor, lenColor);
        if(utn_getNumero(&list->idColor,"\nIngrese el numero del color de bicicleta: ",
                         "\nERROR, el dato ingresado no es un color de bicileta. Solo puede ingresar tipos del 5000 al 5004 sin letras ni caracteres especiales.\n",5000,5004,2) == 0)
        {
            obtenerDescripcionColor(listColor, lenColor, list->idColor, color);
            printf("\nBicicletas que tienen el color %s: \n", color);
            for(int i=0; i<len; i++)
            {
                if(list[i].isEmpty == 0 && list[i].idColor == idColor)
                {
                    bicicletaPrint(&list[i], listTipo, lenTipo, listColor, lenColor, listCliente, lenCliente);
                    flag = 1;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay bicicletas con el color %s\n\n", color);
            }

        }
        answer=0;
    }
    return answer;
}

/**
* \brief Display menu for the user can choose what data want to inform
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int menuModifyInformes(eBicicleta* list, int len, eColor* listColor, int lenColor, eTipo* listTipo, int lenTipo, eCliente* listCliente, int lenCliente)
{
    int answer = -1;
    int optionMenu;

    if(list != NULL && len > 0)
    {
        do
        {
            if ((utn_getNumero (&optionMenu,"\nLISTADO DE INFORMES\n\n"
                                "1. Mostrar bicicletas del color seleccionado por el usuario\n"
                                "2. Mostrar bicicletas de un tipo seleccionado\n"
                                "3. Informar el o las bicicletas de menor rodado\n"
                                "4. Mostrar un listado de las bicicletas separadas por tipo\n"
                                "5. Volver\n\n"
                                "Ingrese una opcion: ",
                                "Esta opcion no es valida. Intente nuevamente.\n\n", 1, 5, 3))==0)
            {

                switch(optionMenu)
                {
                case 1:
                    listarBicicletasPorColor(list, len, listColor, lenColor, listTipo, lenTipo, listCliente, lenCliente);
                    break;
                case 2:
                    listarBicicletasPorTipo(list, len, listColor, lenColor, listTipo, lenTipo, listCliente, lenCliente);
                    break;
                case 3:
                    break;
                case 4:
                    listarBicicletasDeCadaTipo(list, len, listTipo, lenTipo, listColor, lenColor, listCliente, lenCliente);
                    break;
                }
            }
        }
        while (optionMenu!=5);
    }
    return answer;
}

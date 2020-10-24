#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "bicicleta.h"
#include "dataStore.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"

/**
* \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initBicicletas(eBicicleta* list, int len)
{
    int answer = -1;
    if(list != NULL && len > 0)
    {
        answer = 0;
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return answer;
}

/**
* \brief For hardcoding bikes
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \param cantidad to indicate the number of bikes that I am going to hardcode
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int hardcodearBicicleta(eBicicleta* list, int len, int cantidad)
{
    int error = -1;

    if (list!=NULL && len>0 && cantidad>0 && cantidad<=len)
    {
        error = 0;
        for(int i=0; i<cantidad; i++)
        {
            list[i].id = ids[i];
            strcpy(list[i].marca, marcas[i]);
            list[i].idTipo = idsTipo[i];
            list[i].idColor = idsColor[i];
            list[i].rodado = rodados[i];
            list[i].idCliente = clientes[i];
            list[i].isEmpty = 0;
            error++;
        }
    }
    return error;
}


/**
* \brief Find fist empty position in the array
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \return Returns the index of the position empty and -1 in case of error
*
*/
int getEmptyIndexBicicletas(eBicicleta* list,int len)
{
    int answer = -1;
    if(list != NULL && len > 0)
    {
        answer = 0;
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                answer = i;
                break;
            }
        }
    }
    return answer;
}


/**
* \brief Add in a existing list of bicicleta the values received as parameters in the first empty position
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \param index Position to be updated
* \param id Position where an bicicleta will be registered
* \return Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addBicicletas(eBicicleta* list, int len, int index, int* id, eCliente* listCliente, int lenCliente)
{
    int answer = -1;
    eBicicleta bufferBicicleta;

    system("cls");
    printf("***************ALTA BICICLETA***************");

    if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
    {
        if(	utn_getString(bufferBicicleta.marca,MARCA_LEN,"\nIngrese la marca de su bicicleta: ",
                          "\nERROR, el dato ingresado no es una marca. Solo puede ingresar marcas sin numeros o caracteres especiales.\n",2) == 0 &&
                utn_getNumero(&bufferBicicleta.idTipo,"\n*****Tipos*****"
                              "\n1000 - Rutera"
                              "\n1001 - Carrera"
                              "\n1002 - Mountain"
                              "\n1003 - BMX\n"
                              "\nIngrese el numero de tipo de bicicleta: ",
                              "\nERROR, el dato ingresado no es un tipo de bicileta. Solo puede ingresar tipos del 1000 al 1003 sin letras ni caracteres especiales.\n",1000,1003,2) == 0 &&
                utn_getNumero(&bufferBicicleta.idColor,"\n*****Colores*****"
                              "\n5000 - Gris"
                              "\n5001 - Negro"
                              "\n5002 - Blanco"
                              "\n5003 - Azul"
                              "\n5004 - Rojo\n"
                              "\nIngrese el numero del color de bicicleta: ",
                              "\nERROR, el dato ingresado no es un color de bicileta. Solo puede ingresar colores del 5000 al 5004 sin letras ni caracteres especiales.\n",5000,5004,2) == 0 &&
                utn_getNumero(&bufferBicicleta.rodado,"\n*****Rodados*****"
                              "\n20"
                              "\n26"
                              "\n27.5"
                              "\n29"
                              "\nIngrese el rodado de bicicleta dentro de las opciones arriba mencionadas: ",
                              "\nERROR, el dato ingresado no es un rodado de bicileta. Solo puede ingresar rodados del 20 al 29 sin letras ni caracteres especiales.\n",20,29,2) == 0 &&
                printCliente(listCliente,lenCliente) == 0 &&
                utn_getNumero(&bufferBicicleta.idCliente,"\nIngrese el id del cliente: ",
                              "\nERROR, el dato ingresado no es un id de cliente. Solo puede ingresar clientes del 6000 al 6004 sin letras ni caracteres especiales.\n",6000,6004,2) == 0)
        {
            answer = 0;
            bufferBicicleta.id = *id;
            bufferBicicleta.isEmpty = 0;
            list[index] = bufferBicicleta;
        }
    }
    return answer;
}

/**
* \brief Print the content of bicicleta in a position
* \param pElement eBicicleta* Pointer to the product to be printed
* \param listTipo eTipo* Pointer to array of tipo
* \param lenTipo int Array length
* \param listColor eColor* Pointer to array of color
* \param lenColor int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int bicicletaPrint(eBicicleta* pElement, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente)
{
    int answer = -1;
    char descripcionColor[20];
    char descripcionTipo[20];
    char descripcionCliente[20];

    if((obtenerDescripcionColor(listColor, lenColor, pElement->idColor, descripcionColor)) == 0
            && (obtenerDescripcionTipo(listTipo, lenTipo, pElement->idTipo, descripcionTipo) == 0)
            && (obtenerDescripcionCliente(listCliente, lenCliente, pElement->idCliente, descripcionCliente) == 0))
    {
        if(pElement != NULL && pElement->isEmpty == 0)
        {
            answer = 0;

            printf ("%3d              %10s               %10s                 %10s                %2d           %10s\n\n", pElement->id, pElement->marca, descripcionTipo, descripcionColor, pElement->rodado, descripcionCliente);
        }
    }
    else
    {
        printf("Problemas para cargar la descripcion\n\n");
    }
    return answer;
}

/**
* \brief Print the content of bicicleta array
* \param list eBicicleta* Pointer to array of bicicleta
* \param length int Array length
* \param listTipo eTipo* Pointer to array of tipo
* \param lenTipo int Array length
* \param listColor eColor* Pointer to array of color
* \param lenColor int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printBicicletas(eBicicleta* list, int length, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente)
{
    int answer = -1;
    int flag = 0;

    if(list != NULL && length > 0)
    {
        answer = 0;
        printf ("\n--------------------------------------------------Datos Bicicleta------------------------------------------------------\n\n");
        printf ("ID                     Marca                      Tipo                        Color           Rodado            Cliente  \n\n");
        for(int i=0; i<length; i++)
        {
            if (list[i].isEmpty != 1)
            {
                bicicletaPrint(&list[i], listTipo, lenTipo, listColor, lenColor, listCliente, lenCliente);
                flag = 1;
            }
        }
        if (flag==0)
        {
            printf("\n\nNO HAY BICICLETAS EN LA LISTA\n\n");
        }
    }
    return answer;
}

/**
* \brief Find an ID in an array and return the position it is in
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \param id Position to be found
* \param listTipo eTipo* Pointer to array of tipo
* \param lenTipo int Array length
* \param listColor eColor* Pointer to array of color
* \param lenColor int Array length
* \return Returns the index of the position whith the sought value, o if finds the sought value and -1 in case of error
*
*/
int findBicicletaById(eBicicleta* list, int len, int id, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor, eCliente* listCliente, int lenCliente)
{
    int answer = -1;
    int i;
    if(list != NULL && len > 0 && id >= 0)
    {
        answer = 0;
        for(i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                printf("\nLa bicicleta seleccionada es la siguiente: \n\n");
                printf ("ID                     Marca                    idTipo                      idColor           Rodado\n\n");
                answer = i;
                bicicletaPrint(&list[i], &listTipo[i], lenTipo, &listColor[i], lenColor, listCliente, lenCliente);
                break;
            }
        }
    }
    return answer;
}

/**
* \brief Remove a Bicicleta by Id (put isEmpty Flag in 1)
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \param id Position to be remove
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int removeBicicleta(eBicicleta* list,int len, int id)
{
    int answer = -1;
    if(list != NULL && len > 0 && id >= 0 && list[id].isEmpty == 0)
    {
        list[id].isEmpty = 1;
        answer = 0;
    }
    return answer;
}


/**
* \brief Display menu for the user can choose what data want to modify
* \param list eBicicleta* Pointer to array of bicicleta
* \param len int Array length
* \param index Position to be modify
* \return Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int menuModifyBicicletas (eBicicleta* list, int len, int index)
{
    int answer = -1;
    int optionMenu;
    eBicicleta bufferBicicleta;

    if(list != NULL && len > 0 && index < len && index >= 0)
    {
        do
        {
            if ((utn_getNumero (&optionMenu,"\nQue desea modificar?\n\n"
                                "1. Tipo\n"
                                "2. Rodado\n"
                                "3. Volver\n\n"
                                "Ingrese una opcion: ",
                                "Esto no es valido. Intente nuevamente.\n\n", 1, 3, 2))==0)
            {

                switch(optionMenu)
                {
                case 1:
                    if (utn_getNumero(&bufferBicicleta.idTipo,"\n*****Tipos*****"
                                      "\n1000 - Rutera"
                                      "\n1001 - Carrera"
                                      "\n1002 - Mountain"
                                      "\n1003 - BMX\n"
                                      "\nIngrese el numero de tipo de bicicleta: ",
                                      "\nERROR, el dato ingresado no es un tipo de bicileta. Solo puede ingresar tipos del 1000 al 1003 sin letras ni caracteres especiales.\n",1000,1003,2) == 0)
                    {
                        bufferBicicleta.id = list[index].id;
                        bufferBicicleta.isEmpty = 0;
                        list[index].idTipo = bufferBicicleta.idTipo;
                        printf("\nEl tipo fue modificado satisfactoriamente\n\n");
                    }
                    answer = 0;
                    system ("pause");
                    system ("cls");
                    break;
                case 2:
                    if (utn_getNumero(&bufferBicicleta.rodado,"\n*****Rodados*****"
                                      "\n20"
                                      "\n26"
                                      "\n27,5"
                                      "\n29"
                                      "\nIngrese el rodado de bicicleta: ",
                                      "\nERROR, el dato ingresado no es un rodado de bicileta. Solo puede ingresar tipos del 20 al 29 sin letras ni caracteres especiales.\n",20,29,2) == 0)
                    {
                        bufferBicicleta.id = list[index].id;
                        bufferBicicleta.isEmpty = 0;
                        list[index].rodado = bufferBicicleta.rodado;
                        printf("\nEl rodado fue modificado satisfactoriamente\n\n");
                    }
                    answer = 0;
                    system ("pause");
                    system ("cls");
                    break;
                }
            }
        }
        while (optionMenu!=3);
    }
    return answer;
}

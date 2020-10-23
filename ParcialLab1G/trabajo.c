#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "trabajo.h"
#include "bicicleta.h"
#include "servicio.h"

/**
* \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list eTrabajo* Pointer to array of trabajos
* \param len int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initTrabajos(eTrabajo* list, int len)
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
 * \brief Find fist empty position in the array
 * \param list eTrabajo* Pointer to array of trabajo
 * \param len int Array length
 * \return Returns the index of the position empty and -1 in case of error
 *
 */
int getEmptyIndexTrabajos(eTrabajo* list,int len)
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
* \brief Print the content of trabajo in a position
* \param pElement eTrabajo* Pointer to the product to be printed
* \param listBicicleta eBicicleta* Pointer to array of bicicleta
* \param lenBicicleta int Array length of bicicleta
* \param listServicio eServicio* Pointer to array of servicio
* \param lenServicio int Array length of servicio
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int trabajoPrint(eTrabajo* pElement, eBicicleta* listBicicleta, int lenBicicleta, eServicio* listServicio, int lenServicio)
{
    int answer = -1;
    char descripcion[20];

    if ((obtenerDescripcionServicio(listServicio, lenServicio, pElement->idServicio, descripcion)) == 0)
    {
        if(pElement != NULL && pElement->isEmpty == 0)
        {
            answer = 0;
            printf ("%d        %4d            %10s           %02d/%02d/%d \n\n", pElement->id, pElement->idBicicleta, descripcion, pElement->fecha.dia, pElement->fecha.mes, pElement->fecha.anio);
        }
    }
    return answer;
}


/**
* \brief Print the content of trabajos array
* \param list eTrabajo* Pointer to array of trabajos
* \param length int Array length of trabajo
* \param listBicicleta eBicicleta* Pointer to array of bicicleta
* \param lenBicicleta int Array length of bicicleta
* \param listServicio eServicio* Pointer to array of servicio
* \param lenServicio int Array length of servicio
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printTrabajos(eTrabajo* list, int length, eBicicleta* listBicicleta, int lenBicicleta, eServicio* listServicio, int lenServicio)
{
    int answer = -1;
    int flag = 0;

    if(list != NULL && length > 0)
    {
        answer = 0;
        printf ("\n----------------------Datos Trabajos-------------------\n\n");
        printf ("ID    idBicicleta           Servicio             Fecha\n\n");
        for(int i=0; i<length; i++)
        {
            if (list[i].isEmpty != 1)
            {
                trabajoPrint(&list[i], listBicicleta, lenBicicleta, listServicio, lenServicio);
                flag = 1;
            }
        }
        if (flag==0)
        {
            printf("\n\nNO HAY TRABAJOS EN LA LISTA\n\n");
        }
    }
    return answer;
}

/**
* \brief Add in a existing list of trabajo the values received as parameters in the first empty position
* \param list eTrabajo* Pointer to array of trabajo
* \param len int Array length
* \param index Position to be updated
* \param id Position where an trabajo will be registered
* \param listBicicleta eBicicleta* Pointer to array of bicicleta
* \param length int Array length
* \param listTipo eTipo* Pointer to array of tipo
* \param lenTipo int Array length
* \param listColor eColor* Pointer to array of color
* \param lenColor int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addTrabajo(eTrabajo* list, int len, int index, int* id, eBicicleta* listBicicleta, int length, eTipo* listTipo, int lenTipo, eColor* listColor, int lenColor)
{
    int answer = -1;
    eTrabajo bufferTrabajo;

    printf("\n*********************************************ALTA TRABAJO**********************************************\n\n");

    printBicicletas(listBicicleta, length, listTipo, lenTipo, listColor, lenColor);

    if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
    {
        if(utn_getNumero(&bufferTrabajo.idBicicleta,"\nIngrese el ID de la bicicleta: ",
                         "\nERROR, el dato ingresado no es un id de bicicleta. Solo puede ingresar IDs del 3000 al ultimo ID dado de alta sin letras ni caracteres especiales.\n",3000,3500,2) == 0 &&
                utn_getNumero(&bufferTrabajo.idServicio,"\n*****Servicios*****"
                              "\n20000 - Limpieza"
                              "\n20001 - Parche"
                              "\n20002 - Centrado"
                              "\n20003 - Cadena\n"
                              "\nIngrese el numero del servicio que se le realizo a la bicicleta: ",
                              "\nERROR, el dato ingresado no es un tipo de servicio. Solo puede ingresar servicios del 20000 al 20003 sin letras ni caracteres especiales.\n",20000,20003,2) == 0 &&
                utn_getNumero(&bufferTrabajo.fecha.dia,"\nIngrese el dia en que se realizo el servicio: ",
                              "\nERROR, el dato ingresado no es un dia. Solo puede ingresar dias del 1 al 31 sin letras ni caracteres especiales.\n",1,31,2) == 0 &&
                utn_getNumero(&bufferTrabajo.fecha.mes,"\nIngrese el mes en que se realizo el servicio: ",
                              "\nERROR, el dato ingresado no es un mes. Solo puede ingresar meses del 1 al 12 sin letras ni caracteres especiales.\n",1,12,2) == 0 &&
                utn_getNumero(&bufferTrabajo.fecha.anio,"\nIngrese el anio en que se realizo el servicio: ",
                              "\nERROR, el dato ingresado no es un anio. Solo puede ingresar anios del 2010 al 2020 sin letras ni caracteres especiales.\n",2010,2020,2) == 0)
        {
            answer = 0;
            bufferTrabajo.id = *id;
            bufferTrabajo.isEmpty = 0;
            list[index] = bufferTrabajo;
        }
    }
    return answer;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

/**
 * \brief Print the content of cliente in a position
 * \param pElement eCliente* Pointer to the product to be printed
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cliente_print(eCliente* pElement)
{
	int answer = -1;

	if(pElement != NULL)
	{
		answer = 0;

		printf ("%d    %10s         %c\n\n", pElement->id, pElement->nombre, pElement->sexo);
	}
	return answer;
}

/**
* \brief Print the content of cliente array
* \param list eCliente* Pointer to array of cliente
* \param length int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printCliente(eCliente* list, int length)
{
    int answer = -1;

	if(list != NULL && length > 0)
	{
		answer = 0;
		printf ("\n***********Cliente************\n\n");
        printf ("ID         Nombre        Sexo\n\n");
		for(int i=0;i<length;i++)
		{
            cliente_print(&list[i]);
		}
	}
	return answer;
}

/**
* \brief to get the description of the cliente
* \param list eCliente* Pointer to array of cliente
* \param len int Array length
* \param id Position where an cliente will be registered
* \param nombre nombre of cliente
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int obtenerDescripcionCliente(eCliente* list, int len, int id, char nombre[])
{
    int answer=-1;

    if(list!=NULL && len>0 && id>=6000 && nombre!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                strcpy(nombre, list[i].nombre);
                answer=0;
                break;
            }
        }
    }
    return answer;
}

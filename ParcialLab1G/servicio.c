#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

/**
 * \brief Print the content of servicios in a position
 * \param eServicio Pointer to the product to be printed
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int servicio_print(eServicio* pElement)
{
	int answer = -1;

	if(pElement != NULL)
	{
		answer = 0;

		printf ("%d    %20s\n\n", pElement->id, pElement->descripcion);
	}
	return answer;
}

/**
* \brief Print the content of servicio array
* \param list eServicio* Pointer to array of servicio
* \param length int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printServicios(eServicio* list, int length)
{
    int answer = -1;

	if(list != NULL && length > 0)
	{
		answer = 0;
		printf ("\n***************Servicios****************\n\n");
        printf ("ID                  Descripcion\n\n");
		for(int i=0;i<length;i++)
		{
            servicio_print(&list[i]);
		}
	}
	return answer;
}


int obtenerDescripcionServicio(eServicio* list, int len, int id, char descripcion)
{
    int answer=-1;

    if( list!=NULL && len>0 && id>=20000 && descripcion!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                strcpy(descripcion, list[i].descripcion);
                answer=0;
                break;
            }
        }
    }
    return answer;
}

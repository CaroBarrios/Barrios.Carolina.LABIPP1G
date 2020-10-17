#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

/**
 * \brief Print the content of tipos in a position
 * \param eTipo Pointer to the product to be printed
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int tipo_print(eTipo* pElement)
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
* \brief Print the content of tipo array
* \param list eTipo* Pointer to array of tipo
* \param length int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printTipos(eTipo* list, int length)
{
    int answer = -1;

	if(list != NULL && length > 0)
	{
		answer = 0;
		printf ("\n***************Tipo****************\n\n");
        printf ("ID                  Descripcion\n\n");
		for(int i=0;i<length;i++)
		{
            tipo_print(&list[i]);
		}
	}
	return answer;
}


int obtenerDescripcionTipo(eTipo* list, int len, int id, char descripcion)
{
    int answer=-1;

    if( list!=NULL && len>0 && id>=1000 && descripcion!=NULL)
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

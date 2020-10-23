#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

/**
 * \brief Print the content of color in a position
 * \param pElement eColor* Pointer to the product to be printed
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int color_print(eColor* pElement)
{
	int answer = -1;

	if(pElement != NULL)
	{
		answer = 0;

		printf ("%d    %20s\n\n", pElement->id, pElement->nombreColor);
	}
	return answer;
}

/**
* \brief Print the content of color array
* \param list eColor* Pointer to array of color
* \param length int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printColores(eColor* list, int length)
{
    int answer = -1;

	if(list != NULL && length > 0)
	{
		answer = 0;
		printf ("\n***************Color****************\n\n");
        printf ("ID                  NombreColor\n\n");
		for(int i=0;i<length;i++)
		{
            color_print(&list[i]);
		}
	}
	return answer;
}

/**
* \brief to get the description of the color
* \param list eColor* Pointer to array of color
* \param len int Array length
* \param id Position where an color will be registered
* \param descripcion description of color
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int obtenerDescripcionColor(eColor* list, int len, int id, char nombreColor[])
{
    int answer=-1;

    if(list!=NULL && len>0 && id>=5000 && nombreColor!=NULL)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id)
            {
                strcpy(nombreColor, list[i].nombreColor);
                answer=0;
                break;
            }
        }
    }
    return answer;
}

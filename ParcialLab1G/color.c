#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

/**
 * \brief Print the content of color in a position
 * \param eColor Pointer to the product to be printed
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
* \param list eTColor* Pointer to array of tipo
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


int obtenerDescripcionColor(eColor* list, int len, int id, char nombreColor)
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

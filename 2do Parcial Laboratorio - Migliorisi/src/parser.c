#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "movies.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno=1;
	int cant;
	char buffer[4][128];
	eMovie* auxMovie;

	if(pFile!=NULL && pArrayList!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(cant==4)
			{
				auxMovie = movie_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
				if(!ll_add(pArrayList, auxMovie))
				{
					retorno=0;
				}
			}
		}
	}

    return retorno;
}


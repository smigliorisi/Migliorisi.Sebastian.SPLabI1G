#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "movies.h"
#include "parser.h"
#include "utn_migliorisi.h"

int controller_List(LinkedList* pArrayList)
{
	int retorno=-1;
	int tam=ll_len(pArrayList);
	eMovie* auxMovie;
	if(pArrayList!=NULL)
	{
		if(ll_isEmpty(pArrayList)==0)
		{
			printf("ID             TITULO    		  GENERO         DURACION\n");
			for(int i=0;i<tam;i++)
			{
				auxMovie = (eMovie*) ll_get(pArrayList,i);

				if( auxMovie != NULL)
				{
					mostrarMovie (auxMovie);
					retorno=1;
				}
			}
		}
		else
		{
			printf("No hay peliculas que mostrar\n\n");
			retorno=0;
		}
	}
	return retorno;
}

int controller_load(char* path , LinkedList* pArrayList)
{
	int retorno=1;
	FILE* pFile;

	ll_clear(pArrayList);
	pFile = fopen(path, "r");

	if(path!=NULL && pArrayList!=NULL && pFile!=NULL)
	{
		if(!parser_FromText(pFile,pArrayList))
				retorno=0;
	}

	fclose(pFile);
    return retorno;
}

int controller_save(char* path , LinkedList* pArrayList)
{
	int retorno=1;
	int tam=ll_len(pArrayList);
	FILE* pFile;
	eMovie* aux;

	if(pArrayList!=NULL)
	{
		pFile = fopen(path,"w");

		if(pFile!=NULL)
		{
			fprintf(pFile,"id_peli,titulo,genero,duracion\n");
			for(int i=0;i<tam;i++)
			{
				aux = (eMovie*) ll_get(pArrayList,i);
				fprintf(pFile,"%d,%s,%s,%d\n",aux->id_peli,aux->titulo,aux->genero,aux->duracion);
			}
		retorno=0;
		}
		fclose(pFile);
	}
	return retorno;
}


int lastId(LinkedList* pArrayList)
{
    int retorno=-1;
    int mayor=0;
    int flag=0;
    eMovie* aux;
    int tam=ll_len(pArrayList);

    if(pArrayList!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
        	aux = (eMovie*) ll_get(pArrayList,i);
            if(aux!=NULL)
            {
                if(aux->id_peli > mayor || flag==0)
                {
                    mayor = aux->id_peli;
                    flag = 1;
                }
            }
        }
        retorno = mayor;
    }
    return retorno;
}


int compareGenero (void* datoA , void* datoB)
{
   int retorno=0;

   if(strcmp(((eMovie*) datoA)->genero,((eMovie*) datoB)->genero) > 0)
	   retorno=1;
   if(strcmp(((eMovie*) datoA)->genero,((eMovie*) datoB)->genero) < 0)
	   retorno=-1;

   return retorno;
}
int compareDuracion (void* datoA , void* datoB)
{
   int retorno=0;

   if(((eMovie*) datoA)->duracion > ((eMovie*) datoB)->duracion)
	   retorno=1;
   if(((eMovie*) datoA)->duracion < ((eMovie*) datoB)->duracion)
	   retorno=-1;

   return retorno;
}

int controller_sort(LinkedList* pArrayList)
{
    int retorno=1;
    LinkedList* auxLinkedList;
    auxLinkedList = ll_newLinkedList();

    if(pArrayList!=NULL && auxLinkedList!=NULL)
    {
    	auxLinkedList=ll_clone(pArrayList);
		printf("Ordenando. Aguarde un momento...\n");

		if(!ll_sort(auxLinkedList,compareDuracion,1))
		{
			if(!ll_sort(auxLinkedList,compareGenero,1))
			{
				controller_List(auxLinkedList);
				retorno=0;
			}
			else
				printf("Error. Operacion cancelada\n");
		}
    }
    return retorno;
}

int getRandom ()
{
	int aleatorio;
	aleatorio = rand () % 141 + 100;

	return aleatorio;
}

void* add_randomTime (void* movie)
{
	((eMovie*) movie)->duracion = getRandom();
	return movie;
}

int controller_asignTime (LinkedList* pArrayList)
{
	int retorno=1;

	if(pArrayList!=NULL)
	{
		pArrayList=ll_map(pArrayList, add_randomTime);
		retorno=0;
	}
	return retorno;
}



int filtrarGeneroDrama (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Drama")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroAdventure (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Adventure")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroComedia (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Comedy")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroHorror (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Horror")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroMusical (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Musical")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroWestern (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Western")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroRomance (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Romance")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroAnimation (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Animation")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroDocumentary (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Documentary")==0)
	{
		retorno=1;
	}

	return retorno;
}

int filtrarGeneroAction (void* element)
{
	int retorno=0;
	eMovie* aux;

	aux = (eMovie*) element;
	if(strcmp(aux->genero,"Action")==0)
	{
		retorno=1;
	}

	return retorno;
}


int controller_filterByType(LinkedList* pArrayList)
{
	int retorno=1;
	int opcion=0;
    LinkedList* auxLinkedList;
    auxLinkedList = ll_newLinkedList();

	if(pArrayList!=NULL && auxLinkedList!=NULL)
	{
		if(utn_getNumeroInt(&opcion, "Ingrese genero: \n1.Drama\n2.Adventure\n3.Comedia\n4.Horror\n5.Musical\n6.Western\n7.Romance\n8.Animation\n9.Documentary\n10.Action\n", "Error", 1, 10, 2)==0)
		{
			switch(opcion)
			{
			case 1:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroDrama);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 2:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroAdventure);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 3:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroComedia);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 4:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroHorror);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 5:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroMusical);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 6:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroWestern);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 7:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroRomance);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 8:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroAnimation);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 9:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroDocumentary);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			case 10:
				auxLinkedList = ll_filter(pArrayList, filtrarGeneroAction);
				if(controller_save("moviesXgenero.csv",auxLinkedList))
					printf("Error al guardar el listado\n");
				else
					printf("Datos guardados\n");
				break;
			}
		}
		else
			printf("Operación cancelada");
	}
	return retorno;
}

/*
 ============================================================================
 Name        : 2do.c
 Author      : Sebastian Migliorisi
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "Controller.h"
#include "movies.h"
#include "parser.h"
#include "utn_migliorisi.h"

int main()
{
	setbuf(stdout, NULL);
	srand(time(NULL));

	int option = 0;

	LinkedList* lista = ll_newLinkedList();

	    do{
	    	if(!menu(&option))
	    	{
				switch(option)
				{
					case 1:
						if(controller_load("movies.csv",lista))
							printf("Error al cargar los empleados\n");
						else
							printf("Carga de peliculas exitosa\n");
						break;
					case 2:
						controller_List(lista);
						break;
					case 3:
						if(controller_asignTime(lista))
							printf("Ningún tiempo fue asignado\n");
						else
							printf("Tiempo asignado exitosamente\n");
						break;
					case 4:
						controller_filterByType(lista);
						break;
					case 5:
						controller_sort(lista);
						break;
					case 6:
						if(controller_save("moviesNew.csv",lista))
							printf("Error al guardar el listado\n");
						else
							printf("Datos guardados\n");
						break;
					case 7:
						ll_deleteLinkedList(lista);
						break;
				}
	    	}
	    }while(option != 7);

	return 0;
}


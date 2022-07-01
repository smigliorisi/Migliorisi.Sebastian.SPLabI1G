#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "utn_migliorisi.h"
#include "movies.h"

/**
 * \brief Muestra un menu de opciones
 *
 * \param option opcion seleccionada
 * \return devuelve el numero entero valido ingresado
 */
int menu(int* option)
{
	int retorno=-1;
	int opcIngresada;
	if(utn_getNumeroInt(&opcIngresada,"\nMenu de opciones\n"
	    			 "1. Cargar archivo\n"
	    			 "2. Imprimir lista\n"
	    			 "3. Asignar duraciones\n"
	    			 "4. Filtrar por genero\n"
	    			 "5. Mostrar duraciones\n"
	    			 "6. Guardar peliculas\n"
					 "7. Salir\n",
	    	     	 "Error, reingrese opcion (1 a 7)\n", 1, 7, 1)==0)
	{
		retorno=0;
		*option=opcIngresada;
	}
	return retorno;
}


eMovie* movie_find(LinkedList* pArrayList, int id)
{
    int tam = ll_len(pArrayList);
    eMovie* movie;

    if(pArrayList!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
        	movie = (eMovie*)ll_get(pArrayList,i);
            if(movie->id_peli == id)
                break;
            movie=NULL;
        }
    }
    return movie;
}

int mostrarMovie(eMovie* movie)
{
    int retorno=-1;

    if(movie!=NULL)
    {
        printf(" %d    %20s    %20s    %d\n", movie->id_peli, movie->titulo, movie->genero, movie->duracion);
        retorno=0;
    }
    return retorno;
}

eMovie* movie_new()
{
    eMovie* newMovie;
    newMovie = (eMovie*) malloc(sizeof(eMovie));

    if(newMovie!=NULL)
    {
    		newMovie->id_peli=0;
            strcpy(newMovie->titulo, "");
            strcpy(newMovie->genero, "");
            newMovie->duracion=0;
    }

    return newMovie;
}

eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* duracionStr)
{
    int id;
    int duracion;
    eMovie* newMovie;
    newMovie = movie_new();


    if(newMovie!=NULL)
    {
        id = atoi(idStr);
        duracion = atoi(duracionStr);

        if(    movie_setId(newMovie,id)
            || movie_setTitulo(newMovie, tituloStr)
            || movie_setGenero(newMovie, generoStr)
			|| movie_setDuracion(newMovie, duracion)
           )
        {
            free(newMovie);
            newMovie=NULL;
        }
    }
    return newMovie;
}


int movie_delete(eMovie* movie)
{
    int retorno=1;

    if(movie!=NULL)
    {
        free(movie);
        retorno=0;
    }

    return retorno;
}

int movie_setId(eMovie* this,int id)
{
    int retorno=1;

    if(this!=NULL && id>0 && id<1000)
    {
    	this->id_peli=id;
        retorno=0;
    }
    return retorno;
}
int movie_getId(eMovie* this,int* id)
{
    int retorno=1;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id_peli;
        retorno=0;
    }
    return retorno;
}

int movie_setTitulo(eMovie* this,char* titulo)
{
    int retorno=1;

    if(this!=NULL && strlen(titulo)>=3 && strlen(titulo)<=40)
    {
        strcpy(this->titulo,titulo);
        retorno=0;
    }
    return retorno;
}
int movie_getTitulo(eMovie* this,char* titulo)
{
    int retorno=1;

    if(this!=NULL && titulo!=NULL)
    {
        strcpy(titulo,this->titulo);
        retorno=0;
    }
    return retorno;
}

int movie_setGenero(eMovie* this,char* genero)
{
    int retorno=1;

    if(this!=NULL && strlen(genero)>=1 && strlen(genero)<=40)
    {
        strcpy(this->genero,genero);
        retorno=0;
    }
    return retorno;
}
int movie_getGenero(eMovie* this,char* genero)
{
    int retorno=1;

    if(this!=NULL && genero!=NULL)
    {
        strcpy(genero,this->genero);
        retorno=0;
    }
    return retorno;
}

int movie_setDuracion(eMovie* this,float duracion)
{
    int retorno=1;

    if(this!=NULL && duracion>=0 && duracion<1000000)
    {
    	this->duracion=duracion;
        retorno=0;
    }
    return retorno;
}
int movie_getDuracion(eMovie* this,float* duracion)
{
    int retorno=1;

    if(this!=NULL && duracion!=NULL)
    {
        *duracion=this->duracion;
        retorno=0;
    }
    return retorno;
}

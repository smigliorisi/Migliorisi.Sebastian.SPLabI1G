#ifndef MOVIES_H_
#define MOVIES_H_

typedef struct
{
    int id_peli;
    char titulo[128];
    char genero[128];
    int duracion;
}eMovie;

int menu(int* option);
eMovie* movie_find(LinkedList* pArrayList, int id);
int mostrarMovie(eMovie* Movie);
eMovie* movie_new();
eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* duracionStr);
int movie_delete(eMovie* Movie);
int movie_setId(eMovie* this,int id);
int movie_getId(eMovie* this,int* id);
int movie_setTitulo(eMovie* this,char* titulo);
int movie_getTitulo(eMovie* this,char* titulo);
int movie_setGenero(eMovie* this,char* genero);
int movie_getGenero(eMovie* this,char* genero);
int movie_setDuracion(eMovie* this,float duracion);
int movie_getDuracion(eMovie* this,float* duracion);

#endif /* MOVIES_H_ */

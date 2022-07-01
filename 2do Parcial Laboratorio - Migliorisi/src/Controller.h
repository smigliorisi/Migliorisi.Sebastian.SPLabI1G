#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_load(char* path , LinkedList* pArrayList);
int controller_save(char* path , LinkedList* pArrayList);
int controller_List(LinkedList* pArrayList);
int lastId(LinkedList* pArrayList);
int getRandom ();
int controller_asignTime (LinkedList* pArrayList);
void* add_randomTime (void* movie);
int compareTiempo (void* datoA , void* datoB);
int compareTipo (void* datoA , void* datoB);
int controller_sort(LinkedList* pArrayList);
int controller_filterByType(LinkedList* pArrayList);


#endif /* CONTROLLER_H_ */

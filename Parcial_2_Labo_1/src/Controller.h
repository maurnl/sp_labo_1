/*
 * Controller.h
 *
 *  Created on: 20 jun. 2022
 *      Author: Mauro
 */
int controller_loadFromText(LinkedList* pArrayListServicios);
int controller_ListServicios(LinkedList* pArrayListServicios);
int controller_mapServicios(LinkedList* pArrayListServicios);
int controller_filterServicios(char* path,LinkedList* pArrayListServicios);
int controller_sortAndListServicios(LinkedList* pArrayListServicios);
int controller_saveAsText(char* path,LinkedList* pArrayListServicios);
//int controller_loadFromBinary(char* path , LinkedList* pArrayListServicios);
//int controller_addServicio(LinkedList* pArrayListServicios,int* id);
//int controller_editServicio(LinkedList* pArrayListServicios);
//int controller_removeServicio(LinkedList* pArrayListServicios);
//int controller_saveAsBinary(char* path , LinkedList* pArrayListServicios);
//int controller_getNextId(LinkedList* pArrayListServicios);
//int controller_mergeLinkedList(LinkedList* list1, LinkedList* list2);

/*
 ============================================================================
 Name        : Parcial_2_Labo_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);
	//int id=0;
	int opcion, salida;
	LinkedList* listaServicios=ll_newLinkedList();
	do{
		opcion=menu();
		switch(opcion){
		case 1:
			salida=controller_loadFromText(listaServicios);
			switch(salida){
			case 1:
				printf("- NO SE ENCONTRO EL ARCHIVO ESPECIFICADO.\n");
				break;
			case 0:
				printf("- SE CARGO EL ARCHIVO CON EXITO.\n");
				break;
			case -1:
				printf("- CARGA DE ARCHIVO CANCELADA.\n");
				break;
			case -2:
				printf("- LA RUTA INGRESADA NO ES VALIDA.\n");
				break;
			}
			break;
		case 2:
			salida=controller_ListServicios(listaServicios);
			if(salida==-1)
				printf("- LISTA VACIA. CARGUE ALGUN DATO Y REINTENTE.\n");
			break;
		case 3:
			salida=controller_mapServicios(listaServicios);
			switch(salida){
			case -2:
				printf("- LISTA VACIA. CARGUE ALGUN DATO Y REINTENTE.\n");
				break;
			case -1:
				printf("- ERROR EN MAPEO.\n");
				break;
			case 0:
				printf("- TOTALES CALCULADOS CORRECTAMENTE.\n");
				break;
			}
			break;
		case 4:
			salida=controller_filterServicios("data_filtered.csv", listaServicios);
			switch(salida){
			case -2:
				printf("- LISTA VACIA. CARGUE ALGUN DATO Y REINTENTE.\n");
				break;
			case -1:
				printf("- NO SE ENCONTRO EL TIPO ESPECIFICADO.\n");
				break;
			case 0:
				printf("- SE GENERO EL ARCHIVO CON EXITO.\n");
				break;
			}
			break;
		case 5:
			salida=controller_sortAndListServicios(listaServicios);
			if(salida==-1)
				printf("- LISTA VACIA. CARGUE ALGUN DATO Y REINTENTE.\n");
			break;
		case 6:
			salida=controller_saveAsText("data_sorted.csv",listaServicios);
			switch(salida){
			case -2:
				printf("- LISTA VACIA. CARGUE ALGUN DATO Y REINTENTE.\n");
				break;
			case -1:
				printf("- NO SE PUDO GUARDAR EL ARCHIVO (ERROR EN LA ESCRITURA)\n");
				break;
			case 0:
				printf("- SE GENERO EL ARCHIVO CON EXITO.\n");
				break;
			}
			break;
		}
	}while(opcion!=7);
	return EXIT_SUCCESS;
}

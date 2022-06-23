/*
 * Controller.c
 *
 *  Created on: 20 jun. 2022
 *      Author: Mauro
 */
#include <stdio.h>
#include "utn.h"
#include "eServicios.h"
#include "LinkedList.h"
#include "parser.h"

/** \brief Pide un path y carga los datos de las servicios desde un archivo (modo texto).
 * \param pArrayListServicios LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListServicios){
	int retorno=-2;
	char path[30];
	FILE* pArchivo=NULL;
	getAlphanumericText("- INGRESE ARCHIVO DE TEXTO A CARGAR:",path,30);
	printf("- INTENTANDO ABRIR ARCHIVO...\n");
	if(stringIsPath(path)){
		pArchivo=fopen(path,"r");
		retorno=1;
	}
	if(pArrayListServicios!=NULL&&pArchivo!=NULL){
		retorno=-1;
		printf("- ARCHIVO ENCONTRADO.\n");
		if(ll_isEmpty(pArrayListServicios)){
			printf("- REALIZANDO LECTURA...\n");
			retorno=parser_ServiciosFromText(pArchivo, pArrayListServicios);
		} else if(confirm("- SE HAN DETECTADO SERVICIOS CARGADOS. DESEA CARGAR EL ARCHIVO DE TODAS FORMAS(S/N)? (SE PERDERAN LOS DATOS ACTUALES):")){
			ll_clear(pArrayListServicios);
			retorno=parser_ServiciosFromText(pArchivo, pArrayListServicios);
		}
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Listar servicios
 * \param pArrayListServicios LinkedList*
 * \return int
 *
 */
int controller_ListServicios(LinkedList* pArrayListServicios){
	int retorno=-1;
    if(pArrayListServicios!=NULL&&!ll_isEmpty(pArrayListServicios)){
    	printf("ID      DESCRIPCION                     TIPO DE SERVICIO        PRECIO UNI.     CANTIDAD        TOTAL SERVICIO\n");
    	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<ll_len(pArrayListServicios);i++){
			Servicios_mostrarServicio(ll_get(pArrayListServicios,i));
    	}
		printf("------------------------------------------------------------------------------------------------------------------------------------\n");
		retorno=0;
    }
	return retorno;
}

/**
 * map Servicios (calcular costo total) Aplica una función a cada elemento de la linkedList
 * @param pArrayListServicios
 * @return -2 si puntero a NULL o lista vacia; -1 error en map; 0 si funciono
 */
int controller_mapServicios(LinkedList* pArrayListServicios){
	int retorno=-2;
	void* (*pFuncionMapeo)(void*arg)=NULL;
	LinkedList* listaMapeada=NULL;
	pFuncionMapeo=Servicios_mapCalcularTotalServicio;
	if(pArrayListServicios!=NULL&&pFuncionMapeo!=NULL&&!ll_isEmpty(pArrayListServicios)){
		listaMapeada=ll_map(pArrayListServicios, pFuncionMapeo);
		retorno=controller_ListServicios(listaMapeada);
		ll_deleteLinkedList(listaMapeada);
	}
	return retorno;
}
/**
 * filter Servicios Aplica un filtro a traves de ll_filter a una linkedList y la muestra
 * @param pArrayListServicios
 * @return -2 si puntero a null o lista original vacia; -1 si criterio invalido; 0 si funciono
 */
int controller_filterServicios(char* path,LinkedList* pArrayListServicios){
	char tipoStr[30];
	int tipoInt;
	int retorno=-2;
	FILE* pArchivo=NULL;
	LinkedList* listaServiciosFiltrada=NULL;
	int (*pFuncionFiltro)(void*arg);
	pArchivo=fopen(path,"w");
	if(pArchivo!=NULL&&stringIsPath(path)&&pArrayListServicios!=NULL&&!ll_isEmpty(pArrayListServicios)){
		getAlphabeticText("- INGRESE TIPO DE SERVICIO A FILTRAR (MINORISTA, MAYORISTA O EXPORTAR): ",tipoStr,30);
		tipoInt=Servicios_getTipoIdByStr(tipoStr);
		switch(tipoInt){
			case 0:
				fclose(pArchivo);
				return -1;
				break;
			case 1:
				printf("- FILTRO A APLICAR: SERVICIOS DE TIPO 'MINORISTA'\n");
				pFuncionFiltro=Servicios_filtrarPorTipoMinorista;
				break;
			case 2:
				printf("- FILTRO A APLICAR: SERVICIOS DE TIPO 'MAYORISTA'\n");
				pFuncionFiltro=Servicios_filtrarPorTipoMayorista;
				break;
			case 3:
				printf("- FILTRO A APLICAR: SERVICIOS DE TIPO 'EXPORTAR'\n");
				pFuncionFiltro=Servicios_filtrarPorTipoExportar;
				break;
		}
		listaServiciosFiltrada=ll_filter(pArrayListServicios, pFuncionFiltro);
		printf("- REALIZANDO ESCRITURA...\n");
		retorno=parser_saveServiciosAsText(pArchivo, listaServiciosFiltrada);
		ll_deleteLinkedList(pArrayListServicios);
	}
	fclose(pArchivo);
    return retorno;
}
/** \brief Ordena y lista servicios
 * \param pArrayListServicios LinkedList*
 * \return int -1 si error o 0 si ok
 *
 */
int controller_sortAndListServicios(LinkedList* pArrayListServicios){
	int retorno=-1;
	int (*pFunc)(void*arg1,void*arg2)=NULL;
	pFunc=Servicios_compareByDescripcion;
	if(pArrayListServicios!=NULL&&pFunc!=NULL&&!ll_isEmpty(pArrayListServicios)){
		retorno=ll_sort(pArrayListServicios, pFunc, 1);
		controller_ListServicios(pArrayListServicios);
	}
	return retorno;
}

/** \brief Guarda los datos de los servicios en el archivo 'path' (modo texto).
 *
 * \param path char*
 * \param pArrayListServicios LinkedList*
 * \return int -2 si error al crear archivo o -1 si error de escritura o 0 si ok
 *
 */
int controller_saveAsText(char* path,LinkedList* pArrayListServicios){
	int retorno=-2;
	FILE* pArchivo;
	pArchivo=fopen(path,"w");
	if(pArchivo!=NULL&&stringIsPath(path)&&pArrayListServicios!=NULL&&!ll_isEmpty(pArrayListServicios)){
			printf("- REALIZANDO ESCRITURA...\n");
			retorno=parser_saveServiciosAsText(pArchivo, pArrayListServicios);
	}
	fclose(pArchivo);
    return retorno;
}

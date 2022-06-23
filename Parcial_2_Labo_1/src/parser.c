#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eServicios.h"
/** \brief Parsea los datos los datos de los Servicios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListMascotas LinkedList*
 * \return int
 *
 */
int parser_ServiciosFromText(FILE* pArchivo, LinkedList* pArrayListServicios)
{
	int retorno=0;
	int leido;
	char buffers[6][50];
	char fantasma[50];
	eServicios* serviciosBuff=NULL;
	// Lectura fantasma
	fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", fantasma, fantasma, fantasma, fantasma, fantasma, fantasma);
	while(!feof(pArchivo)){
		leido=fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffers[0], buffers[1], buffers[2], buffers[3], buffers[4], buffers[5]);
		if(leido==6){
			serviciosBuff=Servicios_newParametros(atoi(buffers[0]),buffers[1],atoi(buffers[2]),atof(buffers[3]),atoi(buffers[4]),atof(buffers[5]));
			if(serviciosBuff!=NULL){
				ll_add(pArrayListServicios, serviciosBuff);
			}
		} else if(!feof(pArchivo)){
			retorno=-1;
			break;
		}
	}
    return retorno;
}


/**
 * @brief Guarda los datos de una lista de mascotas en modo texto
 * @param pArchivo Puntero a archivo
 * @param pArrayListMascotas LinkedList*
 * @return
 */
int parser_saveServiciosAsText(FILE* pArchivo, LinkedList* pArrayListServicios){
	int retorno=0;
	eServicios* serviciosBuff=NULL;
	int idAux, tipoAux, cantidadAux;
	char descripcionAux[30];
	float precioUniAux, totalAux;
	fprintf(pArchivo, "id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");
	for(int i=0;i<ll_len(pArrayListServicios);i++){
		serviciosBuff=ll_get(pArrayListServicios, i);
		if(serviciosBuff!=NULL){
			Servicios_getId(serviciosBuff, &idAux);
			Servicios_getDescripcion(serviciosBuff, descripcionAux);
			Servicios_getTipo(serviciosBuff, &tipoAux);
			Servicios_getPrecioUnitario(serviciosBuff, &precioUniAux);
			Servicios_getCantidad(serviciosBuff, &cantidadAux);
			Servicios_getTotalServicio(serviciosBuff, &totalAux);
			fprintf(pArchivo, "%d,%s,%d,%.2f,%d,%.2f\n", idAux, descripcionAux, tipoAux, precioUniAux,cantidadAux, totalAux);
		}  else {
			retorno=-1;
			break;
		}
	}
	return retorno;
}

/*
 * eServicios.c
 *
 *  Created on: 20 jun. 2022
 *      Author: Mauro
 */

#include "eServicios.h"
#include "utn.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Retorna un puntero a una nueva entidad eServicios en memoria dinamica
 * @return NULL si no hay memoria disponible o eServicios* Puntero a eServicios si funciono
 */
eServicios* Servicios_new(){
	eServicios* servicioBuff=NULL;
	servicioBuff=(eServicios*) malloc(sizeof(eServicios));
	if ( servicioBuff==NULL
	||Servicios_setId(servicioBuff, 0)
	||Servicios_setDescripcion(servicioBuff, " ")
	||Servicios_setTipo(servicioBuff, 1)
	||Servicios_setPrecioUnitario(servicioBuff, 1)
	||Servicios_setCantidad(servicioBuff, 1)
	||Servicios_setTotalServicio(servicioBuff, 0))
	{
		Servicios_delete(servicioBuff);
		servicioBuff=NULL;
	}
	return servicioBuff;
}
/**
 * Retorna un puntero a una nueva entidad eServicios en memoria dinamica
 * @param id int
 * @param descripcion char*
 * @param tipo int
 * @param edad int
 * @param precioUnitario float
 * @param cantidad int
 * @param totalServicio float
 * @return NULL si no hay memoria disponible o eServicios* Puntero a eServicios si funciono
 */
eServicios* Servicios_newParametros(int id,char descripcion[],int tipo,float precioUnitario,int cantidad,float totalServicio){
	eServicios* servicioBuff=Servicios_new();
	if (Servicios_setId(servicioBuff, id)
	||Servicios_setDescripcion(servicioBuff, descripcion)
	||Servicios_setTipo(servicioBuff, tipo)
	||Servicios_setPrecioUnitario(servicioBuff, precioUnitario)
	||Servicios_setCantidad(servicioBuff, cantidad)
	||Servicios_setTotalServicio(servicioBuff, totalServicio))
	{
		Servicios_delete(servicioBuff);
		servicioBuff=NULL;
	}
	return servicioBuff;
}
/**
 * Libera la memoria ocupada por un puntero a estructura eServicios en memoria dinamica
 * @param this eServicios* puntero a servicios
 */
void Servicios_delete(eServicios* this){
	if(this!=NULL){
		free(this);
	}
}
/**
 * Muesta la informacion de un servicio
 * @param this eServicios* puntero a servicio
 * @return -1 si puntero NULL o 0 si funciono
 */
int Servicios_mostrarServicio(eServicios* this){
	int retorno=-1;
	int id, cantidad;
	char descripcion[30];
	float precioUnitario, totalServicio;
	char tipo[30];
	if(this!=NULL){
		Servicios_getId(this, &id);
		printf("%-4d\t", id);
		Servicios_getDescripcion(this, descripcion);
		printf("%-25s\t", descripcion);
		Servicios_getTipoStr(this, tipo);
		printf("%-12s\t\t", tipo);
		Servicios_getPrecioUnitario(this, &precioUnitario);
		printf("%-5.2f\t\t", precioUnitario);
		Servicios_getCantidad(this, &cantidad);
		printf("%-4d\t\t", cantidad);
		Servicios_getTotalServicio(this, &totalServicio);
		printf("%-5.2f\t\n", totalServicio);
		retorno=0;
	}
	return retorno;
}

int Servicios_setId(eServicios* this, int id){
	int retorno=-1;
	if(this!=NULL&&id>=0&&id<9999){
		this->id_servicio=id;
		retorno=0;
	}
	return retorno;
}
int Servicios_setDescripcion(eServicios* this, char descripcion[]){
	int retorno=-1;
	if(this!=NULL&&descripcion!=NULL){
		strcpy(this->descripcion, descripcion);
		stringToUpper(this->descripcion,1);
		retorno=0;
	}
	return retorno;
}
int Servicios_setTipo(eServicios* this, int tipo){
	int retorno=-1;
	if(this!=NULL&&tipo>=1&&tipo<4){
		this->tipo=tipo;
		retorno=0;
	}
	return retorno;
}
int Servicios_setPrecioUnitario(eServicios* this, float precioUnitario){
	int retorno=-1;
	if(this!=NULL&&precioUnitario>0){
		this->precioUnitario=precioUnitario;
		retorno=0;
	}
	return retorno;
}
int Servicios_setCantidad(eServicios* this, int cantidad){
	int retorno=-1;
	if(this!=NULL&&cantidad>0){
		this->cantidad=cantidad;
		retorno=0;
	}
	return retorno;
}
int Servicios_setTotalServicio(eServicios* this,float totalServicio){
	int retorno=-1;
	if(this!=NULL&&totalServicio>=0){
		this->totalServicio=totalServicio;
		retorno=0;
	}
	return retorno;
}

int Servicios_getId(eServicios* this, int* id){
	int retorno=-1;
	if(this!=NULL&&id!=NULL){
		*id=this->id_servicio;
		retorno=0;
	}
	return retorno;
}
int Servicios_getDescripcion(eServicios* this,char* descripcion){
	int retorno=-1;
	if(this!=NULL&&descripcion!=NULL){
		strcpy(descripcion, this->descripcion);
		retorno=0;
	}
	return retorno;
}
int Servicios_getTipo(eServicios* this, int* tipo){
	int retorno=-1;
	if(this!=NULL&&tipo!=NULL){
		*tipo=this->tipo;
		retorno=0;
	}
	return retorno;
}

int Servicios_getTipoStr(eServicios* this, char* tipo){
	int retorno=-1;
	int tipoInt;
	if(this!=NULL&&tipo!=NULL){
		Servicios_getTipo(this, &tipoInt);
		switch(tipoInt){
		case 1:
			strcpy(tipo, "MINORISTA");
			break;
		case 2:
			strcpy(tipo, "MAYORISTA");
			break;
		case 3:
			strcpy(tipo, "EXPORTAR");
			break;
		}
		retorno=0;
	}
	return retorno;
}

int Servicios_getTipoIdByStr(char* tipo){
	int retorno=0;
	if(tipo!=NULL){
		stringToUpper(tipo,strlen(tipo));
		if(!strcmp("MINORISTA", tipo)){
			retorno=1;
		}else if(!strcmp("MAYORISTA", tipo)){
			retorno=2;
		}else if(!strcmp("EXPORTAR", tipo)){
			retorno=3;
		}
	}
	return retorno;
}

int Servicios_getPrecioUnitario(eServicios* this, float* precioUnitario){
	int retorno=-1;
	if(this!=NULL&&precioUnitario!=NULL){
		*precioUnitario=this->precioUnitario;
		retorno=0;
	}
	return retorno;
}

int Servicios_getCantidad(eServicios* this, int* cantidad){
	int retorno=-1;
	if(this!=NULL&&cantidad!=NULL){
		*cantidad=this->cantidad;
		retorno=0;
	}
	return retorno;
}

int Servicios_getTotalServicio(eServicios* this,float* totalServicio){
	int retorno=-1;
	if(this!=NULL&&totalServicio!=NULL){
		*totalServicio=this->totalServicio;
		retorno=0;
	}
	return retorno;
}
/**
 * Funcion criterio. Compara dos servicios por descripcion
 * @param arg1 void*
 * @param arg2 void*
 * @return 0 si error (punteros NULL) o 1 si descripcion de arg1 es mayor que descripcion de arg2 o -1 si descripcion de arg2 es mayor que descripcion de arg1
 */
int Servicios_compareByDescripcion(void* arg1, void* arg2){
	int retorno=0;
	char descripcion1[50], descripcion2[50];
	if(arg1!=NULL&&arg2!=NULL){
		Servicios_getDescripcion((eServicios*)arg1, descripcion1);
		Servicios_getDescripcion((eServicios*)arg2, descripcion2);
		if(strncmp(descripcion2,descripcion1,4)<0){
			retorno=1;
		} else if(strncmp(descripcion2,descripcion1,4)>0){
			retorno=-1;
		}
	}
	return retorno;
}
/**
 * Funcion filtro. Campo tipo=1
 * @param arg eServicios*
 * @return 0 si puntero NULL o -1 si no cumple criterio o 1 si cumple criterio
 */
int Servicios_filtrarPorTipoMinorista(void* arg){
	int retorno=-1;
	int tipo;
	if(arg!=NULL){
		retorno=0;
		Servicios_getTipo((eServicios*)arg, &tipo);
		if(tipo==1)
			retorno=1;
	}
	return retorno;
}
/**
 * Funcion filtro. Campo tipo=2
 * @param arg eServicios*
 * @return 0 si puntero NULL o -1 si no cumple criterio o 1 si cumple criterio
 */
int Servicios_filtrarPorTipoMayorista(void* arg){
	int retorno=-1;
	int tipo;
	if(arg!=NULL){
		retorno=0;
		Servicios_getTipo((eServicios*)arg, &tipo);
		if(tipo==2)
			retorno=1;
	}
	return retorno;
}
/**
 * Funcion filtro. Campo tipo=3
 * @param arg eServicios*
 * @return 0 si puntero NULL o -1 si no cumple criterio o 1 si cumple criterio
 */
int Servicios_filtrarPorTipoExportar(void* arg){
	int retorno=-1;
	int tipo;
	if(arg!=NULL){
		retorno=0;
		Servicios_getTipo((eServicios*)arg, &tipo);
		if(tipo==3)
			retorno=1;
	}
	return retorno;
}
/**
 * Funcion map. Calcula el campo totalServicio de eServicios
 * @param arg eServicios*
 * @return eServicio* puntero a nuevo eServicios* calculado
 */
void* Servicios_mapCalcularTotalServicio(void* arg){
	float precioUnitario;
	int cantidad;
	eServicios* this=Servicios_new();
	(*this)=*(eServicios*)(arg);
	Servicios_getPrecioUnitario((eServicios*)arg, &precioUnitario);
	Servicios_getCantidad((eServicios*)arg, &cantidad);
	Servicios_setTotalServicio(this, precioUnitario*cantidad);
	return this;
}

//void Servicios_mapCalcularTotalServicio(void* arg){
//	eServicios* this=(eServicios*)arg;
//	float precioUnitario;
//	int cantidad;
//	Servicios_getPrecioUnitario(this, &precioUnitario);
//	Servicios_getCantidad(this, &cantidad);
//	Servicios_setTotalServicio(this, precioUnitario*cantidad);
//}

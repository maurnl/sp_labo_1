/*
 * eServicios.h
 *
 *  Created on: 20 jun. 2022
 *      Author: Mauro
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_

typedef struct{
	int id_servicio;
	char descripcion[30];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
}eServicios;

#endif /* ESERVICIOS_H_ */

eServicios* Servicios_new(); // Encapsula el malloc
eServicios* Servicios_newParametros(int id,char* descripcion,int tipo,float precioUnitario,int cantidad,float totalServicio);
void Servicios_delete(eServicios* this);

int Servicios_mostrarServicio(eServicios* this);

int Servicios_setId(eServicios* this, int id);
int Servicios_setDescripcion(eServicios* this, char* descripcion);
int Servicios_setTipo(eServicios* this, int tipo);
int Servicios_setPrecioUnitario(eServicios* this, float precioUnitario);
int Servicios_setCantidad(eServicios* this, int cantidad);
int Servicios_setTotalServicio(eServicios* this,float totalServicio);

int Servicios_getId(eServicios* this, int* id);
int Servicios_getDescripcion(eServicios* this,char* descripcion);
int Servicios_getTipo(eServicios* this, int* tipo);
int Servicios_getTipoStr(eServicios* this, char* tipo);
int Servicios_getPrecioUnitario(eServicios* this, float* precioUnitario);
int Servicios_getCantidad(eServicios* this, int* cantidad);
int Servicios_getTotalServicio(eServicios* this,float* totalServicio);

int Servicios_compareByDescripcion(void* arg1, void* arg2);

int Servicios_getTipoIdByStr(char* tipo);

int Servicios_filtrarPorTipoMinorista(void* arg);
int Servicios_filtrarPorTipoMayorista(void* arg);
int Servicios_filtrarPorTipoExportar(void* arg);

void Servicios_mapCalcularTotalServicio(void* arg);

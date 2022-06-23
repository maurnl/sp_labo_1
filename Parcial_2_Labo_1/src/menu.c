/*
 * input.c
 *
 *  Created on: 18 jun. 2022
 *      Author: Mauro
 */
#include <stdio.h>
#include "utn.h"

/**
 * @brief Funcion para control de menu
 * @param flagSave bandera para evitar salir sin guardar
 * @return int la opcion elegida
 */
int menu(){
	int opcion=-1;
	getPositiveInt("\tMenu:\n\t\t1. Cargar archivo.\n\t\t2. Imprimir lista.\n\t\t3. Asignar totales.\n\t\t4. Filtrar por tipo.\n\t\t5. Ordenar servicios.\n\t\t6. Guardar servicios\n\t\t7. Salir.",
			&opcion, 1, 7);
	return opcion;
}

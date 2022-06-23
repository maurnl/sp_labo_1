/*
 * utn.c
 *
 *  Created on: 4 jun. 2022
 *      Author: Mauro
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Imprimite un mensaje y pide ingreso de S o N
 * @param mensaje char* mensaje a mostrar
 * @return -1 si error o [1 si S o 0 si N]
 */
int confirm(char mensaje[]) {
	int retorno;
	char respuesta;
	retorno = -1;
	if(mensaje!= NULL) {
		printf("%s \n", mensaje);
		fflush(stdin);
		respuesta = getchar();
		respuesta = toupper(respuesta);
		while((respuesta != 'S') && (respuesta != 'N') && (respuesta != '\n')) {
			printf("%s \n", mensaje);
			fflush(stdin);
			respuesta = getchar();
			respuesta = toupper(respuesta);
		}
		if (respuesta == 'S') {
			retorno = 1;
		} else {
			retorno = 0;
		}
	}

	return retorno;
}
/**
 * @brief Busca si un string es solo numeros
 * @param string char* a recorrer
 * @return 1 si es solo numero 0 si contiene algun caracter no numerico
 */
int stringIsInt(char string[]){
	int retorno=1;
	if(string!=NULL){
		for(int i=0;i<strlen(string)-1;i++){
			if(isdigit(string[i])==0){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * @brief Imprime un mensaje y permite el ingreso de un numero dentro de un rango
 * @param mensaje char* mensaje a mostrar
 * @param resultado int* donde guardar el resultado
 * @param min int minimo
 * @param max int maximo
 * @return -1 si error (punteros nulos) o 0 si funciono
 */
int getPositiveInt(char mensaje[], int* resultado, int min, int max) {
	char buffer[9];
	int flagError;
	int retorno;
	int numero;
	retorno = -1;
	if(resultado != NULL && mensaje != NULL) {
		do {
			flagError=0;
			printf("%s \n", mensaje);
			fflush(stdin);
			fgets(buffer,9,stdin);
			if(!stringIsInt(buffer)){
				flagError=1;
			} else {
				numero=atoi(buffer);
			}
		}while(flagError==1 || (numero<min || numero>max));
		retorno=0;
		*resultado = numero;
	}
	return retorno;
}

/**
 * @brief Busca si un string es solo numeros y contiene un solo punto
 * @param string char* a recorrer
 * @return 1 si es solo numero 0 si contiene algun caracter no numerico distino de punto o mas de dos puntos
 */
int stringIsFloat(char string[]){
	int retorno=1;
	int i;
	int dot=0;
	if(string!=NULL){
		for(i=0;i<strlen(string)-1;i++){
			if(isdigit(string[i])==0){
				if(string[i]=='.'&&dot<1){
					dot++;
				} else {
					retorno=0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * @brief Imprime un mensaje y permite el ingreso de un numero dentro de un rango
 * @param mensaje char* mensaje a mostrar
 * @param resultado float* donde guardar el resultado
 * @param min int minimo
 * @param max int maximo
 * @return -1 si error (punteros nulos) o 0 si funciono
 */
int getPositiveFloat(char mensaje[], float* resultado, float min, float max) {
	int retorno=-1;
	char buffer[9];
	int flagError;
	float numero;
	if(resultado!= NULL&&mensaje!=NULL) {
		do {
			flagError=0;
			printf("%s \n", mensaje);
			fflush(stdin);
			fgets(buffer,9,stdin);
			if(!stringIsFloat(buffer)){
				flagError=1;
			} else {
				numero=atof(buffer);
			}
		}while(flagError==1 || (numero<min || numero>max));
		retorno=0;
		*resultado = numero;
	}
	return retorno;
}

/**
 * @brief Busca si un string es solo letras y espacio
 * @param string char* a recorrer
 * @return 1 si es solo letras 0 si contiene algun caracter no alfabetico distinto de espacios
 */
int stringIsAlphabetic(char string[]){
	int retorno=1;
	int i;
	if(string!=NULL){
		for(i=0;i<strlen(string)-1;i++){
			if(isalpha(string[i])==0 && string[i]!=' '){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * @brief Imiprime un mensaje y permite el ingreso de un texto alfabetico
 * @param mensaje char* mensjae a mostrar
 * @param destino char* donde se almacenara la respuesta
 * @param len int largo de la cadena
 * @return -1 si error(punteros nulos o largo no admitido) o 0 si funciono
 */
int getAlphabeticText(char mensaje[], char destino[], int len) {
	int retorno;
	int flagError;
	retorno=-1;
	if(mensaje!=NULL && destino!=NULL && len>0) {
		do {
			flagError=0;
			printf("%s \n", mensaje);
			fflush(stdin);
			fgets(destino,len,stdin);
			if(!stringIsAlphabetic(destino)){
				flagError=1;
			}
		}while(flagError==1);
		destino[strlen(destino)-1]='\0';
		retorno=0;
	}
	return retorno;
}

/**
 * @brief Imiprime un mensaje y permite el ingreso de un texto alfanumerico
 * @param mensaje char* mensjae a mostrar
 * @param destino char* donde se almacenara la respuesta
 * @param len int largo de la cadena
 * @return -1 si error(punteros nulos o largo no admitido) o 0 si funciono
 */
int getAlphanumericText(char mensaje[], char destino[], int len) {
	int retorno;
	retorno=-1;
	if(mensaje!=NULL && destino!=NULL && len>0) {
		printf("%s \n", mensaje);
		fflush(stdin);
		fgets(destino,len,stdin);
		destino[strlen(destino)-1]='\0';
		retorno=0;
	}

	return retorno;
}

/**
 * @brief Busca si un string es una ruta valida
 * @param string char* cadena a recorrer
 * @return 1 si no encuentra espacios o 0 si contiene espacios
 */
int stringIsPath(char string[]){
	int retorno=1;
	int i;
	if(string!=NULL){
		for(i=0;i<strlen(string);i++){
			if(string[i]==' '){
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * @brief Recorre un string y lleva a mayusculas qty caracteres
 * @param string char* string a recorrer
 * @param qty cantidad de caracteres
 * @return -1 si error (punteros nulos o cantidad fuera de rango) o 0 si funciono
 */
int stringToUpper(char* string, int qty){
	int retorno=-1;
	int i;
	if(string!=NULL&&qty>0&&qty<=strlen(string)){
		for(i=0;i<qty;i++){
			*(string+i)=toupper(*(string+i));
		}
		retorno=0;
	}
	return retorno;
}

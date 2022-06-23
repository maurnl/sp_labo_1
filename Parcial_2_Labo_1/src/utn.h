/*
 * utn.h
 *
 *  Created on: 4 jun. 2022
 *      Author: Mauro
 */

#ifndef UTN_H_
#define UTN_H_
#endif /* UTN_H_ */

int stringIsInt(char string[]);
int stringIsAlphabetic(char string[]);
int getPositiveInt(char mensaje[], int* resultado, int min, int max);
int stringIsFloat(char string[]);
int getPositiveFloat(char mensaje[], float* resultado, float min, float max);
int confirm(char mensaje[]);
int getAlphabeticText(char mensaje[], char destino[], int len);
int getAlphanumericText(char mensaje[], char destino[], int len);
int stringIsPath(char string[]);
int stringToUpper(char* string, int qty);

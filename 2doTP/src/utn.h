/*
 * utn.h
 *
 *  Created on: 30 sept. 2020
 *      Author: NOELIA
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumberInt(char* mensaje, char*mensajeError, int* pResultado, int reintentos,int maximo, int minimo);
int utn_getName(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);


int utn_getNumberFloat(char* mensaje, char* mensajeError,float* pResultado,float minimo, float maximo, int reintentos);
//===========================================
int utn_getInt(int* pResultado);
//===========================================
int utn_isNumber(char cadena[]);
//===========================================
int esUnNombreValido(char* cadena, int limite);

#endif /* UTN_H_ */

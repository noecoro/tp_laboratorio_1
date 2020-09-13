/*
 * utn.h
 *
 *  Created on: 12 sep. 2020
 *      Author: noelia
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>


/**\brief Solicita al usuario un numero, lo verfica y lo valida y devuelve un resultado
*\param pResultado Puntero al resultado, donde se dejara el numero ingresado por el usuario
*\param mensaje Puntero al mensaje a mostrar para pedirle el dato al usuario
*\param mensajeError Puntero al mensaje a mostrar al usuario en caso de error
*\param minimo Valor minimo aceptado
*\param maximo Valor maximo aceptado
*\param reintentos Cantidad de reintentos en caso de error
*\return Devuelve el valor -1 en caso de error y 0 en caso de exito
*/
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos);
//==================================================
/** \brief solicita un numero verifica valida y devuelve resultado
 *
 * \param pResultado puntero al resultado donde se dejara el numero ingresado por el usuario
 * \param mensaje Puntero al mensaje a mostrar para pedirle el dato al usuario
 * \param mensajeError Puntero al mensaje a mostrar al usuario en caso de error
 * \param reintentos Cantidad de reintentos en caso de error
 * \return  Devuelve el valor -1 en caso de error y 0 en caso de exito
 *
 */
int operandosIngresados(int* pResultado,char* mensaje, char* mensajeError,int reintentos);
//=================================================

/** \brief realiza la suma de dos numeros ingresados
 *
 * \param int x primer numero
 * \param int y segundo numero
 * \return resultado de la suma
 *
 */
 int sumar(int x, int y);
 //==================================================


/** \brief realiza la resta de dos numeros ingresados
 *
 * \param int x primer numero
 * \param int y segundo numero
 * \return resultado de la resta
 *
 */

 int restar(int x, int y);
 //==================================================

 /** \brief realiza la multiplicacion de dos numeros ingresados
 *
 * \param int x primer numero
 * \param int y segundo numero
 * \return resultado de la multiplicacion
 *
 */
 int multiplicar(int x, int y);
 //==================================================



/** \brief realiza la division entre x dividido en y
 *
 * \param x dividendo
 * \param y divisor
 * \return resultado de la division entre x / y
 *
 */

 float dividir(int x, int y);
 //==================================================


 /**\brief Realiza el factorial de "x" numero
*\param x a ser factoreado
*\return Devuelve el valor factorizado de x
*/
 int factorialX (int x);
 //==================================================

 /**\brief Realiza el factorial del "y" numero
*\param Y a ser factoreado
*\return Devuelve el valor factorizado de Y
*/
 int factorialY (int y);

#endif /* UTN_H_ */


#ifndef UTN_H_
#define UTN_H_

/**\brief Solicita al usuario un numero, lo verfica y lo valida y devuelve un resultado
*\param pResultado Puntero al resultado, donde se dejara el numero ingresado por el usuario
*\param mensaje Puntero al mensaje a mostrar para pedirle el dato al usuario
*\param mensajeError Puntero al mensaje a mostrar al usuario en caso de error
*\param minimo Valor minimo aceptado
*\param maximo Valor maximo aceptado
*\param reintentos Cantidad de reintentos en caso de error
*\return Devuelve el valor -1 en caso de error y 0 en caso de exito
*/
int utn_numeroEntero(int* pResultado, char* msj, char* msjError, int min, int max, int reintentos );
//=================================================

/** \brief realiza la suma de dos numeros ingresados
 *
 * \param float a primer numero
 * \param float b segundo numero
 * \return resultado de la suma
 *
 */
float sumar (float a, float b);
//=================================================

/** \brief realiza la resta de dos numeros ingresados
 *
 * \param float a primer numero
 * \param float b segundo numero
 * \return resultdo de la resta
 *
 */
float restar (float a, float b);
//=================================================

/** \brief realiza la multiplicacion de dos numeros ingresados
 *
 * \param float a primer numero
 * \param float b segundo numero
 * \return resultdo de la multiplicacion
 *
 */
float multiplicar (float a, float b);
//=================================================

/** \brief realiza la division de dos numeros ingresados
 *
 * \param float a primer numero
 * \param float b segundo numero
 * \return resultdo de la division
 *
 */
float dividir (float a, float b);
//===============================
/** \brief realiza el factorial de x
 *
 * \param float x
 * \
 * \return resultdo del factorial
 *
 */
float factorial (float x);
#endif /* UTN_H_ */

/*
 * utn.c
 *
 *  Created on: 30 sept. 2020
 *      Author: NOELIA
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define LIMITE_BUFFER_STRING 1000
//#define LIMITE_BUFFER_STRING 1000//en get int
//static int esNumerica(char* cadena, int limite);
//static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int isNumberFloat(char cadena[]);
static  int getFloat(float* pResultado);


/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNumberInt(char* mensaje, char*mensajeError, int* pResultado, int minimo,int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	int resultadoScanf;
	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos > 0 && maximo >= minimo)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			resultadoScanf = scanf("%d",&bufferInt);
			if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
			{
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}
			else{
				printf("%s",mensajeError);
				reintentos --;
			}
		}while (reintentos >= 0);
	}

	return retorno;
}

//==================================
static int myGets(char* cadena, int longitud)// a mano
{
	fflush(stdin);
	fgets(cadena, longitud,stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}

//=====================================================
/**
 * \brief 	Verifica una cadena recibida como parametro para determinar
 * 			si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int esUnNombreValido(char* cadena, int limite)
{
	int respuesta = 1;//ok
	for(int i=0; i <= limite && cadena[i] != '\0'; i++)
	{
		if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != '.')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
//========================================
/**
 * \brief 	Verifica una cadena recibida es numerica y puede contener signo en el primer indice o ninguno o 1 punto
 *
 * \param   Cadena a analizar
 * \param i
 * \return (1) exito/ (0) error
 *
 */
static int isNumberFloat(char cadena[])//warning revisar
{
	int retorno = 1;
	int flag = 0;
	int i = 0;
	if(cadena[0] == '-')
	{
		i = 1;
	}
	for(;cadena[i] != '\0'; i++)
	{
if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.'))
{
	retorno = 0;
	break;
}
if (cadena[i] == '.')
{
	flag ++;
}
if(flag > 1)
{
retorno = 0;
break;
}
	}
return retorno;
		}
/**
 * \brief obtiene un float
 * \param  float* pResultado puntero al espacio de memoria donde quedara el resultado de la funcion
 * \return retorno 0 exito si obtiene un numero entero y -1 error
 */
static  int getFloat(float* pResultado)
		{
	int retorno = -1;
	char buffer[LIMITE_BUFFER_STRING];
	fflush(stdin);
	fgets(buffer,LIMITE_BUFFER_STRING,stdin);
	buffer[strlen(buffer) -1] ='\0';
	if(isNumberFloat(buffer))
	{
		retorno = 0;
		*pResultado = atof(buffer);
	}
	return retorno;
		}
/**
 * \brief Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
/*int utn_getName(char* mensaje, char* mensajeError, int* pResultado, int reintentos,int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;
	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && limite >0)
	{
		do
		{
			printf("%s", mensaje);
			if(myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
					strnlen(bufferString,sizeof(bufferString) -1) <= limite &&
					esUnNombreValido(bufferString,limite) != 0)
			{
				retorno = 0;
				strncpy(pResultado, bufferString,limite);// passing argument 1 of 'strncpy' from incompatible pointer type

				break;
			}
			else
			{
				printf("%s",mensajeError);
							reintentos --;
			}

		}while(reintentos >= 0);
	}


return retorno;
}
*/
//===========================================
int utn_getName(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMITE_BUFFER_STRING];
	int retorno = -1;

	if(		mensaje != NULL &&
			mensajeError != NULL &&
			pResultado != NULL &&
			reintentos >= 0 &&
			limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMITE_BUFFER_STRING) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnNombreValido(bufferString,limite) != 0 )
			{
				retorno = 0;
				//NO EXISTE pResultado = bufferString;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);

	}
	return retorno;

}


/**
 * \brief Solicita un float
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param float* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */

int utn_getNumberFloat(char* mensaje, char* mensajeError, float* pResultado, float minimo, float maximo, int reintentos)
{
	int retorno = 0;
	float bufferFloat;

//==if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos > 0 && maximo >= minimo)
	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos > 0 && maximo >= minimo)
		{
			do{
				printf("%s", mensaje);
				fflush(stdin);

				if(getFloat (&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
				{
					retorno = 0;
					*pResultado = bufferFloat;
					break;
				}
				else{
					printf("%s",mensajeError);
					reintentos --;
				}
			}while (reintentos >= 0);
		}
	//====
	return retorno;
}

/**
 * \brief obtiene un numero entero
 * \param pResultado puntero al espacio de memoria donde quedara el resultado de la funcion
 * \return retorno 0 exito si obtiene un numero entero y -1 error
 */
/*static int getInt(int* pResultado)// A MANO
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado != NULL && miGets(bufferString,sizeof(bufferString))==0 &&
			esNumerica(bufferString))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}*/
//===========
/**
 * \brief verifica si la cadena ingresada es numerica
 * \param cadena, cadena a ser analizada
 * \return retorno 1 verdadero y 0 falso
 */
/*static int esNumerica(char* cadena, int limite)// a mano
{
	int retorno = 1;//verdadero

	for(int i=0; i<limite;i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] < '0' && cadena[i] >'9')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}*/


/**
 * \brief Solicita un entero al usuario y verifica, devuelve el resultado
 * \param char* pMensaje, mensaje a mostrar
 * \param char* pMensajeError,  mensaje de error a  mostrado
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor ingresado
 * \param int reintentos, cantidad de intentos
 * \param int minimo, valor minimo permitido
 * \param int maximo, valor maximo permitido
 * \return (-1) Error / (0) Ok
 */

//===========================================================
/**
 * \brief
 * \param pResultado puntero espacio reservado en memoria donde quedara el resultado
 * \return retorno 0 en caso de exito al haber obtenido un entero y -1 para error
 */
/*int utn_getInt(int* pResultado)
{
	int retorno = -1;
	char buffer [LIMITE_BUFFER_STRING];

	fflush(stdin);
	fgets(buffer,LIMITE_BUFFER_STRING, stdin);
	buffer[strlen(buffer) -1 ]= '\0';

	if(utn_isNumber(buffer))
	{
		retorno = 0;
		*pResultado = atoi (buffer);

	}
	return retorno;
}*/
//===============================================================
/**
 * \ briefverificara si la cadena q se ingreso es numerica
 * \param cadena de caracteres para analizar
 * \return 0 error y 1 exito
 */

/*int utn_isNumber(char cadena[])// chequear las dos opciones con i=0 y directamente sin i=0 for(  ; cadena[i etc
{
	int retorno = 1;
	int i = 0;//cadena [i] != '\0'

	if(cadena[0] == '-')
	{
		i = 1;
	}
		for(i=0 ; cadena [i] != '\0'; i++)// for(  ; cadena[i] != '\0'; i++)
		{
			if(cadena [i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}

	return retorno;
}*/






//===============================================================





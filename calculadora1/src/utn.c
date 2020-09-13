/*
 * utn.c
 *
 *  Created on: 12 sep. 2020
 *      Author: noelia
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

//============================================================
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
    {
    do{
        printf("%s",mensaje);
        scanf("%d",&bufferInt);
        if(bufferInt >= minimo && bufferInt <= maximo)
        {
        *pResultado = bufferInt;
        retorno = 0;
        break;
        }
        else { printf("%s",mensajeError);
        reintentos --;
    }}
    while (reintentos >= 0);
    }

    return retorno;
}
//===========================================================
int operandosIngresados(int* pResultado,char* mensaje, char* mensajeError,int reintentos)
{
    int bufferInt;
    int retorno = -1;
    do{
        printf ("%s", mensaje);
        __fpurge(stdin);
        scanf ("%d", & bufferInt);
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL  && reintentos >= 0 )
    {
        *pResultado = bufferInt;
        retorno = 0;
        break;
    }
    else
    {
        printf ("%s", mensajeError);
        reintentos --;
    }
     }while (reintentos >= 0);

  return 0;
}
//===============================================================
int sumar(int x, int y)
{
    int resultado;
    resultado = x + y;
    return resultado;
}
//===============================================================
int restar(int x, int y)
{
    int resultado;
    resultado = x - y;
    return resultado;
}
//===============================================================
float dividir(int x, int y)
{
    float resultado;
    if (y!=0)
    {
        resultado = (float) x/y;
    }
    else
    {
        resultado = 0;
    }
    return resultado;
}
//===============================================================

int multiplicar(int x, int y)
{
    int resultado;
    resultado = x * y;
    return resultado;
}
//===============================================================
int factorialX(int x)
{
    int factUno;

    if (x==1)
    {
        factUno=1;
    }
    else
    {
        factUno = x*factorialX (x-1);
    }

    return factUno;
}

//=================
int factorialY (int y)
{
    int factDos;

    if (y==1)
    {
        factDos=1;
    }
    else
    {
        factDos = y*factorialY (y-1);
    }

    return factDos;
}





#include <stdio.h>
#include <stdlib.h>
int utn_numeroEntero(int* pResultado, char* msj, char* msjError, int min, int max, int reintentos )

{
	int bufferInt;
	int retorno = -1;

	if (pResultado != NULL && msj != NULL && msjError != NULL &&  min <= max && reintentos >= 0)
	{
		do
		{
			printf ("%s ", msj);
			scanf ("%d", &bufferInt);
			if (bufferInt >= min && bufferInt <= max)
			{
				*pResultado = bufferInt;
				retorno = 0;
			break;
			}
		else
		{
			fflush(stdin);
			printf ("%s", msjError);
			reintentos --;
		}
		}while (reintentos >= 0);
	}
	return retorno;
}
//====================================
float sumar (float a, float b)
{
	float resultSuma;
	resultSuma = a + b;
	return resultSuma;
}
//====================================
float restar (float a, float b)
{
	float resultResta;
	resultResta = a - b;
	return resultResta;
}
//===============================
float multiplicar (float a, float b)
{
	float resultMultiplicar;
	resultMultiplicar = a * b;
	return resultMultiplicar;
}
//===============================
float dividir (float a, float b)
{
	float resultDividir;
	resultDividir = a / b;
	return resultDividir;
}
//================================
float factorial (float x)
{
	float respuesta;
	if (x == 1)
	{
		return 1;
	}
	respuesta = x* factorial (x -1);
	return (respuesta);
}

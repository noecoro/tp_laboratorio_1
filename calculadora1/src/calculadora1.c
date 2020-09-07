
		/*
		 ============================================================================
		 Name        : calcu.c
		 Author      :
		 Version     :
		 Copyright   : Your copyright notice
		 Description : Hello World in C, Ansi-style
		 ============================================================================
		 */
		#include <stdio_ext.h>
		#include <stdio.h>
		#include <stdlib.h>
		//=============PROTOTIPOS================
		int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
		int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,  int reintentos);//para ingres un nro
		int sumar(float nro1, float nro2);
		int restar(float nro1, float nro2);
		int multiplicar(float nro1, float nro2);
		int dividir(float nro1, float nro2);
		//=================================================
		int main(void) {
		int opcion;
		int rta;
		int x;
		int y;
		do {
		rta = utn_getNumero(&opcion,"CALCULADORA\nMENU\n\n1- Ingese 1er operando\n2- Ingrese 2do operando\n3- Calcular operaciones"
				"\n4- Mostrar resultados\n5-salir(6realizar opra operacion\n","No es una opcion valida",1,5,2);
		/*if(! rta){
	switch (opcion){
	if(utn_getNumeroFlotante (&x,"\nIngrese primer operando","Error, no es valido",2)==0){// si esto se cumple

				printf("el primer operando es %.2f",x);
				break;
		}
		case 2:
			if(utn_getNumeroFlotante(&y, "ingrese primer operando","error, no es valido",2)==0)
			{
			printf("\n El segundo  operando  es %.2f",y);
			break;
		}*/
		 }while(opcion != 5);
			return 0;
		}
//=============FUNCIONES=================
		int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){

			int bufferInt;
			int retorno = -1;


			if(pResultado != NULL && mensaje != NULL && mensajeError !=NULL && minimo <= maximo && reintentos >= 0)
			{
				do{
					printf("%s", mensaje);
						scanf("%d", &bufferInt);
						if(bufferInt >= minimo && bufferInt <= maximo){
							*pResultado = bufferInt;
							retorno = 0;
							break;
						}else{
							printf("%s", mensajeError);
							reintentos--;
						}

				}while(reintentos > 0);
			}
			return retorno;
		}
		//================================================================
		int sumar(float nro1, float nro2){
			int rta;
			rta = nro1+ nro2;
			return rta;
		}
		//================================================================
		int restar(float nro1, float nro2){
			int rta;
			rta = nro1 - nro2;
			return rta;
		}
		//================================================================
		int multiplicar(float nro1, float nro2){
			int rta;
			rta = nro1 * nro2;
			return rta;
		}
		//================================================================
		int dividir(float nro1, float nro2){
			int rta;
			rta = (float)nro1 / nro2;
			return rta;
		}
		//================================================================

		int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,  int reintentos)
		{
			float bufferFloat;
			int retorno = -1;
			int resultado;
			printf("%s", mensaje);
			//purge
			//resultado= scanf("%.2f",& bufferFloat);
			while(resultado ==  0 && reintentos >0)
			{
				reintentos--;
				printf("%s",mensajeError);
				__fpurge(stdin);
				resultado = scanf("%.2f",& bufferFloat);}

			if (resultado != 0){
				*pResultado = bufferFloat;
				retorno = 0;
			}
			return retorno;
		}

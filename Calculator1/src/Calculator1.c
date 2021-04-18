
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);

			int opcion;

			float valorA;
			float valorB;

			float resultSumar;
			float resultRestar;
			float resultMultiplicar;
			float resultDividir;
			float resultFactorialA;
			float resultFactorialB;

			int flagValorA = 0;
			int flagValorB = 0;

			int validarDividirPorCero = 0;

			do
			{
				if (utn_numeroEntero (&opcion, "\n||||=====CALCULADORA=====||||\n    ---------Menu---------\n1. Ingrese valor A\n2. Ingrese valor B\n3. Operar valores [+;-;*;/;!]\n4. Resultados de las operaciones\n5. Salir\n", "Opcion no válida\n", 1, 5, 2)==0  )
				{
					switch (opcion)
					{
					case 1 :
						flagValorA = 1;
						printf ("Ingrese valor A\n");
						fflush (stdin);
						scanf("%f",&valorA);
						printf ("El valor de A: %f\n", valorA);
						break;

					case 2 :
						flagValorB = 1;
					printf ("Ingrese valor B\n");
					fflush(stdin);
					scanf ("%f", &valorB);
					printf ("El valor de B: %f\n", valorB);
						break;

					case 3 :

						if (flagValorA == 1 && flagValorB == 1 ){

						printf ("Se han realizado todas las operaciones\n\n");
						resultSumar = sumar (valorA, valorB);
						resultRestar = restar (valorA, valorB);
						resultMultiplicar= multiplicar(valorA, valorB);
						resultDividir= dividir (valorA, valorB);
						resultFactorialA = factorial(valorA);
						resultFactorialB = factorial(valorB);
						}
						else {
							printf ("ERROR debe ingresar valores en la opcion 1 y 2\n");
						}

						break;
					case 4 :
						printf ("El resultado de %f + %f es: %f\n", valorA, valorB, resultSumar);
						printf ("El resultado de %f - %f es: %f\n", valorA, valorB, resultRestar);
						printf ("El resultado de %f * %f es: %f\n", valorA, valorB, resultMultiplicar);


						if ( validarDividirPorCero  == 0)
						  {
							printf("El resultado de %f / %f es: %f\n", valorA, valorB, resultDividir);
						  }
						else
						{

							printf ("NO se puede dividir por 0\n");
						}
						printf ("El factorial de %f es %f\n", valorA, resultFactorialA);
						printf ("El factorial de %f es %f\n", valorB, resultFactorialB);
						printf("\n");
						break;
					}
				}
			}while(opcion != 5);

	return EXIT_SUCCESS;
}

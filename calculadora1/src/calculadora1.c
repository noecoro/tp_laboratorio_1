#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


//===============================================
int main (void){

    int respuesta;
    int opcion;

    int num1 = 0;
    int num2 = 0;

    int rSuma;
    int rResta;
    int rMultiplicacion;
    float rDivision;
    int rFactorialX = 0;
    int rFactorialY =0;

     int flag1 =0;
     int flag2=0;


    do{
         respuesta= utn_getNumero(&opcion,"\n=========CALCULADORA========\n MENU\n1.Ingresar 1er operando\n2.Ingresar 2do operando\n3.Calcular todas las operaciones \n4.Informar Resultado \n5.Salir\n", "\nOpcion INVALIDA",1, 5, 2);
        if (respuesta == 0)
        {
            switch (opcion)
            {


              case 1:
if(operandosIngresados(&num1,"Ingrese primer operando\n","Error",2)==0)
              {
                  printf("El primer operando es: %d\n ",num1);
              }
           else
           {
               printf("Error debe ingresar un nro\n");
           }


break;
case 2:
if(operandosIngresados(&num2,"Ingrese segundo operando\n","Error",2)==0)
              {
                  printf("El segundo operando es: %d\n ",num2);
              }

break;


                case 3 ://realizo las operaciones

                if (flag1==1&& flag2 == 1){
                    printf("Error\n ");
                 }
                    else{
                    rSuma = sumar(num1,num2);
                    rResta = restar (num1,num2);
                    rMultiplicacion = multiplicar (num1,num2);
                    rDivision = dividir (num1,num2);
                    rFactorialX = factorialX (num1);
                    rFactorialY = factorialY (num2);
               }
                break;
                case 4 :
                if(flag1== 0 && flag2==0){
                    printf ("%d + %d es: %d\n",num1, num2, rSuma);
                    printf("%d - %d es %d \n",num1, num2, rResta);
                    printf("%d * %d es %d \n",num1, num2, rMultiplicacion);}
                      if(num2==0)
            {
                printf("\nNo se puede dividir por 0, ingrese numero valido\n");
            }
            else{
                    printf("%d / %d es %.2f \n",num1, num2, rDivision);
            }
                printf("Factorial de %d es %d\n",num1, rFactorialX);
                printf("Factorial de %d es %d\n",num2, rFactorialY);

                  break;
                case 5 :{
                printf("\n");

                }
                 break;
            }
        }

    }while (opcion != 5);

    return 0;
}


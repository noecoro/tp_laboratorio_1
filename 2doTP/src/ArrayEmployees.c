/*
 * ArrayEmployees.c
 *
 *  Created on: 30 sept. 2020
 *      Author: NOELIA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define NAME_LEN 51
#define LASTNAME_LEN 51
//#include "ArrayEmployees.h"


typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}sEmployees;
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
//=================================0
/*Ejemplo uso:
r = initEmployees(arrayEmployees, ELEMENTS);*/
int initEmployees(sEmployees* list, int len)// error: unknown type name 'Employee' a mano
{
	int retorno = -1;// a modo de error
	int i;
	if(list != NULL && len >0)
	{// verifico parametros el array distinto de null y el limite mayor a cero
		retorno = 0;//ok
		for(i=0; i < len; i++)
		{// recorro el array
			list[i].isEmpty = 1;//en cada posicion del array.isEmpty 1 (verdader)si esta disponible en este caso seria p todos
		}

	}
return retorno;
}
//======================================================================================
/** NO ESTa en el pdf
 * brief buscar primer posicion vacia
 * param array de empleados
 * param limite del array de empleados
 * return
 */
int Employees_getEmptyIndex(sEmployees* array, int limite)
{
	int respuesta = -1;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;

	for(int i = 0; i < limite ; i ++)
	{
		if(array[i].isEmpty == 1)
		{
			respuesta = 1;
			break;
		}
	}
	}
	return respuesta;
}
//=============================================================

int addEmployee(sEmployees* list, int len,int index, int* id)//CORREGIR ELDOXIGEN
{
	int respuesta = -1;
	sEmployees bufferEmployee;
	if (list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
	{
		if(	utn_getName(" Ingrese nombre\n","\nError",bufferEmployee.name,2,NAME_LEN) == 0 &&
		utn_getName("\nIngrese apellido\n","\nError", bufferEmployee.lastName,2,LASTNAME_LEN) == 0 &&
		utn_getNumberFloat("\nIngrese sueldo\n","\nError",&bufferEmployee.salary,2,0,100000) == 0 &&
		utn_getNumberInt("\nIngrese sector entre 1 y 5\n1 - RRHH\n2 - Marketing\n3 - Sistemas\n4 - Ventas\n5 - Administracion\n","\nError Ingrese entre 1 y 5\n",&bufferEmployee.sector,1,5,2)==0)

		{
			respuesta = 0;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;

			list[index] = bufferEmployee;

			(*id)++;
		}
	}

	return respuesta;
}

//Ejemplo uso:
//r = addEmployee(arrayEmployees, ELEMENTS,id,name,lastName,salary,sector);

int menu()
{
	int opcion;
	printf("===EMPLEADOS===\n");
	printf(" 1- Alta\n");
	printf(" 2- Modificar\n");
	printf(" 3- Baja\n");
	printf(" 4- Informar\n");
	printf(" 5- Salir\n");
	utn_getNumberInt("Ingrese opcion\n","Error\n",&opcion,2,5,1);
	//fflush(stdin);
	//scanf("%d",&opcion);

	return opcion;
}
//===============
int employeePrintSimple(sEmployees* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty == 0)//NO ME DEJA USAR PUNTO SOLO FLECHA x defecto
	{
		retorno = 0;
		printf("ID: %d       %s      %s      %.2f      %d",pElemento->id,pElemento->name,pElemento->lastName,pElemento->salary,pElemento->sector);
	}

	return retorno;
}
//===============
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/

//==============================
int printEmployees(sEmployees* list, int length)
{
	int respuesta = -1;
	if( list != NULL && length >0)
	{
		respuesta = 0;
		for(int i = 0; i < length ; i++)
		{
			employeePrintSimple(&list[i]);
		}
	}


	return respuesta;
}
//==============================

/** \brief find an employee by id in returns the index position in array
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
* pointer received or employee not found]
*
*/
int findEmployeeById(sEmployees* list, int len, int id)// p case2id valor buscado list es array len es limite
{
	int respuesta = -1;
	 if(list != NULL && len > 0 && id >= 0)
	 {
		 respuesta = 0;
		 for(int i = 0; i < len ; i++)
		 {
			 if(list[i].id == id){
			 respuesta = i;
			 break;
		 }
	 }
}
	 return respuesta;
}
//==============================
/*
 *brief menu para modificar datos personales
 *\param array puntero al array de empleados
 *\limite  del array
 *\indice para modificar
 *\return -1 eror  0 ok
 * */


int modificarArray(sEmployees* array, int limite, int indice)
{
	int respuesta = -1;
	int menuParaModificarDatos;
	sEmployees bufferEmployees;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0)// isempty p ver si asi funciona
	{
		do
		{
			if(utn_getNumberInt("Que desea modificar\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n","Opcion invalida",&menuParaModificarDatos,1,4,2)==0)
		{
			switch(menuParaModificarDatos)
			{
			case 1:
				if(utn_getName("\n Ingrese nombre","\nError no se permite nros ni caracteres especiales",bufferEmployees.name,NAME_LEN,2)== 0)
				{
					bufferEmployees.id = array[indice].id;
					bufferEmployees.isEmpty = 0;
					strncpy(array[indice].name,bufferEmployees.name,NAME_LEN);
					printf("\nEl nombre ha sido modificado con exito");
				}
				break;

			case 2:
				if(utn_getName("\n Ingrese apellido","\nError no se permite nros ni caracteres especiales",bufferEmployees.lastName,LASTNAME_LEN,2)== 0)
								{
									bufferEmployees.id = array[indice].id;//QUEDA IGUAL Q 1
									bufferEmployees.isEmpty = 0;// SAME
									strncpy(array[indice].lastName,bufferEmployees.lastName,LASTNAME_LEN);
									printf("\nEl apellido ha sido modificado con exito");
								}
				respuesta = 0;

				break;

			case 3:
				if(utn_getNumberFloat("\nIngrese sueldo","\nError no se permite caracteres especiales",&bufferEmployees.salary,1,100000,2)== 0)
				{
				bufferEmployees.id = array[indice].id;//QUEDA IGUAL Q 1
				bufferEmployees.isEmpty = 0;// SAME,
				array[indice].salary = bufferEmployees.salary;
				printf("\nEl sueldo ha sido modificado con exito");
				}
				respuesta = 0;

				break;

			case 4:
				if(utn_getNumberInt("\n Ingrese sector entre 1 y 5\n1 - RRHH\n2 - Marketing\n3 - Sistemas\n4 - Ventas\n5 - Administracion\n","\nError Ingrese entre 1 y 5\n",&bufferEmployees.sector,1,5,2)== 0)
					{
					bufferEmployees.id = array[indice].id;//QUEDA IGUAL Q 1
					bufferEmployees.isEmpty = 0;// SAME
					array[indice].sector = bufferEmployees.sector;

					printf("\nEl sector ha sido modificado con exito");
					}
							respuesta = 0;
				break;
			}
		}
		}while(menuParaModificarDatos != 4);
	}
		return respuesta;
}


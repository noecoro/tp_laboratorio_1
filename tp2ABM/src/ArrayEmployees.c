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
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(sEmployees* list, int len,int index, int* id)//CORREGIR ELDOXIGEN
{
	int respuesta = -1;
	sEmployees bufferEmployee;
	if (list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
	{
		if(	utn_getName("\n Ingrese nombre","\nError",bufferEmployee.name,2,NAME_LEN) == 0 &&
		utn_getName("\nIngrese apellido","\nError", bufferEmployee.lastName,2,LASTNAME_LEN) == 0 &&

		utn_getNumberFloat("\nIngrese sueldo","\nError",&bufferEmployee.salary,0,100000,2) == 0 &&
		utn_getNumberInt("\nIngrese sector entre 1 y 5\n1 - RRHH\n2 - Marketing\n3 - Sistemas\n 4 - Ventas\n 5 - Administracion ","\nError Ingrese entre 1 y 5\n",&bufferEmployee.sector ,0,5,2)==0)

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


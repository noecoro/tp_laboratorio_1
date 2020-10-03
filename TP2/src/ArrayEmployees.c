

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define NAME_LEN 51
#define LASTNAME_LEN 51
#define QTY_EMPLOYEES 1000
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


int initEmployees(sEmployees* list, int len)
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
//NO esta en  pdf
/**
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
/**
* \brief Add in a existing list of employees the values received as parameters in the first empty position
* \param list sEmployee* Pointer to array of employees
* \param len int Array length
* \param index Position to be updated
* \param id Position where an employee will be registered
* \return Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(sEmployees* list, int len,int index, int* id)
{
	int respuesta = -1;
	sEmployees bufferEmployee;
	if (list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
	{
		if(	utn_getName(" Ingrese nombre\n","\nError",bufferEmployee.name,2,NAME_LEN) == 0 &&
		utn_getName("\nIngrese apellido\n","\nError", bufferEmployee.lastName,2,LASTNAME_LEN) == 0 &&
		utn_getFloat("\nIngrese sueldo\n","\nError",&bufferEmployee.salary,2,1,100000) == 0 &&
		utn_getNumberInt("\nIngrese sector entre 1 y 5\n\n1 - RRHH\n2 - Marketing\n3 - Sistemas\n4 - Ventas\n5 - Administracion\n","\nError Ingrese entre 1 y 5\n",&bufferEmployee.sector,1,5,2)==0)
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
//==================================================================
//muestra menu
int menu()
{
	int opcion;
	utn_getNumberInt("\n===EMPLEADOS===\n1- Alta\n2- Modificar\n3- Baja\n4- Informar\n5- Mostrar\n","Error\n",&opcion,1,6,2);

	return opcion;
}
//=======================================================
int employeePrintSimple(sEmployees* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty == 0)//NO ME DEJA USAR PUNTO SOLO FLECHA x defecto
	{
		retorno = 0;
		printf("%d   %s    %s      %.2f     %d",pElemento->id,pElemento->name,pElemento->lastName,pElemento->salary,pElemento->sector);
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
	int i = 0;
	if( list != NULL && length >0)
	{
		respuesta = 0;
		printf("*************LISTADO DE EMPLEADOS**************\n");
				printf("ID  NOMBRE  APELLIDO  SUELDO   SECTOR\n");

		for(i = 0; i < length ; i++)
		{
			if(list[i].isEmpty != 1)
			{
			employeePrintSimple(&list[i]);
		}
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
int findEmployeeById(sEmployees* list, int len, int id)
{//case2
	int respuesta = -1;
	 if(list != NULL && len > 0 && id >= 0)
	 {
		 respuesta = 0;
		 for(int i = 0; i < len ; i++)
		 {
			 if(list[i].id == id){
			 respuesta = i;
			 //podria agregar un print con encabezado
			 employeePrintSimple(&list[i]);
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
 *\return -1 error  0 ok
 * */
int modificarArrayEmployees(sEmployees* array, int limite, int indice)//case 2
{
	int respuesta = -1;
	int menuParaModificarDatos;
	sEmployees bufferEmployees;


	if(array != NULL && limite > 0 && indice < limite && indice >= 0)// isempty p ver si asi funciona
	{
		do
		{
			if(utn_getNumberInt("\n¿Que dato desea modificar?\n\n1. Nombre\n2. Apellido\n3. Sueldo\n4. Sector\n5. Salir\n","Opcion invalida",&menuParaModificarDatos,1,5,1)==0)
		{
			switch(menuParaModificarDatos)
			{
			case 1:

				if(utn_getName("\n Ingrese nombre\n","\nError no se permite nros ni caracteres especiales",bufferEmployees.name,2,NAME_LEN)== 0)
				{
					bufferEmployees.id = array[indice].id;
					bufferEmployees.isEmpty = 0;
					strncpy(array[indice].name,bufferEmployees.name,NAME_LEN);
					printf("\nEl nombre ha sido modificado con exito\n");
				}
				break;

			case 2:
				if(utn_getName("\n Ingrese apellido\n","\nError no se permite nros ni caracteres especiales",bufferEmployees.lastName,2,LASTNAME_LEN)== 0)
								{
									bufferEmployees.id = array[indice].id;//QUEDA IGUAL Q 1
									bufferEmployees.isEmpty = 0;// SAME
									strncpy(array[indice].lastName,bufferEmployees.lastName,LASTNAME_LEN);
									printf("\nEl apellido ha sido modificado con exito\n");
								}
				respuesta = 0;

				break;

			case 3:

				if(utn_getFloat("\nIngrese sueldo\n","\nError no se permite caracteres especiales",&bufferEmployees.salary,2,1,100000)== 0)
				{
				bufferEmployees.id = array[indice].id;//QUEDA IGUAL Q 1
				bufferEmployees.isEmpty = 0;// SAME,
				array[indice].salary = bufferEmployees.salary;
				printf("\nEl sueldo ha sido modificado con exito\n");
				}
				respuesta = 0;

				break;

			case 4:
				if(utn_getNumberInt("\n Ingrese sector entre 1 y 5\n1 - RRHH\n2 - Marketing\n3 - Sistemas\n4 - Ventas\n5 - Administracion\n","\nError Ingrese entre 1 y 5\n",&bufferEmployees.sector,1,5,2)== 0)
					{
					bufferEmployees.id = array[indice].id;//QUEDA IGUAL Q 1
					bufferEmployees.isEmpty = 0;// SAME
					array[indice].sector = bufferEmployees.sector;

					printf("\nEl sector ha sido modificado con exito\n");
					}
							respuesta = 0;
				break;
				//agrego case 5
			case 5:
			{
				printf("Salio\n");
				break;
			}
			}
		}
		}while(menuParaModificarDatos != 5);
	}
		return respuesta;
}
//======================================== para BAJA
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployees(sEmployees* array, int len,int id)
{
	int respuesta = -1;
	if(array != NULL && len > 0 && id < len && id >= 0 && array[id].isEmpty == 0)
	{
		array[id].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}
//========================================

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(sEmployees* list, int len, int order)//apellido y sector
{
	int respuesta = -1;
	int flagPswap;
	int auxComp;
	sEmployees buffer;
	if(list!= NULL && len > 0 )
	{
	do
	{
		flagPswap = 0;
		switch (order) {
		case 0:
		for(int i=0; i < len; i++)
		{
			if(list[i].isEmpty || list[i+1].isEmpty )
			{
				continue;
			}
			auxComp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
		if( auxComp > 0 ||( auxComp == 0 && list[i].sector > list[i+1].sector))
		{
			buffer = list[i];//burbujeo con swap
			list[i] = list[i+1];
			list[i+1] = buffer;
			flagPswap = 1;
		}
		}
		break;
	case 1:
		for(int i=0; i < len-1; i++)
			{
				if(list[i].isEmpty || list[i+1].isEmpty )
				{
					continue;
				}
				auxComp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
				if( auxComp < 0 ||( auxComp == 0 && list[i].sector < list[i+1].sector))
				{
					buffer = list[i];
					list[i] = list[i+1];
	   			    list[i+1] = buffer;
					flagPswap = 2;
				}
			}
		respuesta = 1;
		break;
		}
		len --;

	}while(flagPswap);
	}

	return respuesta;
}
//============================================
/**
* \brief calcula el salario total
* \param list puntero al array de empleados
* \param len limite
* \param pSalarioTotal puntero
* \return Return (-1)  Error - (0)  Ok
*
*/
int salarioTotal(sEmployees* list, int len, float* pSalarioTotal)
{
	int respuesta = -1;
	float auxSalarioTotal = 0;
		if(list != NULL && len > 0)
		{
			for(int i=0; i < len; i++)
				{
				    if(list[i].isEmpty == 0)//siempre is empty
                    {
				    	 auxSalarioTotal += list[i].salary;// y de donde
                    }
				}
			*pSalarioTotal =  auxSalarioTotal;
			respuesta = 0;
		}
	return respuesta;
}
//============================================
/**
* \brief cuenta los empleados que se registraron luego obtener el promedio del salario
* \param sEmployees* list  puntero al array de empleados
* \param int len  array limite
* \param float salarioTotal suma de los sueldos
* \param float* pPromedioSalario puntero al promedio de los salarios
* \return Return (-1) Error  - (0)  Ok
*
*/
int cantEmpleadosYpromedio(sEmployees* list, int len, float salarioTotal, float* pPromedioSalario)
{
	int respuesta = -1;
	int cantEmpleados = 0;
	int auxPromedio;

		if(list != NULL && len > 0)
		{
			for(int i=0; i < len; i++)
			{
				if(list[i].isEmpty == 0)
				{
					cantEmpleados++;
				}
			}
			auxPromedio = salarioTotal / cantEmpleados;
			*pPromedioSalario= auxPromedio;
			respuesta = 0;
		}
	return respuesta;
}
//=======================================================
/**
* \brief  empleados que superan el sueldo promedio
* \param  sEmployees*list puntero al array de empleados
* \param  int  len array
* \param promedio auxiliar para Promedio
* \param qtyEmployeesExceedAverageSalary Pointer of the number of employees exceeding the average salary
* \return Return (-1) if Error [Invalid length or NULL pointer or if can't calculate the total salary] - (0) if Ok
*
*/
int empleadosSuperanSp(sEmployees* list, int len, float promedio, int* empleadosQsuperanSueldoP)
{
	int respuesta= -1;
    int empQsuperanSueldoP = 0;
		if(list != NULL && len > 0)
		{
			for(int i=0; i < len; i++)
				{
				    if(list[i].isEmpty == 0 && list[i].salary > promedio)
                    {
				    	empQsuperanSueldoP++;
                    }
				}
			*empleadosQsuperanSueldoP = empQsuperanSueldoP;
			 respuesta = 0;
		}
	return  respuesta;
}
//=======================================================
/**
* \brief menu para mostrar informes
* \param sEmployee* list  puntero al array de empleados
* \param int len Array
* \return Return (-1)  (0)  Ok
*
*/
int listadoMenuEmpl(sEmployees* list, int lentgh)
{
	int respuesta = -1;
	int opcion;
	int opcionAyD;//ascendente y descendente
	float sueldoTotal;
	float sueldoPromedio;
	int empleadosQSuperanSueldoP;

	if(list != NULL && lentgh > 0)
	{
		do
		{
			if ((utn_getNumberInt ("\n¿Que informe desea ver?\n\n"
											"1. Lista de empleados alfabeticamente por apellido y sector.\n"
											"2. Total y promedio de los sueldos y cuantos empleados superan el promedio .\n"
											"3. salir\n\n",
											"Error opcion invalida\n\n",&opcion, 1, 3, 2))==0)
			{
				switch(opcion)
				{
					case 1:
						if ((utn_getNumberInt ("\n 0 ascendente - 1 descendente: ",
                                                         "\nError opcion invalida\n\n",&opcionAyD, 0, 1, 2))==0)
						{
							sortEmployees(list,QTY_EMPLOYEES,opcionAyD);
							printEmployees(list, QTY_EMPLOYEES);
						}
						respuesta  = 0;

						break;
					case 2:
						salarioTotal(list,QTY_EMPLOYEES,&sueldoTotal);
						printf("\nSueldo total: %.2f\n\n",sueldoTotal);

						cantEmpleadosYpromedio(list,QTY_EMPLOYEES,sueldoTotal,&sueldoPromedio);
						printf("Sueldo promedio: %.2f\n\n",sueldoPromedio);

						empleadosSuperanSp(list,QTY_EMPLOYEES,sueldoPromedio,&empleadosQSuperanSueldoP);
						printf("Empleados que superan sueldo promedio: %.d\n\n",empleadosQSuperanSueldoP);
						respuesta  = 0;

						break;
				}
			}
		}while (opcion!=3);
	}
	return respuesta;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define QTY_EMPLOYEES 1000// cant max de empleados
//#define NAME 51
//#define LASTNAME 51
int main(void) {
	setbuf(stdout, NULL);
	sEmployees arrayEmployees[QTY_EMPLOYEES];// p inicializar
	int idEmployees = 0;//p alta
//	int opcion;//p menu pero funciono con otra func menu
	int auxIndice;//p alta
	int auxId;//p modif case2

	initEmployees(arrayEmployees,QTY_EMPLOYEES);

	do
	{

	//if((utn_getNumberInt( "Ingrese opcion\n1-Alta\n2-Modificacion\n3-Baja\n4-informar\n5-Salir","Error ingrese opcion correcta",&opcion,2,1,5))==0)

	switch (menu())
	{
	case 1://ALTA CARGAR UN CLIENTE nombre apellido sueldo y sector
		auxIndice = Employees_getEmptyIndex(arrayEmployees,QTY_EMPLOYEES);
		if(auxIndice >= 0)
		{
		//alta
			if(addEmployee(arrayEmployees,QTY_EMPLOYEES,auxIndice,&idEmployees)==0)
				{
				printf("\n Carga exitosa");
				}
		}
			else
				{
			printf("\n No hay lugar disponible");
				}


		break;

	case 2://MODIFICAR agregar bandera p ingresar x posible msj error no 2 sin 1
		printEmployees(arrayEmployees,QTY_EMPLOYEES);
		if(utn_getNumberInt("Ingrese ID que desea modificar\n","Error ID invalido\n",&auxId,0,idEmployees,2)==0)
		{
			auxIndice = findEmployeeById(arrayEmployees,QTY_EMPLOYEES, auxId);
		if(auxIndice >= 0 && modificarArray(arrayEmployees,QTY_EMPLOYEES,auxIndice) == 0)
		{
			printf("\n Modificacion realizada con exito");
		}
		}
		else
		{
			printf("\n No puede ingresar a esta opcion sin haber registrado a un empleado en la opcion 1");
		}

			break;

	case 3://BAJA
		break;

	case 4://INFORMAR sub menu listado de emplead alfab x ape y sector con utn_number y luego con 2 case o ifs
		break;

	case 5://SALIR
		break;

	}

	}while(menu() !=5);//si un par o sin? ()


	return EXIT_SUCCESS;
}

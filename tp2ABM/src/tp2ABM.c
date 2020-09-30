
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define QTY_EMPLOYEES 1000// cant max de empleados
//#define NAME 51
//#define LASTNAME 51
//===============================================
int main(void)
{
setbuf(stdout, NULL);
sEmployees arrayEmployees[QTY_EMPLOYEES];
//sEmployees arrayEmployeesName[NAME];
//sEmployees arrayEmployeesLastName[LASTNAME];
//int empSalary;

int idEmployees = 0;
int opcion;
int auxIndice;
//int indice = 0;
//int flagCase1 = 1;


//_________________________
if (initEmployees(arrayEmployees,QTY_EMPLOYEES) == 0)
{
	printf("Initialized successfully\n");
}
do
{
	utn_getNumberInt("Ingrese opcion\n1-Alta\n2-Modificacion\n3-Baja\n4-informar\n5-Salir","Error ingrese opcion correcta",&opcion,2,1,5);
switch (opcion)
{
case 1://ALTA CARGAR UN CLIENTE nombre apellido sueldo
	auxIndice = Employees_getEmptyIndex(arrayEmployees,QTY_EMPLOYEES);
	if(auxIndice == 0)
	{//alta
if(addEmployee(arrayEmployees,QTY_EMPLOYEES,auxIndice,&idEmployees)==0)
{
printf("\n Carga exitosa");
}
else
{
	printf("\n No hay lugar disponible");
}
	}
	break;

case 2://MODIFICAR
	break;

case 3://BAJA
	break;

case 4://INFORMAR sub menu listado de emplead alfab x ape y sector con utn_number y luego con 2 case o ifs
	break;

case 5://SALIR
	break;

}

}while(opcion !=5);


	return EXIT_SUCCESS;
}
//===============================0






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "ArrayEmployees.h"
#define QTY_EMPLOYEES 1000

int main(void) {
	setbuf(stdout, NULL);
	sEmployees arrayEmployees[QTY_EMPLOYEES];
	int idEmployees = 0;//p alta

	int auxIndice;//p alta

	int auxId;//p modif case2

	//int flagCase = 0;
	initEmployees(arrayEmployees,QTY_EMPLOYEES);

	do
	{

	switch (menu())
	{
	case 1:
		auxIndice = Employees_getEmptyIndex(arrayEmployees,QTY_EMPLOYEES);
		if(auxIndice >= 0)
		{
		//alta
			if(addEmployee(arrayEmployees,QTY_EMPLOYEES,auxIndice,&idEmployees)==0)
				{
				printf("\n Carga exitosa\n\n");

				}
		}
			else
				{
			printf("\n No hay lugar disponible");
				}


		break;

	case 2:
		//printEmployees(arrayEmployees,QTY_EMPLOYEES);
		if(utn_getNumberInt("\n\nIngrese ID que desea modificar\n","Error ID invalido\n",&auxId,0,idEmployees,2)==0)
		{
			auxIndice = findEmployeeById(arrayEmployees,QTY_EMPLOYEES, auxId);
		if(auxIndice >= 0 &&
				modificarArrayEmployees(arrayEmployees,QTY_EMPLOYEES,auxIndice) == 0)
		{
			printf("\n Modificacion realizada con exito\n");
		}
		}
		/*else
		{
			printf("\n No puede ingresar a esta opcion sin haber registrado a un empleado en la opcion 1");
		}
*/
			break;

	case 3://BAJA
			//if(flagCase){
		printEmployees(arrayEmployees,QTY_EMPLOYEES);

			//=========
			if(utn_getNumberInt("\n\nIngrese ID que desea dar de baja\n","Error ID invalido\n",&auxId,0,idEmployees,0)==0)
			{
				auxIndice = findEmployeeById(arrayEmployees,QTY_EMPLOYEES, auxId);
			if(auxIndice >= 0 &&
					removeEmployees(arrayEmployees,QTY_EMPLOYEES,auxIndice) == 0)
			{
				printf("\n Baja realizada con exito\n");
			}
			}
//}
			/*else
			{
				printf("\n No puede ingresar a esta opcion sin haber registrado a un empleado en la opcion 1");
			}*/

		break;

	case 4://INFORMAR sub menu listado de emplead alfab x ape y sector
		//if(flagCase)
			//{
				listadoMenuEmpl(arrayEmployees,QTY_EMPLOYEES);
			/*}
		else
			{
				printf("Error. No puede ingresar a esta opcion sin haber registrado a un empledo (alta)");
			}*/
		break;

	case 5:
		printEmployees(arrayEmployees,QTY_EMPLOYEES);
		break;
	}

	}while(menu() !=6);


	return EXIT_SUCCESS;
}

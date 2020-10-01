/*
 * ArraysEmployees.h
 *
 *  Created on: 30 sept. 2020
 *      Author: NOELIA
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct{// si dejo llave abajo tira error
 int id;
 char name[NAME_LEN];
 char lastName[LASTNAME_LEN];
 float salary;
 int sector;
 int isEmpty;
}sEmployees;
//========================================
int initEmployees(sEmployees* list, int len);
//========================================
int Employees_getEmptyIndex(sEmployees* array, int limite);
//========================================
int addEmployee(sEmployees* list, int len,int index, int* id);
int menu();
//========================================
int findEmployeeById(sEmployees* list, int len, int id);
//========================================
int printEmployees(sEmployees* list, int length);
//========================================
int employeePrintSimple(sEmployees* pElemento);
//========================================
int modificarArray(sEmployees* array, int limite, int indice);


#endif /* ARRAYEMPLOYEES_H_ */

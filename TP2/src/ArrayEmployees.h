

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
//========================================
int menu();
//========================================
int findEmployeeById(sEmployees* list, int len, int id);
//========================================
int printEmployees(sEmployees* list, int length);
//========================================
int employeePrintSimple(sEmployees* pElemento);
//========================================
int modificarArrayEmployees(sEmployees* array, int limite, int indice);
//========================================
int removeEmployees(sEmployees* array, int len,int id);
//========================================
int salarioTotal(sEmployees* list, int len, float* pSalarioTotal);
//========================================
int sortEmployees(sEmployees* list, int len, int order);
//========================================
int cantEmpleadosYpromedio(sEmployees* list, int len, float salarioTotal, float* pPromedioSalario);
//========================================
int empleadosSuperanSp(sEmployees* list, int len, float promedio, int* empleadosQsuperanSueldoP);
//========================================
int listadoMenuEmpl(sEmployees* list, int lentgh);
#endif /* ARRAYEMPLOYEES_H_ */

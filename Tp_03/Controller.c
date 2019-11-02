#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee) {
	int ret = 0;
	FILE* pFile;
	pFile = fopen(path, "r");
	ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);
	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee) {
	int ret = 0;
	FILE* pFile;
	pFile = fopen(path, "rb");
	ret = parser_EmployeeFromText(pFile, pArrayListEmployee);
	fclose(pFile);
	return ret;
}

/** \brief Obtiene el mayor id del LinkedList y lo carga en la estructura empleado.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_lastIdEmployee(LinkedList* pArrayListEmployee) {
	int ret = -1;
	Employee* auxEmployee;
	int  bufferId;
	int auxId = -1;
	int i, len;

	if(pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);
		for(i = 0; i < len; i++) {
			auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee,&bufferId);
			if(bufferId > auxId) {
				auxId = bufferId;
			}
		}
		employe_idInit(auxId);
		ret = 0;
	}
	return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee) {
  int ret = -1;
  char auxNombre[256];
  int auxHorasTrabajadas;
  int auxSueldo;
  Employee* auxEmployee;
  auxEmployee = employee_new();
  if(pArrayListEmployee != NULL && auxEmployee != NULL) {

    if(utn_getName("Ingrese el nombre", "Error. Ingrese un nombre valido", 1, 127, 2, auxNombre) == 0 && utn_getUnsignedInt("Ingrese la cantidad de horas trabajadas", "Error. Ingrese un valor valido", 1, sizeof(auxHorasTrabajadas), 0, 200, 2, &auxHorasTrabajadas) == 0 && utn_getUnsignedInt("Ingrese el sueldo", "Error. Ingrese un valor valido", 1, sizeof(auxSueldo), 1, 50000, 2, &auxSueldo) == 0) {
      employee_setId(auxEmployee, employee_idGenerator());
      employee_setNombre(auxEmployee, auxNombre);
      employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
      employee_setSueldo(auxEmployee, auxSueldo);

      ll_add(pArrayListEmployee, auxEmployee);
    }
  }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee) {
	int ret = -1;
	Employee* auxEmployee;
	int auxId;
	char auxNombre[4096];
	int auxHorasTrabajadas;
	int auxSueldo;
	int i, len;
	if(pArrayListEmployee != NULL) {
		if(ll_len(pArrayListEmployee) > 0) {
			len = ll_len(pArrayListEmployee);
			for(i = 0; i < len; i++) {
				auxEmployee = ll_get(pArrayListEmployee, i);
				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxNombre);
				employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
				employee_getSueldo(auxEmployee, &auxSueldo);
				printf("%d\n%s\n%d\n%d\n", auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
			}
			ret = 0;
		} else {
			printf("No existen registros cargados");
		}
		return ret;
	}
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arcade.h"


int controller_ListArcades2(LinkedList* pArrayListArcades);


int arcade_printArcade(eArcade* this);


/** \brief La funci�n se encarga de comparar los datos recibidos por par�metro.
 *
 * \param pFirstArcade puntero a los datos de un Arcade
 * \param pSecondArcade puntero a los datos de un Arcade
 * \return int Devuelve TRUE si se debe hacer un swap o FALSE si sucede lo contrario.
 *
 */
int compareArcades(eArcade* pFirstArcade,eArcade* pSecondArcade,int orden);
/** \brief La funci�n se encarga de contar la cantidad de datos en los archivos para llevar un control de cual es la �ltima ID registrada.
 *
 * \param pArrayListeArcade lista de punteros
 * \return int Devuelve el contador de datos registrados en el archivo.
 *
 */

int controller_dataCount(LinkedList* pArrayListeArcade);

/** \brief La funci�n se encarga de desplegar y utilizar un men� de modificaciones para los datos del empleado.
 *
 * \param respuestaUsuario contiene la respuesta ingresada por el usuario para usarla en el switch.
 * \param ArcadeMod puntero con la direcci�n de memoria a los datos que queremos modificar.
 * \return int Retorna true si los par�metros son correctos o false en caso contrario.
 *
 */

int controller_modMenu(int respuestaUsuario,eArcade* eArcadeMod, LinkedList* pArrayListeArcade);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListeArcade);


/** \brief Alta de arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_addArcade(LinkedList* pArrayListeArcade);
/** \brief Modificar datos de arcade
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_editArcade(LinkedList* pArrayListeArcade);
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_removeArcade(LinkedList* pArrayListeArcade);
/** \brief Listar arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
//int controller_ListArcade(LinkedList* pArrayListeArcade);
/** \brief genera una lista mencioanando los nombres todos los juegos registrados
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_ListaDejuegosArcade(LinkedList* pArrayListeArcade);




/** \brief Ordenar arcades
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */

int controller_sortArcade(LinkedList* pArrayListeArcade);

/** \brief Guarda los datos de los arcade en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeArcade LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListeArcade);
int controller_saveAsBinary(char* path , LinkedList* pArrayListeArcade);

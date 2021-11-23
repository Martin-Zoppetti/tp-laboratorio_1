/*
 men�:
1) LEER ARCADES DESDE ARCHIVO CSV Se lee de archivo arcades.csv provisto, la lista de arcades del sistema, y se cargan en una LinkedLIst.
2) INCORPORAR ARCADE Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad m�xima de fichas, Nombre del sal�n al que pertenece y  nombre  del juego que contiene (hasta 63 caracteres). Se generar� un ID �nico para gestionar los ARCADE. Actualizar el archivo CSV con el arcade agregado
3) MODIFICAR ARCADE Se imprime la lista de arcades con los ID y datos que lo componen. Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene. Al elegir modificar el juego que contiene este arcade, mostrar en un listado los  nombres de los juegos ya cargados en el sistema y se permitir� ingresar un texto con el nombre del nuevo juego. Actualizar el archivo CSV con el arcade modificado.
4) ELIMINAR ARCADE Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la informaci�n del sal�n y el juego que contiene. Se ingresa un ID y previo a dar de baja se deber� solicitar confirmaci�n, imprimiendo el arcade a dar de baja y confirmando si est� seguro dar de baja est� mismo. Actualizar el archivo CSV con el arcade aeliminado.
5) IMPRIMIR ARCADES ordenados por nombre de juego Se imprime la lista de arcades con ID, y sus datos.
6) Generar archivo con JUEGOS Se generar� un archivo .txt con los nombres de los juegos (uno por linea) sin repetir.
7) Generar un archivo con arcades �Multijugador� (mas de 1 jugador) Se generar� un archivo �multijugador.csv� con el mismo formato que arcades.csv (incluida la cabecera), que contenga solo los arcades que tengan mas de 1 jugador.
8) Actualizar cantidad de fichas La empresa compr� una actualizacion para que los arcades soporten el doble de fichas, por lo que debe actualizarse el valor de fichas en el archivo. Al elegir esta opcion, se duplicar� el valor de cantidad de fichas de todos los arcades.


1) LEER ARCADES DESDE ARCHIVO CSV.
 2) INCORPORAR ARCADE.
 3) MODIFICAR ARCADE.
 4) ELIMINAR ARCADE.
5) IMPRIMIR ARCADES
6) Generar archivo con JUEGOS.
 7) Generar un archivo con arcades �Multijugador� (mas de 1 jugador).
 8) Actualizar cantidad de fichas.

 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "ingresos.h"
#include "LinkedList.h"


#define VERDADERO 1
#define FALSO 0
#define Tamano 128
#define reintentos 5

int main(void) {
setbuf(stdout,NULL);
LinkedList* listaArcades = ll_newLinkedList();
int auxRespuesta;
int respuesta;
int banderaCargaDatosTexto = FALSO;

do{
auxRespuesta=UTN_ingresoIntReintentosMinMax(&respuesta,
		"----------------------------------------Menu----------------------------------------\n \n"
		" Bienvenido.\n"
		" Selecciones una opcion: \n"
		" 1) LEER ARCADES DESDE ARCHIVO CSV. \n"
		" 2) INCORPORAR ARCADE. \n"
		" 3) MODIFICAR ARCADE. \n"
		" 4) ELIMINAR ARCADE.\n"
		" 5) IMPRIMIR ARCADES. \n"
		" 6) Generar archivo con JUEGOS. \n"
		" 7) Generar un archivo con arcades �Multijugador� (mas de 1 jugador).\n"
		" 8) Actualizar cantidad de fichas. \n"
		" 9) Salir del programa. \n"
		"Opcion: \n","Error, ingreso un valor incorrecto,intente nuevamente", 1, 8, reintentos);

if(auxRespuesta!=FALSO){

		switch (respuesta) {


		case 1:



			if(controller_loadFromText("arcades.csv", listaArcades)==VERDADERO)
				{
				eArcade* auxi;
				auxi=ll_get(listaArcades, 1);
				printf("imprimio %d",auxi->cantidadMaximaDeFichas);
					puts("�Operacion exitosa!");

					banderaCargaDatosTexto = VERDADERO;
				}
		/*1) LEER ARCADES DESDE ARCHIVO CSV
		 *  Se lee de archivo arcades.csv provisto,
		 *  la lista de arcades del sistema, y se cargan en una LinkedLIst.
	*/
			break;
		case 2:
			if(banderaCargaDatosTexto == VERDADERO )
					{ printf("hasta aca todo bien");
						controller_addArcade(listaArcades);
					}
					else{
						puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
					}
			/*2)INCORPORAR ARCADE
			 * Se da de alta un arcade
			 * Se generar� un ID �nico para gestionar los ARCADE.
			 * Actualizar el archivo CSV con el arcade agregado
			 */
			break;

		case 3:
			if(banderaCargaDatosTexto == VERDADERO)
					{ 	controller_ListArcades2(listaArcades);
						controller_editArcade(listaArcades);
					}
					else{
						puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
					}
			/*3) MODIFICAR ARCADE
			 * Se imprime la lista de arcades con los ID y datos que lo componen.
			 * Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
			 * Al elegir modificar el juego que contiene este arcade,
			 * mostrar en un listado los  nombres de los juegos ya cargados en el sistema
			 * y se permitir� ingresar un texto con el nombre del nuevo juego.
			 * Actualizar el archivo CSV con el arcade modificado.
			 */
			break;

		case 4:
			if(banderaCargaDatosTexto == FALSO)
						{ controller_ListArcades2(listaArcades);
							controller_removeArcade(listaArcades);
						}
						else{
							puts("Aun no realiza la carga de datos por archivo, vuelva al menu");
						}
			/*4) ELIMINAR ARCADE
			 * Se imprime la lista de arcades con sus ID y datos que lo componen,
			 * junto con la informaci�n del sal�n y el juego que contiene.
			 * Se ingresa un ID y previo a dar de baja se deber� solicitar confirmaci�n,
			 * imprimiendo el arcade a dar de baja y confirmando si est� seguro dar de baja est� mismo.
			 * Actualizar el archivo CSV con el arcade ya eliminado.
			 */
			break;

		case 5:
			/*5) IMPRIMIR ARCADES
			 *  ordenados por nombre de juego
			 *   Se imprime la lista de arcades con ID, y sus datos.
			 */
			break;

		case 6:
			/*6) Generar archivo con JUEGOS
			 *  Se generar� un archivo .txt con los nombres de los juegos (uno por linea) sin repetir.
			 */
			break;

		case 7:
			/*7)Generar un archivo con arcades �Multijugador� (mas de 1 jugador)
			 *  Se generar� un archivo �multijugador.csv� con el mismo formato que arcades.csv (incluida la cabecera),
			 *  que contenga solo los arcades que tengan mas de 1 jugador.
			 */
			break;

		case 8:
			/*8)Actualizar cantidad de fichas
			 * La empresa compr� una actualizacion para que los arcades soporten el doble de fichas,
			 * por lo que debe actualizarse el valor de fichas en el archivo. Al elegir esta opcion,
			 * se duplicar� el valor de cantidad de fichas de todos los arcades.
			 *
			 */
			break;



		case 9:
			puts("Fin del programa.");
			break;
		}



}
else{
	printf("Supero la cantidad de reintentos, reinicie el programa.\n");
}


} while (respuesta != 9);






	return EXIT_SUCCESS;
}

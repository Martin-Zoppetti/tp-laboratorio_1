
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "arcade.h"
#include "parser.h"
#define TRUE 1
#define FALSE 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int
 *
 */
/*
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayListArcade)
{
	//id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game
	eArcade* pArcadeAuxiliar;
	int retorno = FALSE;
	if(pFile != NULL && pArrayListArcade != NULL)
	{

		char nacionalidad[256];
		int tipoDeSonido [256];
		int idArcade[256];
		char nombreDelSalon[256];
		int cantidadDeJugadores[256];
		int cantidadMaximaDeFichas[256];
		char nombreDelJuego[256];
		char auxTipo[20];
		int auxInt;

		if(pFile!=NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoDeSonido,cantidadDeJugadores,cantidadMaximaDeFichas,nombreDelSalon,nombreDelJuego);
			do{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idArcade,nacionalidad,tipoDeSonido,cantidadDeJugadores,cantidadMaximaDeFichas,nombreDelSalon,nombreDelJuego)==7)
				{
					if(stricmp(tipoDeSonido, "stereo") == 0)
					{
						auxInt = Tipo_STEREO;
						sprintf(auxTipo, "%d", auxInt);
					}
					else if(stricmp(tipoDeSonido, "mono") == 0)
					{
						auxInt = Tipo_MONO;
						sprintf(auxTipo, "%d", auxInt);
					}
					else
					{
						retorno = FALSE;
						break;
					}

					pArcadeAuxiliar = eArcade_newParametros(auxTipo, idArcade, cantidadDeJugadores, cantidadMaximaDeFichas, nombreDelSalon, nacionalidad, nombreDelJuego);
					if(pArcadeAuxiliar != NULL)
					{
						if(controller_find(list, atoi(id)) == FALSE)
						{
							ll_add(list, pArcadeAuxiliar);
							retorno = TRUE;
						}
						else
						{
							newId = arc_getMaxId("data/idMax.txt", list);
							arc_setId(pArcadeAuxiliar, newId);
							ll_add(list, pArcadeAuxiliar);
						}
					}
					else
					{
						status = FALSE;
					}
				}

			}while(feof(pFile) == 0 && status != FALSE);
		}
	}
	return retorno;
}
*/
int parserArcades(FILE* pFile, LinkedList* list)
{
	int status = FALSE;
	char id[256];
	char nacionalidad[256];
	char auxTipo[256];
	char cantidadDeJugadores[256];
	char cantidadMaximaDeFichas[256];
	char nombreDelSalon[256];
	char nombreDelJuego[256];
	eArcade* aux;

	if(pFile != NULL && list != NULL)
	{

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id , nacionalidad, auxTipo, cantidadDeJugadores, cantidadMaximaDeFichas, nombreDelSalon, nombreDelJuego);
		do{

		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id , nacionalidad, auxTipo, cantidadDeJugadores, cantidadMaximaDeFichas, nombreDelSalon, nombreDelJuego) == 7)
		{
			printf("%s,%s,%s,%s,%s,%s,%s",auxTipo, id, cantidadDeJugadores, cantidadMaximaDeFichas, nombreDelSalon, nacionalidad, nombreDelJuego);

			aux = eArcade_newParametros(auxTipo, id, cantidadDeJugadores, cantidadMaximaDeFichas, nombreDelSalon, nacionalidad, nombreDelJuego);

			if(aux != NULL)
			{
			ll_add(list, aux);
			status = TRUE;
			}

			else
			{
			status = FALSE;
			}
			}

		}while(feof(pFile) == 0 && status != FALSE);
	}
	else
	{
		status = FALSE;
	}

	return status;

}

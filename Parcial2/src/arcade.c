#include "arcade.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Ingresos.h"


	/*
	 * 	char nacionalidad[nombreMaximoArcade];
	int tipoDeSonido;
	int idArcade;
	char nombreDelSalon[nombreMaximoArcade];
	int cantidadDeJugadores;
	int cantidadMaximaDeFichas;
	char nombreDelJuego[nombreMaximoArcade];
	 */
//(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)



eArcade* eArcade_new()
{
	eArcade* peArcade = malloc(sizeof(eArcade));
	return peArcade;
}

void eArcade_delete(eArcade* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

eArcade* eArcade_newParametros(char* tipoDeSonido,char* idArcade, char* cantidadDeJugadores,char* cantidadMaximaDeFichas,char* nombreDeSalon,char* nacionalidad, char* nombreDelJuego)
{

	int auxID;
	int auxtipoDeSonido;
	int auxcantidadDeJugadores;
	int auxCantidadMaximaDeFichas;


	eArcade* retornoAuxArcade;
	retornoAuxArcade = eArcade_new();

	if(idArcade != NULL &&  tipoDeSonido != NULL && cantidadDeJugadores != NULL && cantidadMaximaDeFichas != NULL)
	{
		if(retornoAuxArcade!=NULL && idArcade!=NULL && cantidadDeJugadores != NULL && cantidadMaximaDeFichas != NULL && idArcade != NULL && tipoDeSonido != NULL )
		{

	if(strcmp(tipoDeSonido, "STEREO") == 0)
							{
								auxtipoDeSonido = 1;
							}
							else if(strcmp(tipoDeSonido, "MONO") == 0)
							{
								auxtipoDeSonido = 0;
							}


			auxID = atoi(idArcade);
			auxcantidadDeJugadores = atoi(cantidadDeJugadores);
			auxCantidadMaximaDeFichas = atoi(cantidadMaximaDeFichas);



			if(retornoAuxArcade != NULL)
			{

				int ida;
				char tipoaux[256];
				int canfi;
				int cantJ;
				char nombs[256];
				char nombj[256];
				char naci[256];






				eArcade_setId(retornoAuxArcade, auxID);
				eArcade_setNacionalidad(retornoAuxArcade, nacionalidad);
				eArcade_setNombreDelSalon(retornoAuxArcade, nombreDeSalon);
				eArcade_setNombreDelJuego(retornoAuxArcade, nombreDelJuego);
				eArcade_setTipoDeSonido(retornoAuxArcade, auxtipoDeSonido);
				eArcade_setCantidadDeJugadores(retornoAuxArcade,auxcantidadDeJugadores);
				eArcade_setCantidadMaximaDeFichas(retornoAuxArcade,auxCantidadMaximaDeFichas);

				eArcade_getId(retornoAuxArcade, &ida);
				eArcade_getNacionalidad(retornoAuxArcade, naci);
				eArcade_get(retornoAuxArcade, nombs);
				eArcade_getNombreDelJuego(retornoAuxArcade, nombj);
				eArcade_getTipoDeSonido(retornoAuxArcade, tipoaux);
				eArcade_getCantidadDeJugadores(retornoAuxArcade, &cantJ);
				eArcade_getCantidadMaximaDeFichas(retornoAuxArcade, &canfi);


			}
		}
		else{

			retornoAuxArcade = NULL;
		}
	}
	return retornoAuxArcade;
}

int eArcade_setId(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->idArcade = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getId(eArcade* this,int* id)
{
	int retorno = FALSE;
	if(this != NULL && id != NULL)
	{
		*id = this->idArcade;
		retorno = TRUE;
	}
	else{
		printf("error en get id");
	}
	return retorno;
}

int eArcade_setTipoDeSonido(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->tipoDeSonido = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getTipoDeSonido(eArcade* this,char* sonido)
{
	int retorno = FALSE;
	if(this != NULL && sonido != NULL)
	{
		if(this->tipoDeSonido==1){
		strcpy(sonido,"stereo");
		}
		else{
			strcpy(sonido,"mono");
		}


		retorno = TRUE;
	}
	else{
		printf("error en get sonido");
	}
	return retorno;
}

int eArcade_setCantidadDeJugadores(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->cantidadDeJugadores = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getCantidadDeJugadores(eArcade* this,int* id)
{
	int retorno = FALSE;
	if(this != NULL && id != NULL)
	{
		*id = this->cantidadDeJugadores;
		retorno = TRUE;
	}

	else{
		printf("error en get cantijuego");
	}return retorno;
}

int eArcade_setCantidadMaximaDeFichas(eArcade* this,int id)
{
	int retorno = FALSE;
	if(this != NULL && id >= 0)
	{
		this->cantidadMaximaDeFichas = id;
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getCantidadMaximaDeFichas(eArcade* this,int* id)
{
	int retorno = FALSE;
	if(this != NULL && id != NULL)
	{
		*id = this->cantidadMaximaDeFichas;
		retorno = TRUE;
	}
	else{
		printf("error en get canti fichas");
	}
	return retorno;
}

int eArcade_setNacionalidad(eArcade* this,char* Nacionalidad)
{
	int retorno = FALSE;
	if(this != NULL && Nacionalidad != NULL)
	{
		strcpy(this->nacionalidad,Nacionalidad);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getNacionalidad(eArcade* this,char* Nacionalidad)
{
	int retorno = FALSE;
	if(this != NULL && Nacionalidad != NULL)
	{
		strcpy(Nacionalidad,this->nacionalidad);
		retorno = TRUE;
	}
	else{
		printf("error en get nacio");
	}
	return retorno;
}

int eArcade_setNombreDelSalon(eArcade* this,char* nombreDelSalon)
{
	int retorno = FALSE;
	if(this != NULL && nombreDelSalon != NULL)
	{
		strcpy(this->nombreDelSalon,nombreDelSalon);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_get(eArcade* this,char* NombreDelSalon )
{
	int retorno = FALSE;
	if(this != NULL && NombreDelSalon != NULL)
	{
		strcpy(NombreDelSalon,this->nombreDelSalon);
		retorno = TRUE;
	}
	else{
			printf("error en get salon");
		}

	return retorno;
}

int eArcade_setNombreDelJuego(eArcade* this,char* nombreDelJuego)
{
	int retorno = FALSE;
	if(this != NULL && nombreDelJuego != NULL)
	{
		strcpy(this->nombreDelJuego,nombreDelJuego);
		retorno = TRUE;
	}
	return retorno;
}

int eArcade_getNombreDelJuego(eArcade* this,char* NombreDelJuego)
{
	int retorno = FALSE;
	if(this != NULL && NombreDelJuego != NULL)
	{
		strcpy(NombreDelJuego ,this->nombreDelJuego);
		retorno = TRUE;
	}else{
		printf("error en get nombre juego");
	}
	return retorno;
}

int eArcade_findById(LinkedList *pArrayListArcade,int id)
{
	int retorno = -1;
	int tamanoLista;
	if(id>=0 && pArrayListArcade!=NULL)
	{
		tamanoLista = ll_len(pArrayListArcade);
		for(int i=0;i<tamanoLista;i++)
		{
			eArcade* pAuxiliarEmpleado=ll_get(pArrayListArcade, i);
			if(id == pAuxiliarEmpleado->cantidadDeJugadores)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}








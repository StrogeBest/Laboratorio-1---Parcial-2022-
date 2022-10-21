#ifndef TIPO_H_
#define TIPO_H_

#include <stdio.h>

#define CARACTERES_MAXIMO 30

typedef struct{
	int idTipo;
	char descripcion[CARACTERES_MAXIMO];
}eTipo;

void mostrarTipo(eTipo tipos[], int cantTipos);

#endif /* TIPO_H_ */

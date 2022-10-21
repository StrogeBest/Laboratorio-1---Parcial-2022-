#include "mostrarDatos.h"

void mostrarMenu(char mensaje[]){
	if(mensaje != NULL && strlen(mensaje) > 0){
		printf("%s", mensaje);
	}
}

void mostrarMensaje(char mensaje[]){
	if(mensaje != NULL && strlen(mensaje) > 0){
		printf("%s\n\n", mensaje);
		system("pause");
	}
}

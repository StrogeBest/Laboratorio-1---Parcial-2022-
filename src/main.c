#include "pedirDatos.h"
#include "vehiculo.h"
#include "tipo.h"
#include "mostrarDatos.h"

#define CANTIDAD_TIPOS 3
#define CANTIDAD_VEHICULOS 5

int main(void) {
	setbuf(stdout, NULL);

	eTipo tipos[CANTIDAD_TIPOS] = {
		{1, "SEDAN 3PTAS"},
		{2, "SEDAN 5PTAS"},
		{3, "CAMIONETA"}
	};

	eVehiculo vehiculos[CANTIDAD_VEHICULOS];

	int opcion;

	do{
		system("cls");
		mostrarMenu("\n\t>>> MENU PRINCIPAL <<<\n\n[1]. Crear un nuevo vehiculo\n[2]. Actualizar vehiculo\n[3]. Eliminar vehiculo\n[4]. Lista de vehiculos\n[5]. Lista de tipos\n\n");
		opcion = obtenerNumeroRango("Ingrese una opcion", "La opcion es incorrecta. Intentelo de nuevo", 1, 9);

		switch(opcion){
			case 1:
				crearNuevoVehiculo(vehiculos, CANTIDAD_VEHICULOS);
				break;
		}
	}while(opcion != 9);

	return EXIT_SUCCESS;
}

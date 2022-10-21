#include "pedirDatos.h"
#include "vehiculo.h"
#include "tipo.h"
#include "mostrarDatos.h"
#include "nexo.h"

#define CANTIDAD_TIPOS 3
#define CANTIDAD_VEHICULOS 5

int main(void) {
	setbuf(stdout, NULL);

	eTipo tipos[CANTIDAD_TIPOS] = {
		{1000, "SEDAN 3PTAS"},
		{2000, "SEDAN 5PTAS"},
		{3000, "CAMIONETA"}
	};

	eVehiculo vehiculos[CANTIDAD_VEHICULOS];

	int opcion;
	int permitido = 0;

	inicializarVehiculos(vehiculos, CANTIDAD_VEHICULOS);

	do{
		system("cls");
		mostrarMenu("\n\t>>> MENU PRINCIPAL <<<\n\n[1]. Crear un nuevo vehiculo\n[2]. Actualizar vehiculo\n[3]. Eliminar vehiculo\n[4]. Lista de vehiculos\n[5]. Lista de tipos\n\n");
		opcion = obtenerNumeroRango("Ingrese una opcion: ", "La opcion es incorrecta. Intentelo de nuevo", 1, 9);

		switch(opcion){
			case 1:
				system("cls");
				crearNuevoVehiculo(vehiculos, CANTIDAD_VEHICULOS, tipos, CANTIDAD_TIPOS);
				permitido = 1;
				break;
			case 2:
				if(permitido){
					system("cls");
					actualizarVehiculoPorId(vehiculos, CANTIDAD_VEHICULOS);
				}else{
					mostrarMensaje("Se debe haber ingresado por lo menos un vehiculo");
				}
				break;
			case 3:
				if(permitido){
					system("cls");
					eliminarVehiculoPorId(vehiculos, CANTIDAD_VEHICULOS);
				}else{
					mostrarMensaje("Se debe haber ingresado por lo menos un vehiculo");
				}
				break;
			case 4:
				if(permitido){
					system("cls");
					mostrarListaVehiculos(vehiculos, CANTIDAD_VEHICULOS);
					system("pause");
				}else{
					mostrarMensaje("Se debe haber ingresado por lo menos un vehiculo");
				}
				break;
		}
	}while(opcion != 9);

	return EXIT_SUCCESS;
}

#include "vehiculo.h"

eVehiculo actualizarUnVehiculo(eVehiculo vehiculo, int cantVehiculos){
	eVehiculo vehiculoAux = vehiculo;
	int opcion;

	do{
		system("cls");
		printf("\n\t>>> ACTUALIZAR VEHICULO CON ID %d<<<\n\n", vehiculo.idVehiculo);
		mostrarMenu("[1]. Descripcion del vehiculo\n[2]. Precio del vehiculo\n[3]. Salir\n\n");

		opcion = obtenerNumeroRango("Ingrese una opcion: ", "La opcion ingresada es incorrecta. Intentelo de nuevo", 1, 3);

		system("cls");
		switch(opcion){
			case 1:
				printf("\n\t>>> ACTUALIZAR JUGADOR CON ID %d<<<\n\n", vehiculo.idVehiculo);
				obtenerCadena("Ingrese la descipcion del vehiculo: ", "Ingrese una descripcion valida. Intentelo de nuevo", vehiculo.descripcion, 10);
				break;
		}
	}while(opcion != 3);

	return vehiculoAux;
}

int actualizarVehiculoPorId(eVehiculo vehiculos[], int cantVehiculos){
	int retorno = 0;
	int idVehiculo;
	int bandera = 1;
	int salir;
	int resultado = 0;
	int indice;

	eVehiculo vehiculo;

	printf("\n                                                >>> ACTUALIZAR VEHICULO POR ID <<<\n\n");

	mostrarListaVehiculos(vehiculos, cantVehiculos);

	if (bandera) {
		do{
			idVehiculo = obtenerNumero("Ingrese el ID del vehiculo a actualizar: ", "El ID no existe. Intentelo de nuevo");

			/* Si es un 0(El ID no es valido) vuelvo a pedir el ID */
			if(!validarIdVehiculo(vehiculos, cantVehiculos, idVehiculo)){
				mostrarMensaje("El ID no existe. Intentelo de nuevo");
			}
		}while(!validarIdVehiculo(vehiculos, cantVehiculos, idVehiculo));

		indice = buscarIdVehiculo(vehiculos, cantVehiculos, idVehiculo);
		vehiculo = actualizarUnVehiculo(vehiculos[indice], cantVehiculos);

		if(resultado){
			printf("\n                                                >>> ACTUALIZAR VEHICULO POR ID <<<\n\n");

			/* Pregunto si quiere actualizar el jugador */
			salir = validarSalir("Seguro que desea actualizar el vehiculo? [S/N]: ", "La opcion debe ser \"S\"(Si) o \"N\"(No). Intentelo de nuevo");

			/* Si es 1 actualizo el jugador */
			if(salir){
				indice = buscarIdVehiculo(vehiculos, cantVehiculos, idVehiculo);

				vehiculos[indice] = vehiculo;

				mostrarMensaje("\nSe ha actualizado el vehiculo correctamente");
			}
		}
	}

	return retorno;
}

int eliminarVehiculoPorId(eVehiculo vehiculos[], int cantVehiculos){
	int retorno = 0;
	int idVehiculo;
	int bandera = 1;
	int eliminar = 0;
	int indice;

	printf("\n                                                >>> ELIMINAR VEHICULO POR ID <<<\n\n");

	if(bandera) {
		do{
			idVehiculo = obtenerNumero("Ingrese el ID del vehiculo a actualizar: ", "El ID no existe. Intentelo de nuevo");

			/* Si es un 0(El ID no es valido) vuelvo a pedir el ID */
			if(!validarIdVehiculo(vehiculos, cantVehiculos, idVehiculo)){
				mostrarMensaje("El ID no existe. Intentelo de nuevo");
			}
		}while(!validarIdVehiculo(vehiculos, cantVehiculos, idVehiculo));

		/* Pregunto si desea eliminar */
		eliminar = validarSalir("\nSeguro que desea eliminar el vehiculo? [S/N]: ", "La opcion debe ser \"S\"(Si) o \"N\"(No). Intentelo de nuevo");

		/* Si es 1 elimino el vehiculo */
		if(eliminar){
			indice = buscarIdVehiculo(vehiculos, cantVehiculos, idVehiculo);

			vehiculos[indice].isEmpty = BAJA;

			mostrarMensaje("Se ha eliminado el vehiculo correctamente");
		}
	}

	return retorno;
}

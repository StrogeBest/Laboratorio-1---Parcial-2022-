#include "vehiculo.h"

static int obtenerIdVehiculo(void);
static int obtenerIdVehiculo(void) {
	static int idIncremental = 0;
	return idIncremental++;
}

void inicializarVehiculos(eVehiculo vehiculos[], int cantVehiculos){
	if (vehiculos != NULL && cantVehiculos > 0){
		for(int i = 0; i < cantVehiculos; i++){
			/* El estado de los vehiculos en LIBRE */
			vehiculos[i].isEmpty = LIBRE;
		}
	}
}

int obtenerIndiceLibre(eVehiculo vehiculos[], int cantVehiculos){
	int retorno = -1;

	if(vehiculos != NULL && cantVehiculos > 0){
		for(int i = 0; i < cantVehiculos; i++){
			/* Si el estado es LIBRE devuelvo el indice */
			if(vehiculos[i].isEmpty == LIBRE){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int buscarIdVehiculo(eVehiculo vehiculos[], int cantVehiculos, int idVehiculo){
	int retorno = 0;

	if(vehiculos != NULL && cantVehiculos > 0){
		for(int i = 0; i < cantVehiculos; i++){
			/* Busco que el ID este OCUPADO y coincida */
			if(vehiculos[i].idVehiculo == idVehiculo && vehiculos[i].isEmpty == OCUPADO){
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int validarIdVehiculo(eVehiculo vehiculos[], int cantVehiculos, int idVehiculo){
	int retorno = 0;

	if(vehiculos != NULL && cantVehiculos > 0){
		for(int i = 0; i < cantVehiculos; i++){
			/* Si encuentra un ID valido termina la funcion */
			if(vehiculos[i].idVehiculo == idVehiculo){
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

eVehiculo cargarDatosVehiculo(eVehiculo vehiculos[], int cantVehiculos){
	eVehiculo vehiculo;

	if(vehiculos != NULL && cantVehiculos > 0){
		obtenerCadenaConEspacios("Ingrese la descripcion del vehiculo: ", "El nombre ingresado es incorrecto. Intentelo de nuevo", vehiculo.descripcion, 10);

		vehiculo.modelo = obtenerNumeroRango("Ingrese el modelo(anio de fabricacion): ", "El anio debe estar entre 1900 y 2022. Intentelo de nuevo", 1900, 2022);

		obtenerCadena("Ingrese el color del vehiculo: ", "El color no es valido. Intentelo de nuevo", vehiculo.color, 10);
	}

	return vehiculo;
}

int crearNuevoVehiculo(eVehiculo vehiculos[], int cantVehiculos){
	int retorno = 0;
	eVehiculo vehiculo;

	/* Encabezado */
	printf("\n\t>>> CREAR NUEVO VEHICULO <<<\n\n");

	/* Busco espacio LIBRE */
	int index = obtenerIndiceLibre(vehiculos, cantVehiculos);

	if (index != -1) {
		/* Pido datos */
		vehiculo = cargarDatosVehiculo(vehiculos, cantVehiculos);
		/* Incremento el ID */
		vehiculo.idVehiculo = obtenerIdVehiculo();
		/* Cambio el estado a OCUPADO */
		vehiculo.isEmpty = OCUPADO;

		/* Seteo el arreglo en index LIBRE */
		vehiculos[index] = vehiculo;

		/* Devuelve 1 para saber que el vehiculo se creo correctamente */
		retorno = 1;
	}

	return retorno;
}

eVehiculo actualizarUnVehiculo(eVehiculo vehiculo, int cantVehiculos){
	eVehiculo vehiculoAux = vehiculo;
	int opcion;

	do{
		system("cls");
		printf("\n\t>>> ACTUALIZAR JUGADOR CON ID %d<<<\n\n", vehiculo.idVehiculo);
		mostrarMenu("[1]. Nombre del jugador\n[2]. Posicion del jugador\n[3]. Numero de la camiseta\n[4]. Confederacion del jugador\n[5]. Salario\n[6]. Anio de contrato\n[7]. Salir\n\n");
		//printf("\tActualizar Jugador\n\n1. Nombre\n2. Posicion\n3. Numero de la camiseta\n4. Salario\n5. Anio de contrato\n6. Salir\n\n");
		opcion = obtenerNumeroRango("Ingrese una opcion: ", "La opcion ingresada es incorrecta. Intentelo de nuevo", 1, 7);

		system("cls");
		switch(opcion){
			case 1:
				printf("\n\t>>> ACTUALIZAR JUGADOR CON ID %d<<<\n\n", vehiculo.idVehiculo);
				obtenerCadena("Ingrese la descipcion del vehiculo: ", "Ingrese una descripcion valida. Intentelo de nuevo", vehiculo.descripcion, 10);
				break;
		}
	}while(opcion != 7);

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

	/*
	ordenarJugadoresPorId(jugadores, cantJugadores);

	if (NEXO_mostrarListaJugadores(jugadores, cantJugadores, confederaciones, cantConfederaciones)){
		bandera = 1;
	}else{
		mostrarMensaje("No hay jugadores para mostrar");
	}
	*/

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

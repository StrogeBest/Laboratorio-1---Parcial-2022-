#include "nexo.h"

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

void mostrarUnVehiculo(eVehiculo vehiculo){
	printf("| %-4d| %-25s| %-7d| %-16s| %-15d|\n", vehiculo.idVehiculo, vehiculo.descripcion, vehiculo.modelo, vehiculo.color, vehiculo.tipoId);
}

int mostrarListaVehiculos(eVehiculo vehiculos[], int contVehiculos){
	int retorno = 0;

	if(vehiculos != NULL && contVehiculos > 0){
		printf("+=====+==========================+==========================+================+\n");
		printf("| ID  | DESCRIPCION              | MODELO | COLOR           | TIPO           |\n");
		printf("+=====+==========================+==========================+================+\n");
		for(int i = 0; i < contVehiculos; i++){
			if(vehiculos[i].isEmpty == OCUPADO){
				mostrarUnVehiculo(vehiculos[i]);

				retorno = 1;
			}
		}
		printf("+=====+==========================+==========================+================+\n\n");
	}

	return retorno;
}

void mostrarTipo(eTipo tipos[], int cantTipos){
	if(tipos != NULL && cantTipos > 0){
		printf("+======+===============================+\n");
		printf("| ID   | DESCRIPCION                   |\n");
		printf("+======+===============================+\n");
		for(int i = 0; i < cantTipos; i++){
			printf("| %-5d| %-30s|\n", tipos[i].idTipo, tipos[i].descripcion);
		}
		printf("+======+===============================+\n");
	}
}

eVehiculo cargarDatosVehiculo(eVehiculo vehiculos[], int cantVehiculos, eTipo tipos[], int cantTipos){
	eVehiculo vehiculo;

	if(vehiculos != NULL && cantVehiculos > 0){
		obtenerCadenaConEspacios("Ingrese la descripcion del vehiculo: ", "El nombre ingresado es incorrecto. Intentelo de nuevo", vehiculo.descripcion, 10);

		vehiculo.modelo = obtenerNumeroRango("Ingrese el modelo(anio de fabricacion): ", "El anio debe estar entre 1900 y 2022. Intentelo de nuevo", 1900, 2022);

		obtenerCadena("Ingrese el color del vehiculo: ", "El color no es valido. Intentelo de nuevo", vehiculo.color, 10);

		printf("\n\t>>> TIPOS DISPONIBLES <<<\n\n");
		mostrarTipo(tipos, cantTipos);

		do{
			vehiculo.tipoId = obtenerNumeroRango("Ingrese el ID del tipo: ", "El ID no existe. Intentelo de nuevo", 1000, 3000);
		}while(vehiculo.tipoId != 1000 && vehiculo.tipoId != 2000 && vehiculo.tipoId != 3000);
	}

	return vehiculo;
}

int crearNuevoVehiculo(eVehiculo vehiculos[], int cantVehiculos, eTipo tipos[], int cantTipos){
	int retorno = 0;
	eVehiculo vehiculo;

	/* Encabezado */
	printf("\n\t>>> CREAR NUEVO VEHICULO <<<\n\n");

	/* Busco espacio LIBRE */
	int index = obtenerIndiceLibre(vehiculos, cantVehiculos);

	if (index != -1) {
		/* Pido datos */
		vehiculo = cargarDatosVehiculo(vehiculos, cantVehiculos, tipos, cantTipos);
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


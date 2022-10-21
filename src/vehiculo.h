#ifndef VEHICULO_H_
#define VEHICULO_H_

#include <stdio.h>
#include <stdlib.h>
#include "pedirDatos.h"
#include "fecha.h"
#include "mostrarDatos.h"

#define CARACTERES_MAXIMOS 10
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct{
	int idVehiculo;
	char descripcion[CARACTERES_MAXIMOS];
	int modelo;
	char color[CARACTERES_MAXIMOS];
	int tipoId;
	int isEmpty;
}eVehiculo;

void mostrarUnVehiculo(eVehiculo vehiculo);
int mostrarListaVehiculos(eVehiculo vehiculos[], int contVehiculos);
void inicializarVehiculos(eVehiculo vehiculos[], int cantVehiculos);
int obtenerIndiceLibre(eVehiculo vehiculos[], int cantVehiculos);
int buscarIdVehiculo(eVehiculo vehiculos[], int cantVehiculos, int idVehiculo);
int validarIdVehiculo(eVehiculo vehiculos[], int cantVehiculos, int idVehiculo);
eVehiculo actualizarUnVehiculo(eVehiculo vehiculo, int cantVehiculos);
int actualizarVehiculoPorId(eVehiculo vehiculos[], int cantVehiculos);
int eliminarVehiculoPorId(eVehiculo vehiculos[], int cantVehiculos);

#endif /* VEHICULO_H_ */

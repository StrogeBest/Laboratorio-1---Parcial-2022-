#ifndef NEXO_H_
#define NEXO_H_

#include <stdio.h>
#include "vehiculo.h"
#include "tipo.h"

void inicializarVehiculos(eVehiculo vehiculos[], int cantVehiculos);
int obtenerIndiceLibre(eVehiculo vehiculos[], int cantVehiculos);
int buscarIdVehiculo(eVehiculo vehiculos[], int cantVehiculos, int idVehiculo);
int validarIdVehiculo(eVehiculo vehiculos[], int cantVehiculos, int idVehiculo);
void mostrarUnVehiculo(eVehiculo vehiculo);
int mostrarListaVehiculos(eVehiculo vehiculos[], int contVehiculos);
void mostrarTipo(eTipo tipos[], int cantTipos);
eVehiculo cargarDatosVehiculo(eVehiculo vehiculos[], int cantVehiculos, eTipo tipos[], int cantTipos);
int crearNuevoVehiculo(eVehiculo vehiculos[], int cantVehiculos, eTipo tipos[], int cantTipos);

#endif /* NEXO_H_ */

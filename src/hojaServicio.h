#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_

#include "fecha.h"

typedef struct{
	int idHoja;
	int vehiculoId;
	char descripcion[];
	float precioServicio;
	eFecha fecha;
}eHojaServicio;

#endif /* HOJASERVICIO_H_ */

#include "pedirDatos.h"

int validarSalir(char mensaje[], char mensajeError[]){
	int retorno = 0;
	char salir;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do{
			/* Muestro un mensaje al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &salir);

			/* Si no es una letra valida muestro el mensaje de error */
			if(salir != 's' && salir != 'S' && salir != 'N' && salir != 'n'){
				printf("%s\n\n", mensajeError);
				system("pause");
			}else if(salir == 's' || salir == 'S'){ /* Si desea salir devuelvo 1 */
				retorno = 1;
			}
		}while(salir != 's' && salir != 'S' && salir != 'N' && salir != 'n');
	}

	return retorno;
}

int validarNumero(char buffer[], int valorInicial){
	int retorno = 1;

	if(buffer != NULL && strlen(buffer) > 0){
		for(int i = valorInicial; i < strlen(buffer); i++){
			if(!isdigit(buffer[i])){
				retorno = 0;
				break;
			}
		}
	}else{
		retorno = 0;
	}

	return retorno;
}

int validarNumeroFlotante(char buffer[]){
	int retorno = 1;

	if(buffer != NULL && strlen(buffer) > 0){
		for(int i = 0; i < strlen(buffer); i++){
			if(isdigit(buffer[i])){
				/* Si encuentro un punto entonces valido los decimales */
				if(buffer[i + 1] == '.'){
					/* Verifico que el siguiente valor despues del punto sea menor al tamaño de la cadena */
					if(i + 2 < strlen(buffer)){
						/* Si me devuelve un 0 NO ES UN NUMERO VALIDO */
						if(!validarNumero(buffer, i + 2)){
							retorno = 0;
							break;
						}else{
							retorno = 1;
							break;
						}
					}else{
						retorno = 0;
						break;
					}
				}
			}else{
				/* Si no es un numero rompe la validacion y el numero no es valido */
				if(!isdigit(buffer[i])){
					retorno = 0;
					break;
				}
			}
		}
	}else{
		retorno = 0;
	}

	return retorno;
}

int validarAlfabeto(char buffer[]){
	int retorno = 1;

	if(buffer != NULL && strlen(buffer) > 0){
		for(int i = 0; i < strlen(buffer); i++){
			/* Si NO es una letra rompe la validacion y la letra no es valida */
			if(isalpha(buffer[i]) == 0){
				retorno = 0;
				break;
			}
		}
	}else{
		retorno = 0;
	}

	return retorno;
}

int validarAlfabetoConEspacio(char buffer[]){
	int retorno = 1;

	if(buffer != NULL && strlen(buffer) > 0){
		for(int i = 0; i < strlen(buffer); i++){
			/* Si hay un espacio valido despues del espacio */
			if(isspace(buffer[i])){
				if(i < strlen(buffer)){
					for(int j = i+1; j < strlen(buffer); j++){
						/* Si NO es una letra rompe la validacion y la letra no es valida */
						if(isalpha(buffer[j]) == 0){
							retorno = 0;
							break;
						}
					}
				}
			}else{
				if(isalpha(buffer[i]) == 0){
					retorno = 0;
					break;
				}
			}
		}
	}else{
		retorno = 0;
	}

	return retorno;
}

int obtenerNumero(char mensaje[], char mensajeError[]){
	char numeroIngresado[50];
	int largoNumero = 50;
	int numeroValidado;
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/* Si tiene el simbolo "-" es un numero negativo */
			if(numeroIngresado[0] == '-'){
				/* valido los numeros y si me devuelve 0(NO es un numero valido) muestro un mensaje de error */
				if(!validarNumero(numeroIngresado, 1)){
					printf("%s\n\n", mensajeError);
					system("pause");
				}else{
					/* Transformo el numero a entero */
					numeroValidado = atoi(numeroIngresado);
					resultado = 1;
				}
			}else{
				/* Si me devuelve un 0(NO es un numero valido) muestro un mensaje de error */
				if(!validarNumero(numeroIngresado, 0)){
					printf("%s\n\n", mensajeError);
					system("pause");
				}else{
					/* Transformo el numero a entero */
					numeroValidado = atoi(numeroIngresado);
					resultado = 1;
				}
			}
		}while(!resultado); /* Si es 0(NO es un numero valido) vuelvo a pedir un numero */
	}

	return numeroValidado;
}

int obtenerNumeroRango(char mensaje[], char mensajeError[], int minimo, int maximo){
	char numeroIngresado[100];
	int largoNumero = 100;
	int numeroValidado;
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/*
				Si el primer caracter es el "-" es negativo y valido el numero si me devuelve un
				0(NO es un numero negativo valido) muestro un mensaje de error.
			*/
			if(numeroIngresado[0] == '-' && !validarNumero(numeroIngresado, 1)){
				printf("%s no es una numero entero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else if(!validarNumero(numeroIngresado, 1)){ /* Si me devuelve un 0(NO es un numero positivo valido) muestro un mensaje de error */
				printf("%s no es un numero entero valido. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				/* Transformo el numero a entero */
				numeroValidado = atoi(numeroIngresado);

				/* Si el numero no esta entre el minimo o maximo muestro el mensaje de error */
				if(numeroValidado < minimo || numeroValidado > maximo){
					printf("%s\n\n", mensajeError);
					system("pause");
				}else{
					resultado = 1;
				}
			}

		}while(!resultado);
	}

	return numeroValidado;
}

float obtenerFlotantePositivo(char mensaje[], char mensajeError[]){
	char numeroIngresado[100];
	int largoNumero = 100;
	int numeroValidado;
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0){
		do{
			/* Pido un numero al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(numeroIngresado, largoNumero, stdin);
			numeroIngresado[strlen(numeroIngresado) - 1] = '\0';

			/* Si me devuelve 0(NO es un numero valido) muestro un mensaje de error */
			if(!validarNumeroFlotante(numeroIngresado)){
				printf("%s no es un numero flotante valido positivo. Intentelo de nuevo\n\n", numeroIngresado);
				system("pause");
			}else{
				/* Transformo el numero a flotante */
				numeroValidado = atof(numeroIngresado);

				/* Si el numero es menor que 0 muestro el mensaje de error */
				if(numeroValidado < 0){
					printf("%s\n\n", mensajeError);
					system("pause");
				}else{
					resultado = 1;
				}
			}
		}while(!resultado); /* Si es 0(NO es un numero valido) vuelvo a pedir un numero */
	}

	return numeroValidado;
}

void obtenerCadena(char mensaje[], char mensajeError[], char nombre[], int largoNombre){
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0 && nombre != NULL && strlen(nombre) > 0){
		do{
			/* Pido texto al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(nombre, largoNombre, stdin);
			nombre[strlen(nombre) - 1] = '\0';

			/* Si me devuelve 0(NO es una cadena valida) muestro el mensaje de error */
			if(!validarAlfabeto(nombre)){
				printf("%s\n\n", mensajeError);
				system("pause");
			}else{
				resultado = 1;
			}
		}while(!resultado); /* Si es 0(NO es un numero valido) vuelvo a pedir texto */
	}
}

void obtenerCadenaConEspacios(char mensaje[], char mensajeError[], char nombre[], int largoNombre){
	int resultado = 0;

	if(mensaje != NULL && strlen(mensaje) > 0 && mensajeError != NULL && strlen(mensajeError) > 0 && nombre != NULL && strlen(nombre) > 0){
		do{
			/* Pido texto al usuario */
			printf("%s", mensaje);
			fflush(stdin);
			fgets(nombre, largoNombre, stdin);
			nombre[strlen(nombre) - 1] = '\0';

			/* Si me devuelve 0(NO es una cadena valida) muestro el mensaje de error */
			if(!validarAlfabetoConEspacio(nombre)){
				printf("%s\n\n", mensajeError);
				system("pause");
			}else{
				resultado = 1;
			}
		}while(!resultado); /* Si es 0(NO es un numero valido) vuelvo a pedir texto */
	}
}

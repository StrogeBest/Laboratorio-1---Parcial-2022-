#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarSalir(char mensaje[], char mensajeError[]);
int validarNumero(char cadena[], int valorInicial);
int validarNumeroFlotante(char buffer[]);
int validarAlfabeto(char buffer[]);
int validarAlfabetoConEspacio(char buffer[]);

int obtenerNumero(char mensaje[], char mensajeError[]);
int obtenerNumeroRango(char mensaje[], char mensajeError[], int minimo, int maximo);
int obtenerNumeroPositivo(char mensaje[], char mensajeError[]);
int obtenerNumeroNegativo(char mensaje[], char mensajeError[]);
float obtenerFlotante(char mensaje[], char mensajeError[]);
float obtenerFlotantePositivo(char mensaje[], char mensajeError[]);
void obtenerCadena(char mensaje[], char mensajeError[], char cadena[], int largoCadena);
void obtenerCadenaConEspacios(char mensaje[], char mensajeError[], char nombre[], int largoNombre);

#endif /* PEDIRDATOS_H_ */

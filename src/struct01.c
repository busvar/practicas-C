/*
 struct01.c
 
 Created on: 12 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>
#include <string.h>

struct sensorType {
	char nombre[20];
	char unidad[20];
	double valor;
};

int main(){
	struct sensorType PresionS, TemperaturaT;

	// Presión
	strcpy( PresionS.nombre, "P001");
	strcpy( PresionS.unidad, "MPa");
	PresionS.valor = 1.5;

	// Temperatura
	strcpy( TemperaturaT.nombre, "T001");
	strcpy( TemperaturaT.unidad, "K");
	TemperaturaT.valor = 280;

	TemperaturaT.valor += 10;

	printf("Sensor de presión\n%s = %.3f %s\n", PresionS.nombre, PresionS.valor, PresionS.unidad);
	printf("Sensor de temperatura\n%s = %.2f %s\n", TemperaturaT.nombre, TemperaturaT.valor, TemperaturaT.unidad);
	return 0;
}

/*
 enum.c
 
 Created on: 12 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>

enum Instruccion_enum
{
	Leer,		//Leer = 0 por defecto
	Escribir,	//Escribir = 1
	Ejecutar = 4
};

int main(){
	enum Instruccion_enum instruccion;
	int i;
	instruccion = Leer;
	printf("Instrucción = %d\n",instruccion);
	instruccion++;
	printf("Instrucción = %d\n",instruccion);
	instruccion = Ejecutar;
	i = instruccion;
	printf("Instrucción = %d\n",i);
	return 0;
}

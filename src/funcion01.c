/*
 funcion01.c
 
 Created on: 11 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>

// Declaración de la función
int suma(int a, int b);

// método inicial
int main(){
	int x = 5, y = 6, resultado;
	// llamada a la función
	resultado = suma(x,y);
	printf("Suma  = %d\n", resultado);
	return 0;
}

// implementación de la función
int suma(int a, int b){
	int suma = a+b;
	return suma;
}

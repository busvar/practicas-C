/*
 funcion02.c
 
 Created on: 11 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>

// Declaración de funciones
int suma01(int a, int b);
void suma02(int a, int b, int *resultado);

int main()
{
	int a = 1, b = 3, resultado01, resultado02;
	// llamada a la función
	resultado01 = suma01(a, b);
	suma02(a, b, &resultado02);
	printf("Suma01  = %d\nSuma02 = %d\n", resultado01, resultado02);
	return 0;
}

int suma01(int a, int b){
	return a+b;
}

void suma02(int a, int b, int *resultado){
	*resultado = a + b;
}

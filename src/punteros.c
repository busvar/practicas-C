/*
 punteros.c
 
 Created on: 12 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>

int main(){
	int numeros[] = {100,101,102,103,104,105,106,107,108,109};
	int *pnumeros;

	// guarda la dirección de memoria del primer elemento del array en el puntero
	pnumeros = &numeros[0];
	/* Algebra de punteros
	numeros[0]   equivale a   *pnumeros
	numeros[2]   equivale a   *(pnumeros + 2)
	*/
	puts("Posición | Puntero | Valor");
	printf("0 | %X | %d\n", (unsigned int) pnumeros, *pnumeros); // 100
	pnumeros++;
	printf("1 | %X | %d\n", (unsigned int) pnumeros, *pnumeros); // 101
	pnumeros++;
	printf("2 | %X | %d\n", (unsigned int) pnumeros, *pnumeros); // 102
	pnumeros += 7;
	printf("9 | %X | %d\n", (unsigned int) pnumeros, *pnumeros); // 109
	puts("!!!! El array no tiene tantas componentes. Ahora apunta a otro sitio fuera del array!!!");
	pnumeros++;
	printf("10 | %X | %d\n", (unsigned int) pnumeros, *pnumeros); // ???


	// https://en.wikipedia.org/wiki/Printf_format_string#Syntax
	return 0;
}

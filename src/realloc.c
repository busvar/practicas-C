/*
 * realloc.c
 *
 *  Created on: 10 jun. 2018
 *      Author: master
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	int *myArray;
	int n = 10;

	myArray = malloc(sizeof(int)*n);
	if(myArray == NULL){
		puts("Error al reservar la memoria");
	}

	myArray = realloc(myArray,sizeof(int)*3);
	if(myArray == NULL){
		puts("Error al reservar la memoria");
	}

	free(myArray);
	puts("programa acabado");

	return 0;
}

/*
Se han reservado 40 bytes
myArray[0] = 5
myArray[3] = 2
myArray[8] = (null)
*/



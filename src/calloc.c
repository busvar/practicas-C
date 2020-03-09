/*
 * calloc.c
 *
 *  Created on: 10 jun. 2018
 *      Author: master
 */

/*
 * malloc.c
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
	int *myArray;
	int n = 10;

	myArray = calloc(n,sizeof(int));
	if(myArray == NULL){
		puts("Error al reservar la memoria");
	} else {
		printf ("Se han reservado %d bytes\n", sizeof(int)*n);
	}

	myArray[0] = 5;
	printf ("myArray[0] = %d \n", myArray[0]);
	*(myArray+3) = 2; // myArray[3]
	printf ("myArray[3] = %d \n", myArray[3]);
	printf ("myArray[8] = %d \n", myArray[8]);

	free(myArray);
	return 0;
}

/*
Se han reservado 40 bytes
myArray[0] = 5
myArray[3] = 2
myArray[8] = (null)
*/


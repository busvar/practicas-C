/*
 union.c
 
 Created on: 12 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>
#include <string.h>

union ErrorType {
	char mensaje[20];
	int codigo;
};

int main(){
	union ErrorType myError;

	// string
	strcpy( myError.mensaje, "Divided by zero");
	printf("string = %s\n",myError.mensaje);
	// entero
	myError.codigo = 2;
	printf("int = %d\n",myError.codigo);
	return 0;
}

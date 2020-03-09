/*
 for.c
 
 Created on: 11 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>

int main(){
	// suma de los 10 primeros números (del 0 al 9)
	int i, sum = 0, n = 10;
	for(i= 0; i < n; i++){
		sum += i;
	}
	printf("Suma  = %d\n",sum);
	return 0;
}

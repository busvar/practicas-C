/*
 dowhile.c
 
 Created on: 11 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>

int main(){
	// suma de los 10 primeros números (del 0 al 9)
	int i = 0, sum = 0, n = 10;
	do {
		sum += i;
		i++;
	} while(i < n);
	printf("Suma  = %d\n",sum);
	return 0;
}

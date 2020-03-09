/*
 punteros02.c
 
 Created on: 12 de feb. de 2016
 Author: alumno
 */

#include <stdio.h>

int main () {

   unsigned int  var = 20;   /* actual variable declaration */
   unsigned int  *ip;        /* pointer variable declaration */

   ip = &var;  /* store address of var in pointer variable*/

   printf("Address of var variable: %X\n", (unsigned int) &var  );

   /* address stored in pointer variable */
   printf("Address stored in ip variable: %X\n", (unsigned int)ip );

   /* access the value using the pointer */
   printf("Value of *ip variable: %d\n", *ip );

   return 0;
}

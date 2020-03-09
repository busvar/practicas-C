#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main (){
	char str[30];
	int len;
	double raiz;
	len = 0;
	raiz = 0.0;
	puts("Introduce una palabra:");
	// https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm
	scanf("%s",str);
	len = strlen(str);
	raiz = (double)len;
	raiz = sqrt(raiz);
	printf("Resultado: %.3f\n",raiz);
	return 0;
}
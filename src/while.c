#include <stdio.h>

int main(){
	// suma de los 10 primeros números (del 0 al 9)
	int i = 0, sum = 0, n = 10;
	while(i < n){
		sum += i;
		i++;
	}
	printf("Suma  = %d\n",sum);
	return 0;
}

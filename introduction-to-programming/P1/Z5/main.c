#include <stdio.h>
#include <math.h>

int main(){
	double broj,x;
	printf("Unesite broj: ");
	scanf("%lf", &broj);
	x=round(broj*100)/100;
	printf("%g", x);
	
	return 0;
}

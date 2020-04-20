#include <stdio.h>

int main() {
	float a,b,c,d,e,k,z;
	printf("Unesite 5 ocjena: ");
	scanf("%f %f %f %f %f", &a,&b,&c,&d,&e);
	z=a+b+c+d+e;
	k=z/5;
	printf("Zbir unesenih ocjena je %g, a prosjek je: %.2f",z,k);
	return 0;
}

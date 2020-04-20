#include <stdio.h>
#include <math.h>

int main() {
	double a,b,c,k,d;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	d=b*b-4*a*c;
	if(d<0)
	printf("Korijen negativnog broja nema realnih rjesenja!");
	else{
	k=sqrt(d);
	printf("Iznos za koeficijente %g, %g i %g je: %g",a,b,c,k); }
	return 0;
}

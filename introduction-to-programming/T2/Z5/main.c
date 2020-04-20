#include <stdio.h>

int main() {
	float a,b,c,x,d;
	printf("Unesite koeficijente a, b i c: ");
	scanf("%f %f %f", &a, &b, &c);
	if((a<-10||a>10)||(b<-10||b>10)||(c<-10||c>10))
	printf("Koeficijenti a, b i c nisu u zadanom rasponu.");
	else{
	printf("Unesite tacku x: ");
	scanf("%f", &x);
		d=2*a*x+b;
		printf("Prva derivacija u tacki x=%g je %g.", x,d);
		
	}
	return 0;
}

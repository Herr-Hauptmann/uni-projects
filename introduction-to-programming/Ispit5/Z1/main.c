#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001


int kvadratna_funkcija(double *x, int vel, double *y, double a, double b, double c)
{
	int vel2=vel;
	int i,j;

	for(i=0; i<vel; i++) {
		y[i]=(a*x[i]*x[i])+b*x[i]+c;
	}

	for(i=0; i<vel2; i++) {
		if(y[i] - floor(y[i]) < EPSILON) {
			for(j=i; j<vel2-1; j++) y[j]=y[j+1];
			i--;
			vel2--;
		}
	}
	return vel2;
}

int main()
{
	/* AT2: Neki su cijeli neki nisu */
	double x[] = { 1, 2, 3, 4, 5 };
	double y[5];
	int i, vel = kvadratna_funkcija (x, 5, y, 1, 0.5, 1);
	printf("Vel: %d\n", vel);
	for (i=0; i<vel; i++) printf("%g ",y[i]);
	return 0;
}

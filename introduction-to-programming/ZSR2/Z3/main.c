#include <stdio.h>
#include <math.h>

int main() {
	double x,s=0;
	double i;
	printf("Unesite broj: ");
	scanf("%lf", &x);
	for (i=1; i<=10; i++) {
		s=pow(x,i);
		if(i<=5)
		printf("^ %g: %20.5f \n",i,s);
		else if(i>5)
		printf("^ %g: %.5f \n",i,s);

	}
	
	return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
	int broj,i,cifra;
	double broj2=0;
	printf("Unesite broj: ");
	scanf("%d", &broj);
	i=0;
	while (broj != 0){
		cifra = broj % 10;
		if(cifra % 2 == 0){ 
			cifra = 0;
		}
		broj2 += cifra * pow(10,i);
		broj = broj / 10;
		i++;
		
	}
	printf("\n Broj nakon preslaganja = %g", broj2);
	return 0;
}

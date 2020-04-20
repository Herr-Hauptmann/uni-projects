#include <stdio.h>
#include <math.h>


void zaokruzi(double *niz, int vel){
	double *p;
	p=niz;
	while(p<niz+vel){
		*p = round((*p * 10)) / 10;
		p++;
	}
	
}

int main() {
	double niz[1000];
	int n,i;
	printf("Unesite broj clanova niza n: ");
	scanf("%d",&n);
	printf("Unesite clanove niza: ");
	for(i=0; i<n; i++){
		scanf("%lf",&niz[i]);
	}
	zaokruzi(&niz[0], n);
	for(i=0; i<n; i++){
	printf("%g ", niz[i]);	
	}
	return 0;
}

	#include <stdio.h>
	#include <stdlib.h>
	#define EPSILON 0.00001
	#include <math.h>

	
	float maxtemp(float *niz, int br) {
		float *p, *q;
		p = niz;
		q = niz;
			for(q; q<niz+br; q++){
			if(*q-*p>EPSILON) p = q;
			q++;
			}
		return *p;
	}
	
	float prtemp(float *niz, int br){
		float suma=0, prosjek;
		float *p = niz;
		for(p; p<niz+br; p++){
			suma+=*p;
		}
		prosjek = suma / br;
		return prosjek;
	}
	
	
	int main() {
	float niz[10000],max,prosjek;
	int i,br;
	printf("Unesite broj mjerenja: ");
	scanf("%d", &br);
	printf("Unesite temperature: ");
		for(i=0; i<br; i++){
			scanf("%f", &niz[i]);
		}
	max = maxtemp(niz,br);
	prosjek = prtemp(niz,br);
	printf("Maksimalna temperatura: %.1f", max);
	printf("\nProsjecna temperatura: %.1f", prosjek);
	
	
	
	return 0;
	}

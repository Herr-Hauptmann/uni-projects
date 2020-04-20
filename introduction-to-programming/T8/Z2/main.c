	#include <stdio.h>
	#include <stdlib.h>

	
	float maxtemp(float *niz) {
		float *p, *q;
		p = niz;
		q = niz;
			for(q; q<niz+8; q++){
			if(*q > *p) p = q;
			q++;
			}
		return *p;
	}
	
	float prtemp(float *niz){
		float suma=0, prosjek;
		float *p = niz;
		for(p; p<niz+8; p++){
			suma+=*p;
		}
		prosjek = suma / 8;
		return prosjek;
	}
	
	
	int main() {
	float niz[8],max,prosjek;
	int i;
	printf("Unesite temperature: ");
		for(i=0; i<8; i++){
			scanf("%f", &niz[i]);
		}
	max = maxtemp(niz);
	prosjek = prtemp(niz);
	printf("Maksimalna temperatura: %.1f", max);
	printf("\nProsjecna temperatura: %.1f", prosjek);
	
	
	
	return 0;
	}

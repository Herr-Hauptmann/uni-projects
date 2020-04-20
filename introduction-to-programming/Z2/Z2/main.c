#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int i=0,niz[100],temp,brojac_clanova=0,j,input;
	
	printf("Unesite brojeve: \n");
	while(brojac_clanova < 100 && scanf("%d", &input) == 1 && input!= -1)
	niz[brojac_clanova++] = input;

	int pozicija = 0;
	
	for(i=0; i<brojac_clanova; ++i){
	int iste_cifre = 1;

	int trenutni_broj=niz[i];
	int zadnja_cifra=-1;
	while(trenutni_broj && iste_cifre ){
		int trenutna_cifra = trenutni_broj % 10;
		trenutni_broj /= 10;
		
		if(zadnja_cifra != -1 && trenutna_cifra != zadnja_cifra)
		iste_cifre = 0;
		zadnja_cifra = trenutna_cifra;
		}
		
		if(iste_cifre){
			temp = niz[i];
			
			for(j=i; j>pozicija; --j)
			niz[j] = niz[j-1];
			
			niz[pozicija++] = temp;
		}
	
	
	}
	printf("Nakon preslaganja niz glasi: \n");
	for(i=0; i<brojac_clanova; ++i){
		if(i<brojac_clanova-1)
		printf("%d,", niz[i]);
		else {
			printf("%d.",niz[i]);
		}
			
		}
	
	return 0;
}

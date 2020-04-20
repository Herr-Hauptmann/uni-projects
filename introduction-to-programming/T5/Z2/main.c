#include <stdio.h>
#define BROJ_EL 10

int main() {
	int niz[BROJ_EL],suma=0,i,sumap=0;
	int max=-99999, min=99999;
	int brojp=0;
	float prosjek,prosjekp;
	
	for(i=0; i<BROJ_EL; i++){
		printf("Unesite %d. cijeli broj: ", i+1);
		scanf("%d", &niz[i]);
		suma = suma + niz[i];
		if(niz[i]%2==0){
		sumap = sumap + niz[i];
		brojp=brojp+1;
		}
		if(niz[i]>max)
		max=niz[i];
		if(niz[i]<min)
		min=niz[i];
		
	}
	
	prosjek = (float)suma/BROJ_EL;
	if(sumap!=0)
	prosjekp = (float)sumap/brojp;
	else
	prosjekp=0;
	printf("Srednja vrijednost unesenih brojeva je %.2f. \n", prosjek);
	printf("Srednja vrijednost parnih brojeva je %.2f. \n", prosjekp);
	printf("Najveci element je %d a najmanji %d. \n", max,min);

	
	
	return 0;
}

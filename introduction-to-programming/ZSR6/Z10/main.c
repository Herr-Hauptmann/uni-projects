#include <stdio.h>

int main() {
	float niz[500];
	int broj_studenata;
	
	printf("Unesite broj studenata: ");
	scanf("%d", &broj_studenata);
	
	printf("\nUnesite bodove na ispitu: ");
	for(int i=0; i<broj_studenata; i++){
		scanf("%f", &niz[i]);
		if(niz[i]>20 || niz[i]<0){
			printf("\n Rezultat ispita nije u trazenom intervalu");
			return 1;
		}
		
	}
	float temp;
	int min;
	for(int i=0; i<broj_studenata; i++){
		min=i;
		
		for(int j= i+1; j<broj_studenata; j++){
			if(niz[j] < niz[min])  min = j;
			
		}
		temp=niz[i];
		niz[i]=niz[min];
		niz[min]=temp;
		
	}
//	for(int i=0; i<broj_studenata; i++){
//		printf(" %f", niz[i]);
	//	}
	if(broj_studenata%2==1){
		int n = broj_studenata / 2;
		printf("\nMedijan je: %.1f", niz[n]);
	}
	
	if(broj_studenata%2==0){
		int k = broj_studenata / 2;
		float m = (niz[k-1] + niz[k]) / 2;
		printf("\nMedijan je: %.1f", m);

		
	}
	return 0;
}

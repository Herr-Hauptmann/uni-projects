#include <stdio.h>
#define BROJ_EL 5

int main() {
	double nizA[BROJ_EL],nizB[BROJ_EL],nizC[BROJ_EL];
	int i;
	
	printf("Unesite clanove niza A: ");
	for(i=0; i<BROJ_EL; i++){
	scanf("%lf", &nizA[i]);
	}
	printf("Unesite clanove niza B: ");
	for(i=0; i<BROJ_EL; i++){
		scanf("%lf", &nizB[i]);
	}
	
	for(i=0; i<BROJ_EL; i++){
		nizC[i]=2*nizA[i] + nizB[i];
	}
	
	printf("Niz A glasi: ");
	for(i=0; i<BROJ_EL; i++){
		if(i!=BROJ_EL-1)
		printf("%.2f, ",nizA[i]);
		else
		printf("%.2f \n",nizA[i]);
	}
	
	printf("Niz B glasi: ");
	for(i=0; i<BROJ_EL; i++){
		if(i!=BROJ_EL-1)
		printf("%.2f, ",nizB[i]);
		else
		printf("%.2f \n",nizB[i]);
	}
	

	printf("Niz C glasi: ");
	for(i=0; i<BROJ_EL; i++){
		if(i!=BROJ_EL-1)
		printf("%.2f, ",nizC[i]);
		else
		printf("%.2f \n",nizC[i]);
	}
	
	
	return 0;
}

#include <stdio.h>

int main()
{
	int niz[100],i=0,vel;
	do {
		scanf("%d",&niz[i]);
		if(niz[i]==-1) {
			i--;
			break;
		}
		i++;
	} while(i<100);
	vel = i;

	if(vel<3) {
		printf("Nedovoljno elemenata");
		return 0;
	}


	int min = 0;
	
	for(i=0; i<vel; i++) {
		if(niz[min] > niz[i]) min = i;
	}

	int logika = 1;


	for(i=0; i<min-1; i++) {
		if(niz[i] <= niz[i+1]) {
			logika = 0;
		}
	}

	for(i=min; i<vel-1; i++) {
		if(niz[i] >= niz[i+1]) {
			logika = 0;
		}
	}

	if(min==0 || min==vel) logika = 0;

	if(logika) printf("Niz je v-niz");
	else printf("Niz nije v-niz");
	return 0;
}

#include <stdio.h>

int main()
{
	int i=0, niz[1000],niz2[1000]= {0},velicina=0;
	printf("Unesite brojeve: \n");
	for(i=0; i<1000; i++) {
		scanf("%d",&niz[i]);
		if(niz[i]==-1) {
			break;
		}
		if(niz[i]<0 || niz[i]>100) {
			printf("Brojevi moraju biti izmedju 0 i 100!\n");
			i--;
			continue;
		}
	}

	velicina=i;


	if(velicina!=0) {
		for(i=0; i<velicina; i++) {
			niz2[niz[i]]++;
		}
		for(i=0; i<=100; i++) {
			if(niz2[i]>0) printf("Broj %d se javlja %d puta.\n",i,niz2[i]);

		}
	}

		return 0;
	}

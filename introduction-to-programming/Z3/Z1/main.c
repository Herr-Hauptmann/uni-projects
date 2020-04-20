#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void oduzmi_cifre(int* niz, int vel)
{
	/* varijable temp1 - za privremeno cuvanje prve cifre od desna, temp2- za privremeno cuvanje druge cifre od desna,
	temp3 - privremeno cuvanje "prepravljenog" clana niza */
	int i=0,temp,temp1,temp2,temp3=0;
	int* p = niz;
	while(p<niz+vel) {
		if(*p/10==0) *p = 0;
		else {
			temp = abs(*p);
			temp3=0;
			i=0;
			while(temp!=0) {
				temp1 = temp % 10;
				temp2 = (temp / 10) % 10;
				temp3 = temp3 + abs((temp1-temp2)) * pow(10,i);
				temp = temp/10;
				if(temp/10==0) break;
				i++;
			}
			*p = temp3;
		}
		p++;

	}

}

/* main program za provjeru funkcije */
int main()
{
	int niz[1000],i=0,vel;
	printf("Unesite clanove niza: ");
	do {
		scanf("%d", &niz[i]);
		if(niz[i]==-1) break;
		i++;
	} while(i<1000);
	vel = i;
	oduzmi_cifre(&niz[0],vel);
	for(i=0; i<=vel; i++) {
		printf("%d \n",niz[i]);
	}
	return 0;
}

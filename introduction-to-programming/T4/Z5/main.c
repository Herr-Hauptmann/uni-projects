#include <stdio.h>
#include <math.h>

int main() {
	int cif,cifbr,i=0;
	long br,novibr=0;
	do {
		printf("Unesite broj: ");
		scanf("%ld",&br);
	}while(br < 0);
	do{
		printf("Unesite cifru: ");
		scanf("%d",&cif);
	}while(cif<0);
	
	{
	
	while(br!=0)
	{
		cifbr=br%10;
		if(cifbr!=cif)
		{
		novibr=novibr+cifbr*pow(10,i);
		i++;
		}
		br=br/10;
	}
	printf("Nakon izbacivanja broj glasi %ld. \n",novibr);
	printf("Broj pomnozen sa dva glasi %ld.",novibr*2);
	}
	
	return 0;
}

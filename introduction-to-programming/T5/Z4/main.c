#include <stdio.h>

int main()
{
	int i=0, niz[1000],velicina=0,broj5=0,broj7=0,broj11=0, broj;
	printf("Unesite brojeve: \n");
	do {
		scanf("%d",&niz[i]);
		if(niz[i]==-1) {
			break; }
		i++;
		
	} while(1);

	velicina=i;

	
if(velicina!=0){
	for(i=0; i<velicina; i++) {
		if(niz[i] % 5==0) broj5++;
		if(niz[i] % 7==0) broj7++;
		if(niz[i] % 11==0) broj11++;
	}
}
	printf("Djeljivih sa 5: %d \n",broj5);
	printf("Djeljivih sa 7: %d \n",broj7);
	printf("Djeljivih sa 11: %d \n",broj11);



	return 0;
}

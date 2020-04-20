#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int rbroj,broj;
	rbroj=rand()%100+1;
	srand(time(NULL));
	
	printf("Izabrao sam broj. Probaj ga pogoditi (-1 za izlaz). \n");
	
	do{
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj==-1){
		printf("Kraj igre.");
		return 0;
	}
	
	if(broj>rbroj){
		printf("MANJI\n");
	}
	if(broj<rbroj){
		printf("VECI\n");
	}
	}while(broj!=rbroj);
	printf("JEDNAK");
	return 0;
}

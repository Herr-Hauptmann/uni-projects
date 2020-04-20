#include <stdio.h>

int main() {
	int matrica[20][20],i,j,broj_tacaka,x,y;
	
	for(i=0; i<20; i++){
		for(j=0; j<20; j++){
			matrica[i][j]=' ';
		}
	}
	

	do{
	printf("Unesite broj tacaka: ");	
	scanf("%d",&broj_tacaka);
	if(broj_tacaka <= 0 || broj_tacaka > 10){
		printf("Pogresan unos\n");
		continue;
	} 
	}while(broj_tacaka>10||broj_tacaka<=0);
	
	int k=0;
	int max=0;
	do{
		printf("Unesite %d. tacku: ",k+1);
		scanf("%d %d",&x,&y);
		if(x>19 || x<0 || y>19 || y<0){
			printf("Pogresan unos\n");
			continue;
		}
		if(y>max) max=y;
		matrica[y][x] = '*';
		k++;
	}while(k<broj_tacaka);
	
	if(max==0){
		for(j=0; j<20; j++){
			printf("%c",matrica[0][j]);
		}
		return 0;
	}
		for(i=0; i<=max; i++){
		for(j=0; j<20; j++){
			printf("%c",matrica[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

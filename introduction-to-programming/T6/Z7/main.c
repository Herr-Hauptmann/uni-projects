#include <stdio.h>

int main(){
	int matrica[10][10],i,j,min,max,red_min=0,red_max=0,temp;
	
printf("Unesite elemente matrice: ");
	for(i=0; i<10; i++){
		for(j=0; j<10; j++) scanf("%d",&matrica[i][j]);
	}


min = matrica[0][0];
for(i=0; i<10; i++){
	for(j=0; j<10; j++) {
		if(matrica[i][j] < min) {
			min=matrica[i][j];
			red_min = i;
		}
	}
}

max = matrica[0][0];

for(i=0; i<10; i++){
	for(j=0; j<10; j++) {
		if(matrica[i][j] > max) {
			max=matrica[i][j];
			red_max = i;
		}
	}
}

if(red_min == red_max) printf("Najmanji i najveci element se nalaze u istom redu.");
else{
	for(i=0; i<10; i++){
		temp = matrica[red_min][i];
		matrica[red_min][i] = matrica[red_max][i];
		matrica[red_max][i] = temp;
		
	}
	
	printf("Nakon zamjene matrica glasi: \n");
	for(i=0; i<10; i++){
		for(j=0; j<10; j++) printf("%d ",matrica[i][j]);
		printf("\n");
	}
	
}


return 0;
}

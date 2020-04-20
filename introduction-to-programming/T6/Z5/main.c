#include <stdio.h>

int main() {
	int i,j,min;
	int matrica[10][10];
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			scanf("%d",&matrica[i][j]);
		}
	}
	min=matrica[0][0];
	for(i=0; i<10; i++){
		if(matrica[i][i] < min) min = matrica[i][i];
	}
	printf("%d",min);
	return 0;
}

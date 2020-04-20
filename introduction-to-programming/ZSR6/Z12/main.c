#include <stdio.h>

int main() {
	int n,i,j,matrica[50][50];
	printf("Unesite n: \n");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			matrica[i][j] = j-i;
		}
	}
	
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%4d",matrica[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

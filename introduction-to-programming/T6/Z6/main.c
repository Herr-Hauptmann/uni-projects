#include <stdio.h>

int main() {
	int V,S,i,j;
	float matrica[100][100],suma=0;
	printf("Unesite dimenzije matrice: ");
	scanf("%d",&V);
	scanf("%d",&S);
	printf("Unesite elemente matrice: ");
	for(i=0; i<V; i++){
		for(j=0; j<S; j++) scanf("%f",&matrica[i][j]);
	}

	for(i=0; i<S; i++) suma+=matrica[0][i];
	for(i=0; i<S; i++) suma+=matrica[V-1][i];
	for(i=1; i<V-1; i++) suma+=matrica[i][0];
	for(i=1; i<V-1; i++) suma+=matrica[i][S-1];
	printf("Suma elemenata na rubu je %.2f",suma);




	
	return 0;
}

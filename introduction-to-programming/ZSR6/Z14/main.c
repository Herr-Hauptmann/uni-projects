#include <stdio.h>

int main()
{
	int matrica[100][100],N,i,j,nul=1,jedinicna=1,dijagonalna=1,gornja_trougaona=1,donja_trougaona=1,sporedna_dij=1;
	printf("Unesite broj N: ");
	do {
		scanf("%d",&N);
	} while(N<0 || N>100);
	printf("Unesite elemente matrice: \n");
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			scanf("%d",&matrica[i][j]);
		}
	}

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(matrica[i][j]!=0) nul = 0;
		}
	}

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(i!=j) if(matrica[i][j]!=0){ jedinicna = 0;
			dijagonalna=0;}
		}
		if(matrica[i][i]!=1) jedinicna=0;
	}
	
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(i>j) {
				if(matrica[i][j]!=0) gornja_trougaona = 0;
			}
		}
		
	}

		
		for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(i<j) {
				if(matrica[i][j]!=0) donja_trougaona = 0;
							//	printf("mala %d",matrica[i][j]);
							}
		}
		}	


		for(i=0; i<N; i++) {
			for(j=0; j<N; j++) {
				if(j!=N-i-1) if(matrica[i][j]!=0) sporedna_dij = 0;
			}
		}
	

	if(nul) {
		printf("Nul-matrica");
		return 0;
	}

	if(jedinicna) {
		printf("Jedinicna matrica");
		return 0;
	}
	if(dijagonalna) {
		printf("Dijagonalna matrica");
		return 0;
	}
	if(gornja_trougaona) {
		printf("Gornja trougaona matrica");
		return 0;
	}
	if(donja_trougaona) {
		printf("Donja trougaona matrica");
		return 0;
	}
	if(sporedna_dij) {
	printf("Sporedna dijagonalna matrica");
		return 0;
	}

	printf("Nista od navedenog");


	return 0;
}

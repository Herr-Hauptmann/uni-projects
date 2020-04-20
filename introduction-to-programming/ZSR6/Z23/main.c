#include <stdio.h>

int main() {
	int m,n,i,j,matrica[100][100];
	printf("Unesite M i N: \n");
	do{
	scanf("%d %d",&m, &n);
	if(m>100 || n>100 || m<=0 || n<=0){
		printf("Pogresan unos!");
		continue;
	}
	}while(m>100 || n>100);
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			scanf("%d", &matrica[i][j]);
		}
	}
	
	int teplikova=1, cirkularna=1;
	for(j=0; j<n; j++){
	for(i=0; i<m-1; m++){
		if (matrica[i][j] != matrica[i+1][j+1]) teplikova = 0;
	}
	}
	
	for(i=0; i<m-1; i++){
		if(matrica[i+1][0] != matrica[i][n-1]) cirkularna =0;
	}
	
	if(teplikova==1 && cirkularna==1){
		printf("Matrica je cirkularna");
		return 0;
	}
	if(teplikova==1){
		printf("Matrica je teplikova");
		return 0;
	}
	
	printf("Matrica nije ni teplikova ni cirkularna.");
	
	return 0;
}

#include <stdio.h>

int main() {
	int n,i,j;
	int matrica[12][22];
	printf("Crtat cemo funkciju y = x + n. Unesite n: \n");
	scanf("%d",&n);
for(i=0; i<12; i++){
	for(j=0; j<22; j++){
		matrica[i][j]=' ';
	}
}


	for(i=0; i<11; i++){
		matrica[i][0] = 10 - i;
	}
	for(i=0; i<11; i++){
		matrica[i][1] = '+';
	}
//	matrica[10][0] = ' ';
	for(i=1; i<22; i++){
		matrica[11][i] = i-1;
	}
	for(i=1; i<22; i++){
		matrica[10][i] ='+';
	}
	
	if(n<=10){
		for(i=0; i<n; i++){
			matrica[10-n+i][2+i] ='*';
		
	}
	}
	
	
	for(i=0; i<12; i++){
	for(j=0; j<22; j++){
		if(j==0 && i<11) printf("%2d",matrica[i][j]);
		else if(j==1 && i<11) printf("%2c",matrica[i][j]);
		else if(j==0 && i==11) printf(" ");
		else if(j==1 && i==1) printf("%2d",matrica[i][j]);
		else if(j>1 && i==10) printf("%3c",matrica[i][j]);
		else if(i==11) printf("%3d", matrica[i][j]);
		else printf("%3c", matrica[i][j]);

	}
	printf("\n");
}
	
	
	
	return 0;
}

#include <stdio.h>

int main() {
int N,i,j,polovina;
do{
	printf("Unesite broj N: ");
	scanf("%d",&N);
	if(N%4!=1)
	printf("N nije ispravno!\n");
		
	}while(N%4!=1);
	
	polovina = N / 2 + 1;
	
	printf("\n");
	
	// gornji dio //
	
	for(i=0; i<polovina; i++){
		if(i&1) {
			for(j=0; j<N; j++){
				if(!(j&1) && (j<i-1 || j >=N-i)){
					printf("*");
				}
				else { printf(" "); 
					
				}		
			}
		}
		
		else {
			for(j=0; j<N; j++){
				if((j&1) && (j<i-1 || j >= N-i)) {
					printf(" ");
				} 
				else { printf("*");	
					
				}
			}
		}
		printf("\n");
		
	}
	
	// donji dio//
	
	for(; i<N; i++){
		if(i & 1) {
			for(j=0; j<N; j++) {
				if(!(j&1) && (j<N-i || j>i )) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		}
		else {
			for(j=0; j<N; j++) {
				if ((j&1) && (j<N-i || j>i )){
					printf(" ");
				}
				else {
					printf("*");
				}
				
			}
		}
		printf("\n");
	}
	
	
	




	
	return 0;
}

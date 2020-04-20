#include <stdio.h>

int main() {
	int j,i,k,a;
    printf("  X |");
	for(i=1; i<=10; i++){
		printf("  %2d",i);
		}
		printf("\n");
		printf("----+");
		printf("----------------------------------------");
		printf("\n");
		
		for(j=1; j<=10; j++){
			printf(" %2.0d |",j);
		for(k=1; k<=10; k++){
			printf(" %3.0d",j*k);
			
			
		}
		printf("\n");
			
			
			
			
			
		
		
	}
	return 0;
}

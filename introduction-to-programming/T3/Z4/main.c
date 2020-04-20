#include <stdio.h>

int main() {
 int n,k,j;
 int i;
 printf("Unesite broj n: ");
 scanf("%d", &n);
 
 for(i=1; i<=n; i++) {
 	if(i%2!=0) {
 		for(j=0; j<n; j++){
 			printf("* ");
 		}
 		printf("\n");
 	}
 	
 	else if(i%2==0) {
 		printf(" ");
 		for(k=0; k<n; k++){
 			printf("* ");
 		}
 		printf("\n");
 	}	
 	
 } 
 
return 0;	
}
 
	


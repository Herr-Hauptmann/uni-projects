#include <stdio.h>

int main() {
	int a,b,i,j;
	printf("Unesite stranice pravougaonika a,b: ");
	scanf("%d,%d", &a, &b);
	
	for (i=0; i<b; i++){
		for(j=0; j<a; j++){
			if((i==0&&j==0)||(i==0&&j==a-1))
			printf("+");
			else if ((i==b-1&&j==0)||(i==b-1&&j==a-1))
			printf("+");
			else if((i==0&&j>0&&j<a-1)||(i==b-1&&j>0&&j<a-1))
			printf("-");
			else if(i>=1&&i<b-1&&j>=1&&j<a-1)
			printf(" ");
			else if((i>0&&i<b-1&&j==0)||(i>0&&i<b-1&&j==a-1))
			printf("|");
			
			
			
		}
		printf("\n");
		
	}
	return 0;
}

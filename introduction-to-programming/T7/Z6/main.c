#include <stdio.h>

long int faktorijel(int x){
	long int fakt=1;
	int i;
	for(i=1; i<=x; i++){
		fakt*=i;
	}
	return fakt; }

	int pascal(int x, int y){
	int P;
	x=x-1;
	y=y-1;
	P=faktorijel(x)/(faktorijel(y)*faktorijel(x-y));
	return P; }

int main() {
	int n,i,j,P;
	printf("Unesite n: ");
	scanf("%d", &n);
	printf("\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++){
		P=0;
		P=pascal(i,j);
		printf("%-4d",P);
		}
		printf("\n");
		
	}
	
	return 0;
}

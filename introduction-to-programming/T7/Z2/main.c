#include <stdio.h>

int faktorijel(int x){
	int fakt=1;
	int i;
	for(i=1; i<=x; i++){
		fakt*=i;
	}
	
	return fakt;
}


int main() {
	int n,i;
	double x,suma=0;
	printf("Unesite broj n u intervalu [1, 12]: ");
	do{
		scanf("%d",&n);
	}while(n<1||n>12);
	printf("Unesite realan broj x: ");
	scanf("%lf", &x);
	for(i=1; i<=n; i++){
		suma += x/faktorijel(i);
	}
	printf("Suma od 1 do %d za x = %.3f je %.3f",n,x,suma);
	

	return 0;
}

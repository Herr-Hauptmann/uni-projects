#include <stdio.h>


int obrnut(int n){
	int ret=0;
	while(n){
		int cif=n%10;
		n/=10;
		ret=ret*10+cif;
		}
		return ret;
}

int main() {
	int x;
	printf("Unesite broj: ");
	scanf("%d", &x);
	printf("Broj naopako: %d",obrnut(x));
	return 0;
}

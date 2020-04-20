#include <stdio.h>

void zamijeni(int*a, int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
	
}

int main() {
	int a,b;
	printf("Unesite brojeve a i b: ");
	scanf("%d %d", &a,&b);
	zamijeni(&a,&b);
	printf("Nakon zamjene %d,%d",a,b);
	
	return 0;
}

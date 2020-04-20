#include <stdio.h>

void Ispisi(int niz[], int vel){
	int *p = niz;
	printf("{");
	printf("%d",*p++);
	while(p<p+vel){
		printf("  %d,",*p++);
		
	}
	printf("%d",*p);
	printf("}");
}

int main() {
	printf("ZSR 7, Zadatak 1");
	return 0;
}

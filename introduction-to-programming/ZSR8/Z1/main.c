#include <stdio.h>

void Ispisi(int *niz, int vel){
	int *p = niz;
	printf("{");
	if(vel!=0){
	printf("%d,",*p++);
	while(p<niz+vel-1){
		printf(" %d,",*p);
		p++;
		
	}
	printf(" %d",*p);
	}
	printf("}");
}

int main() {
	int niz[10]={0,1,2,3,4,5,6,7,8,9,10};
	Ispisi(niz,11);
	return 0;
}

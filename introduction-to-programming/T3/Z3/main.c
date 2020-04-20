#include <stdio.h>

int main() {
	int n, a=0;
	printf("Unesite broj n: ");
	scanf("%d",&n);
	for(a=n; a>=1; a--) {
		if(a%5==0){
			printf("%d \n",a);
		}
	else if(a%7==0){
		printf("%d \n",a);
	}
	else if(a%11==0){
		printf("%d \n",a);
	}
}
	return 0;
}


#include <stdio.h>
#define NSP1 90.0
#define NPS2 120.0
#define DP1 60.0
#define DP2 80.0
#define P1 55.0
#define P2 100.0


int main() {
    float SP,DP,P;
	printf("Dobrodosli kod Vaseg kucnog ljekara!\n");
	printf("Unesite sistolicki, dijastolicki pritisak i puls: ");
	scanf("%f %f %f", &SP,&DP,&P);
	if(SP>=NSP1 && SP<=NPS2) {
	    printf("SP: normalan\n");
	}
	else {
	    printf("SP: nije normalan\n");
	}
	if(DP>=DP1 && DP<=DP2){
		printf("DP: normalan\n");
	}
	else {
		printf("DP: nije normalan\n");
	}
	if(P>=P1 && P<=P2){
		printf("Puls: normalan\n");
	}
	else {
		printf("Puls: nije normalan");
	}
	return 0;
}

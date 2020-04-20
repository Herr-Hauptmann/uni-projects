#include <stdio.h>
#define NSP1 90.0
#define NPS2 120.0


int main() {
    float SP;
	printf("Unesite vrijednost sistolickog pritiska: ");
	scanf("%f", &SP);
	if(SP>=NSP1 && SP<=NPS2) {
	    printf("Sistolicki pritisak je normalan!\n");
	}
	else {
	    printf("Sistolicki pritisak nije normalan!\n");
	}
	return 0;
}

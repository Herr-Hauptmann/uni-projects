#include <stdio.h>
#include <string.h>

struct Kurs {
char valuta[5];
float vrijednost;
};



double razmjena(struct Kurs* niz, int vel, char* s, double km){
	double novac=0;
	int i;
	for(i=0; i<vel; i++){
		if(strcmp(niz[i].valuta,s)==0) novac=niz[i].vrijednost*km;
	}
	return novac;
}

int main() {
	struct Kurs niz[3] = {{"AAA", 1.1}, {"AAB", 2.2}, {"AAC", 3.3}};
	printf("%g ", razmjena(niz, 3, "AAA", 1.5));
	printf("%g ", razmjena(niz, 3, "AAB", 1.5));
	printf("%g ", razmjena(niz, 3, "AAC", 1.5));
	printf("%g ", razmjena(niz, 3, "AAD", 1.5));
	return 0;
}

#include <stdio.h>



struct Grad {
	char naziv[20];
	int broj_stanovnika;
};

// Zbir broja stanovnika u gradovima cije ime sadrzi barem jedno veliko ili malo slovo A
int funkcija(struct Grad* niz, int vel) {
	int i, zbir=0, sadrzi_a;
	char* s;
	for (i=0; i<vel; i++) {
		sadrzi_a = 0;
		s = niz[i].naziv;
		while (*s != '\0') {
			if (*s == 'a' || *s == 'A') {
				sadrzi_a=1;
				break;
			}
			s++;
		}
		if (sadrzi_a) 
			zbir += niz[i].broj_stanovnika;
	}
	return zbir;
}

int main() {
int nesto;
	struct Grad grad[1];
	grad[0].naziv="A";
	grad[0].broj_stanovnika=200;
 	grad[1].naziv="A";
	grad[1].broj_stanovnika=200;
	funkcija
	nesto=	funkcija(grad,2);
	printf("%d",nesto);
	
}

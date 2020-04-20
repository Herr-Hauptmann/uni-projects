#include <stdio.h>

int main() {
	struct Mjerenja mjerenja[1000];
	int br_mjerenja = ucitaj(mjerenja, 100);
	printf("Broj mjerenja: %d\n", br_mjerenja);
	struct Datum d = {1, 1, 2010}, d2 = {1, 2, 2010};
	printf("Prosjek: %.2f\n", prosjek(mjerenja, br_mjerenja, "Sarajevo", d, d2));
	zapisi(mjerenja, br_mjerenja, d);
	return 0;
}

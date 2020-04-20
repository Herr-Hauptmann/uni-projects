#include <stdio.h>
#include <string.h>

struct Grad {
	char naziv[20];
	int br_stanovnika;
};
struct Drzava {
	char naziv[20];
	struct Grad gradovi[100];
	int br_gradova;
};

int izbaci_duple(struct Grad* gradovi, int velg, struct Drzava* drzave, int veld) {
	int i, j, brojac = 0, k;
	for(i = 0; i < velg; i++){
		brojac = 0;
		for(j = 0; j < veld; j++){
			for(k = 0; k < drzave[j].br_gradova; k++){
				if(strcmp(gradovi[i].naziv,drzave[j].gradovi[k].naziv) == 0) brojac++;
			}
		}
	
	if(brojac > 1){
		for(j = i; j < velg - 1; j++){
			gradovi[j] = gradovi[j+1];
		}
		velg--;
		i--;
	}
	}
	return velg;
}

int main() {
	/* AT2: Sarajevo i Beograd se pojavljuju u dvije drzave, ostali u jednoj ili nula */
struct Grad gradovi[10] = {
	{"Sarajevo", 500000},
	{"Beograd", 1500000},
	{"Zagreb", 1000000},
	{"Ljubljana", 300000},
	{"Skopje", 400000},
	{"Banja Luka", 150000},
	{"Slavonski Brod", 50000}
};

struct Drzava drzave[10] = {
	{"BiH", {{"Sarajevo", 500000}, {"Banja Luka", 150000}}, 2},
	{"Hrvatska", {{"Zagreb", 1000000}, {"Beograd", 50000}}, 2},
	{"Neka", {{"Sarajevo", 300000}, {"Beograd", 150000}}, 2},
};

int vel = izbaci_duple(gradovi,7,drzave,3);
int i;
for (i=0; i<vel; i++)
	printf("%s\n", gradovi[i].naziv);
	return 0;
}

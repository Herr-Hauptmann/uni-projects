#include <stdio.h>
#include <math.h>
struct Tacka{
	double x,y;
};
struct Kruznica{
	struct Tacka centar;
	double poluprecnik;
};
double Udaljenost(struct Tacka t1, struct Tacka t2){
	return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));
}
struct Kruznica obuhvat(struct Tacka* niz, int vel){
	int i,j;
	double max_udaljenost = 0;
	if(vel == 1){
		struct Kruznica k;
		k.centar = niz[0];
		k.poluprecnik = 0;
		return k;
	}
	int index_1, index_2;
	for(i = 0; i < vel; ++i){
		for(j = i+1; j < vel; ++j){
			if(Udaljenost(niz[i],niz[j]) > max_udaljenost){
				max_udaljenost = Udaljenost(niz[i],niz[j]);
				index_1 = i; index_2 = j;
			}
		}
	}
	struct Kruznica k;
	k.centar.x = (niz[index_1].x + niz[index_2].x) / 2;
	k.centar.y = (niz[index_1].y + niz[index_2].y) / 2;
	k.poluprecnik = max_udaljenost / 2;
	return k;
}
void ispis_kruznice(struct Kruznica k){
	printf("(%2f,%2f) %2f",k.centar.x,k.centar.y,k.poluprecnik);
}
int main() {
	printf("ZSR 11, Zadatak 6");
	return 0;
}

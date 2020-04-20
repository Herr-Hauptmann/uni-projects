#include <stdio.h>

struct Osoba {
	char ime[15];
	char prezime[20];
	int telefon;
};


void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if ( znak == '\n' ) znak=getchar();
	int i=0;
	while ( i < velicina -1 && znak!='\n' ) {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}



struct Osoba unos_osobe()
{
	struct Osoba o;
	printf("Unesite ime: ");
	unesi(o.ime,15);
	printf("Unesite prezime: ");
	unesi(o.prezime,15);
	printf("Unesite broj telefona: ");
	scanf("%d",&o.telefon);
	return o;
}

void ispis_osobe(struct Osoba o)
{
	printf("%s %s, Tel: %d \n",o.ime, o.prezime, o.telefon);
}






int main()
{
	struct Osoba imenik[100];
	int meni, redni_broj=0,i;
	while(1) {
		printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
		scanf("%d",&meni);
		if(meni==0) break;
		if(meni==1) {
			imenik[redni_broj] = unos_osobe();
			redni_broj++;
			}
		if(meni==2){
			for(i=0; i<redni_broj; i++){
				printf("\n%d. ",i+1);
				ispis_osobe(imenik[i]);
			}
			
		}

	}
	return 0;
}

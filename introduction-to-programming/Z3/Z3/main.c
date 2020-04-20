#include <stdio.h>

int daj_sljedeci_broj(int parametar)
{
	/* deklarisane su staticke varijable jer je potrebno da funkcija "pamti" prethodne granice intervala */
	static int interval1=100;
	static int interval2=0;
	static int broj=50;
	if(parametar==0) {
		broj=(interval1+interval2)/2;
	} else if(parametar==1) {
		interval2=broj;
		broj=(interval1+interval2)/2;
	} else {
		interval1=broj;
		broj=(interval1+interval2)/2;

	}



	return broj;

}

/* main program za provjeru funkcije */
int main()
{
	int broj;
	char odgovor;
	/* linija koda za provjeru poziva  kad je paramtetar=0
		broj=daj_sljedeci_broj(0);
		printf("%d",broj); */
	printf("Zamislite neki broj...\n");
	broj=50;
	do {
		do {
			printf("Da li je taj broj %d? ",broj);
			scanf(" %c",&odgovor);
			if((odgovor!='J') && (odgovor!='V')&& (odgovor!='M')) printf("Pogresan unos, probajte ponovo.\n");
		} while(odgovor!='J'&&odgovor!='V'&&odgovor!='M');
		if(odgovor=='V') {
			broj =daj_sljedeci_broj(1);
		} else {
			broj=daj_sljedeci_broj(-1);
		}


	} while(odgovor!='J');
	printf("Pogodio sam!");

	return 0;
}

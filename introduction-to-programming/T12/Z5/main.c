#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */
#include <string.h>

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

int main()
{
	char naziv_predmeta[40],predmet_s[100];
	FILE *ulaz;
	FILE *izlaz;
	int niz_ocjena[100],predmet,brindeks, ocjena,broj_predmeta=0,broj_studenata=0,slusali_predmet=0,prosli=0,i=0,Suma=0,brpredmeta,c,k=0,meni,index,v;
	double prosjek,prolaznost;
	ulaz=fopen("ispiti.txt","r");
	if (ulaz == NULL) {
		printf ("Pogreska kod otvaranja datoteke %s!\n\n", "ispiti.txt");
		return 1;
	}
	while(1) {
		printf("\nUnesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz: ");
		scanf("%d",&meni);



		switch(meni) {

		case 1:
			Suma = 0;
			slusali_predmet=0;
			prosli=0;
			i=0;
			prosjek=0;
			for(v=0; v<100; v++) niz_ocjena[v]=0;
			printf("Unesite broj indexa: ");
			scanf("%d",&index);
			while(fscanf(ulaz, "%d %d %d",&brindeks, &predmet, &ocjena)==3) {
				if(index==brindeks) {
					if(ocjena>=5) {
						niz_ocjena[i]=ocjena;
						i++;
					}
					if(ocjena>5) prosli++;


					slusali_predmet++;
				}
				broj_studenata++;
			}
			if(i==0) {
				printf("Zalimo, ali ne postoje podaci o studentu sa brojem indexa %d!",index);
				break;
			}
			printf("Student je slusao %d predmeta, a polozio %d (%d%%).",slusali_predmet,prosli,prosli/slusali_predmet*100);
			int j=0;
			for(j=0; j<i; j++) {
				Suma+=niz_ocjena[j];
			}

			fclose(ulaz);
			prosjek = (double) Suma/slusali_predmet;
			printf("\nProsjecna ocjena polozenih predmeta je %.1f",prosjek);

			break;


		case 2:
			Suma=0;
			slusali_predmet=0;
			prosli=0;
			broj_studenata=0;
			i=0;
			prosjek=0;
			for(v=0; v<100; v++) niz_ocjena[v]=0;
			ulaz=fopen("ispiti.txt","r");


			do {
				printf("Unesite predmet: ");
				unesi(naziv_predmeta,40);
				izlaz=fopen("predmeti.txt", "r");
				if(izlaz == NULL) {
					fclose(ulaz);
					printf("Pogreska kod otvaranja datoteke %s\n\n", "predmeti.txt");
				}
				while(fscanf(izlaz, "%d ",&brpredmeta)==1) {
					k=0;
					while((c=fgetc(izlaz))!='\n') {
						predmet_s[k++] = c;
					}
					predmet_s[k] = '\0';
					if(strcmp(naziv_predmeta,predmet_s)==0) broj_predmeta = brpredmeta;
					if(broj_predmeta != 0) break;
				}
				if(broj_predmeta==0) printf("Nepostojeci predmet!");
			} while(broj_predmeta==0);
			


			while(fscanf(ulaz, "%d %d %d",&brindeks, &predmet, &ocjena)==3) {
				if(predmet==broj_predmeta) {
					if(ocjena>=5) {
						niz_ocjena[i]=ocjena;
						i++;
					}
					if(ocjena>5) prosli++;


					slusali_predmet++;
				}
				broj_studenata++;
			}

			if(i==0) {
				printf("Zalimo, ali ne postoje podaci o predmetu %s!",predmet_s);
				return 0;
			}

			j=0;
			for(j=0; j<i; j++) {
				Suma+=niz_ocjena[j];
			}

			fclose(ulaz);
			prosjek = (double) Suma/slusali_predmet;
			prolaznost = (double) prosli/slusali_predmet*100;
			printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%", prosjek, prolaznost);
			break;

		case 0:
			return 0;
		}
	}

	return 0;
}

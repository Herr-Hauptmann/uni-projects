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
    int niz_ocjena[1000],predmet,brindeks, ocjena,broj_predmeta=0,broj_studenata=0,slusali_predmet=0,prosli=0,i=0,Suma=0,brpredmeta,c,k=0;
    double prosjek,prolaznost;
    ulaz=fopen("ispiti.txt","r");
    if (ulaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke %s!\n\n", "ispiti.txt");
        return 1;
    }
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

    int j=0;
    for(j=0; j<i; j++) {
        Suma+=niz_ocjena[j];
    }

    fclose(ulaz);
    prosjek = (double) Suma/slusali_predmet;
    prolaznost = (double) prosli/slusali_predmet*100;
    printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%", prosjek, prolaznost);
    return 0;
}

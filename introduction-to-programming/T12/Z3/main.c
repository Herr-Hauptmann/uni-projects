#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */

int main()
{
    FILE *ulaz;
    int niz_ocjena[1000],predmet,brindeks, ocjena,broj_predmeta,broj_studenata=0,slusali_predmet=0,prosli=0,i=0,Suma=0;
    double prosjek,prolaznost;
    ulaz=fopen("ispiti.txt","r");
    if (ulaz == NULL) {
        printf ("Pogreska kod otvaranja datoteke %s!\n\n", "ispiti.txt");
        return 1;
    }
    printf("Unesite predmet: ");
    scanf("%d", &broj_predmeta);
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
        printf("Zalimo, ali ne postoje podaci o predmetu sa brojem 6!");
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

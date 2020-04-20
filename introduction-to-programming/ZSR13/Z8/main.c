#include <stdio.h>
#include <stdlib.h>

int broj_rastuci(int* niz, int vel)
{
    int brojac=0, i, c, posljednja, rastuci;
    for (i=0; i<vel; i++) {
        posljednja = abs(niz[i]%10);
        niz[i] /= 10;
        rastuci = 1;
        while (niz[i] != 0) {
            c = abs(niz[i]%10);
            if (c >= posljednja) rastuci=0;
            niz[i] /= 10;
        }
        if (rastuci) brojac++;
    }
    return brojac;
}

int main()
{
    int niz[100];
    int i=0;
    FILE* ulaz = fopen("mjerenja.txt", "r");
    if (ulaz == NULL) {
        printf("Greska pri otvarajnu datoteke.");
        return 1;
    }
    while (i<100 && fscanf(ulaz, "%d,", &niz[i])==1) i++;
    fclose(ulaz);

    FILE* izlaz = fopen("statistika.txt", "w");
    if (izlaz == NULL) {
        printf("Greska pri otvarajnu datoteke.");
        return 2;
    }
    fprintf(izlaz, "%d", broj_rastuci(niz, i));
    fclose(izlaz);
    return 0;
}

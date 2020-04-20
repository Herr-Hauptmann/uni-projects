#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x, brojac=1, i;
    int c, prethodni='/';

    printf("Unesite broj: ");
    scanf("%d", &x);
    if (x<1) {
        printf("Pogresan unos");
        return 1;
    }

    FILE* ulaz = fopen("input.txt", "r");
    if (ulaz == NULL) {
        printf("Greska");
        return 2;
    }
    FILE* izlaz = fopen("output.txt", "w");
    if (izlaz == NULL) {
        fclose(ulaz);
        printf("Greska");
        return 3;
    }

    do {
        c = fgetc(ulaz);
        if (c==prethodni)
            brojac++;
        else {
            if (brojac >= x) {
                for (i=0; i<x; i++) fputc(prethodni, izlaz);
            }
            brojac=1;
            prethodni=c;
        }

    } while(c != EOF);
    fclose(ulaz);
    fclose(izlaz);
    return 0;
}

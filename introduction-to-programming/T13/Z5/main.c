#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */
#include <string.h>

struct Student {
    char prezime[20];
    char ime[15];
    int  broj_bodova1;
    int broj_bodova2;
};

struct StudentBIN {
    char prezime[20];
    char ime[15];
    int  ukupan_broj_bodova;
};

void unesi(char niz[], int velicina)
{
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

struct Student novi_student()
{
    struct Student covjek;
    printf("Unesite ime: ");
    unesi(covjek.ime, 10);
    printf("Unesite prezime: ");
    unesi(covjek.prezime, 15);
    printf("Unesite broj bodova na I parcijalnom: ");
    scanf("%d", &covjek.broj_bodova1);
    printf("Unesite broj bodova na II parcijalnom: ");
    scanf("%d", &covjek.broj_bodova2);
    return covjek;
}
int main()
{
    struct Student studenti[300],student;
    struct StudentBIN tmp;
    FILE *ulaz, *ulaz2, *izlaz;
    int i=0, j,meni,k,max,vel;

    if ((ulaz = fopen("ispit.dat","wb")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.dat\n");
        return 1;
    }
    if ((ulaz2 = fopen("ispit.dat","rb")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.dat\n");
        return 1;
    }


    do {
        printf("Unesite 1 za unos, 2 za ispis, 3 za usmeni, 0 za izlaz: ");
        scanf("%d",&meni);

        switch(meni) {
        case 0:
            break;

        case 1:
            student = novi_student();
            int zapisano = fwrite(&student, sizeof(struct Student), 1, ulaz);
            if(ferror(ulaz)) {
                printf("Greska prilikom zapisivanja u datoteku.\n");
                printf("Zapisano je samo %d osoba.\n",zapisano);
            }
            fflush(ulaz);
            break;

        case 2:
            while (i<300 && fread(&studenti[i], sizeof(struct Student), 1, ulaz2)==1) {
                i++;
            }
            vel = i;
            for(j=0; j<i; j++)
                printf("\n%d. %s %s - %d, %d",j+1,studenti[j].prezime, studenti[j].ime, studenti[j].broj_bodova1, studenti[j].broj_bodova2);
            printf("\n");
            break;

        case 3:
            if ((izlaz = fopen("usmeni.dat","wb")) == NULL) {
                printf("Greska pri kreiranju datoteke usmeni.dat\n");
                return 1;
            }
            printf("Izlazna datoteka usmeni.dat je kreirana\n");
            struct StudentBIN usmeni[300];
            int brojac=0;
            for(k=0; k<i; k++) {
                if(studenti[k].broj_bodova1 >= 10 && studenti[k].broj_bodova2 >= 10) {
                    strcpy(usmeni[brojac].prezime, studenti[k].prezime);
                    strcpy(usmeni[brojac].ime, studenti[k].ime);
                    usmeni[brojac].ukupan_broj_bodova = studenti[k].broj_bodova1 + studenti[k].broj_bodova2;
                    brojac++;
                }
            }

            for (k=0; k<brojac; k++) {
                max = k;
                for (j=k+1; j<brojac; j++)
                    if (usmeni[j].ukupan_broj_bodova > usmeni[max].ukupan_broj_bodova) max = j;

                tmp = usmeni[k];
                usmeni[k] = usmeni[max];
                usmeni[max] = tmp;
            }
            fwrite(usmeni, sizeof(struct StudentBIN), brojac, izlaz);
            fclose(izlaz);
            break;
        }




    } while(meni!=0);

    fclose(ulaz);
    fclose(ulaz2);
    return 0;

}

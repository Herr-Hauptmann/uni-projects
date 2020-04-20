#include <stdio.h>
#include <stdlib.h> /* Zbog funkcije exit() */

struct Student {
    char prezime[20];
    char ime[15];
    int  broj_bodova1;
    int broj_bodova2;
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

struct Student novi_student() {
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
    FILE *ulaz, *ulaz2;
    int i, j, vel, meni;
    if ((ulaz = fopen("ispit.txt","a")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.txt\n");
        return 1;
    }
    if ((ulaz2 = fopen("ispit.txt","r")) == NULL) {
    printf("Greska pri otvaranju datoteke ispit.txt\n");
        return 1;
    }

    do {
         printf("Unesite 1 za unos, 2 za ispis, 0 za izlaz: ");
        scanf("%d",&meni);
   
         switch(meni) {
        case 0: break;

         case 1:
            student = novi_student();
            fprintf(ulaz,"%-20s%-15s%2d %2d\n",student.prezime,student.ime,student.broj_bodova1,student.broj_bodova2);
            fflush(ulaz);
            break;
            
        case 2:
            i=0;
            while (i<300 && fscanf(ulaz2,"%20s%15s%2d %2d\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova1, &studenti[i].broj_bodova2) == 4) {
                i++;
            }
            for(j=0; j<i; j++) 
            printf("\n%d. %s %s - %d, %d",j+1,studenti[j].ime, studenti[j].prezime, studenti[j].broj_bodova1, studenti[j].broj_bodova2);
            printf("\n");
            break;
         }

    }while(meni!=0);
    fclose(ulaz);
    fclose(ulaz2);
    return 0;

}

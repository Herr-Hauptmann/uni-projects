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

int main() {
    struct Student studenti[300], tmp;
    FILE *ulaz, *izlaz;
    int i, j, vel, max;

    /* Otvaranje datoteka */
    if ((ulaz = fopen("ispit.txt","r")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.txt\n");
        remove("usmeni.txt");
        return 1;
    }

    if ((izlaz = fopen("usmeni.dat","wb")) == NULL) {
        fclose(ulaz);
        printf("Greska pri otvaranju datoteke usmeni.dat");
        return 1;
    }

    /* Ucitavanje datoteke u niz studenti */
   
    i=0;
     while (i<300 && fscanf(ulaz,"%20s%15s%2d%2d\n", studenti[i].prezime, studenti[i].ime, &studenti[i].broj_bodova1, &studenti[i].broj_bodova2) == 4)
        i++;
    vel = i;

    /* Sortiranje niza po broju bodova */
    for (i=0; i<vel; i++) {
        max = i;
        for (j=i+1; j<vel; j++)
            if (studenti[j].broj_bodova1 + studenti[j].broj_bodova2 > studenti[max].broj_bodova1 + studenti[max].broj_bodova2) 
                max = j;

        tmp = studenti[i];
        studenti[i] = studenti[max];
        studenti[max] = tmp;
    }
    
    
    struct StudentBIN usmeni[300];
    
    int brojac=0;
    
    for(i=0; i<vel; i++){
         if(studenti[i].broj_bodova1 >= 10 && studenti[i].broj_bodova2 >= 10){
             strcpy(usmeni[brojac].prezime, studenti[i].prezime);
             strcpy(usmeni[brojac].ime, studenti[i].ime);
             usmeni[brojac].ukupan_broj_bodova = studenti[i].broj_bodova1 + studenti[i].broj_bodova2;
             brojac++;
         }
    }

   
     int prosli=fwrite(usmeni, sizeof(struct StudentBIN), brojac, izlaz);
     if(ferror(izlaz)){ printf("Greska prilikom pisanja datoteke. \n");
     printf("Zapisano je %d osoba.\n",prosli);
     }
     
         
    
    printf ("Izlazna datoteka usmeni.dat je kreirana\n");
    fclose(ulaz);
    fclose(izlaz); 
    return 0;
    
}
    



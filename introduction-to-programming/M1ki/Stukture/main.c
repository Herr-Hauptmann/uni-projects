R Usmeni zad3   -   by @who.so
 
 
 
#include <stdio.h>
struct Ocjena
{
    char naziv_predmeta[100];
    int ocjena;
};
struct Student
{
    char ime[20], prezime[20];
    int br_ocjena;
    struct Ocjena ocjene[100];
};
 
 
 
void top_studenti(struct Student niz[], int n)
{
   
    int i, j;
    int kvota=0;
    int suma=0;
    double prosjek=0;
    double minprosjek;
    double maxprosjek;
        int najbolji;
    while(n>10)
    {
            for(i=0;i<niz[0].br_ocjena;i++)
            {
                suma+=niz[0].ocjene[i].ocjena;
            }
                    minprosjek=(double)suma/niz[0].br_ocjena;
                    for(i=0; i<n; i++)
                    {
                        suma=0;
                        prosjek=0;
                        for(j=0; j<niz[i].br_ocjena; j++)
                        {
                            suma+=niz[i].ocjene[j].ocjena;
                        }
                        prosjek=(double)suma/niz[i].br_ocjena;
                        if(prosjek<minprosjek)
                        {
                            minprosjek=prosjek;
                            kvota=i;
                        }
                       
                    }
            if(n<=10) break;
             for(j=kvota; j<n-1; j++)
            {
                niz[j]=niz[j+1];
            }
            n--;
           
   
    }
        suma=0;
            for(i=0;i<niz[0].br_ocjena;i++)
            {
                suma+=niz[0].ocjene[i].ocjena;
            }
            maxprosjek=(double)suma/niz[0].br_ocjena;
            for(i=0; i<n; i++)
            {
                suma=0;
                prosjek=0;
                for(j=0; j<niz[i].br_ocjena; j++)
                {
                    suma+=niz[i].ocjene[j].ocjena;
                }
                prosjek=(double)suma/niz[i].br_ocjena;
                if(prosjek>maxprosjek)
                {
                    maxprosjek=prosjek;
                    najbolji=i;
                }
               
            }
           
            for(i=0; i<niz[najbolji].br_ocjena; i++)
            {
                if(niz[najbolji].ocjene[i].ocjena==10)
                {
                    printf("%s ", niz[najbolji].ocjene[i].naziv_predmeta);
       
                }
            }
        printf("\n");
       
           
   
}
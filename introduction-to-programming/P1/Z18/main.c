#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lowercase(char* string){
    char* ret = string;
    while(*string++ != '\0') if(*string >= 'A' && *string <= 'Z') *string += 32;
    return ret;
}

int JeLiSlovo(char c){
if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) return 1;
else return 0;
}

// funkcija za unos stringa - ustvari implementacija funkcije getline
void unesi(char niz[], int velicina) {
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

// funkcija koja od izjavne recenice pravi upitnu, podrazumjeva se da je recenica prosta - tj u obliku subjekat, predikat, objekat
char* izjavna2upitna(char* recenica, char* ret){
    char* p = recenica;
    char subjekat[20];
    char predikat[20];
    char pomocni_predikat[20];
    char objekat[20];
    int brojac = 0;
    char ubaci[] = "Da li";

    // 1. slucaj - ako je recenica u sadasnjem ili proslom vremenu
    if(strstr(recenica,"je")){
            while(*p != '\0' && *p == ' ') p++; // pomjeramo pokazivac u slacaju da ima whitespace ispred
            while(JeLiSlovo(*p)) subjekat[brojac++] = *p++;
            subjekat[brojac] = '\0';
            lowercase(subjekat);
            brojac = 0;
            while(*p != '\0' && *p == ' ') p++;
            while(JeLiSlovo(*p)) predikat[brojac++] = *p++;
            predikat[brojac] = '\0';
            // provjeravamo da li recenica sadrzi pomocnu rjecicu je
            if(strcmp(predikat,"je") == 0){
            while(*p != '\0' && *p == ' ') p++;
            brojac = 0;
            while(JeLiSlovo(*p)) pomocni_predikat[brojac++] = *p++;
            pomocni_predikat[brojac] = '\0';
            while(*p != '\0' && *p == ' ') p++;
            brojac = 0;
            while(JeLiSlovo(*p) || *p == '.' || *p == ' ') objekat[brojac++] = *p++;
            objekat[brojac] = '\0';
            strcat(ret,ubaci);
            strcat(ret," ");
            strcat(ret,predikat);
            strcat(ret," ");
            strcat(ret,subjekat);
            strcat(ret," ");
            strcat(ret,pomocni_predikat);
            strcat(ret," ");
            strcat(ret,objekat);
            strcat(ret,"?");
            return ret;
            }
            else{
            while(*p != '\0' && *p == ' ') p++;
            brojac = 0;
            while(JeLiSlovo(*p) || *p == '.' || *p == ' ') objekat[brojac++] = *p++;
            objekat[brojac] = '\0';
            strcat(ret,ubaci);
            strcat(ret," ");
            strcat(ret,subjekat);
            strcat(ret," ");
            strcat(ret,predikat);
            strcat(ret," ");
            strcat(ret,objekat);
            strcat(ret,"?");
            return ret;
            }




    }
    // 2. slucaj - ako je recenica u buducem vremenu
    if(strstr(recenica,"će") || strstr(recenica,"ćemo") || strstr(recenica,"ćete") || strstr(recenica,"ćemo")){

    }


}
int main()
{
    while(1){
    printf("Unesite recenicu: ");
    char recenica[100];
    char ret[200] = "";
    unesi(recenica,100);
    printf("Izjavna2Upitna glasi: %s \n", izjavna2upitna(recenica,ret));
}
    return 0;
}

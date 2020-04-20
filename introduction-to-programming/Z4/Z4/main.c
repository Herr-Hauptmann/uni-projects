#include <stdio.h>

void unesi_matrica(char niz[][300], int sirina, int visina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    int j = 0;
    while (i < (sirina-1)*26 && j < visina-1) {
        niz[i][j] = znak;
        if(znak=='\n'){
            j++;
            i=0; 
            znak= getchar();
            continue;
        }
        i++;
        znak = getchar();
    }
    niz[i][j]='\0';
}
void unesi_alfabet(char niz[], int sirina, int visina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0, j=0;
    while (i < (sirina-1)*26 && j<visina-1 ) {
        niz[i] = znak;
        if(znak=='\n'){
            j++;
        }
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
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

int main() {
int l,h,n,i,j;
char rijec[200];
char alfabet[10000];
scanf("%d",&l);
scanf("%d",&h);
unesi(rijec,200);
unesi_alfabet(alfabet,l,h);
printf("\n");
printf("%c*",alfabet[9]);
printf("%s",alfabet);




	
	
//	printf("%s",rijec);
	return 0;
}

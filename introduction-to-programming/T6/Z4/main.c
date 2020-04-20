#include <stdio.h>
#define DUZINA 10
int main() {
    int niz[DUZINA],e,vel,k;
    int i=0,j=0;
    /* unos niz */
    printf("Unesite elemente niza: ");
    do {
        scanf("%d", &niz[i]);
        if(niz[i]==-1)
        break;
        i++;
    }while(i<DUZINA);
    vel=i;
    printf("Unesite element koji treba izbaciti: ");
    scanf("%d",&e);
    for(i=0; i<vel; i++){
    	if(niz[i] == e){
    		for(k=i; k<vel-1; k++){
    			niz[k]=niz[k+1];
    			}
    			vel--;
    			i--;
    	}
     }
     printf("Novi niz glasi: ");
    for(i=0; i<vel; i++){
    if(i<vel-1) printf("%d,",niz[i]);
    else printf("%d",niz[i]);
    }
    return 0;
}
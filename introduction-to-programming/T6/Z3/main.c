#include <stdio.h>
#define DUZINA 10
int main() {
    double nizA[DUZINA],temp,nizB[DUZINA],nizC[100];
    int i=0,j=0,k,velA,velB,velC;
    /* unos niza */
    printf("Unesite elemente niza A: ");
    do {
        
        scanf("%lf", &nizA[i]);
        if(nizA[i]==-1)
        break;
        i++;
    }while(i<DUZINA);
    velA=i;
    i=0;
    printf("Unesite elemente niza B: ");
    do {
        
        scanf("%lf", &nizB[i]);
        if(nizB[i]==-1)
        break;
        i++;
    }while(i<DUZINA);
    velB=i;
    
    for(k=0; k<velA; k++){
    	nizC[k]=nizA[k];
    }
    for(k=0; k<velB; k++){
    	nizC[k+velA]=nizB[k];
    }
    velC=velA+velB;
    printf("Niz C glasi: ");
    for(k=0; k<velC; k++){
    	if(k!=velC-1)
    	printf("%g,", nizC[k]);
    	else
    	printf("%g", nizC[k]);
    }
    return 0;
}

#include <stdio.h>
#define VELICINA 30

int main(){
    int niz[VELICINA],temp,i,j,brojaci[11],imena[11];
    i=0;
    while(i<VELICINA){
        
        printf("Unesite brojeve izmedju 1 i 10");
        scanf("%d", &niz[i]);
        if(niz[i]<1||niz[i]>10){
            printf("Ne valja unos");
        }
        else {
            i++;
        }
        
    }
    
    for(i=0; i<11; i++){
        brojaci[i]
    }
    
    
    
    
    
    return 0;
}
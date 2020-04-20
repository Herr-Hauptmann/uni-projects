#include <stdio.h>

int main(){
    int niz[100],i,j,hazaminut[100]={0},N,flag,xOR,brojac=1;
    
    printf("Unesite N ");
    do{
        scanf("%d", &N);
    }while(N>100||N<1);
    for(i=0; i<N; i++){
        scanf("%d", &niz[i]);
    }

  
    for(j=1; j<=N; j++){
    for(i=0; i<N; i++){
       printf("niz 1 = %d \n",niz[i]);
        xOR = niz[i]^j;
        hazaminut[i] = xOR;
        printf("niz 2 = %d \n",hazaminut[i]);
        }
    
   flag = 1;
    for(int k=0; k<N; k++){
       printf(" hazamint = %d",k);
        if(hazaminut[k]>hazaminut[k+1]){
        flag = 0;
        break;
        }
    }
    if(flag==0) continue;
    else break;
    }  
    
  
  
  if(flag == 1)
  printf("X=%d",j);
  else
  printf("X=-1");

  
    
    
    return 0;
}
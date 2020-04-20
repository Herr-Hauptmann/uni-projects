	#include <stdio.h>

	
	int drugi(int niz[], int n){
		int maxind=0,maxind2=0,i;
		if(n==1) return -1;
		for(i=0; i<n; i++){
			if(niz[i]>niz[maxind])
			maxind = i;
		}
		int nadjen=0;
		if(maxind == 0) maxind2 =1;
		for(i=0; i<n; i++){
		if(niz[i]>=niz[maxind2] && niz[i]<niz[maxind]){
			maxind2=i;
			nadjen=1;
		}	
		}
		if(nadjen == 0)
		maxind2 = -1;
		
	return maxind2;	
	}
	
	
	int main() {
	int niz[10000],i,max2;
	printf("Unesite niz brojeva: ");
	i=0;
		do{
			scanf("%d",&niz[i]);
			if(niz[i] == -1){
			//i--; 
			break;}
		    i++;	
		}while(i<10000);
		
	max2 = drugi(niz, i);
	
	printf("Indeks drugog po velicini je: %d", max2);
		
		
	return 0;
	}

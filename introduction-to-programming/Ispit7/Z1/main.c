#include <stdio.h>

int ImaLiDjelilaca(int a, int b){
	int i = 0;
	if(a > b){
		for(i=2; i <= b; i++){
			if(a % i == 0 && b % i == 0 ) return 1;
		}
	}
	else{
		for(i = 2; i <= a; i++){
				if(a % i == 0 && b % i == 0 ) return 1;
		}
		
	}
	return 0;
}

int Farey(double* niz, int n){
	int i = 0, j = 0, brojac = 1, max = 0;
	double temp;
	niz[0] = 0;
	if(n > 100) n = 100;
	for(i = 1; i < n; i++){
		for(j=i+1; j <= n; j++){ 
			if(brojac > 99) break;
			if(!ImaLiDjelilaca(i,j)) niz[brojac++] = (double)i/j;}
	}
	if(brojac < 100) niz[brojac++] = 1;

	for (i=0; i<brojac; i++) {
        max=i;
        for (j=i+1; j<brojac; j++) 
            if (niz[j] < niz[max])
                max = j;
        temp = niz[i];
        niz[i] = niz[max];
        niz[max] = temp;
    }
    return brojac;
	
}
int main() {
double niz[100];
int vel = Farey(niz, 50);
int i;
for (i=0; i<vel; i++) printf("%.3f ", niz[i]);


	return 0;
}

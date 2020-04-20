#include <stdio.h>

void sortiraj(double* niz, int vel){
	double* p = niz;
	double temp;
	double* min, *p2;
	
	
	for(p; p<niz+vel-1; p++){
		min = p;
		for(p2=p; p2<niz+vel; p2++){
			if(*min > *p2) min = p2;
		}
		
		temp = *p;
		*p = *min;
		*min = temp;
		
	}
	
}






int main(){
	
	return 0;
}
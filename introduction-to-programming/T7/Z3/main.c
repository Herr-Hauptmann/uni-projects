#include <stdio.h>


int prost(int x){
	int logika=1,i;
	if(x<2)
	return 0;
	for(i=2; i<x; i++){
		if(x%i==0) logika=0;
	}
	return logika;
}



int main() {
	int i;
	for(i=1; i<=100; i++){
		if(prost(i))		
		printf("%d \n",i);
	}
	return 0;
}

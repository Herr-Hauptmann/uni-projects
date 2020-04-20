#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	printf("Proba 1, Zadatak 8\n");
int temp,temp1,temp2,i,temp3;
i=0;
temp = 45654;
	
	while(temp!=0){
		temp=temp/10;
		i++;
	}
	printf("\n Temp je %d",i);
	return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	printf("Proba 1, Zadatak 8\n");
int temp,temp1,temp2,i,temp3=0;
scanf("%d", &temp);
i=0;
	
	while(temp!=0){
		temp1 = temp % 10;
		temp2 = (temp / 10) % 10;
		temp3=temp3 + abs((temp1-temp2)) * pow(10,i);
		temp = temp/10;
		if(temp/10==0) break;
		i++;
	}
	printf("\n Temp je %d",temp3);
	return 0;
}

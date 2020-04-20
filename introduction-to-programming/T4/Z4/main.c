#include <stdio.h>

int main() {
	int m,g;
	printf("Unesite mjesec: ");
	scanf("%d", &m);
	printf("Unesite godinu: ");
	scanf("%d", &g);
	
	
	switch(m){
		case 1:
		printf("Januar %d, broj dana: 31",g);
		break;
		
		case 2:
		if(g%4==0)
		printf("Februar %d, broj dana: 29",g);
		else
		printf("Februar %d, broj dana: 28",g);
		break;
		
		case 3:
		printf("Mart %d, broj dana: 31",g);
		break;
		
		case 4:
		printf("April %d, broj dana: 30",g);
		break;
		
		case 5:
		printf("Maj %d, broj dana: 31",g);
		break;
		
		case 6:
		printf("Juni %d, broj dana: 30",g);
		break;
		
		case 7:
		printf("Juli %d, broj dana: 31",g);
		break;
		
		case 8:
		printf("Avgust %d, broj dana: 31",g);
		break;
		
		case 9:
		printf("Septembar %d, broj dana: 30",g);
		break;
		
		case 10:
		printf("Oktobar %d, broj dana: 31",g);
		break;
		
		case 11:
		printf("Novembar %d, broj dana: 30",g);
		break;
		
		case 12:
		printf("Decembar %d, broj dana: 31",g);
		break;
	}
	return 0;
}

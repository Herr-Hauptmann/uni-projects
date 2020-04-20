#include <stdio.h>

int main() {
	int temp1,temp2,temp3;
	char S,M,B;
	printf("Unesite prognozu za Sarajevo: \n");
	printf("Temperatura:");
	scanf("%d",&temp1);
	printf(" Padavine (D/N): ");
	scanf(" %c", &S);
	while(S!='D' && S!='d' && S!='n' && S!='N'){
		printf("Pogresan unos. \n");
		printf("Padavine (D/N): ");
		scanf(" %c", &S);
	}
	printf("Unesite prognozu za Mostar: \n");
	printf("Temperatura:");
	scanf("%d",&temp2);
	printf(" Padavine (D/N): ");
	scanf(" %c", &M);
	while(M!='D' && M!='d' && M!='n' && M!='N'){
		printf("Pogresan unos. \n");
		printf("Padavine (D/N): ");
		scanf(" %c", &M);
	}
	printf("Unesite prognozu za Bihac: \n");
	printf("Temperatura:");
	scanf("%d",&temp3);
	printf(" Padavine (D/N): ");
	scanf(" %c", &B);
	while(B!='D' && B!='d' && B!='n' && B!='N'){
		printf("Pogresan unos. \n");
		printf("Padavine (D/N): ");
		scanf(" %c", &B);
	}
	
	if((S=='n' || S=='N')&&(((temp1>20)&&(temp1<30))||((temp1>-5)&&(temp1<5))))
	printf("Drugarice idu u Sarajevo.");
	else if((M=='n' || M=='N')&&(((temp2>20)&&(temp2<30))||((temp2>-5)&&(temp2<5))))
	printf("Drugarice idu u Mostar.");
	else if((B=='n' || B=='N')&&(((temp3>20)&&(temp3<30))||((temp3>-5)&&(temp3<5))))
	printf("Drugarice idu u Mostar.");
	else if((S=='d' || S=='D')&&(temp1>-5&&temp1<=0))
	printf("Anja i Elma mogu u Sarajevo.");
	else if((S=='n' || S=='N')&&(temp1>-5&&temp1<=30))
	printf("Anja i Elma mogu u Sarajevo.");
	else if((S=='n' || S=='N')&&(temp1<5||temp1>20))
	printf("Anja i Una mogu u Sarajevo.");
	else if((S=='n' || S=='N')&&((temp1>=-5&&temp1<5)||(temp1>20&&temp1<30)))
	printf("Elma i Una mogu u Sarajevo.");
	else if((M=='d' || M=='D')&&(temp2>-5&&temp2<=0))
	printf("Anja i Elma mogu u Mostar.");
	else if((M=='n' || M=='N')&&(temp2>-5&&temp2<=30))
	printf("Anja i Elma mogu u Mostar.");
	else if((M=='n' || M=='N')&&(temp2<5||temp2>20))
	printf("Anja i Una mogu u Mostar.");
	else if((M=='n' || M=='N')&&((temp2>=-5&&temp2<5)||(temp2>20&&temp2<30)))
	printf("Elma i Una mogu u Mostar.");
	else if((B=='d' || M=='D')&&(temp3>-5&&temp3<=0))
	printf("Anja i Elma mogu u Bihac.");
	else if((B=='n' || B=='N')&&(temp3>-5&&temp3<=30))
	printf("Anja i Elma mogu u Bihac.");
	else if((B=='n' || B=='N')&&(temp3<5||temp3>20))
	printf("Anja i Una mogu u Bihac.");
	else if((B=='n' || B=='N')&&((temp3>=-5&&temp3<5)||(temp3>20&&temp3<30)))
	printf("Elma i Una mogu u Bihac.");
	else
	printf("Ne odgovara niti jedan grad.");
	

	return 0;
}

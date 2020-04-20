#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main() {
	double novac=100000,zlato=1200,srebro=15,nafta=70,prZ,prS,prN,razlika;
	int rZlato, rSrebro,rNafta,G=1;
	double procenatZ=0, procenatS=0, procenatN=0, novacZlato=0, novacSrebro=0, novacNafta=0,U=0;
	int uncaZlata=0, uncaSrebra=0, barelNafte=0, izborG=1, izbor,izbor2, KuncaZlata=0, PuncaZlata=0,KuncaSrebra=0, PuncaSrebra=0,KbarelNafte=0,PbarelNafte=0;
	int G2=1;
	srand((0));

while(G==1){	
	for(int i=0; i<5; i++){
	//rZlato=rand()%2;
//	rSrebro=rand()%2;
//	rNafta=rand()%2;
	if(rand()%2==1)
	procenatZ+=0.1;
	else
	procenatZ-=0.1;
	if(rand()%2==1)
	procenatS+=0.1;
	else
	procenatS-=0.1;
	if(rand()%2==1)
	procenatN+=0.1;
	else
	procenatN-=0.1;

	
//	procenatZ=procenatZ+prZ;
	zlato=zlato+(procenatZ*zlato)/100;
	
//	procenatS=procenatS+prS;
	srebro=srebro+(procenatS*srebro)/100;
	
//	procenatN=procenatN+prN;
	nafta=nafta+(procenatN*nafta)/100;

	if(i==0)
	printf("PON: Zlato $%.2f (%+g) Srebro $%.2f (%+g) Nafta $%.2f (%+g) \n",zlato,procenatZ,srebro,procenatS,nafta,procenatN);
	if(i==1)
	printf("UTO: Zlato $%.2f (%+g) Srebro $%.2f (%+.1f) Nafta $%.2f (%+.1f) \n",zlato,procenatZ,srebro,procenatS,nafta,procenatN);
	if(i==2)
	printf("SRI: Zlato $%.2f (%+g) Srebro $%.2f (%+g) Nafta $%.2f (%+g) \n",zlato,procenatZ,srebro,procenatS,nafta,procenatN);
	if(i==3)
	printf("CET: Zlato $%.2f (%+g) Srebro $%.2f (%+g) Nafta $%.2f (%+g) \n",zlato,procenatZ,srebro,procenatS,nafta,procenatN);
	if(i==4)
	printf("PET: Zlato $%.2f (%+g) Srebro $%.2f (%+g) Nafta $%.2f (%+g) \n \n",zlato,procenatZ,srebro,procenatS,nafta,procenatN);
	

	}
	


	
while(G2==1){
	novacZlato=uncaZlata*zlato;
	novacSrebro=uncaSrebra*srebro;
	novacNafta=barelNafte*nafta;
	
	
	U=novac+novacZlato+novacNafta+novacSrebro;
	razlika=U-100000;
	
do {
	printf("\nImate:\nZlata: %d ($%.2f) Srebra: %d ($%.2f) Nafte: %d ($%.2f) Novca: $%.2f \n",uncaZlata,novacZlato,uncaSrebra,novacSrebro,barelNafte,novacNafta,novac);
	printf("UKUPNO: $%.2f ($%+.2f)\n \n",U,razlika);
	
	printf("Unesite izbor (1 - Kupi, 2 - Prodaj, 3 - Sljedeca sedmica, 0 - Kraj igre): ");
	scanf("%d",&izbor);
	if(izbor<0||izbor>3)
	printf("Pogresan izbor!\n");
	}while(izbor<-1||izbor>3);
	
	if(izbor==0)
    break;
   
    if(izbor==3)
    break;


	
	
	//Kupovina
		if(izbor==1){
		printf("Sta kupujete (1 - Zlato, 2 - Srebro, 3 - Naftu): ");
		scanf("%d",&izbor2);
		
		if(izbor2==1){
			printf("Koliko?");
			scanf("%d",&KuncaZlata);
			uncaZlata=uncaZlata+KuncaZlata;
			novac=novac-KuncaZlata*zlato;
			continue;
		}
		if(izbor2==2){
			printf("Koliko?");
			scanf("%d",&KuncaSrebra);
			uncaSrebra=uncaSrebra+KuncaSrebra;
			novac=novac-KuncaSrebra*srebro;
			continue;
		}
		if(izbor2==3){
			printf("Koliko?");
			scanf("%d",&KbarelNafte);
			barelNafte=barelNafte+KbarelNafte;
			novac=novac-KbarelNafte*nafta;
			continue;
		}
	
	}
		// Prodaja
		if(izbor==2){
			printf("Sta prodajete (1 - Zlato, 2 - Srebro, 3 - Naftu): ");
		scanf("%d",&izbor2);
		if(izbor2==1){
			do{
			printf("Koliko?");
			scanf("%d",&PuncaZlata);
			}while((uncaZlata-PuncaZlata)<0);
			uncaZlata=uncaZlata-PuncaZlata;
			novac=novac+PuncaZlata*zlato;
			continue;}
		}
		if(izbor2==2){
			do{
			printf("Koliko?");
			scanf("%d",&PuncaSrebra);
			}while((uncaSrebra-PuncaSrebra<0));
			uncaSrebra=uncaSrebra-PuncaSrebra;
			novac=novac+PuncaSrebra*srebro;
			continue;
		}
		if(izbor2==3){
			do{
			printf("Koliko?");
			scanf("%d",&PbarelNafte);
			}while((barelNafte-PbarelNafte)<0);
			barelNafte=barelNafte-PbarelNafte;
			novac=novac+PbarelNafte*nafta;
			continue;
		}
	}
	
	
	
	
	if(izbor==3)
	continue;
	if(izbor==0)
	break;
}
	



	
	
	

	return 0;
}

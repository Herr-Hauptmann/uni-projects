#include <stdio.h>
#include <math.h>

int broj_sadrzan(unsigned int a, unsigned int b){
	unsigned int temp,temp1,broj_cifara1=0,i,temp3,j;
	int logika=0;
	temp1=0;
	if(a==b) return 1;
	temp=b;
	while(temp!=0){
		broj_cifara1++;
		temp=temp/10;
		}
		if(b==0) broj_cifara1=1;
		
	temp1=a;
	temp=0;
	while(a!=0){
	temp3 =a;

	for(i=0,j=0; i<broj_cifara1; i++,j++){
			temp1=temp3%10;
			temp=temp+temp1*pow(10,j);
			temp3=temp3/10;
		}
		if (temp==b){
			logika=1;
			break;
		}
		temp=0;
		a=a/10;
		
	}
	return logika;
}

int main() {
	int a,b,flag;
	printf("Unesite broj a: ");
	scanf("%d",&a);
	printf("Unesite broj b: ");
	scanf("%d",&b);
	flag=broj_sadrzan(a,b);
	if(flag==1) printf("ISTINA");
	else printf("NEISTINA");
	


	return 0;
}

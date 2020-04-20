#include <stdio.h>

int main() {
	int a,b,c,max,min;
	printf("Unesite tri broja: ");
	scanf("%d %d %d", &a, &b, &c);
	if((a<50||a>200)||(b<50||b>200)||(c<50||c>200)){
		printf("Svi brojevi nisu iz intervala 50 do 200");
	}
	else {
		min=a;
		if(b<min)
		min=b;
		if(c<min)
		min=c;
		
		max=a;
		if(b>max)
		max=b;
		if(c>max)
		max=c;
	

	if(a==min&&b==max)
	printf("Brojevi poredani po velicini glase: %d,%d,%d", a,c,b);
	else if(a==max&&b==min)
	printf("Brojevi poredani po velicini glase: %d,%d,%d", b,c,a);
	else if(a==max&&c==min)
	printf("Brojevi poredani po velicini glase: %d,%d,%d", c,b,a);
	else if(c==max&&a==min)
	printf("Brojevi poredani po velicini glase: %d,%d,%d", a,b,c);
	else if(b==max&&c==min)
	printf("Brojevi poredani po velicini glase: %d,%d,%d", c,a,b);
	else if(c==max&&b==min){
	printf("Brojevi poredani po velicini glase: %d,%d,%d", b,a,c);}
	
	if(a!=b&&b!=c&&a!=c){
	printf("\nUnesena su 3 razlicita broja");}
	else if(a==b&&a==c&&c==b){
	printf("\nUnesen je 1 razlicit broj");}
	else if(a==b){
	printf("\nUnesena su 2 razlicita broja");}
	else if(a==c){
	printf("\nUnesena su 2 razlicita broja");}
	else if(b==c){
	printf("\nUnesena su 2 razlicita broja");}
	}
	return 0;
}



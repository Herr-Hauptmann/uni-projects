#include <stdio.h>

int main() {
	int a,b,c,d,e,f,g;
	printf("Unesite iznos: ");
	scanf("%d",&a);
	b=a/50;
	c=(a-b*50)/20;
	d=(a-b*50-c*20)/10;
	e=(a-b*50-c*20-d*10)/5;
	f=(a-b*50-c*20-d*10-5*e)/2;
	g=(a-b*50-c*20-d*10-5*e-2*f)/1;
	printf("%d novcanica od 50 KM\n",b);
	printf("%d novcanica od 20 KM\n",c);
	printf("%d novcanica od 10 KM\n",d);
	printf("%d novcanica od 5 KM\n",e);
	printf("%d novcanica od 2 KM\n",f);
	printf("%d novcanica od 1 KM\n",g);

	return 0;
}

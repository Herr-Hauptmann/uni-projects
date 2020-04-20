#include <stdio.h>
#include <math.h>
#define PI 3.14
int main() {
	float a,b,c,r,H,P,V;
	printf("Unesite stanice kvadra a,b,c");
	scanf("%f,%f,%f",&a,&b,&c);
	printf("Unesite poluprecnik r valjka i visinu H valjka");
	scanf("%f,%f",&r,&H);
	P=2*(a*b+a*c+b*c)+r*r*PI+2*r*PI;
	V=a*b*c+r*r*PI*H;
	printf("\n Povrsina tijela sa slike je %.3f cm2",P);
	printf("\n Zapremina tijela sa slike je %.3f cm3",V);

	return 0;
}

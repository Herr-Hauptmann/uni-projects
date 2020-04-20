#include <stdio.h>
#include <math.h>


long int faktorijel(int x){
	long int fakt=1;
	int i;
	for(i=1; i<=x; i++){
		fakt*=i;
	}
	
	return fakt;
}

double sinus(double x, int n){
	int i=0;
	double sinus=0;
	for(i=1; i<=n; i++){
		sinus+=pow(-1,i-1)*((pow(x,(2*i-1)))/(faktorijel(2*i-1)));
	}
	return sinus;
	
}

int main() {
	int n;
	double x,S,S2,razlika;
	printf("Unesite x: \n");
	scanf("%lf", &x);
	printf("Unesite n: \n");
	scanf("%d",&n);
	S = sinus(x, n);
	S2 = sin(x);
	printf("sin(x)=%.6f \n",S2);
	printf("sinus(x)=%.6f \n",S);
	razlika = fabs(S2 - S);
	
	printf("Razlika: %.6f (%.2f%%).", razlika,razlika);
	
	

	return 0;
}

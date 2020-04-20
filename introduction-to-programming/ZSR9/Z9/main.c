#include <stdio.h>
#include <math.h>

int UnesiRealan(const char* string, double* broj){
	const char* p=string;
	int i,brojac=0;
	int cifra=0,prava_cifra=0;
	double cifra1;
	while(*p!='\0'){
		if(!(*p>='0'&&*p<='9')&& *p!='.') return 0;
		if(*p=='.') brojac++;
		p++;
	}
	if(brojac>1) return 0;
	i=0;
	p=string;
	while(*p!='\0' && *p!='.'){
		cifra=cifra*10+(*p-'0');
		i++;
		p++;
		
	}
	if(*p=='\0'){
		*broj =(double) cifra;
		return 1;
	}
	else{
		p++;
		cifra1=0;
		i=1;
		while(*p!='\0'){
			cifra1=cifra1 + (*p-'0') * pow(10,-i);
			i++;
			p++;
			}
	}
	*broj = ( (double)cifra + cifra1);
	return 1;
}

int main() {
	char niz[]="123.123";
	double x;
	printf("%d",UnesiRealan(niz,&x));
	printf("%f",x);
	return 0;
}

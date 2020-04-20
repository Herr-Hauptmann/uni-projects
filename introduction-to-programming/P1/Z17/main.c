#include <stdio.h>

int trazi_broj(const char* s, int broj) {
	char sbroj[12];
	char* sb = sbroj;
	int tmp=broj;

	/* predznak */
	if (broj < 0) {
		broj = -broj;
		*sb++ = '-';
	}

	/* prebrojavamo cifre */
	do {
		sb++;
		tmp /= 10;
	} while (tmp != 0);
	*sb-- = '\0';

	do {
		*sb-- = broj % 10 + '0';
		broj /= 10;
	} while (broj != 0);
return 0;
}


int main() {
	char win[100]="C:\\Users\\M\\Desktop\\OET parcijalni";
	int brojac=0;
	char* p = win;
	
	while(*p!='\0'){
		if(*p=='\') brojac++;
		p++;
	}
	printf("%d",brojac);
	return 0;
}

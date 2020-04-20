#include <stdio.h>


/* pomocna funkcija koja ubacuje jedan space karakter ukoliko novi broj ima vise cifara od prvobitnog */
void push(char* s)
{
	char space,trenutni;
	space=' ';
	do {
		trenutni = *s;
		*s = space;
		space = trenutni;
	} while(*s++ != '\0');
}

/* funkcija dvostruko koja mnozi sve brojeve unutar stringa sa 2 */
char* dvostruko(char* string)
{
	char* ret = string;

	while(*string!='\0') {

		if(*string>='0' && *string<='9') {
			char* p = string;
			char* q;
			if(*p=='0') p++;
			/* logicka varijabla koja govori ako je cifra veca od 4 onda pomnozen broj ce imati vise cifri od prvobitnog */
			int jos_mjesta = *p > '4';
			int temp=0,temp2=0,temp3=0;

			/* petlja za pretvaranje cifri stringa u broj */
			while(*p>='0' && *p<='9') {
				temp=temp*10 + *p - '0';
				p++;
			}
			q=p;

			temp3=temp*2;
			if(jos_mjesta) {
				/* poziv pomocne funkcije za ubacivanje dodatnog space karaktera */
				push(p);
				/* petlja za zamjenu prvobitnog broja sa dobivenim brojem */
				while(temp3!=0 && p >= string ) {
					temp2=temp3%10;
					*p = '0' + temp2;
					temp3=temp3/10;
					p--;
				}


			} else {
				p--;
				while(temp3!=0 && p >= string ) {
					temp2=temp3%10;
					*p = '0' + temp2;
					temp3=temp3/10;
					p--;
				}
			}
			string = q;
		}
		string++;
	}
	return ret;
}
/* main program za provjeru funkcije */
int main()
{
	char tekst[100000]="broj 8 i broj 87.";
	dvostruko(tekst);

	printf("%s\n", tekst);
	return 0;
}

#include <stdio.h>
/* Funkcija za provjeru ispravnosti zagrada u stringu */
int provjeri_zagrade(char* string)
{
/* deklarisan pomocni pokazivac p za prolazak kroz string, logicke varijable za provjeru zagrada */
	char* p = string;
	int ima_zagrada=0,velika_zagrada=0,srednja_zagrada=0,mala_zagrada=0;
/* petlja za provjeru da li string uopste sadrzi zagrade */
	while(*p!='\0') {
		if(*p=='('||*p==')'||*p=='['||*p==']'||*p=='{'||*p=='}')
			ima_zagrada=1;
		p++;
	}
	if(ima_zagrada==0) return 1;
/* vracanje pokazivaca na pocetak stringa i petlja za provjeru ispravnosti zagrada uz pomoc logickih varijabli */
	p = string;
	while(*p !='\0') {
		if(*p=='{' && srednja_zagrada==0 && mala_zagrada==0 ) velika_zagrada=1;
		else if(*p=='{' && (srednja_zagrada==1|| mala_zagrada==1) ) return 0;
		else if(*p=='[' && mala_zagrada==0) srednja_zagrada=1;
		else if(*p=='[' && mala_zagrada==1) return 0;
		else if(*p=='(') mala_zagrada=1;
		else if(*p=='}'&& srednja_zagrada==0 && mala_zagrada==0 && velika_zagrada==1) velika_zagrada=0;
		else if(*p=='}'&& (srednja_zagrada==1||mala_zagrada==1)) return 0;
		else if(*p==']' && (mala_zagrada==0) && srednja_zagrada==1) srednja_zagrada=0;
		else if(*p==']' && (mala_zagrada==1)) return 0;
		else if(*p== ')' && mala_zagrada==1) mala_zagrada=0;
		else if(*p== ')' && (mala_zagrada==0||velika_zagrada==1||srednja_zagrada==1)) return 0;

		p++;
	}
	if(mala_zagrada==1||velika_zagrada==1||srednja_zagrada==1) return 0;
	return 1;
}

/* main za provjeru funkcije */
int main()
{
	char string[100]="[x)";
	printf("%d",provjeri_zagrade(string));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void izbaci_tekst(char* s, const char* sta){
	char* pozicija = strstr(s,sta);
	int vel = strlen(sta);
	while(pozicija){
		char* p = pozicija;
		char* q = pozicija + vel;
		while(*p++ = *q++);
		pozicija = strstr(s,sta);
	}
}
int ObrniCifre(int x){
	int ret = 0;
	int predznak = 1;
	if(x < 0) predznak = -1;
	do{
		ret = ret * 10 + x % 10;
		x /= 10;
	}while(x);
	ret = ret * predznak;
	return ret;
}
char* broj2string(int broj, char* s){
	char* ret = s;
	broj = ObrniCifre(broj);
	if(broj < 0) *s++ = '-';
	do{
	*s++ = broj%10 + '0';
	broj/=10;
	}while(broj);
	*s = '\0';
	return ret;
}
void izbaci_rijec(char* s, int n) {
	int razmak=1, broj_rijeci=0;
	char* pocetak;
	while (*s != '\0') {
		if (*s == ' ')
			razmak=1;
		else if (razmak == 1) {
			razmak=0;
			broj_rijeci++;
			if (broj_rijeci==n) pocetak=s;
			if (broj_rijeci==n+1) {
				while (*pocetak++ = *s++);
				return;
			}
		}
		s++;
	}
}



int JeLiBroj(char c){
	if(c >= '0' && c <= '9') return 1;
	return 0;
}



char* izbaci_maxbroj(char* s) //mogu koristit vec postojece funkcije kao indeks i to
{
char* ret = s;
int nebroj = 1, max = 0, broj = 0, predznak = 1, prvi = 1;
while(*s != '\0'){
	if(!JeLiBroj(*s) && predznak == -1) predznak = 1;
	if(!JeLiBroj(*s)) nebroj = 1;
	if(nebroj && JeLiBroj(*s)){
		nebroj = 0;
		broj = 0;
		char* p = s;
		while(*p != '\0' && JeLiBroj(*p)){
			broj = broj * 10 + (*p - '0');
			p++;
		}
		broj = predznak * broj;
		if(prvi){ 
			max = broj;
			prvi = 0;
		}
		if(broj > max) max = broj;
	}
	if(*s == '-') predznak = -1;
	s++;
}
char niz[100];
broj2string(max,niz);
izbaci_tekst(ret,niz);
return ret;

}


int main()
{
	char tekst[] = "Broj -123: broj -123 je veci od broja -56 koji je veći od -9 i -999";
	printf("%s", izbaci_maxbroj(tekst));
	return 0;
}

#include <stdio.h>
int DaLiJeBro(char c){
	if(c >= '0' && c <= '9') return 1;
	return 0;
}
int DuzinaBroja(int broj){
	int brojac = 0;
	do{
		brojac++;
		broj /= 10;
	}while(broj);
	return brojac;
}
int ObrniCifre(int broj){
	int ret = 0;
	do{
		ret = ret * 10 + (broj%10);
		broj/=10;
	}while(broj);
	return ret;
}
void UbaciUzv(char* p){
	char* kraj = p;
	while(*kraj != '\0') kraj++;
	while(kraj > p){
		*(kraj+1) = *kraj;
		kraj--;
	}
	p++;
	*p='!';
}
char* kompresuj(char* s) //welp, sretno sa ovim
{
	char* ret = s;
	while(*s != '\0'){
		char c = *s;
		char* p = s;
		if(*s == '!'){
			UbaciUzv(s);
			s=s+2;
			continue;
		}
		else{
		int brojac = 0;
		while(*p == c){
			brojac++;
			p++;
		}
		if(brojac > 3 && !DaLiJeBro(*s)){
		int pomak = brojac - 3;
		p = s;
		char* q = s + pomak;
		while(*q != '\0') {
		//	printf("%s\n",p);
			*p = *q;
			p++; q++;
		}
		*p = '\0';
		*s++ = '!';
		*s++ = c;
		if(brojac <= 9)	*s ='0' + brojac;
		else{
			int razmak = DuzinaBroja(brojac);
			p = s;
			while(*p != '\0') p++;
			while(p > s){
				*(p+razmak-1) = *p;
				p--;
			}
			int broj = ObrniCifre(brojac);
			while(broj){
				*s = '0' + (broj%10);
				broj /= 10;
				s++;
			}
			
			
		}
		}
		else{
		int pomak = brojac - 3;
		p = s;
		char* q = s + pomak;
		while(*q != '\0') {
		//	printf("%s\n",p);
			*p = *q;
			p++; q++;
		}
		*p = '\0';
		*s++ = '!';
		*s++ = c;
		*s = '0' + brojac;
		}
		}
		s++;
	}
	return ret;

}

char* dekompresuj(char* s){
	char* ret = s;
	while(*s != '\0'){
		s++;
	}
	return ret;
}

int main()
{
	char tekst[100] = "aaaa!bbbbcccccccccccc";
	printf("'%s'\n", kompresuj(tekst));
	return 0;
}

// Ovo je ujedno peti zadatak sa ispisima iz fajla or-rokovi-ispisi-i-mali-zadaci.pdf

#include<stdio.h>
struct predmeti{
	char naziv[20];
	char ime_prezime_nastavnika[25];
	int nesto;
}

int isto slovo(const char* s1){
char* p = s;
if(*p>='a' && *p<='z') *p=*p+'a'-'A';
while(*s!='\0') s++;
if(*p==*s) return 1;
else return 0;

	
}
	

int funkcija(struct predmeti *pr, int vel){
	int broj=0;
	for(i=0; i<vel; i++){
		if(funkcija(pr[i].naziv)) broj++;
		}
		return broj;
	
}

int main(){
	
	
}
	return 0;
}

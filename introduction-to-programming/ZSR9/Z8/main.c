#include <stdio.h>
int brojPonavljanja(char c, const char* s){
	int brojac = 0;
	if(c >= 'A' && c <= 'Z') c+=32;
	while(*s != '\0'){
		if(*s == c || (*s + 32) == c) brojac++;
		s++;
	}
	return brojac;
}
int KarakterUStringu(char c, const char* slova){
	const char* p = slova;
	if(c >= 'A' && c <= 'Z') c+=32;
	while(*p != '\0'){
		if(*p == c || (*p + 32) == c) return 1;
		p++;
	}
	return 0;
}
int Prebroji(const char* str, const char* slova){
	int brojac = 0;
	while(*str != '\0'){
		int ponavljanje = brojPonavljanja(*str,slova);
		if(KarakterUStringu(*str,slova)) brojac+=ponavljanje;
		str++;
	}
	return brojac;
}

int main() {
	printf("%d\n",Prebroji("Otorinolaringologija","oaG"));
	return 0;
}

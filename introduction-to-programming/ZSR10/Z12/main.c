#include <stdio.h>
#include <string.h>
void zamijeni_string_ubaci(char* s, const char* rijeci, const char* zamjene, int pomak)
{
	char* pozicija = strstr(s,rijeci);
	while(pozicija) {
		char* kraj = pozicija;
		while(kraj != '\0') kraj++;
		while(kraj > pozicija) {
			*(kraj+pomak) = *kraj;
			kraj--;
		}
		while(*zamjene != '\0') *pozicija++ = *zamjene++;
		pozicija = strstr(pozicija+pomak, rijeci);
	}
}

void zamijeni_string_izbaci(char* s, const char* rijeci, const char* zamjene, int pomak)
{
	char* pozicija = strstr(s, rijeci);
	while(pozicija) {
		char* tmp = pozicija;;
		while(*tmp != '\0') {
			*tmp = *(tmp+pomak);
			tmp++;
		}
		while(*zamjene != '\0') *pozicija++ = *zamjene++;
		pozicija=strstr(s, rijeci);
	}
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
	char* ret = tekst;
	int i=0;
	while(i<broj_rijeci){
	int pomak=strlen(zamjene[i]) - strlen(rijeci[i]);
	if(pomak > 0)
		zamijeni_string_ubaci(tekst, rijeci[i], zamjene[i], pomak);
	else
		zamijeni_string_izbaci(tekst, rijeci[i], zamjene[i], -pomak);
		i++;
	}

return ret;	
}




int main()
{
	printf("ZSR 10, Zadatak 12");
	return 0;
}

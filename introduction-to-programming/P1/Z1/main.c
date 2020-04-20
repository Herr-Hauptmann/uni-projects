/* STRINGOVI FUNKCIJE */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* STR LEN */
int duzina(char* s) {
	int duz=0;
	while (*s++) duz++;
	return duz;
}
/* strchr koliko se puta znak ponavlja u stringu */
int prebroji(const char* s, char znak) {
	int broj=0;
	if (znak >= 'A' && znak <= 'Z')
		znak += 'a' - 'A';
	while (*s != '\0') {
		char tmp = *s;
		if (tmp >= 'A' && tmp <= 'Z')
			tmp += 'a' - 'A';
		if (tmp == znak) broj++;
		s++;
	}
	return broj;
}

/* STRCMP vraca -1 ako je  1.<2., 1 ako je 2. < 1. i 0 ako su jednaki */
int uporedi(const char* s1, const char* s2) {
	while (*s1 != '\0' && *s2 != '\0') {
		if (*s1 < *s2) return -1;
		if (*s1 > *s2) return 1;
		s1++;
		s2++;
	}
	if (*s1 != '\0') return 1;
	if (*s2 != '\0') return -1;
	return 0;
}
/* strcat spaja dva stringa vraca pokazivac na prvi */
char* spoji(char* s1, const char* s2) {
	char* ret = s1;
	while (*s1++);
	s1--;
	while (*s1++ = *s2++);
	return ret;
}
/* STRSTR pronalazi podstring, vraca pokazivac na prvo ponavaljanje */
const char* podstring(const char* s1, const char* s2) {
	while (*s1 != '\0') {
		const char* p = s1;
		const char* q = s2;
		while (*p++ == *q++)
			if (*q == '\0') return s1;
		s1++;
	}
	return NULL;
}


/* provjerava da li se broj nalazi u stringu, potrebna podstring() za rad */
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
if (podstring(s, sbroj)) return 1;
	return 0;
}

/* druga varijanta iste funkcije */
int trazi_broj1(const char* s, int broj) {
	int tmp, predznak=1;
	while (*s != '\0') {
		if (*s == '-') predznak = -1;
		else if (*s >= '0' && *s <='9') {
			tmp = 0;
			while (*s >= '0' && *s <= '9') {
				tmp = tmp * 10 + *s - '0';
				s++;
			}
			if (tmp * predznak == broj) return 1;
			s--;
		} 
		else predznak = 1;
		s++;
	}
	return 0;
}
/* trazi rijec u stringu, rijec se definiše kao niz karaktera razdvojenih sa jednim ili više znakova razmak. */
int trazi_rijec(const char* s1, const char* s2) {
	while (*s1 != '\0') {
		while (*s1 == ' ') s1++;
		const char* p = s1;
		const char* q = s2;
		while (*p++ == *q++)
			if (*q == '\0' && (*p == ' ' || 
				*p == '\0')) return 1;
		while (*s1 != ' ' && *s1 != '\0')
			s1++;
	}
	return 0;
}


/*rijec se definiše kao niz karaktera razdvojenih sa jednim ili više znakova razmak. */
void izbaci_ntu_rijec(char* s, int n) {
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
	if (broj_rijeci == n) *pocetak = '\0';
}

/* FIND AND REPLACE */
void zamijeni_string_ubaci(char* s, const char* pretraga, const char* zamjena, int pomak){
	char* pozicija = strstr(s,pretraga);
	while(pozicija){
		char* kraj = pozicija;
		while(kraj != '\0') kraj++;
		while(kraj > pozicija){
			*(kraj+pomak) = *kraj;
			kraj--;
		}
		while(*zamjena != '\0') *pozicija++ = *zamjena++;
		pozicija = strstr(pozicija+pomak, pretraga);
	}
}

void zamijeni_string_izbaci(char* s, const char* pretraga, const char* zamjena, int pomak){
	char* pozicija = strstr(s, pretraga);
	while(pozicija){
		char* tmp = pozicija;;
		while(*tmp != '\0'){
			*tmp = *(tmp+pomak);
			tmp++;
		}
		while(*zamjena != '\0') *pozicija++ = *zamjena++;
		pozicija=strstr(s, pretraga);
	}
}

void zamijeni_string(char* s, const char* pretraga, const char* zamjena){
	int pomak=strlen(zamjena) - strlen(pretraga);
	if(pomak > 0)
		zamijeni_string_ubaci(s, pretraga, zamjena, pomak);
	else
		zamijeni_string_izbaci(s, pretraga, zamjena, -pomak);
}



































int main() {
	int r,k;
	printf("Proba 1, Zadatak 1");
	srand(0);
	for(int i=0; i<5; i++){
	r=rand()%2;
	if(r==0)
	k=-1.;
	if(r==1)
	k=1;
	
	
	printf("K je %d \n",k);
	
		
		
	}
	return 0;
}

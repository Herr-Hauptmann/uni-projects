#include <stdio.h>
#include <math.h>
#include <string.h>
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

int IspravnoSlovo(char c){
	char niz[] = "AEJKMOT";
	for(int i = 0; i < 6; i++) if(niz[i] == c) return 1;
	return 0;
}

char DajSljedeceSlovo(char c){
	char niz[] = "AEJKMOT";
	int index = 0;
	for(int i = 0; i < 6; i++) if(niz[i] == c) index = i;
	if(index==6) return 'T';
	return niz[index+1];
}


int GenerisiTablice (const char *prethodna, char *nova){
	char* p = prethodna;
	int i = 0;
	int vel = strlen(prethodna);
	if(strlen(prethodna) != 9) return -1;
	if(!IspravnoSlovo(p[0]) || !IspravnoSlovo(p[4])) return -1;
	for(i=1; i < 3; i++){
		if(!(p[i] >= '0' && p[i] <= '9')) return -1;
	}
	if(p[3] != '-' || p[5] != '-') return -1;
	for(i=6; i < 9; i++) if(!(p[i] >= '0' && p[i] <= '9')) return -1;
	if(strcmp(prethodna,"T99-T-999") == 0) return 0;
	char c1 = p[0];
	char c2 = p[4];
	int broj1 = (p[1] -'0') * 10 + (p[2] -'0');
	int broj2 = (p[6] - '0') * 100 + (p[7] - '0') * 10 + (p[8] - '0');
	//printf("%d , %d \n",broj1,broj2);
	if(broj2 == 999){
		if(broj1 == 99){
			if(c2 == 'T'){
				c1 = DajSljedeceSlovo(c1);
				nova[0] = c1;
				nova[1] = '\0';
				strcat(nova,"00-A-000");
				return 1;
			}
			else{
				c2 = DajSljedeceSlovo(c2);
				nova[0] = c1;
				nova[1] = '\0';
				strcat(nova,"00-");
				nova[4] = c2;
				nova[5] = '\0';
				strcat(nova,"-000");
				return 1;
			}
			
		}
		
	}
	else{
		broj2++;
	if(broj2 < 10){
	for(i = 0; i < 8; i++ )	nova[i] = prethodna[i];
	nova[8] = '0' + (broj2 % 10);
	nova[9] = '\0';
	}
	if(broj2 >= 10 && broj2 <= 99){
	for(i = 0; i < 6; i++) nova[i] = prethodna[i];
	nova[6] = '0';
	nova[8] = broj2 % 10 + '0';
	broj2 /= 10;
	nova[7] = '0' + broj2;
	nova[9] = '\0';
	}
	if(broj2 >= 100){
		for(int i = 0; i < 6; i++) nova[i] = prethodna[i];
		nova[8] = broj2 % 10 + '0';
		broj2 /= 10;
		nova[7] = broj2 % 10 + '0';
		broj2 /= 10;
		nova[6] = broj2 + '0';
		nova[9] = '\0';
	}
	return 1;
	}

	
	return 0;
}

int main() {
char tablica[15] = "A00-A-009";
char nova[15], t2[15], t3[15];
printf("%d ",GenerisiTablice (tablica, nova));
printf("%s\n", nova);
printf("%d ",GenerisiTablice (nova, t2));
printf("%s\n", t2);
printf("%d ",GenerisiTablice (t2, t3));
printf("%s\n", t3);
	return 0;
}

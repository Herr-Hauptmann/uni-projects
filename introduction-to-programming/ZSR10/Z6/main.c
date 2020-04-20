#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *ZamijeniTekst1 (char *Str, const char *sta, const char *sa_cim, int cs)
{
	int len1=0,len2=0,razlika;
	char* ret=Str;
	char* s = Str;
	char* q, *p;
	const char* v=sta;
	while(*v++!='\0') len1++;
	v=sa_cim;
	while(*v!='\0') {
		len2++;
		v++;
	}
	razlika=len1-len2;
	int br=abs(razlika);


	if(cs==1) {
		while(*s!='\0') {
			if(*s==*sta) {
				q=s;
				v=sta;
				while(*v!='\0') {
					if(*q!=*v) break;
					v++;
					q++;
				}
				if(*v=='\0') {
					if(razlika==0) {
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
					if(razlika>0) {
						p=q-br;
						while(*q!='\0') *p++=*q++;
						*p='\0';
						q=s;
						v=sa_cim;
						while(*v!='\0') {
							*q=*v;
							q++;
							v++;

						}
					}
					if(razlika<0) {
						p=q--;

						while(*p!='\0') p++;
						while(p>q) {
							*(p+br)=*p;
							p--;
						}
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
				}
			}
			s++;
		}
	}


	if(cs==0) {
		while(*s!='\0') {
			if(*s==*sta || (*s+32)==*sta || (*s-32)==*sta) {
				q=s;
				v=sta;
				while(*v!='\0') {
					if(*q!=*v && (*q-32)!=*v && (*q+32)!=*v) break;
					v++;
					q++;
				}

				if(*v=='\0') {
					if(razlika==0) {
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
					if(razlika>0) {
						p=q-br;
						while(*q!='\0') *p++=*q++;
						*p='\0';
						q=s;
						v=sa_cim;
						while(*v!='\0') {
							*q=*v;
							q++;
							v++;

						}
					}
					if(razlika<0) {
						p=q--;

						while(*p!='\0') p++;
						while(p>q) {
							*(p+br)=*p;
							p--;
						}
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
				}
			}
			s++;
		}
	}
	return ret;
}
char* strstrInsensitive(char* str, const char* pretraga){
	while(*str != '\0'){
		if(*str == *pretraga || (*str - 32) == *pretraga || (*str + 32) == *pretraga){
			const char* p = str;
			const char* q = pretraga;
			while(*p != '\0' && (*p == *q || (*p + 32) == *q || (*p - 32) == *q) & *q != '\0'){
				p++; q++;
			}
			if(*q == '\0') return str;
		}
		str++;
	}
	return NULL;
}
void ZamijeniTekstUbaci(char* str, const char* sta, const char* sa_cim, int pomak, int cs){
	if(cs){
		char* pozicija = strstr(str,sta);
		while(pozicija){
			char* p = pozicija;
			char* kraj = pozicija;
			while(*kraj != '\0') kraj++;
			while(kraj > p){
				*(kraj + pomak) = *kraj;
				kraj--;
			}
			while(*sa_cim != '\0') *p++ = *sa_cim++;
			pozicija=strstr(pozicija+pomak,sta);
		}
	}
	else{
			char* pozicija = strstrInsensitive(str,sta);
		    while(pozicija){
			char* p = pozicija;
			char* kraj = pozicija;
			while(*kraj != '\0') kraj++;
			while(kraj > p){
				*(kraj + pomak) = *kraj;
				kraj--;
			}
			while(*sa_cim != '\0') *p++ = *sa_cim++;
			pozicija=strstrInsensitive(pozicija+pomak,sta);
		}
		
	}
}

void ZamijeniTekstIzbaci(char* str, const char* sta, const char* sa_cim, int pomak, int cs){
	if(cs){
		char* pozicija = strstr(str,sta);
		while(pozicija){
			char* p = pozicija;
			char* q = pozicija + pomak;
			while(*q != '\0') *p++ = *q++;
			p = pozicija;
			while(*sa_cim != '\0') *p++ = *sa_cim++;
			pozicija = strstr(pozicija+pomak,sta);
		}
	}
	else{
		char* pozicija = strstrInsensitive(str,sta);
		while(pozicija){
			char* p = pozicija;
			char* q = pozicija + pomak;
			while(*q != '\0') *p++ = *q++;
			p = pozicija;
			while(*sa_cim != '\0') *p++ = *sa_cim++;
			pozicija = strstrInsensitive(pozicija+pomak,sta);
		}
	}
}

char* ZamijeniTekst(char* str, const char* sta, const char* sa_cim, int cs){
	int pomak = strlen(sa_cim) - strlen(sta);
	if(pomak > 0) ZamijeniTekstUbaci(str,sta,sa_cim,pomak,cs);
	else ZamijeniTekstIzbaci(str,sta,sa_cim,-pomak,cs);
	return str;
}

int main()
{
	char tekst[100] = "  Zeko   pije   CAJ.  Pije caj mali zeko!";

	zamijeni_string(tekst, "caj", "mlijeko"); //cs = 01
	printf ("'%s'", tekst);
	return 0;
}

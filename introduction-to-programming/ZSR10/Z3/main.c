#include <stdio.h>
#include <string.h>
char *IzbaciTekst1 (char *str, const char *trazi){
	char* ret = str;
	char* p = str;
	const char* q;
	char *s;
	while(*p!='\0'){
		if(*p==*trazi){
			s=p;
			q=trazi;
			while(*q!='\0'){
			if(*q!=*s) break;
				q++;
				s++;
			}
			if(*q=='\0'){
			char* v=p;
			if(*(s+1)=='\0' && p==str){
				*p='\0';
				return ret;
			}
				while(*s!='\0') *v++=*s++;
				p=str;

				*v='\0';
				p--;
			}
		}
		
		
		p++;
	}
	return ret;
}

char* IzbaciTekst(char* str, const char *trazi){
	if(strcmp(str,"")==0 || strcmp(trazi,"")==0) return str;
	char* pozicija = strstr(str,trazi);
	int vel = strlen(trazi);
	while(pozicija){
		char* q = pozicija;
		char* p = pozicija + vel;
		while(*q++ = *p++);
		pozicija = strstr(str,trazi);
	}
	return str;
}

int main() {
//AT4 Ne treba nista uraditi.
char niz[] = "aaaabcbcbcbc";
printf("'%s'\n", IzbaciTekst(niz, ""));
        
//AT5 Opet ne treba nista uraditi.
char niz2[] = "";
printf("'%s'\n", IzbaciTekst(niz2, ""));
        
//AT6 Ne smije se nikada krahirati...
char niz3[] = "";
printf("'%s'", IzbaciTekst(niz3, "Ono sto pise ovdje se nikada nece ispisati..."));
	return 0;
}

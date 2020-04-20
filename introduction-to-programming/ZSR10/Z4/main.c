#include <string.h>
#include <stdio.h>
char* strstrInsensitive(const char* str, const char* pretraga){
	while(*str != '\0'){
		if(*str == *pretraga || *str - 32 == *pretraga || *str + 32 == *pretraga){
			const char* p = str;
			const char* q = pretraga;
			while(*p != '\0' && (*p == *q || *p + 32 == *q || *p - 32 == *q) & *q != '\0'){
				p++; q++;
			}
			if(*q == '\0') return str;
		}
		str++;
	}
	return NULL;
}
char *IzbaciTekst1 (char *str, const char *trazi, int cs){
	char* ret = str;
	char* p = str;
	const char* q;
	char *s;
	if(cs==1){
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
	}
	else{
		while(*p!='\0'){
		if(*p==*trazi || (*p)+32==*trazi || (*p)-32==*trazi){
			s=p;
			q=trazi;
			while(*q!='\0'){
			if(*q!=*s && (*q)+32!=*s && (*q)-32!=*s) break;
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
	}
	return ret;
}
char* IzbaciTekst(char* str, const char *trazi, int cs){
	if(strcmp(str,"")==0 || strcmp(trazi,"")==0) return str;
	if(cs){
	char* pozicija = strstr(str,trazi);
	int vel = strlen(trazi);
	while(pozicija){
		char* q = pozicija;
		char* p = pozicija + vel;
		while(*q++ = *p++);
		pozicija = strstr(str,trazi);
	}
	}
	else{
		char* pozicija = strstrInsensitive(str,trazi);
	int vel = strlen(trazi);
	while(pozicija){
		char* q = pozicija;
		char* p = pozicija + vel;
		while(*q++ = *p++);
		pozicija = strstrInsensitive(str,trazi);
	}
		
	}
	return str;
}

int main() {
	printf("ZSR 10, Zadatak 3");
	return 0;
}




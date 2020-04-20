#include <stdio.h>

char* whitespace(char* s){
	char* p = s;
	int razmak=1;
	
	while(*s!='\0'){
		if (*s=='\n' || *s=='\t')
		*s=' ';
		if (*s==' ' && razmak==1){
			char *s1=s;
			while(*s1!='\0'){
				*s1=*(s1+1);
				s1++;
			}
			s--;
		}
		else if (*s==' ') razmak=1;
		else razmak=0;
		if(*(s+1)=='\0' && *s==' ')
		*s='\0';
		s++;
	}
	return p;
}

int main() {
	printf("Tutorijal 10, Zadatak 4");
	return 0;
}

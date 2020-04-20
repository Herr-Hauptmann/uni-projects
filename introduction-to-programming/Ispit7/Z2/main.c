#include <stdio.h>
int JeLiSlovo(char c){
	if((c >='a' && c<='z') || (c >='A' && c <= 'Z')) return 1;
	return 0;
}

void pocetna_slova(const char* string, char* string2, int k){
	char* s= string;
	int brojsl;
	int razmak = 1;
	int i = 0;
	while(*s != '\0'){
		if(JeLiSlovo(*s) && razmak){
			razmak = 0;
			char* p = s;
			brojsl = 0;
			while(*p != '\0' && JeLiSlovo(*p)){
				brojsl++;
				p++;
			}
			if(brojsl > k) string2[i++] = *s;
			s = p;
			if(*p == '\0') break;
			razmak = 1;
		}
		else{
			razmak = 1;
		}
		s++;
	}
	string2[i] = '\0';
}

int main() {
char buf[100];
pocetna_slova("z", buf, 1);
printf("'%s'\n", buf);
pocetna_slova("z", buf, 0);
printf("'%s'\n", buf);


	return 0;
}

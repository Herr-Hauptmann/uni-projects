#include <stdio.h>
void IspisiUnazad(const char* s){
	if(*s!='\0'){
		IspisiUnazad(s+1);
		printf("%c",*s);
	}
}


int main() {
	char s[]="Ispisi me unazad.";
	IspisiUnazad(s);
	printf("%s",s);
	return 0;
}

#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}


char* rot13 (char* s){
	char* p = s;
	while(*p!='\0'){
		if(*p>='A' && *p<='Z'){
			if(*p<'N')
			*p+=13;
			else  *p-=13;}
		
		else if(*p>='a'&&*p<='z'){
			if(*p<'n')
			*p+=13;
			else *p-=13;
		}
		
		p++;
	}
	
return s; }                                                     



 int main() {
	/* char string[100];
	unesi(string,100);
	rot13(string);
	printf("%s",string); */
	return 0;
} 

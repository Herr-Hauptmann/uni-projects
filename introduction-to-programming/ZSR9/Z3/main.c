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


char* velika(char* s){
	char* ret = s;
	while(*s!='\0'){
		if(*s>='a' && *s<='z') *s-=32;
		s++;
	}
	return ret;
}

int main() {
	char string[100];
	printf("Unesite neki tekst: ");
	unesi(string,100);
	printf("%s",velika(string));
	
	return 0;
}

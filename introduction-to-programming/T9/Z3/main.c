#include <stdio.h>
void unesi(char niz[], int velicina)
{
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


char* kapitaliziraj(char *p)
{
	char* s=p;
	while(*s!='\0') {
		if(s==p || *(s-1)==' ') {
			if(*s>='a'&&*s<='z') {
				*s-=32;
			}
		}
		s++;
	}
	return p;
}

int main()
{
	char rijec[100];
	printf("Unesite neki tekst: ");
	unesi(rijec, 100);
	printf("%s",kapitaliziraj(rijec));
	return 0;
}

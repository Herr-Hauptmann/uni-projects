#include <stdio.h>
int strcmpi(const char* s1, const char* s2,int velikamala)
{
	char p1, p2;

	while(*s1!='\0' && *s2!='\0') {
		if(!velikamala) {
			if(*s1>='A' && *s1<='Z') p1 = *s1 -'A' + 'a';
			else p1 = *s1;
			if(*s2>='A' && *s2<='Z') p2 = *s2 - 'A'+ 'a';
			else p2 = *s2;
			if(p1 < p2) return -1;
			if(p2 > p2) return 1;
		}
		else{
		if(*s1 < *s2) return -1;
		if(*s1 > *s2) return 1;
		}
		s1++;
		s2++;

	}
	if(*s1!='\0') return 1;
	if(*s2!='\0') return -1;

	return 0;
}


int main()
{
	printf("Tutorijal 9, Zadatak 6");
	return 0;
}

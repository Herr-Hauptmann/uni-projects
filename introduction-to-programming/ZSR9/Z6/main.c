#include <stdio.h>
#include <string.h>
char* PopuniLijevo(char* s, int n){
	int i = 0;
	char* ret = s;
	char* poc = s;
	if(n <= 0 || n <= strlen(s)) return ret;
	int pomak = n - strlen(s);
	char* kraj = s;
	while(*kraj != '\0') kraj++;
	while(kraj >= s){
		*(kraj + pomak) = *kraj,
		kraj--;
	}
	for(i = 0; i < pomak; i++) *s++ = ' ';
	return ret;
}

char* PopuniDesno(char* s, int n){
	int i = 0;
	char* ret = s;
	if(n <= 0 || n <= strlen(s)) return ret;
	int pomak = n - strlen(s);
	while(*s != '\0') s++;
	for(i = 0; i < pomak; i++) *s++ = ' ';
	*s = '\0';
	return ret;
}
int main() {
	char n1[100] = "Bosna", n2[100] = "Hercegovina";
    char *p1 = PopuniLijevo(n1, 15);
    char *p2 = PopuniLijevo(n2, 15);
    printf ("'%s'\n'%s'", p1, p2);
	return 0;
}

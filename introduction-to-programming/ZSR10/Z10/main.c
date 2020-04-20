#include <stdio.h>
char* prebroji (char* tekst, char* slova){
	char* ret = slova;
	char* s = tekst;
	int i,j,max,temp;
	int niz[26]={0};
	while(*s!='\0'){
		if(*s>='A'&&*s<='Z') niz[*s-'A']++;
		if(*s>='a'&&*s<='z') niz[*s-'a']++;
		s++;
	}
	for(i=0; i<26; i++){
		max=0;
		for(j=0; j<26; j++)	if(niz[j]>niz[max]) max=j;

		if(niz[max]==0) break;
		*slova='A'+max;
		slova++;
		niz[max]=0;
	}
	*slova='\0';
	
	return ret;
	
}


int main() {
	printf("ZSR 10, Zadatak 10");
	return 0;
}

#include <stdio.h>


char max_slovo(char* string){
	int brojaci[26]={0};
	int max,i;
	while(*string != '\0'){
		if(*string>='A' && *string<='Z') brojaci[*string-'A']++;
		if(*string>='a' && *string<='z') brojaci[*string-'a']++;
		string++;
	}
	max=0;
	for(i=0; i<26; i++){
		if(brojaci[max] < brojaci[i]) max = i;
	}
	
	return 'A' + max;
}

int main() {
	printf("Tutorijal 9, Zadatak 4");
	return 0;
}

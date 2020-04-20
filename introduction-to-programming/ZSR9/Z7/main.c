#include <stdio.h>
int JeLiSlovoBroj(char c){
	if((c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z') || (c >= '0' && c <= '9')) return 1;
	return 0;
}
int JeLiPalindrom(const char* str){
	const char* p1 = str;
	const char* p2 = str;
	while(*p2 != '\0') p2++;
	p2--;
	
	while(p1 < p2 && *p1 != '\0' && p2 != str ){
		while(!JeLiSlovoBroj(*p1)) p1++;
		while(!JeLiSlovoBroj(*p2)) p2--;
		if(*p1 != *p2 && *p1 != (*p2+32) && *p1 != (*p2-32)) return 0;
		p1++;
		p2--;

	}
	
	return 1;
}


int main() {
	printf("%d",JeLiPalindrom("  Ana voli... Milovana!"));
	return 0;
}

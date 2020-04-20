#include <stdio.h>
char* izbaci_rijec(char *string, int n){
	int brojac=0;
	int kojaPoRedu=0;
	char *p = string;
	while(*p!='\0'){
		if((*p>='A'&&*p<='Z')||(*p>='a'&&*p<='z'))
		brojac++;
		else{
			if(brojac>0){
				kojaPoRedu++;
				
				if(kojaPoRedu == n){
					char* pp = p;
					while(*pp != '\0'){
						*(pp-brojac) = *pp;
						pp++;
					}
					*(pp-brojac) = '\0';
				} brojac = 0;
				
			}
		}
		
		
		p++;
	}
	return string;}
int main() {
	char string[100]="zasto ne prolazi auto-testove?";
	izbaci_rijec(string,1);
	printf("%s",string);
	return 0;
}

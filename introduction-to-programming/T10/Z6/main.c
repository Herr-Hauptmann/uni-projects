#include <stdio.h>

char* tritacke(char* s){
	char* p = s;
	while(*s!='\0'){
		if(*s!=' '){
			int br=1;
			while(*(s+br)!=' ' && *(s+br)!='\0'){
				br++;
			}
			if(br>=10){
				*(s+3)='.';
				int i=4;
				while(*(s+i)!='\0' && *(s+br-1)!='\0'){
					*(s+i)=*(s+br);
					i++;
					br++;
				}
			}
		}
		
		
		s++;
	}
	return p;
	
	
}
int main(){
	
	return 0;
}
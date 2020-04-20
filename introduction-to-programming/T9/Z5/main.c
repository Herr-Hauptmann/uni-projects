#include <stdio.h>

int prva_rijec(char* s){
	char* p = s;
	char* prvo;
	int flag=0,broj=0;
	while(*p!='\0'){
		if(*p!=' ') flag=1;
		if(*p==' ' || *(p+1)=='\0'){
			if(flag==1) broj++;
			if(broj==1) prvo=p;
			flag=0;
		}
		p++;
	}
	if(broj!=1) *prvo='\0';
    return broj; 
	
}

int main() {
	printf("Tutorijal 9, Zadatak 5");
	return 0;
}

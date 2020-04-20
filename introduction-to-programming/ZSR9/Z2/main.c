#include <stdio.h>

char* PosljednjaRijec(char* s){
	
	char* p = s;
	char* ret1=s;
	char* ret;
	while(*p!='\0'){
		if(((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) &&  (p==s || *(p-1)==' ')) ret1 = p;
		p++;
	}
	ret=ret1;
	while(*ret!='\0'){
		if(*ret==' ') {
			*ret='\0';
			break;
		}
		ret++;
	}
	return ret1;
}

int main() {
	printf("ZSR 9, Zadatak 1");
	return 0;
}

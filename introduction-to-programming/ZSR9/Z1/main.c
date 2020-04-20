#include <stdio.h>

char* PosljednjaRijec(char* s){
	char* p = s;
	char* ret=s;
	while(*p!='\0'){
		if(((*p>='a' && *p<='z') || (*p>='A' && *p<='Z')) && (p == s || *(p-1)==' ')) ret = p;
		p++;
	}
	return ret;
}

int main() {
	char rijec[] = "Mirza";
	printf("%s",PosljednjaRijec(rijec));
	return 0;
}

#include <stdio.h>

int PronadjiPosljednji(const char* s, const char* trazi){
	int logika,flag=0;
	const char* ret =s;
	const char* p = s;
	const char* q = trazi;
	const char* d;
	while(*s!='\0'){
		if(*s==*trazi || *s==*trazi-32 || *s==*trazi+32){
			p=s;
			q=trazi;
			logika=1;
			while(*q!='\0'){
				if(*q!=*p && *q!=*p+32 && *q!=*p-32){
					logika=0;
					break;
				}
				q++;
				p++;
			}
			if(logika==1){
				d=s;
				flag=1;
			}
	}
			s++;

	}
	if(flag) return (int)(d-ret);
	else return -1;
} 

int main() {
	printf("ZSR 10, Zadatak 1");
	return 0;
}

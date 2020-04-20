#include <stdio.h>
int ObrniBroj(int x){
	int ret = 0;
	while(x){
		ret = ret * 10 + x%10;
		x/=10;
	}
	return ret;
}

int PronadjiPosljednji1(const char* s, const char* trazi){
	int logika,flag=0;
	const char* ret =s;
	const char* p = s;
	const char* q = trazi;
	const char* d;
	while(*s!='\0'){
		if(*s==*trazi){
			p=s;
			q=trazi;
			logika=1;
			while(*q!='\0'){
				if(*q!=*p){
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

int PronadjiPosljednji(const char* s, const char* trazi){
	const char* poc = s;
	int ret = -1;
	while(*s != '\0'){
		if(*s == *trazi){
			const char* p = s;
			const char* q = trazi;
			while(*p!='\0' && *q!='\0' && *p == *q){
				p++;
				q++;
			}
			if(*q == '\0') ret = s - poc; 
		}
		s++;
	}
	return ret;
}

int main() {
printf ("%d", PronadjiPosljednji("abc cde abc", "abc"));
	return 0;
}

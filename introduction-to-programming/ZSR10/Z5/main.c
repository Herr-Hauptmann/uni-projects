#include <stdio.h>

void NtaRijec (const char *Str, char *rijec, int n){
	const char* s = Str;
	int logika=1,redni_broj=0;
	while(*s!='\0'){
		if(!(*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z')) logika=1;
		if(((*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z')) && logika==1){
			redni_broj++;
			logika=0;
			if(redni_broj==n){
			const char* p = s;
		 while((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z')){
		 	*rijec=*p;
		 	p++;
		 	rijec++;
		 }
		 *rijec='\0';
		 
		}
		}

		

		s++;
	}
	if(redni_broj<n) *rijec='\0';
}


int main() {
	const char *tekst = "ovo,je.jako-nepismen tekst .";
char rijec[101];
NtaRijec(tekst, rijec, 3); 
printf ("3. rijec: '%s'", rijec);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
char *ZamijeniRijec (char *Str, const char *sta, const char *sa_cim, int cs)
{
	int len1=0,len2=0,razlika,razmak=1;
	char* ret=Str;
	char* s = Str;
	char* q, *p;
	const char* v=sta;
	while(*v++!='\0') len1++;
	v=sa_cim;
	while(*v!='\0') {
		len2++;
		v++;
	}
	razlika=len1-len2;
	int br=abs(razlika);


	if(cs==1) {
		while(*s!='\0') {
		if(*s==' ') razmak=1;
		
			if(*s==*sta && razmak==1) {
				razmak=0;
				q=s;
				v=sta;
				while(*v!='\0') {
					if(*q!=*v) break;
					v++;
					q++;
				}
				if(*v=='\0' && *q==' ') {
					if(razlika==0) {
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
					if(razlika>0) {
						p=q-br;
						while(*q!='\0') *p++=*q++;
						*p='\0';
						q=s;
						v=sa_cim;
						while(*v!='\0') {
							*q=*v;
							q++;
							v++;

						}
					}
					if(razlika<0) {
						p=q--;

						while(*p!='\0') p++;
						while(p>q) {
							*(p+br)=*p;
							p--;
						}
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
				}
			}
			s++;
		}
	}


	if(cs==0) {

		while(*s!='\0') {
			if(*s==' ') razmak=1;
			if((*s==*sta || (*s+32)==*sta || (*s-32)==*sta)&& razmak==1) {

				razmak=0;
				q=s;
				v=sta;
				while(*v!='\0') {
					if(*q!=*v && (*q-32)!=*v && (*q+32)!=*v) break;
					v++;
					q++;
				}


				if(*v=='\0' && (*q==' '||*q=='.'||*q=='\0') && (s==ret || *(s-1)==' ')) {
					if(razlika==0) {
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
					if(razlika>0) {
						p=q-br;
						while(*q!='\0') *p++=*q++;
						*p='\0';
						q=s;
						v=sa_cim;
						while(*v!='\0') {
							*q=*v;
							q++;
							v++;

						}
					}
					if(razlika<0) {

						p=q--;

						while(*p!='\0') p++;
						while(p>q) {
							*(p+br)=*p;
							p--;
						}
						q=s;
						v=sa_cim;
						while(*v!='\0') *q++=*v++;
					}
				}
			}
			s++;
		}
	}
	return ret;
}

int main()
{
	char tekst[100] = "  Zeko   pije   CAJ.  Pije  mali zeko!";
	ZamijeniRijec (tekst, "caj", "mlijeko", 0); //cs = 0
	printf ("'%s'", tekst);
	return 0;
}

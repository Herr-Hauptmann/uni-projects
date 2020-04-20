#include <stdio.h>

char* apsolutna(char* rel, char* tek)
{

	char* ret = rel;
	int brojac1=0, brojac2=0;
	char* p1 = rel;
	char* p2 = tek;

	while(*p2!='\0') p2++;
	while(*p1!='\0') p1++;


	while(p1>=rel) {
		if(*p1=='\\' && *(p1-1)=='.' && *(p1-2)=='.') {
			brojac1++;
		}
		p1--;
	}
	if(brojac1!=0) {

		if(*(p2-1)=='\\') p2=p2-2;


		while(p2>=tek) {
			if(*p2=='\\') {
				brojac2++;
				if(brojac2 == brojac1) break;
			}
			p2--;
		}

		int razmak = p2 - tek + 1;
		p1 = rel;
		char* p3 = rel;
		while(*p1=='.' || *p1=='\\') p1++;
		char* p5 = p1;
		while(*p1!=0) {
			*p3 = *p1;
			p1++;
			p3++;
		}
		*p3='\0';
		p1=rel;
		while(p3>=p1) {
			*(p3+razmak) = *p3;
			p3--;
		}
		p3 = rel;
		char* p4 = tek;
		while(p4<=p2) {
			*p3=*p4;
			p3++;
			p4++;

		}
	}


	if(brojac1==0) {
		int razmak = p2 - tek + 1;
		p1 = rel;
		char* p3 = rel;
		while(*p1=='.' || *p1=='\\') p1++;
		char* p5 = p1;
		while(*p1!=0) {
			*p3 = *p1;
			p1++;
			p3++;
		}
		*p3='\0';
		p1=rel;
		while(p3>=p1) {
			*(p3+razmak) = *p3;
			p3--;
		}
		p3 = rel;
		char* p4 = tek;
		while(p4!='\0') {
			*p3=*p4;
			p3++;
			p4++;

		}
	}



	return ret;
}

int main()
{
//	char rel[100] = "..\\.\\dir1\\file.txt";
//	printf("%s", apsolutna(rel, "C:\\Users\\Student\\Desktop\\"));

	char rel[100] = "dir1\\file.txt";
	printf("%s", apsolutna(rel, "C:\\Users\\Student\\Desktop"));
	return 0;
}

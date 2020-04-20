#include <stdio.h>
#define G 2018

int main() {
	int gd,d;
	char s, m='m', M='M',z='z',Z='Z';
	printf("Unesite godinu rodjenja osobe:");
	scanf("%d",&gd);
	if(gd>G) {
	printf("Neispravna godina rodjenja!"); }
	else  {
	printf("Unesite spol osobe (m/M ili z/Z");
	scanf(" %c",&s);
		
		if(s==M||s==m||s==z||s==Z) {
		d=G-gd;
		if(d<=6&&(s==M||s==m)){
			printf("Osoba ima %d godina/e/u, klasificirana je u kategorij: 'osnovna skola', musko je.",d);
		}
		else if (d<=6&&(s==Z||s==z)){
			printf("Osoba ima %d godina/e/u, klasificirana je u kategorij: 'osnovna skola', zensko je.",d);
		}
		else if((d>14&&d<18)&&(s==M||s==m)){
			printf("Osoba ima %d godina/e/u, klasificirana je u kategorij: 'srednja skola', musko je.",d);
		}
		else if((d>14&&d<18)&&(s==Z||s==z)){
			printf("Osoba ima %d godina/e/u, klasificirana je u kategorij: 'srednja skola', zensko je.",d);
		}
		
		
	}
	
	}
	else {
		printf("Unos spola je pogresan!");
	}

return 0;
	}
	
	


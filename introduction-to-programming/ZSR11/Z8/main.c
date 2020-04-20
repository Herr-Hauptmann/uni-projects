#include <stdio.h>
struct Kompleksni {
	int Im, Re;
} Kompleksni;



int KonjugovanoKompleksni (struct Kompleksni *p1, struct Kompleksni *p2,struct Kompleksni *rez)
{
    int i,j, brojac=0;
    char* q, *p;
    while(p1<p2){
    	q=p1;
    	while(q<p2){
    		if(*p1->Re==*q->Re && *p1->Im == -(*q->Im)){
    			*rez++=*p1;
    			*rez++=*q;
    			brojac=brojac+2;
    			break;
    		}
    		
    		q++;
    	}
    	p1++;
    }
    return brojac;
}


int main() {
	printf("ZSR 11, Zadatak 4");
	return 0;
}

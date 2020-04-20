#include <stdio.h>

struct Tacka {
double x,y;
};
struct Pravougaonik {
struct Tacka dolje_lijevo;
struct Tacka gore_desno;
};

struct Pravougaonik min_pravougaonik(struct Tacka* niz, int vel){
	int i,j;
	double minx, miny, maxx, maxy;
	struct Pravougaonik p;
	
	minx=niz[0].x;
	for(i=0; i<vel; i++){
		if(niz[i].x<minx) minx=niz[i].x;
	}
	
		miny=niz[0].y;
	for(i=0; i<vel; i++){
		if(niz[i].y<miny) miny=niz[i].y;
	}
	
	maxx=niz[0].x;
	for(i=0; i<vel; i++){
		if(niz[i].x>maxx) maxx=niz[i].x;
	}
	
		maxy=niz[0].y;
	for(i=0; i<vel; i++){
		if(niz[i].y>maxy) maxy=niz[i].y;
	}
	
	p.gore_desno.x=maxx;
	p.gore_desno.y=maxy;
	p.dolje_lijevo.x=minx;
	p.dolje_lijevo.y=miny;
	
	return p;
	
	
	
}


int main() {
	int i;
	int broj_tacaka;
	struct Tacka niz[1000];
	struct Pravougaonik p2;
	printf("Unesite broj tacaka: ");
	scanf("%d",&broj_tacaka);
	for(i=0; i<broj_tacaka; i++){
		printf("Unesite koordinate x i y tacke %d: ",i+1);
		scanf("%lf %lf",&niz[i].x, &niz[i].y);
	}
	p2=min_pravougaonik(niz,broj_tacaka);
	printf("%g %g  %g %g", p2.gore_desno.x, p2.gore_desno.y, p2.dolje_lijevo.x, p2.dolje_lijevo.y);
	return 0;
}

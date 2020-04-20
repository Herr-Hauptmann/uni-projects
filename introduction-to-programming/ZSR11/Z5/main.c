#include <stdio.h>
struct Tacka {
    int x,y;
};
struct Pravougaonik{
	struct Tacka t;
	int sirina,visina;
};

int CrtajPravougaonike(struct Pravougaonik *niz, int vel){
	int i,j,k,brojac=0;
	struct Tacka max;
	max.x=0;
	max.y=0;
	char matrica[100][100]={' '};
	for(i=0; i<vel; i++){
		if(niz[i].t.x > 0 && niz[i].t.y>0 && niz[i].t.x < 100 && niz[i].t.y<100){
			brojac++;
			if(niz[i].t.x+niz[i].sirina>100) niz[i].sirina = niz[i].sirina - (niz[i].t.x+niz[i].sirina-100);
			if(niz[i].t.y+niz[i].visina>100) niz[i].visina = niz[i].visina - (niz[i].t.y+niz[i].visina-100);
			if(niz[i].t.x+niz[i].sirina>max.x) max.x=niz[i].t.x;
			if(niz[i].t.y+niz[i].visina>max.y) max.y=niz[i].t.y;

			for(j=niz[i].t.y; j<niz[i].visina; j++){
				for(k=niz[i].t.x; k<niz[i].sirina; k++){
				if(j==niz[i].t.y || j==niz[i].visina-1) matrica[j][k]='*';
				else{
					if(k==niz[i].t.x || k==niz[i].sirina-1) matrica[j][k]='*';
				}
			}
			printf("\n");

		}
	}
	}
	
	for(i=0; i<max.y; i++){
		for(j=0; j<max.x; j++){
			printf("%c",matrica[i][j]);
		}
		printf("\n");
	}
return brojac;	
}


int main() {
struct Pravougaonik niz[3] ={{{1, 1}, 5, 3}, {{3, 3}, 7, 6},{{ 5, 7}, 5, 3}};
CrtajPravougaonike(niz,3);

	return 0;
}

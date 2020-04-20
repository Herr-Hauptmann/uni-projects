#include <stdio.h>
#include <math.h>
struct Tacka {
int x,y;
};
struct Trougao {
struct Tacka A,B,C;
};
int izbaci_pravougle(struct Trougao* niz, int vel){
	int i,j;
	struct Tacka AB, AC,BC;
	for(i=0; i<vel; i++){
	AB.x=niz[i].B.x-niz[i].A.x;
	AB.y=niz[i].B.y-niz[i].A.y;
	AC.x=niz[i].C.x-niz[i].A.x;
	AC.y=niz[i].C.y-niz[i].A.y;
	BC.x=niz[i].C.x-niz[i].B.x;
	BC.y=niz[i].C.y-niz[i].B.y;
	
	if(AB.x*AC.x+AB.y*AC.y==0 || AB.x*BC.x+AB.y*BC.y==0 || BC.x*AC.x+BC.y*AC.y==0 ){
		for(j=i+1; j<vel; j++) niz[j-1]=niz[j];
		i--;
		vel--;
	}

	
	}
	return vel;
}

int main() {
	/* AT1: Osnovni test */
struct Trougao trouglovi[3];
int i, vel;
/* Jeste pravougli */ 
trouglovi[0].A.x=0; trouglovi[0].A.y=0; 
trouglovi[0].B.x=1; trouglovi[0].B.y=0; 
trouglovi[0].C.x=0; trouglovi[0].C.y=1; 
/* Jeste pravougli */
trouglovi[1].A.x=0; trouglovi[1].A.y=0; 
trouglovi[1].B.x=1; trouglovi[1].B.y=1; 
trouglovi[1].C.x=0; trouglovi[1].C.y=1; 
/* Nije pravougli */
trouglovi[2].A.x=0; trouglovi[2].A.y=0; 
trouglovi[2].B.x=1; trouglovi[2].B.y=1; 
trouglovi[2].C.x=2; trouglovi[2].C.y=1; 

/* Izbacivanje */
vel = izbaci_pravougle(trouglovi, 3);
for (i=0; i<vel; i++) {
   printf("Trougao %d: (%d,%d)-(%d,%d)-(%d,%d)\n", i, 
   trouglovi[i].A.x, trouglovi[i].A.y, trouglovi[i].B.x, trouglovi[i].B.y, 
   trouglovi[i].C.x, trouglovi[i].C.y);
}
	return 0;
}

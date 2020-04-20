#include <stdio.h>
struct Tacka {
    double x,y;
};
struct Tacka unos_tacke() {
    struct Tacka t;
    printf ("Unesite koordinate tacke (x, y): \n");
    scanf ("%lf,%lf", &t.x, &t.y);
    return t;
}
struct Cetverougao {
struct Tacka A,B,C,D;
};

struct Tacka OduzmiTacke(struct Tacka a, struct Tacka b){
    struct Tacka c;
    c.x = b.x - a.x;
    c.y = b.y - a.y;
}
int SkalarniProizvod(struct Tacka a, struct Tacka b){
    return a.x*b.x + a.y*b.y;
}
struct Cetverougao unos_cetverougla(){
    struct Cetverougao c;
    printf("Unesite tacku A: \n");
    c.A=unos_tacke();
    printf("Unesite tacku B: \n");
    c.B=unos_tacke();
    printf("Unesite tacku C: \n");
    c.C=unos_tacke();
    printf("Unesite tacku D: \n");
    c.D=unos_tacke();
    return c;
}

int pravougaonik(struct Cetverougao c){
    struct Tacka AB,BC,CD,DA;
    AB = OduzmiTacke(c.A,c.B);
    BC = OduzmiTacke(c.B,c.C);
    CD = OduzmiTacke(c.C,c.D);
    DA = OduzmiTacke(c.D,c.A);
    if(SkalarniProizvod(AB,BC) == 0 && SkalarniProizvod(BC,CD)==0 && SkalarniProizvod(CD,DA)==0 && SkalarniProizvod(AB,DA)==0) return 1;
    return 0;
}
int kvadrat(struct Cetverougao c){
    if(!pravougaonik(c)) return 0;
    
}


int main() {
	printf("ZSR 11, Zadatak 4");
	return 0;
}

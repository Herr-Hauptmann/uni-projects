#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define  PI 4*atan(1)

/* Definicija tacke i kruznice */
struct Tacka {
    double x,y;
};
struct Kruznica {
    struct Tacka centar;
    double poluprecnik;
};

struct Pravougaonik {
    struct Tacka dole_lijevo;
    struct Tacka gore_desno;

};

/* Funkcije za unos */
struct Tacka unos_tacke()
{
    struct Tacka t;
    printf ("Unesite koordinate tacke (x, y): \n");
    scanf ("%lf,%lf", &t.x, &t.y);
    return t;
}

struct Kruznica unos_kruznice()
{
    struct Kruznica k;
    printf ("Unesite centar kruznice:\n");
    k.centar = unos_tacke();
    printf ("Unesite poluprecnik kruznice: \n");
    scanf("%lf", &k.poluprecnik);
    return k;
}

struct Pravougaonik unos_pravougaonika()
{
    struct Pravougaonik p;
    printf("Unesite donju lijevu tacku pravougaonika:\n");
    p.dole_lijevo=unos_tacke();
    printf("Unesite gornju desnu tacku pravougaonika:\n");
    p.gore_desno=unos_tacke();
}

/* Funkcija za udaljenost izmedju dvije tacke */
float udaljenost(struct Tacka t1, struct Tacka t2)
{
    return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

double obim_kruznice(struct Kruznica k)
{
    double obim;
    double r = k.poluprecnik;
    obim = 2*r*PI;
    return obim;
}
double povrsina_kruznice(struct Kruznica k)
{
    double povrsina;
    double r = k.poluprecnik;
    povrsina = r*r*PI;
    return povrsina;
}

double povrsina_pravougaonika(struct Pravougaonik p)
{
    double a, b, povrsina;
    a= abs(p.dole_lijevo.x - p.gore_desno.x);
    b= abs(p.dole_lijevo.y - p.gore_desno.y);
    povrsina = a * b;
    return povrsina;
}

double obim_pravougaonika(struct Pravougaonik p)
{
    double a, b, obim;
    a= abs(p.dole_lijevo.x - p.gore_desno.x);
    b= abs(p.dole_lijevo.y - p.gore_desno.y);
    obim = 2*a + 2*b;
    return obim;
}

int tacka_u_pravougaoniku(struct Tacka t, struct Pravougaonik p)
{
    int flag=0;
    if(p.dole_lijevo.x <= t.x && t.x <= p.gore_desno.x && p.dole_lijevo.y <= t.y && t.y <= p.gore_desno.y) flag=1;
    return flag;
}

/* Glavni program: Da li je tacka unutar kruznice */
int main()
{
    struct Kruznica k;
    struct Tacka t;
    double d;
    printf ("Unesite kruznicu:\n");
    k = unos_kruznice();
    printf ("Unesite neku tacku:\n");
    t = unos_tacke();

    /* Tacka se nalazi unutar kruznice ako je udaljenost tacke od centra
    kruznice manja od poluprecnika kruznice */
    d = udaljenost(t, k.centar);
    if (d<k.poluprecnik)
        printf("Tacka je unutar kruznice.");
    else if (d==k.poluprecnik)
        printf("Tacka je na kruznici.");
    else
        printf("Tacka je izvan kruznice.");

    printf("\nObim kruznice: %.3f\n",obim_kruznice(k));
    printf("Povrsina kruznice: %.3f\n",povrsina_kruznice(k));

    return 0;
}

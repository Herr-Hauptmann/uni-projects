#include <stdio.h>
/* funkcija kao parametre uzima matrice A i B te njihove visine (v1,v2) i sirine (s1,s2) */
int matrica_sadrzana(int m1[][100],int v1,int s1,int m2[][100],int v2, int s2)
{
	/* deklarisemo promjenljive n1 i n2 koje predstavljaju razlike v1-v2,s1-s2, te logicku varijablu sadrzana */
	int n1,n2,i,j,k,l,sadrzana=1;
	if(s1<s2||v1<v2)
		return 0;
	n1=v1-v2;
	n2=s1-s2;
	/* sa cetiri petlje prolazimo kroz elemente svih podmatrica formata v2xs2 matrice A i uporedjujemo ih sa elementima matrice B
	prve dvije petlje sluze sa pomicanje podmatrice formata v2xs2 matrice A kroz sve moguce polozaje,
	a preostale 2 petlje sluze sa uporedjivanje elemenata trenutne podmatrice i elemenata matrice B */
	for(i=0; i<=n1; i++) {
		for(j=0; j<=n2; j++) {
			sadrzana=1;

			for(k=0; k<v2; k++) {
				for(l=0; l<s2; l++) {
					if(m1[k+i][l+j]!=m2[k][l]) sadrzana=0;
				}
			}
			if (sadrzana==1) return 1;
		}

	}
	return 0;
}

/* main program za provjeru funkcije */
int main()
{
	int sadrzana,v1 = 4,s1 = 5,v2 = 3,s2 = 2;
	int matricaA[100][100] = {
		{   1,   2,   3,   4,   5, },
		{   6,   7,   8,   9,  10, },
		{  11,  12,  13,  14,  15, },
		{  16,  17,  18,  19,  20, },
	};
	int matricaB[100][100] = {
		{   2,   3, },
		{   7,   8, },
		{  12,  13, },
	};

	sadrzana=matrica_sadrzana(matricaA,v1,s1,matricaB,v2,s2);
	printf("%d",sadrzana);

	return 0;
}

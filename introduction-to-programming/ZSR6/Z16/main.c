#include <stdio.h>

int main()
{
	int matricaA[100][100],matricaB[100][100],i,j,m,n,duzina,matricaC[100][100]= {0},visina1,duzina1,visina2,duzina2,k;
	printf("Unesite elemente 1. matrice: ");
	i=0;
	j=0;
	do {
		scanf("%d",&matricaA[i][j]);
		if(matricaA[i][j]==-1) {
			if(i==0) {
				duzina = j;
				j=0;
			}
			if(i!=0) {
				if(j!=duzina) {

					printf("Ovo nije matrica!");
					return 0;
				} else j=0;
			}

			i++;
			continue;
		}
		if(matricaA[i][j]==-2) {
			i++;
			if(j!=duzina) {
			
				printf("Ovo nije matrica!");
				return 0;
			}
			break;

		}
		j++;

		if(i>100 || j>100) {
			printf("Prekoracena dimenzija matrice!");
			return 1;
		}
	} while(1);

	visina1=i;
	duzina1=j;

	printf("Unesite elemente 2. matrice: ");
	m=0;
	n=0;
	do {
		scanf("%d",&matricaB[m][n]);
		if(matricaB[m][n]==-1) {
			if(m==0) {
				duzina = n;
				n=0;

			}
			if(m!=0) {
				if(n!=duzina) {
					printf("Ovo nije matrica!");
					return 0;
				} else n=0;
			}

			m++;
			continue;

		}
		if(matricaB[m][n]==-2) {
			m++;
			if(n!=duzina) {
				printf("Ovo nije matrica!");
				return 0;
			}
			break;
		}
		n++;
		if(m>100 || n>100) {
			printf("Prekoracena dimenzija matrice!");
			return 1;
		}

	} while(1);

	visina2=m;
	duzina2=n;

//	printf("duzina1 %d visina %d", duzina1,visina2);
	if(duzina1!=visina2) {
		printf("Matrice nisu pogodne za mnozenje.");
		return 0;
	}
	int suma=0;
	for(i=0; i<visina1; i++) {
		for(j=0; j<duzina2; j++) {
			suma=0;
			for(k=0; k<duzina1; k++) {
				suma+=matricaA[i][k]*matricaB[k][j];
			}
			matricaC[i][j] = suma;

		}
	}


	printf("Matrice su pogodne za mnozenje. Matricni proizvod je: \n");
	for(i=0; i<visina1; i++) {
		for(j=0; j<duzina2; j++) printf("%5d",matricaC[i][j]);
		printf("\n");
	}











	return 0;
}

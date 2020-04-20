#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Ocjena{
	char naziv_predmeta[100];
	int ocjena;
};
struct Student{
	char ime[20],prezime[20];
	int br_ocjena;
	struct Ocjena ocjene[100];
};
struct StudentBINARY{
	char ime[20],prezime[20];
	int br_ocjena;
	struct Ocjena ocjene[100];
	double prosjek;
	int vrijednost_tipa;
};

int main() {
	struct Student Student[100];
	struct StudentBINARY StudentBINARY[100];
	
	int i,j;
	FILE* ulaz, *izlaz;
		if ((ulaz = fopen("ocjene.txt","r")) == NULL) {
		printf("Greska prilikom otvaranja datoteke ocjene.txt");
		exit(1);
	}

	if ((ulaz = fopen("ocjene.dat","wb")) == NULL) {
		printf("Greska pri otvaranju datoteke ispit.txt");
		fclose(ulaz);
		exit(1);
	}

	i=0,j=0;
	while(i<100 && fscanf(ulaz,"%s %s,%d,%s,%d,",Student[i].ime,Student[i].prezime,&Student[i].br_ocjena,Student[i].ocjene[0].naziv_predmeta,&Student[i].ocjene[0].ocjena)==5){
	if(Student[i].br_ocjena>1){
		j=1;
		while(j<=Student[i].br_ocjena && fscanf(ulaz,"%s,%d,",Student[i].ocjene[j].naziv_predmeta,&Student[i].ocjene[j].ocjena)==2) j++;
		
	}
	i++;
		
	}
	
	int vel = i;
	double prosjek=0;
	int ukupno=0;
	for(i=0; i<vel; i++){
		prosjek=0;
		strcpy(StudentBINARY[i].ime,Student[i].ime);
		strcpy(StudentBINARY[i].prezime,Student[i].prezime);
		StudentBINARY[i].br_ocjena = Student[i].br_ocjena;
		for(j=0; j<Student[i].br_ocjena; j++){
		strcpy(StudentBINARY[i].ocjene[j].naziv_predmeta,Student[i].ocjene[j].naziv_predmeta);
		StudentBINARY[i].ocjene[j].ocjena = Student[i].ocjene[j].ocjena;
		prosjek=prosjek+Student[i].ocjene[j].ocjena;
		}
		StudentBINARY[i].prosjek = prosjek / Student[i].br_ocjena;
		StudentBINARY[i].vrijednost_tipa = sizeof(double);
		
	}
		
	int zapisano = fwrite(StudentBINARY, sizeof(struct StudentBINARY), vel, izlaz);
	fclose(ulaz);
	fclose(izlaz);
	
	
	

	return 0;
}

#include <stdio.h>
#include <string.h>
int JeLiSlovo(char c){
	if((c>='a'&&c<='z') || (c>='A'&&c<='Z')) return 1;
	return 0;
}

struct Planina {
	char naziv[51];
	int visina;
};

int ucitaj(struct Planina* planine, int vel){
	FILE* ulaz = fopen("planine.txt","r");
	if(ulaz==NULL) return 0;
	char naziv[55];
	int velp = 0;
	int visina = 0;
	int c = 200;
	int i = 0;
	while(i < vel && c != EOF){
		c = fgetc(ulaz);
		if(c == EOF) break;
		if(JeLiSlovo(c)){
			int br = 0;
			int j = 0;
			while(c != EOF && (JeLiSlovo(c) || c ==' ')){
				if (j < 50) naziv[br++] = c;
				c = fgetc(ulaz);
				j++;
			}
			if(naziv[br-1] == ' ') naziv[br-1] = '\0';
			naziv[br] = '\0';
			visina = 0;
			//c = fgetc(ulaz);
			while(c != EOF && c != '\n'){
				visina = visina * 10 + c - '0';
				c = fgetc(ulaz);
			}
			strcpy(planine[velp].naziv,naziv);
			planine[velp].visina = visina;
			velp++;
		}
		else{
			int d = 0;
			visina = 0;
			int br = 0;
			int j = 0;
			while(c != ' '){
				visina = visina * 10 + c - '0';
				c = fgetc(ulaz);
			}
			c = fgetc(ulaz);
			while(c != EOF && c != '\n'){
				if(j < 50) naziv[br++] = c;
				c = fgetc(ulaz);
				j++;
			}
			naziv[br] = '\0';
			strcpy(planine[velp].naziv,naziv);
			planine[velp].visina = visina;
			velp++;
		}
	i++;
	}
	fclose(ulaz);
	return velp;
}

int zapisi(struct Planina* planine, int vel){
	FILE* izlaz = fopen("planine.dat","ab");
	if(izlaz == NULL) return 0;
	int zapisano = fwrite(planine, sizeof(struct Planina), vel, izlaz);
	fclose(izlaz);
	return zapisano;
}

int sadrzi(const char* s){
	int malo=0, veliko=0;
	while(*s != '\0'){
		if(*s == 'A') veliko = 1;
		if(*s == 'a') malo = 1;
		s++;
	}
	if(malo || veliko) return 1;
	return 0;
}
void ispis(struct Planina* planine, int vel){
	int max_i = 0;
	int flag = 0;
	int i = 0;
	for(i = 0; i < vel; i++){
	if(sadrzi(planine[i].naziv) && planine[i].visina < 2000){ 
		max_i = i;
		flag = 1;
		break;
	}	
	}
	if(!flag) return;
	for(i=1; i < vel; i++){
		if(sadrzi(planine[i].naziv) && planine[i].visina > planine[max_i].visina && planine[i].visina < 2000) max_i = i;
	}
	printf("%s %d\n",planine[max_i].naziv,planine[max_i].visina);
}

int main() {

struct Planina planine[1000] = {
	{ "Bjelasnica", 2067},
	{ "Trebevic", 1627},
	{ "Jahorina",  1913},
	{ "Mount Everest", 8848}
};
int vel=4;
ispis(planine, vel);
planine[0].visina = 1967;
ispis(planine, vel);
	return 0;
}

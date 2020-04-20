#include <stdio.h>
void Izbaci(char *s,int vel){

while(*(s+vel-1)!='\0'){//sablon izbacivanja vel broja znakova iz stringa
    *s=*(s+vel);
    s++;
}
}
void Ubaci(char *s,char *rijec){

    char *pom=rijec;
    int vel=0;

    while(*pom!='\0')pom++;//trazim velicinu rijecu koju ubacujemo
    vel=pom-rijec;

    char *kraj=s;
    while(*kraj!='\0')kraj++;

    while(kraj>=s){//sablon ubacivanja vel mjesta u string Npr: Danas je dan!, da na mjesto slova d ubacimo 5 mjesta bilo bi
            //Danas je xxxx dan! (gdje x su nevazni charovi jer prepisujemo preko njih)
        *(kraj+vel)=*kraj;
        kraj--;
    }
    kraj++;//ima neki bug nmg se sjetit

    while(*rijec!='\0'){//prepisivanje rijeci
        *kraj=*rijec;
        kraj++;
        rijec++;
    }

}


char *ZamijeniRijec (char *Str, const char *sta, const char *sa_cim){

char *pocetak=Str;

int indeks=0;
int vel2=0,vel1=0;
char* k2=sa_cim;
char* k1=sta;

while(*k2!='\0')k2++;
vel2=k2-sa_cim;//velicina stringova

while(*k1!='\0')k1++;
vel1=k1-sta;//velicine stringova



    

 Izbaci(Str+indeks,vel1);//izbacimo prvu rijec pa ubacimo drugu rijec
 Ubaci(Str+indeks,sa_cim);//                      ^^



return pocetak;


}










char* zamijeni_min_max(char* string) {
	int brojaci[1000]={0},razmak=1,i=0,j=0;
	char* p = string;

	while(*p!='\0'){
		if(*p==' '|| *p=='.' || *p==',' || *p==';' || *p=='!' || *p=='?')
		razmak=1;
		else if(razmak==1 && ((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z'))){
			char* p1 = p;
			i++;
			while((*p1>='a'&&*p1<='z')||(*p1>='A'&&*p1<='Z')){
				brojaci[i]++;
				p1++;
			}
			razmak=0;
		}
	
		p++;
	}
		int max=brojaci[1];
		int pozicija_max=1;
		for(j=2; j<=i; j++){
			if(brojaci[j]>max){
			max=brojaci[j];
			pozicija_max=j;
			}
		}
	
		int min=brojaci[1];
		int pozicija_min=1;
			for(j=2; j<=i; j++){
			if(brojaci[j]>max){
			max=brojaci[j];
			pozicija_max=j;
			}
		}
		
		char* p_max, *p_max2;
		char* p_min, *p_min2;
		p=string;
		razmak=1;
		i=0;
		while(*p!='\0'){
			if(*p==' '|| *p=='.' || *p==',' || *p==';' || *p=='!' || *p=='?')
		razmak=1;
		else if(razmak==1 && ((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z'))){
			
			i++;
			if(i==pozicija_max) p_max = p;
			if(i==pozicija_min) p_min = p;
			
			razmak=0;}
			p++;
		}
		
		char minstr[100];
		char maxstr[100];
		int s=0;
		p_min2=p_min;
		while(*p_min!=' '&& *p_min!='.' && *p_min!=',' && *p_min!=';' && *p_min!='!' && *p_min!='?'){
			minstr[s] = *p_min;
			s++;
			p_min++;
			
		}
		minstr[s+1]='\0';
		s=0;
		p_max2=p_max;
		while(*p_max!=' '&& *p_max!='.' && *p_max!=',' && *p_max!=';' && *p_max!='!' && *p_max!='?'){
			maxstr[s] = *p_max;
			s++;
			p_max++;
			
		}
		maxstr[s+1]='\0';
		p_max=maxstr;
		p_min=minstr;
		
		ZamijeniRijec(string,p_max,p_min);
	
	
	
	
	return p;} 




int main() {
	char niz[1000]="Danas je lijep dan veomalijepdan.";
	zamijeni_min_max(niz);
	printf("%s",niz);
	return 0;
}

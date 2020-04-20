#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funkcija provjerava da li je slovo
int je_li_slovo(char c){
if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) return 1;
else return 0;
}

// standardna fja
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}


void upitna(char* string){
char* ret = string;
char* s = string;
char ubaci[7]="Da li ";
// bufferi(spremnici) za subjekat, predikat itd
char subjekat[100], predikat[100], objekat[100], predikat2[100];
int slovo=0, razmak=0, slozeno=0;
char* p = subjekat;
char* r;
// pisemo u prvi buffer subjekat
while(*s!='\0' && je_li_slovo(*s) && *p!='\0'){
	*p=*s;
	s++;
	p++;
	
}

*p='\0';
//preskacemo razmake
while(*s!='\0' && *s==' ') s++;

slovo=0;
razmak=0;
p=predikat;

//pisemo u buffer predikat
while(*s!='\0' && je_li_slovo(*s))
*p++=*s++;

*p='\0';

if(strcmp(predikat,"ce") || (strcmp(predikat, "cemo") || (strcmp(predikat, "cu")))) slozeno=1;

if(slozeno==1){
        while(*s!='\0' && *s==' ') s++;
        p=predikat2;
        while(*s!='\0' && je_li_slovo(*s))*p++=*s++;
        *p='\0';
        while(*s!='\0' && *s==' ') s++;
        p=objekat;
        while(*s!='\0' && je_li_slovo(*s))*p++=*s++;
        *p='\0';
        s=string;
         r=ubaci;
         char* h = string;
         while(*h!='\0') h++;
         while(h>=s){
             *(h+strlen(ubaci)) = *h;
             h--;
         }
        while(*r!='\0') *s++ = *r++;
        while(*s!='\0' && *s!=' ') s++;
        char* q = string;
        while(*q!='\0') q++;
        int duzina = strlen(subjekat);
        while(q>=s){
            *(q+duzina) = *q;
            q--;
        }

        r=predikat;
        while(*r!='\0') *s++=*r++;
        *s++=' ';
        if(*subjekat>='A'&&*subjekat<='Z') *subjekat+=32;
        r=subjekat;
        while(*r!='\0') *s++=*r++;
        *s++=' ';
        r=predikat2;
        while(*r!='\0') *s++=*r++;
        *s++=' ';
        r=objekat;
        while(*r!='\0') *s++=*r++;
        *s++='?';
        *s='\0';

}
else{
     return;

}





}
int main()
{
    
    char string[100];
    printf("Unesi string: \n");
    unesi(string,100);
    upitna(string);
    printf("%s",string);

    return 0;
}

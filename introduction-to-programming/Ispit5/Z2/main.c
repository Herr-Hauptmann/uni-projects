#include <stdio.h>
#include <string.h>

int je_li_slovo(char c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) return 1;
    else return 0;
}


void upitna(char* s)
{
    char subjekat[100], predikat[100], objekat[100];
    char *p = subjekat;
    int sub=1,pr=1,obj=1,logika=0;
    char* ret = s;
    char *q;
    char ubaci[6]="Da li ";
    while(*s!='\0') {
        if(je_li_slovo(*s) && sub==1) {
            sub=0;
            while(*s!='\0' && *s!=' ') *p++=*s++;
            *p='\0';
        }
        if(je_li_slovo(*s) && pr==1) {
            pr=0;
            p=predikat;
            while(*s!='\0' && *s!=' ') {
                *p++=*s++;
            }
            *p='\0';
            if(!(strcmp(predikat,"ce"))||(!(strcmp(predikat,"ce")))) logika=1;
            if(logika==1) {
                while(!(je_li_slovo(*s))) s++;
                while(*s!='\0' && *s!=' ') *p++=*s++;
                *p='\0';
            }
        }

            if(je_li_slovo(*s) && obj==1) {
                obj=0;
                p=objekat;
                char *q = s;
                while(*q!='\0') *p++=*q++;
                *p='\0';
            }

            s++;

        }
    
        s=ret;
        char* kraj=s;
        while(*kraj!='\0') kraj++;
        while(kraj>=s) {
            *(kraj+6)=*kraj;
            kraj--;
        }
        char *h=ubaci;
        while(*h!='\0' && *s!='\0') *s++=*h++;
        p=predikat;
        if(logika==1) {
            kraj=s;
            while(*kraj!='\0') kraj++;
            while(kraj>s) {
                *(kraj+2) = *kraj;
                kraj--;
            }
            while(*p!='\0' && *p!=' ') *s++=*p++;
            *s++=' ';
            p=objekat;
            while(*p!='\0' && *p!=' ') *s++=*p++;
            *s++=' ';

            
        }
        int duzina=0;
        char* v=p;
        while(*v!='\0') {
            duzina++;
            v++;
        }

        kraj=s;
        while(*kraj!='\0') kraj++;
        while(kraj>=s) {
            *(kraj+duzina)=*kraj;
            kraj--;
        }
        while(*p!='\0') *s++=*p++;
        *s++=' ';
        p=subjekat;
        if(*p>='A'&&*p<='Z') *p=*p+32;
        while(*p!='\0') *s++=*p++;
        *s++=' ';
        if(logika==0){    
        p=objekat;
        while(*p!='\0' && *p!='.') *s++=*p++;
        *s++='?';
        *s='\0';
        }
        else{
            p=objekat;
            while(*p!=' ') p++;
            p++;
        while(*p!='\0' && *p!='.') *s++=*p++;
        *s++='?';
        *s='\0';
            
        }




    }



    int main() {
        char tekst[100] = "Medo je isao u sumu.";
upitna(tekst);
printf("'%s'", tekst);
        return 0;
    }

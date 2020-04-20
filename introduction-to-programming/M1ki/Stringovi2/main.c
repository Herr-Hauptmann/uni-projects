#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// funkcija koja izbacuje viska razmake iz stringa
char* IzbaciViskaRazmake(char *Str)
{
    char *p = Str;
    char *p2 = Str;
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            if (*p != *Str) // Not begining
            {
                *p2 = *p; // adding the first ' '
                p2++;
                p++;
            }
            while (*p == ' ') // skipping the rest ' '
            {
                p++;
            }
        }
        else
        {
            *p2 = *p;
            p2++;
            p++;
        }
    }
    if (*(p2 - 1) == ' ') //ends with space
    {
        p2--;
    }
    *p2 = '\0';
    return Str;
}
-------------------------------------------------------------------------------------------------------------------
// funkcija koja rekurzivno ispisuje string unazad
void IspisiUnazad(const char* s){
    if(*s!='\0'){
        IspisiUnazad(s+1);
        printf("%c",*s);
    }
}
---------------------------------------------------------------------------------------------------------------------
//funkcija koja projerava da li je rijec PALINDROM npr. anavolimilovana
int JeLiSlovoBroj(char c){
    if((c >= 'a' && c <= 'z') || (c >='A' && c <= 'Z') || (c >= '0' && c <= '9')) return 1;
    return 0;
}
int JeLiPalindrom(const char* str){
    const char* p1 = str;
    const char* p2 = str;
    while(*p2 != '\0') p2++;
    p2--;
   
    while(p1 < p2 && *p1 != '\0' && p2 != str ){
        while(!JeLiSlovoBroj(*p1)) p1++;
        while(!JeLiSlovoBroj(*p2)) p2--;
        if(*p1 != *p2 && *p1 != (*p2+32) && *p1 != (*p2-32)) return 0;
        p1++;
        p2--;
 
    }
   
    return 1;
}
-------------------------------------------------------------------------------------------------------------------------------
//funkcija koja provjerava broj ponavljanja sloga u recenici, npr "oag" u "otorinolaringologija"
int brojPonavljanja(char c, const char* s){
    int brojac = 0;
    if(c >= 'A' && c <= 'Z') c+=32;
    while(*s != '\0'){
        if(*s == c || (*s + 32) == c) brojac++;
        s++;
    }
    return brojac;
}
int KarakterUStringu(char c, const char* slova){
    const char* p = slova;
    if(c >= 'A' && c <= 'Z') c+=32;
    while(*p != '\0'){
        if(*p == c || (*p + 32) == c) return 1;
        p++;
    }
    return 0;
}
int Prebroji(const char* str, const char* slova){
    int brojac = 0;
    while(*str != '\0'){
        int ponavljanje = brojPonavljanja(*str,slova);
        if(KarakterUStringu(*str,slova)) brojac+=ponavljanje;
        str++;
    }
    return brojac;
}
 
int main() {
    printf("%d\n",Prebroji("Otorinolaringologija","oaG"));
    return 0;
}
------------------------------------------------------------------------------------------------------------------------------
// funkcija koja ekstraktuje realan broj iz stringa u double treba math.h uključit!!!!
int UnesiRealan(const char* string, double* broj){
    const char* p=string;
    int i,brojac=0;
    int cifra=0,prava_cifra=0;
    double cifra1;
    while(*p!='\0'){
        if(!(*p>='0'&&*p<='9')&& *p!='.') return 0;
        if(*p=='.') brojac++;
        p++;
    }
    if(brojac>1) return 0;
    i=0;
    p=string;
    while(*p!='\0' && *p!='.'){
        cifra=cifra*10+(*p-'0');
        i++;
        p++;
       
    }
    if(*p=='\0'){
        *broj =(double) cifra;
        return 1;
    }
    else{
        p++;
        cifra1=0;
        i=1;
        while(*p!='\0'){
            cifra1=cifra1 + (*p-'0') * pow(10,-i);
            i++;
            p++;
            }
    }
    *broj = ( (double)cifra + cifra1);
    return 1;
}
---------------------------------------------------------------------------------------------------------------------------------
//funkcija koja pronalazi n-tu rijec u stringu
void NtaRijec (const char *Str, char *rijec, int n){
    const char* s = Str;
    int logika=1,redni_broj=0;
    while(*s!='\0'){
        if(!(*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z')) logika=1;
        if(((*s>='a'&&*s<='z')||(*s>='A'&&*s<='Z')) && logika==1){
            redni_broj++;
            logika=0;
            if(redni_broj==n){
            const char* p = s;
         while((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z')){
            *rijec=*p;
            p++;
            rijec++;
         }
         *rijec='\0';
         
        }
        }
 
       
 
        s++;
    }
    if(redni_broj<n) *rijec='\0';
}
-----------------------------------------------------------------------------------------------------------------------------
//funkcija zamijeni rijec sa casesenstitive opcijom
char *ZamijeniRijec (char *Str, const char *sta, const char *sa_cim, int cs)
{
    int len1=0,len2=0,razlika,razmak=1;
    char* ret=Str;
    char* s = Str;
    char* q, *p;
    const char* v=sta;
    while(*v++!='\0') len1++;
    v=sa_cim;
    while(*v!='\0') {
        len2++;
        v++;
    }
    razlika=len1-len2;
    int br=abs(razlika);
 
 
    if(cs==1) {
        while(*s!='\0') {
        if(*s==' ') razmak=1;
       
            if(*s==*sta && razmak==1) {
                razmak=0;
                q=s;
                v=sta;
                while(*v!='\0') {
                    if(*q!=*v) break;
                    v++;
                    q++;
                }
                if(*v=='\0' && *q==' ') {
                    if(razlika==0) {
                        q=s;
                        v=sa_cim;
                        while(*v!='\0') *q++=*v++;
                    }
                    if(razlika>0) {
                        p=q-br;
                        while(*q!='\0') *p++=*q++;
                        *p='\0';
                        q=s;
                        v=sa_cim;
                        while(*v!='\0') {
                            *q=*v;
                            q++;
                            v++;
 
                        }
                    }
                    if(razlika<0) {
                        p=q--;
 
                        while(*p!='\0') p++;
                        while(p>q) {
                            *(p+br)=*p;
                            p--;
                        }
                        q=s;
                        v=sa_cim;
                        while(*v!='\0') *q++=*v++;
                    }
                }
            }
            s++;
        }
    }
 
 
    if(cs==0) {
 
        while(*s!='\0') {
            if(*s==' ') razmak=1;
            if((*s==*sta || (*s+32)==*sta || (*s-32)==*sta)&& razmak==1) {
 
                razmak=0;
                q=s;
                v=sta;
                while(*v!='\0') {
                    if(*q!=*v && (*q-32)!=*v && (*q+32)!=*v) break;
                    v++;
                    q++;
                }
 
 
                if(*v=='\0' && (*q==' '||*q=='.'||*q=='\0') && (s==ret || *(s-1)==' ')) {
                    if(razlika==0) {
                        q=s;
                        v=sa_cim;
                        while(*v!='\0') *q++=*v++;
                    }
                    if(razlika>0) {
                        p=q-br;
                        while(*q!='\0') *p++=*q++;
                        *p='\0';
                        q=s;
                        v=sa_cim;
                        while(*v!='\0') {
                            *q=*v;
                            q++;
                            v++;
 
                        }
                    }
                    if(razlika<0) {
 
                        p=q--;
 
                        while(*p!='\0') p++;
                        while(p>q) {
                            *(p+br)=*p;
                            p--;
                        }
                        q=s;
                        v=sa_cim;
                        while(*v!='\0') *q++=*v++;
                    }
                }
            }
            s++;
        }
    }
    return ret;
}
-------------------------------------------------------------------------------------------------------------------------------------
//funkcija koja provjerava da li je string periodican
int Periodican(const char *string){
 
    int vel=0;
    char *kraj=string;
 
    while(*kraj!='\0')kraj++;
    vel=kraj-string;
    int i=0;
 
    for(i=1;i<vel;i++){//gledam za svako moguce i ako je periodican
        char *pom=string;
 
        while(*(pom+i)!='\0'){
            if(*pom!=*(pom+i))break;//gledam ako je trenutni isto kao trenutni +i
            pom++;
        }
        if(*(pom+i)=='\0')return i;//i ako jeste onda vrati to i(da je trebalo vratit zadnje i, onda se mogla
                                                                 //obrnnuti i petlja da ide unazad
 
    }
    return 0;
 
}
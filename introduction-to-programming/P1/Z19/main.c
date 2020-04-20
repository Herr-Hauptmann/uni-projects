#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Nisam uradio 14 jer izgleda smor da se uradi, i nisam uradio zadnji jer se moze lagano preko ovih funkcija
//npr nadjete broj u stringu, pozovete izbaci na adresu, i onda pozovete ubaci na adresu i proslijedite
//"jedan" ili "dva" ili "tri" itd itd

const char* Pronadji (const char *str, const char *trazi){//trazi podniz gdje D!=d

char *s1=str;
char *s2=trazi;
int indeks=-1;

while(*s1!='\0'){

char *pom=s1;
s2=trazi;

if(*s1==*trazi){//Ako nadje prvo slovo drugog stringa tek onda trazi podniz

    while(*s2!='\0'){//uporedjuje element drugog niza sa elementima prvog niza

        if(*s2!=*s1 || *s1=='\0')break;//ako nisu isti il prvi dosoa do kraja ne sadrzi
        s2++;
        s1++;

    }
    if(*s2=='\0')indeks=pom-str;//ako je s2 dosao do kraja s1 ga sazdrzi(ako treba vratit prvi indeks onda samo return ovdje
     //posto treba zadnji onda pamtimo ih sve i kad ne bude bilo vise onad vraca zadnji

    if(*s1=='\0')return indeks;//ako je s1 dosao do kraja nema sta vise gledati
    s1=pom;//vraca s1 pokazivac nazad gdje je bio i nastavlja sa kretanjem krzo string(mslm da se moze napravit test koji pada
                      //ako se ne vraca nisam siguran 100%)


}

    s1++;
}

return indeks;//ako dodje do kraja normalno return indeks;
}

const char* PronadjiR (const char *str, const char *trazi){//trazi samo rijec tj nece naci caj ako ima caja, dok Pronadji hoce

char *s1=str;
char *s2=trazi;
int indeks=-1;

while(*s1!='\0'){

char *pom=s1;
s2=trazi;

if(*s1==*trazi){//Ako nadje prvo slovo drugog stringa tek onda trazi podniz

    while(*s2!='\0'){//uporedjuje element drugog niza sa elementima prvog niza

        if(*s2!=*s1 || *s1=='\0')break;//ako nisu isti il prvi dosoa do kraja ne sadrzi
        s2++;
        s1++;

    }

    if(*s2=='\0' && (*s1<'A' || (*s1>'Z' && *s1<'a') || *s1>'z'))indeks=pom-str;//ako je s2 dosao do kraja s1 ga sazdrzi(ako treba vratit prvi indeks onda samo return ovdje
     //posto treba zadnji onda pamtimo ih sve i kad ne bude bilo vise onad vraca zadnji

    if(*s1=='\0')return indeks;//ako je s1 dosao do kraja nema sta vise gledati
    s1=pom;//vraca s1 pokazivac nazad gdje je bio i nastavlja sa kretanjem krzo string(mslm da se moze napravit test koji pada
                      //ako se ne vraca nisam siguran 100%)


}

    s1++;
}

return indeks;//ako dodje do kraja normalno return indeks;
}

const char* PronadjiRV (const char *str, const char *trazi){//trazi samo rijec tj nece naci caj ako ima caja, dok Pronadji hoce

char *s1=str;
char *s2=trazi;
int indeks=-1;
char c1,c2;

while(*s1!='\0'){

char *pom=s1;
s2=trazi;

c1=*s1;
c2=*trazi;

if(c1>='A' && c1<='Z')c1+=32;//isto ovo dole sto pise
if(c2>='A' && c2<='Z')c2+=32;

if(c1==c2){//Ako nadje prvo slovo drugog stringa tek onda trazi podniz

    while(*s2!='\0'){//uporedjuje element drugog niza sa elementima prvog niza

        c1=*s1,c2=*s2;//pamtim im vrijednosti u charovima da mogu mjenjti i uporedjivati
        if(c1>='A' && c1<='Z')c1+=32;
        if(c2>='A' && c2<='Z')c2+=32;

        if(c1!=c2 || c2=='\0')break;
        s2++;
        s1++;


    }

    if(*s2=='\0' && (*s1<'A' || (*s1>'Z' && *s1<'a') || *s1>'z'))indeks=pom-str;//ako je s2 dosao do kraja s1 ga sazdrzi(ako treba vratit prvi indeks onda samo return ovdje
     //posto treba zadnji onda pamtimo ih sve i kad ne bude bilo vise onad vraca zadnji

    if(*s1=='\0')return indeks;//ako je s1 dosao do kraja nema sta vise gledati
    s1=pom;//vraca s1 pokazivac nazad gdje je bio i nastavlja sa kretanjem krzo string(mslm da se moze napravit test koji pada
                      //ako se ne vraca nisam siguran 100%)


}

    s1++;
}

return indeks;//ako dodje do kraja normalno return indeks;
}

const char* PronadjiV (const char *str, const char *trazi){//trazi podniz gdje D==d

char *s1=str;//isto kao ovo gore, samo sto ovdje uporedjuje charove(vise o tome dole)
char *s2=trazi;
int indeks=-1;
char c1,c2;

while(*s1!='\0'){

char *pom=s1;
s2=trazi;

c1=*s1;
c2=*trazi;

if(c1>='A' && c1<='Z')c1+=32;//isto ovo dole sto pise
if(c2>='A' && c2<='Z')c2+=32;

if(c1==c2){

    while(*s2!='\0'){

        c1=*s1,c2=*s2;//pamtim im vrijednosti u charovima da mogu mjenjti i uporedjivati
        if(c1>='A' && c1<='Z')c1+=32;
        if(c2>='A' && c2<='Z')c2+=32;

        if(c1!=c2 || c2=='\0')break;
        s2++;
        s1++;

    }
    if(*s2=='\0')indeks=pom-str;
    if(*s1=='\0')return indeks;
    s1=pom;


}

    s1++;
}

return indeks;
}

char *IzbaciTekst (char *Str, const char *tekst){//izbacuje samo ako su slova ista, tj D!=d

    char*pocetak=Str;
    int indeks=0;

    char* s2=tekst;

    while(*s2!='\0')s2++;
    int vel=s2-tekst;


    while(1){

        indeks=Pronadji(pocetak,tekst);//Trazi indeks gdje se pojavljuje tekst

        if(indeks==-1)return pocetak;//ako vrati -1 onda nema vise teksta u prvom stringu

        char* pom=pocetak+indeks;//adresa prvog slova u prvom stringu odakle izbacujemo

        while(*(pom+vel-1)!='\0'){//sablon izbacivanja vel broja elemenata iz stringa(ili niza)
            *pom=*(pom+vel);
            pom++;
        }

    }



}

char *IzbaciTekstV (char *Str, const char *tekst, int cs){//Gleda velika i mala slova kad izbacuje, D==d


       char*pocetak=Str;
    int indeks=0;

    char* s2=tekst;

    while(*s2!='\0')s2++;
    int vel=s2-tekst;


    while(1){

        if(cs==0)indeks=Pronadji(pocetak,tekst);//Isto sve samo sto ovdje gleda podniz koji ne prihvata razliku slova
        else indeks=PronadjiV(pocetak,tekst);//i koji prihvata

        if(indeks==-1)return pocetak;//sve ostalo isto

        char* pom=pocetak+indeks;



        while(*(pom+vel-1)!='\0'){
            *pom=*(pom+vel);
            pom++;
        }


    }





}

void NtaRijec (const char *Str, char *rijec, int n){

int rj=0;
*rijec='\0';//stavim da je nista u pocetku ako nema toliko rijeci onda vrati samo ovo

char *s=Str;

while(*s!='\0'){

    while(*s==' ')s++;//Preskacem prazne prostore

    if(*s=='\0') break;//ako je dosao do kraja breakam

    rj++;//ako nije kraj i nije spacebar rijec je

    if(rj==n)break;//ako je pocetak n-te rijeci onda je to, well pocetak ente rijeci|

    while(*s!=' ' && *s!='\0')s++;//Preskacem rijec

    if(*s=='\0') break;//ako je dosao do kraja breakam
    s++;
}

if(rj==n){//ako je breakalo na n-toj rijeci

    while(*s!='\0'){//prepisivanje iz stringa s u string rijec, krecem se kroz oba i stavljam drugi=prvi
        *rijec=*s;
        rijec++;
        s++;
        if(*s==' ')break;
    }
    *rijec='\0';//ogranicim string

}


}

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

void UbaciOpseg(char *s,char *q1,char *q2){

    int vel=q2-q1;



    char *kraj=s;
    while(*kraj!='\0')kraj++;

    while(kraj>=s){//sablon ubacivanja vel mjesta u string Npr: Danas je dan!, da na mjesto slova d ubacimo 5 mjesta bilo bi
            //Danas je xxxx dan! (gdje x su nevazni charovi jer prepisujemo preko njih)
        *(kraj+vel)=*kraj;
        kraj--;
    }
    kraj++;//ima neki bug nmg se sjetit

    while(q1<q2){//prepisivanje rijeci
        *kraj=*q1;
        kraj++;
        q1++;
    }

}


void UbaciS(char *s,char slovo){

    int vel=1;//sve je isto samo sto je vel uvijek 1 mkad ubacuje 1 slovo

    char *kraj=s;
    while(*kraj!='\0')kraj++;

    while(kraj>=s){
        *(kraj+vel)=*kraj;
        kraj--;
    }
    kraj++;
    *kraj=slovo;


}

char *ZamijeniTekst (char *Str,
const char *sta, const char *sa_cim, int cs){

char *pocetak=Str;

int indeks=0;
int vel2=0,vel1=0;
char* k2=sa_cim;
char* k1=sta;

while(*k2!='\0')k2++;
vel2=k2-sa_cim;//velicina stringova

while(*k1!='\0')k1++;
vel1=k1-sta;//velicine stringova

while(1){

    if(cs==1)indeks=Pronadji(pocetak,sta);
        else indeks=PronadjiV(pocetak,sta);
 if(indeks==-1)return pocetak;

 Izbaci(Str+indeks,vel1);//izbacimo prvu rijec pa ubacimo drugu rijec
 Ubaci(Str+indeks,sa_cim);//                      ^^

}

return pocetak;


}

char *ZamijeniRijec (char *Str,
const char *sta, const char *sa_cim, int cs){

char *pocetak=Str;

int indeks=0;
int vel2=0,vel1=0;
char* k2=sa_cim;
char* k1=sta;

while(*k2!='\0')k2++;
vel2=k2-sa_cim;//velicina stringova

while(*k1!='\0')k1++;
vel1=k1-sta;//velicine stringova

while(1){

    if(cs==1)indeks=PronadjiR(pocetak,sta);
        else indeks=PronadjiRV(pocetak,sta);
    if(indeks==-1)return pocetak;

 Izbaci(Str+indeks,vel1);//izbacimo prvu rijec pa ubacimo drugu rijec
 Ubaci(Str+indeks,sa_cim);//                      ^^

}

return pocetak;


}

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

char* kompresuj(char* s){//welp, sretno sa ovim

//znam da svuda govorim slovo il broj ,treba znak il broj pisati
char *pocetak=s;
int br=1;
int izbaceni=0;
int ubaceni=0;
char slovo;

//posto imaju samo 3 uslova manje vise hard kodiram usloev
//ako naidje na 3>znaka zarednom, na 1>brojeva zaredom ili ! znak

while(*s!='\0'){
    br=1;//mora imat minimalno 1 slovo il broj pa stavljam na 1
    izbaceni=0;//pomocna variabla
    ubaceni=0;//pomocna variabla

    char *pom=s;
    slovo=*s;//pamtim znak u var slovo(treba se zvati znak al et)

if(slovo=='!'){Ubaci(s,"!");s++;}//ako naidje na ! znak ubaci jos 1 s++ da nebi opet naislo na taj sljedeci znak i uslo
//u besk rekurziju

else{

    while(*(s+1)==*s){//dok je god sljedeci isti kao trenutno
        br++;
        s++;
    }

    if(br>3 || (slovo<='9' && slovo>='0')){//ako imaju 4 zaredom il ako je broj

        izbaceni=br-3-(int)log10(br);//ako ima npr 6 slova, ono ve izbacit 6 slova, a ubaciti !+slovo+broj tj 6-3 znakova
        //6 je broj koliko ima zaredom, 3 jer ima min 3 clana, log10(br) daje broj cifri preko 10 od broja tj za >0 <9 daje 0
        //za >10 <99 daje 1 itd jer ako treba upisat !a13, uzima jos 1 mjesto

        Izbaci(pom,br);//izbacuje sva slova/brojeve zaredom
        Ubaci(pom,"!");pom++;//ubaci prvo znak !
        UbaciS(pom,slovo);pom++;//ubaci slovo/broj koji je brojalo

        while(br!=0){//ubacuje znak po znak ali ako je string bio Broj je :", i ono ubaci broj 4 pa 3 pa 2 na isto mejsto
                //bit ce Broj je :234",gura prethodne u desno pa mogu ubacivat broj od jedinica pa navise
        UbaciS(pom,'0'+br%10);//ubacijem zadnju cifru
        br/=10;//smanjujem broj
        }
    }

}

   s=s-izbaceni;//moram vratiti s nazad,mslm da sam mogao stavit s=pom al et, ako je izbaceno 4 elemenata sada s pokzuje
   //4 mjesta ispred nego sto treba pa vratim
    s++;

}

return pocetak;

}

char* dekompresuj(char* s){//mnogo lakse nego ovo gore

char *pocetak=s;
int br=0;
char slovo='o';


while(*s!='\0'){

    br=0;

    if(*s=='!'){//ako naidje na ! treba nesto uradit
        char* pom=s;//pamtim lokacije
        s++;//idem na sljedeci znak i opet hard kodiranje 3 uslova
        if(*s=='!')Izbaci(s,1);//ako idu dva ! zaredom izbacim jedan
        else {

            slovo=*s;//ako nisu dva ! zaredom onda gledam koji je znak
            s++;//idem da vidim koliko puta treba ubacit taj broj
            while(*s<='9' && *s>='0'){//posto sklapam broj na fazon 12345=10000+2000+300+40+5 idem preko ove formule
                br=br*10+*s-'0';//*s-'0' daje mi broj u intu a ne charu il ascii
                s++;
            }

                Izbaci(pom,s-pom);//sad izbacim od ! do znaka prije sljeeceg ! ili '\0' sve

                while(br>0){
                    UbaciS(pom,slovo);//onda ubacim broj puta znak kojije bio
                    br--;
                }
                s=pom;//vratim s nazad da se ne ubaga nesto
        }
    }

s++;


}


return pocetak;

}

char* prebroji (char* tekst, char* slova){//mnogo lagan

int niz[26]={0};//brojac slova

char *pocetak=tekst;

while(*tekst!='\0'){//brojim koliko se puta koje slovo javilo

    if(*tekst<='Z' && *tekst>='A')niz[*tekst-'A']++;//ako se pojavi slovo A onda niz[0], ako z onda niz[25] tj uvecava
    //niz[x]gdje je x indeks trenutnog slova u abecedi
    if(*tekst<='z' && *tekst>='a')niz[*tekst-'a']++;//isto za mala slova

    tekst++;
}

int i=0,j=0,maxi=0,brojac=0;//max_indeks==maxi

for(i=0;i<26;i++){
    maxi=0;//kazem da je A slovo najvise puta upisano

    for(j=0;j<26;j++)
       if(niz[j]>niz[maxi]) maxi=j;//trazim koj se slovo najvise naslo
       //posto ovdje pise >, uzet se kao max prvo slovo koje ima max vrijednost
       //ako A i C su se javili 19 puta, maxi ce ostat 0 jer 19>19 je false

    if(niz[maxi]==0) break;//ako se max slovo javilo 0 puta znaci ispisalo ih je sve
    *slova='A'+maxi;
    slova++;
    niz[maxi]=0;

}
*slova='\0';

return pocetak;

}

char* izbaci_maxbroj(char* s){//mogu koristit vec postojece funkcije kao indeks i to

char *pocetak=s;

int broj=0,max=0;
int prvi=0,neg=1;

while(*s!='\0'){//Trazim najveci broj

    broj=0;
    neg=1;

    if(*s=='-' && *(s+1)>='0' && *(s+1)<='9'){s++; neg=-1;}//ako se znak - nalazi prije nekog broja

    while(*s<='9' && *s>='0' && s!='\0'){
        broj=broj*10+*s-'0';//sklapam broj iz stringa
        s++;
    }

    broj*=neg;

    if(prvi==0){//stavi prvi pronadjeni broj kao maximalni
        max=broj;
        prvi=1;
    }

    if(broj>max)max=broj;

    if(*s=='\0')break;
    s++;
}



s=pocetak;


while(*s!='\0'){
    broj=0;
    neg=1;

    if(*s=='-' && *(s+1)>='0' && *(s+1)<='9'){s++; neg=-1;}//ako se znak - nalazi prije nekog broja

    char *pokbr=s;

    while(*s<='9' && *s>='0' && s!='\0'){
        broj=broj*10+*s-'0';//sklapam broj iz stringa
        s++;
    }

    broj*=neg;

   if(broj==max)
   Izbaci(pokbr,s-pokbr);

s=pokbr;//vracam s nazad gdje je bio prije izbacivanja ako naidje opet na isti broj(npr slucaj 123.123) kad se izbaci bit ce
//.123, a s ce biti na broju 2 i onda ce gledat 23 kao broj

    if(*s=='\0')break;
    s++;
}



return pocetak;
}

char* zamjena_rijeci(char* tekst, char** rijeci,
char** zamjene, int broj_rijeci){

char *pocetak=tekst;
int i=0;



    for(i=0;i<broj_rijeci;i++){

        while(1){
        int indeks=Pronadji(tekst,rijeci[i]);//mnogo slicno obicnoj zamjeni rijeci samo sto ovdje
        //trazim za svako i dok ne nadje sve i tjt
        if(indeks!=-1) ZamijeniTekst(tekst,rijeci[i],zamjene[i],1);//ako je naslo zmajeni
        else break;//ako nije break while i sljedece i
        }
    }






return pocetak;
}

int PronadjiOpseg(char *s1,char *q1,char *q2){//trazim podniz u opsegu

    char* pocetak=s1;
    while(*s1!='\0'){

         char *pom1=s1;
        char c1=*s1,c2=*q1;
                    if(c1>='A' && c1<='Z')c1+=32;
                    if(c2>='A' && c2<='Z')c2+=32;
        if(c1==c2){//ako j clan stringa s1 isti ko prvi clan q1

            char*pom2=q1;

            while(pom2<q2){//idem kroz q1 i uporedjujem
                    c1=*s1;
                    c2=*pom2;
                    if(c1>='A' && c1<='Z')c1+=32;
                    if(c2>='A' && c2<='Z')c2+=32;
                if(c1!=c2)break;
                s1++;
                pom2++;
            }
            if(pom2==q2 &&(*s1<'A' || (*s1>'Z' && *s1<'a') || *s1>'z') )return pom1-pocetak;//ako je dosao do kraja sadrzan je
            //pom1 pamti gdje je prvo slovo stringa2 u stringu1 pa kad oduzmem dobijem indeks tog slova u stringu

        }
        s1=pom1;
        s1++;
    }
return -1;
}

char *ZamijeniRijecOpseg (char *Str,
const char *sta, const char *q1,const char* q2){

char *pocetak=Str;

int indeks=0;
int vel2=0,vel1=0;
char* k1=sta;

vel2=q2-q1;

while(*k1!='\0')k1++;
vel1=k1-sta;//velicine stringova

while(1){

    indeks=PronadjiR(pocetak,sta);
    if(indeks==-1)return pocetak;

 Izbaci(Str+indeks,vel1);//izbacimo prvu rijec pa ubacimo drugu rijec
 UbaciOpseg(Str+indeks,q1,q2);//                      ^^

}

return pocetak;


}


void cenzura(char *s1,char *s2){


char *pom1=s1;
char *pom2=s2;

//radi se mnogo slicno onome gdje se salje matrica slova, gdje sa i mjenjamo slova
while(*pom2!='\0'){


    while(*pom2==' ')pom2++;//preskacem spacebarove
    if(*pom2=='\0')break;
    char *q1=pom2;
    while(*pom2!=' ' && *pom2!='\0')pom2++;

    char *q2=pom2;//ogranicio sam rijec sa q1 i q2

    while(1){

        int indeks=PronadjiOpseg(s1,q1,q2);//trazi ako se nalazi strign omedjen sa q1 i q2 unutar s1
        //jer u ovom zadatku se ne smiju koristit pomocni stringovi

        if(indeks==-1)break;//ako nema breka while
        Izbaci(s1+indeks,q2-q1);//izbaci pojavljivanje cenzurisane rijeci
        Ubaci(s1+indeks,"***");//i onda ubaci *** znaka tako se trazi u zadatku

    }

}






}


int main()
{
 /*   //Testiranja trazenja podstringa
   const char *n = "Danas je divan dan!";
printf ("%d\n", Pronadji(n, "divan")); //9
printf ("%d\n", Pronadji(n, "Divan")); //-1 (nema)
printf ("%d\n", Pronadji(n, "Danas")); //0
printf ("%d\n", Pronadji(n, "an")); //16
printf ("%d\n", Pronadji(n, "an!")); //16
printf ("%d\n\n\n", Pronadji("abc cde abc", "abc")); //8

//Testiranje izbacivanja rijeci
char niz[] = "Danas je divan dan!";
printf("'%s'\n\n\n", IzbaciTekstV(niz, "dan",1));

//Testirnje trazenja nte rijeci
const char *tekst = " Zeko pije mlijeko! ";
char rijec[101]; //pretpostavimo da nije duza od 100 znakova
NtaRijec(tekst, rijec, 4); // 2. rijec po redu ("pije")
printf ("2. rijec: '%s'", rijec);
*/

/* //Mjenja rijec u stringu sa drugom, dobro za 2 iz zadace
char tekst[100] = " Zeko pije CAJ. Pije caj mali zeko!";
ZamijeniTekst (tekst, "caj", "mlijeko", 0); //cs = 0
printf ("'%s'", tekst);*/

/* //Mjenja rijec u stringu sa drugom ali samo potpune rijeci mijenja
char tekst[100] = " Zeko pije caj. Pije caja mali zeko!";
ZamijeniRijec (tekst, "caj", "mlijeko", 0); //cs = 0
printf ("'%s'", tekst);*/


//printf("%d ",Periodican("DanasDanasDb")); Testira periodicnost

/*//Kompresovanje
char string[]="|||||44455ccccbb";
printf("\n%s ",kompresuj(string));
//printf("%s ",string);
printf("\n%s ",dekompresuj(string));*/

/*  slova po broju pojavljivanja
char slova[30];
char recenica[]="Ovo je neki primjer.";

prebroji(recenica,slova);

printf("%s ",slova);*/

/*
char s[]="Broj 123: broj 123.123 je veci od broja 59 koji je veci od 9 i -999";
izbaci_maxbroj(s);
printf("%s ",s);*/

/*char* rijeci[2] = { "beli", "sneg" };
char* zamjene[2] = { "bijeli", "snijeg" };
char tekst[100] = "beli sneg je pokrio beli breg";
printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));*/

/*char *s1="Ovo je neki string!";
char *s2="neki";
printf("%d ",PronadjiOpseg(s1,s2,s2+4));*/

/* //cenzurisanje
char tekst[]="Ovo je neki primjer teksta koji ovo se ovo se cenzurise";
char cenzurastr[]="ovo Je KoJi";
cenzura(tekst,cenzurastr);

printf("%s ",tekst);
*/

/*
char s[]="Imam broj 5 u stringu";//funkcija neka nadje adresu broja 5 i onda
Izbaci(s+10,1);
Ubaci(s+10,"pet");
printf("%s ",s);*/

return 0;
}


int main() {
	printf("Proba 1, Zadatak 19");
	return 0;
}

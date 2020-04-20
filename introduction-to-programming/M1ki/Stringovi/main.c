#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//funkcija prekopiraj
char *prekopiraj (char *gdje, const char *sta) {
    while (*sta) *gdje++ = *sta++;
    return gdje;
}

//funkcija unesi - sluzi za unos stringa
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

// implementacija funkcije strlen - vraca duzinu stringa
int duzina(char* s){
    int duzina = 0;
    while(*s++) duzina++;
    return duzina;
}

// implementacija funkcije strcmp - leksigografsko poredjenje stringove
// vraca 0 ako su stringovi jednaki, < 0 ako je s1 < a2 i > 0 ako je s1 > s2
// kraca varijanta 
int uporedi(const char* s1, const char* s2){
    while(*s1 == *s2){s1++; s2++;}
    return *s1 - *s2;
}

// implementacija funkcije strcat - spaja dva stringa tako da na kraj s1 doda s2
// pretpostavlja se da je s1 dovoljno velik da primi dodadne karaktere
char* spoji(char* s1, const char* s2){
    char* ret= s1;
    while(*s1) s1++;
    while(*s1++ = *s2++);
    return ret;
}

// implementacija funkcije strstr koja traži substring u stringu - vraca na pokazivac na pocetak podstringa
// ukoliko takav ne postoji, vraća nullptr
char* podstring(const char* s1, const char* s2){
    while(*s1 != '\0'){
        char* p = s1;
        char* q = s2;
        while(*p++ == *q++);
        if(*q == '\0') return s1;
        s1++;
    }
    return NULL;
}

// funkcija max_slovo vraca slovo koje se najvise puta ponavlja u stringu

char max_slovo(const char* s){
    int brojac[26] = {};
    while(*s != '\0'){
        if(*s >= 'a' && *s <= 'z') brojac[*s - 'a']++;
        if(*s >= 'A' && *s <= 'Z') brojac[*s - 'A']++;
        s++;
    }
    int i_max = 0;
    for(int i = 0; i < 26; i++){
        if(brojac[i] > brojac[i_max]) i_max = i;
    }
    return 'A' + i_max;
}

//funkcija trazi_broj provjerava da li se broj nalazi u stringu
// verzija 1
int trazi_broj_v1(const char* s, int broj){
    char sbroj[12];
    char* sb = sbroj + 11;
    int tmp = broj;
    
    do{
        *sb-- = abs(broj % 10) + '0';
        broj /= 10;
    }while(broj != 0);
    
    if(tmp < 0) *sb-- = '-';
    if(podstring(s,sb)) return 1;
    return 0;
}
 // verzija 2
 int trazi_broj(const char* s, int broj){
     int tmp, predznak = 1;
     while(*s != '\0'){
         if(*s == '-') predznak = -1;
         else if(*s >= '0' && *s <= '9'){
             tmp = 0;
             while(*s >= '0' && *s <= '9') {
                 tmp = tmp * 10 + *s - '0';
                 s++;
             }
             if(predznak * tmp == broj) return 1;
             s--;
         }
         else predznak = 1;
         s++;
     }
     return 0;
 }
 
 // funkcija nadji rijec, gdje je rijec definisana kao karakteri omeđeni space-om tj " "
 
 const char* nadji_rijec(const char* s1, const char* s2){
     char* poc = s1;
     while(*s1 != '\0'){
        char* p = s1;
        char* q = s2;
        while(*p++ == *q++)
        if(*q == '\0' && (s1 == poc || *(s1-1) == ' ') && (*p == ' ' || *p == '\0')) return s1;
        s1++;
     }
     return NULL;
 }
 
 // funkcija izbaci rijec, koja izbacuje n-tu rijec iz stringa
 
 void izbaci_rijec(char* s, int n){
     int broj_rijeci = 0, razmak = 1;
     char* pocetak;
     while(*s != '\0'){
         if(*s == ' ') razmak = 1;
         else if(razmak == 1){
             razmak = 0;
             broj_rijeci++;
             if(broj_rijeci == n) pocetak = s;
             if(broj_rijeci == n+1) {
                 while(*pocetak++ = *s++);
                 return;
             }
         }
         s++;
     }
     if(broj_rijeci == n) pocetak = '\0';
     
 }

// funkcija zamijeni string, koja mijenja određeni podstring drugim stringom
void zamijeni_string_ubaci(char* s, const char* pretraga, const char* zamjena, int pomak) {
 char* pozicija = strstr(s, pretraga);
 while (pozicija) {
 char* kraj = pozicija;
 while (*kraj != '\0') kraj++;
 while (kraj > pozicija) {
 *(kraj+pomak) = *kraj;
 kraj--;
 }
 prekopiraj(pozicija, zamjena);
 pozicija = strstr(s, pretraga);
 }
 }
 void zamijeni_string_izbaci(char* s, const char* pretraga, const char*
zamjena, int pomak) {
 char* pozicija = strstr(s, pretraga);
 while (pozicija) {
 char* tmp = pozicija;
 while (*tmp != '\0') {
 *tmp = *(tmp+pomak);
 tmp++;
 }
 prekopiraj(pozicija, zamjena);
 pozicija = strstr(s, pretraga);
 }
 }
 void zamijeni_string(char* s, const char* pretraga, const char* zamjena) {
 int pomak = strlen(zamjena) - strlen(pretraga);
 if (pomak > 0)
 zamijeni_string_ubaci(s, pretraga, zamjena, pomak);
 else
 zamijeni_string_izbaci(s, pretraga, zamjena, -pomak);
 }






int main(){
    char str[300] = "mirza je mirza mirza heheh mirza mirza     mirza";
    char recenica[100];
    printf("Unesite recenicu: ");
    unesi(recenica,100);
    printf("Unijeli ste: %s \n",recenica);
    printf("Duzina stringa: %d \n",duzina(recenica));
    printf("Funkcija uporedi: %d\n",uporedi("aaa","aab"));
    printf("Funkcija spoji: %s\n",spoji(recenica, "+ jedan"));
    printf("Funkcija podstring: %s\n",podstring("divljaslovapodstringjeumeni","podstring"));
    printf("Funkcija max_slovo: %c\n",max_slovo(recenica));
    printf("Funkcija trazi_broj: %d\n",trazi_broj("Da li postoji ovdje broj 223 negativan -42 broj",-42));
    printf("Funkcija nadji_rijec: %s\n",nadji_rijec("Ja sam papak","papak"));
    izbaci_rijec(recenica,3);
    printf("Funkcija izbaci_rijec: %s\n",recenica);
    zamijeni_string(str,"mirza","Dinkoooo");
    printf("Funkcija zamijeni_string: %s\n",str);
    return 0;
}
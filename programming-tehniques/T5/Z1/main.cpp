/* 
    TP 2018/2019: Tutorijal 5, Zadatak 1
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
void IspisiChar(char* pocetak, char* kraj){
	while(pocetak != kraj) std::cout<<*pocetak++;
}
void unesi(char recenica[], int velicina){
	char znak = getchar();
	char* p = recenica;
	if(znak=='\n') znak = getchar();
	for(int i = 0; i<velicina-1; i++){
		*p++ = znak;
		znak = getchar();
		if(znak=='\n') break;
	}
	*p='\0';
}
int main ()
{
	char recenica[1000];
	std::cout<<"Unesite recenicu: ";
	unesi(recenica,1000);
	char* pok = recenica;
	bool razmak = 1;
	int redni_broj = 0;
	while(*pok != '\0'){
		if(razmak == 1 && *pok!=' ' && *pok!='\n' && *pok != '\t'){
			razmak=0;
			redni_broj++;
			if(redni_broj==2) break;
		}
		if(*pok == ' ') razmak=1;
		pok++;
	}
	char * kraj = recenica;
	while(*kraj != '\0') kraj++;
	std::cout<<"Recenica bez prve rijeci glasi: ";
	IspisiChar(pok,kraj);
	std::cout<<std::endl;
	
	return 0;
}
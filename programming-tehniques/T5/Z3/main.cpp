/* 
    TP 2018/2019: Tutorijal 5, Zadatak 3
	
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
#include <algorithm>
#include <cmath>
const double eps = 0.0000001;
void NijeTrocifren(int x){
	double y = x;
	if(std::log10(abs(y))<2 || std::log10(abs(y))-std::log10(999)>eps) std::cout<<" "<<x;
}
void unos(int& p){
	int x;
	std::cin>>x;
	p = x;
}
bool NajmanjiBrojCifara(int x, int y){
	x=abs(x);
	y=abs(y);
	if(std::log10(y) - std::log10(x) > eps) return true;
	else return false;
	
}
bool PotpunKvadrat(int n){
if(sqrt(n) == floor(sqrt(n))) return true;
else return false;
}
int main ()
{
	int niz[1000];
	std::cout<<"Unesite broj elemenata (max. 1000): ";
	int vel;
	std::cin>>vel;
	std::cout<<"Unesite elemente: ";
	std::for_each(niz,niz+vel,unos);
	std::cout<<"Najveci element niza je "<<*std::max_element(niz,niz+vel)<<std::endl;
	int najmanji = *std::min_element(niz,niz+vel);
	std::cout<<"Najmanji element niza se pojavljuje "<<std::count(niz,niz+vel,najmanji)<<" puta u nizu"<<std::endl;
	std::cout<<"U nizu ima "<<std::count_if(niz,niz+vel,PotpunKvadrat)<<" brojeva koji su potpuni kvadrati"<<std::endl;
	std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(niz,niz+vel,NajmanjiBrojCifara)<<std::endl;
	std::cout<<"Elementi koji nisu trocifreni su:";
	std::for_each(niz,niz+vel,NijeTrocifren);
	return 0;
}
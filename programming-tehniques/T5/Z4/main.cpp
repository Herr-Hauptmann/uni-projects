/*
    TP 2018/2019: Tutorijal 5, Zadatak 4

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
#include <deque>
const double eps = 0.0000001;

int main ()
{
	std::deque<int> dek;
	std::cout<<"Unesite broj elemenata: ";
	int vel;
	std::cin>>vel;
	dek.resize(vel);
	std::cout<<"Unesite elemente: ";
	std::for_each(dek.begin(),dek.end(),[](int& p) {
		int x;
		std::cin>>x;
		p=x;
	});
	std::cout<<"Najveci element deka je "<<*std::max_element(dek.begin(),dek.end())<<std::endl;
	int najmanji = *std::min_element(dek.begin(),dek.end());
	std::cout<<"Najmanji element deka se pojavljuje "<<std::count(dek.begin(),dek.end(),najmanji)<<" puta u deku"<<std::endl;
	std::cout<<"U deku ima "<<std::count_if(dek.begin(),dek.end(),[](int n) {
		if(sqrt(n) == floor(sqrt(n))) return true;
		else return false;
	})<<" brojeva koji su potpuni kvadrati"<<std::endl;
	std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(dek.begin(),dek.end(),[](int x, int y) {
		x=abs(x);
		y=abs(y);
		if(int((std::log10(x)+1))< int(std::log10(y)+1)) return true;
		else return false;

	})<<std::endl;
	std::cout<<"Elementi koji nisu trocifreni su:";
	std::for_each(dek.begin(),dek.end(),[](int x) {
		double y = x;
		if(std::log10(abs(y))<2 || std::log10(abs(y))-std::log10(999)>eps) std::cout<<" "<<x;
	});
	return 0;
}

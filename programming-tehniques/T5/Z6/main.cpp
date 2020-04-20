/* 
    TP 2018/2019: Tutorijal 5, Zadatak 6
	
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
#include <vector>
#include <algorithm>
#include <cmath>
void Ispisi(int x){
	std::cout<<" "<<x;
}
int SumaCifara(int x){
	x=abs(x);
	if(x/10 == 0) return x;
	return x%10 + SumaCifara(x/10);
}
bool sortNmbrDigit(int x, int y){
	if(SumaCifara(x) == SumaCifara(y)) return x < y;
	if(SumaCifara(x) < SumaCifara(y)) return true;
	else return false;
}
void unos(int& p){
	int x;
	std::cin>>x;
	p = x;
}
int main ()
{
	std::vector<int> v;
	std::cout<<"Unesite broj elemenata: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente: ";
	v.resize(n);
	std::for_each(v.begin(),v.end(),unos);
	std::sort(v.begin(), v.end(), sortNmbrDigit);
	std::cout<<"Niz sortiran po sumi cifara glasi:";
	std::for_each(v.begin(),v.end(),Ispisi);
	std::cout<<std::endl;
	std::cout<<"Unesite broj koji trazite: ";
	int element;
	std::cin>>element;
	if(std::binary_search(v.begin(),v.end(),element,sortNmbrDigit)==false) std::cout<<"Trazeni broj ne nalazi se u nizu!";
	else std::cout<<"Trazeni broj nalazi se na poziciji "<<(std::find(v.begin(),v.end(),element) - v.begin());
	return 0;
}
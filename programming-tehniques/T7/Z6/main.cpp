/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
#include <algorithm>
#include <string>
template<typename Tip>
std::list<Tip> SortirajListu(std::list<Tip>& lista){
	auto p = lista.begin();
	while(p!=lista.end()){
		auto q = p;
		auto r = p;
		r++;
		while(r!=lista.end()){
		if(*r < *q){
			auto temp = *q;
			*q = *r;
			*r = temp;
			p--;
			break;
		}
		r++;	
		}
		p++;
	}
	return lista;
}
int main ()
{
/*	std::list<std::string> ls{"Mujo", "Suljo", "Haso", "Hrvoje", "Ivan", "Ante", "Milutin", "Dragan", "Zoran"};
	auto lss = SortirajListu(ls);
	for(auto x : lss) std::cout << x << " "; */
	std::cout<<"Koliko ima elemenata: ";
	int n;
	std::cin>>n;
	std::list<int> list(n);
	std::cout<<"Unesite elemente: ";
	for(auto &x: list) std::cin>>x;
	std::cout<<"Sortirana lista: ";
	auto sort = SortirajListu(list);
	for(auto x: sort) std::cout<<x<<" ";
	
	return 0;
}
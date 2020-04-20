/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <type_traits>
#include <new>
template<typename TipPok>
auto KreirajIzvrnutiNiz(TipPok p1, TipPok p2)->typename std::remove_reference<decltype(*p1)>::type*
{
	using tip = typename std::remove_reference<decltype(*p1)>::type;
	if(p1==p2) {
		throw std::domain_error("test");
	}
	auto br = p1;
	int vel = 0;
	while(br!=p2){
		vel++;
		br++;
	}
	tip* niz = nullptr;
	try {
		niz = new tip[vel];
	} catch(std::bad_alloc) {
		throw std::bad_alloc();
	}
	if(niz==nullptr) throw std::bad_alloc();
	int i = 0;
	while(p1!=p2) {
		niz[vel-1-i] = *p1++;
		i++;
	}
	return niz;
}
int main ()
{
	std::cout<<"Koliko zelite elemenata: ";
	int n;
	std::cin>>n;
	//double* p = nullptr;
	std::vector<double> v;
	try {
		v.resize(n);
		std::cout<<"Unesite elemente: ";
		for(int i = 0; i<n; i++) std::cin>>v[i];
		try {
			auto p = KreirajIzvrnutiNiz(v.begin(),v.end());
			std::cout<<"Kreirani niz:";
			for(int i = 0; i<n; i++) std::cout<<" "<<p[i];
			delete[] p;
			p = nullptr;
		} catch(std::bad_alloc) {
			std::cout<<"Nedovoljno memorije!";
		}
	} catch(std::bad_alloc) {
		std::cout<<"Nedovoljno memorije!";
	}


	return 0;
}

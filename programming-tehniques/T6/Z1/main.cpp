/*
    TP 16/17 (Tutorijal 6, Zadatak 1)

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <iomanip>
template<typename TipNiza>
TipNiza* GenerirajStepeneDvojke(int n)
{
	TipNiza* p = nullptr;
	if(n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
	TipNiza max = std::numeric_limits<TipNiza>::max();
	long double ntiStepen = 1;
	for(int i = 1; i<n; i++) ntiStepen*=2;
	if(ntiStepen>max) throw std::overflow_error("Prekoracen dozvoljeni opseg");
	try {
		p = new TipNiza[n];
	} catch(...) {
		throw std::runtime_error("Alokacija nije uspijela");
	}
	long double buff = 1;
	for(int i = 0; i<n; i++) {
		if(buff>max || std::isinf(buff) || buff<=0) {
			delete[] p;
			throw std::overflow_error("Prekoracen dozvoljeni opseg");
		}
		p[i] = buff;
		buff=buff*2;
	}

	return p;
}
int main ()
{
	unsigned long int* p = nullptr;
	int n;
	std::cout<<"Koliko zelite elemenata: ";
	std::cin>>n;
	try {
		p = GenerirajStepeneDvojke<unsigned long int>(n);
	} catch(std::domain_error e) {
		std::cout<<"Izuzetak: "<<e.what();
		return 0;
	} catch(std::runtime_error e) {
		std::cout<<"Izuzetak: "<<e.what();
		return 0;
	} catch(std::overflow_error d) {
		delete[] p;
		std::cout<<"Izuzetak: "<<d.what();
		return 0;
	}

	for(int i = 0; i<n; i++) {
		if(i==n-1) std::cout<<std::fixed<<p[i];
		else std::cout<<std::fixed<<p[i]<<" ";
	}
//	GenerirajStepeneDvojke<float>(16834);
	delete[] p;
	return 0;
}

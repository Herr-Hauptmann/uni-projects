/*
    TP 2018/2019: Tutorijal 6, Zadatak 5

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <new>
#include <type_traits>
#include <stdexcept>
#include <vector>
#include <deque>

template<typename Kont>
auto KreirajDinamickuKopiju2D(Kont m)->typename std::remove_reference<decltype(m[0][0])>::type**
{
	try {
		auto kopija = new typename std::remove_reference<decltype(m[0][0])>::type*[m.size()] {};
		try {
			for(int i = 0; i<m.size(); i++) {
				kopija[i] = new typename std::remove_reference<decltype(m[0][0])>::type[m[i].size()];
			}
			for(int i = 0; i<m.size(); i++) {
				for(int j = 0; j<m[i].size(); j++) kopija[i][j] = m[i][j];
			}
		}
	 catch(std::bad_alloc) {
		for(int i = 0; i<m.size(); i++) delete[] kopija[i];
		delete[] kopija;
		throw;
	}
	return kopija;
	}
	catch(std::bad_alloc){
		throw;
	}
}
int main ()
{
	try{
	std::cout<<"Unesite broj redova kvadratne matrice: ";
	int n;
	std::cin>>n;
	std::vector<std::deque<int>> m(n,std::deque<int>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			std::cin>>m[i][j];
		}
	}
	int **p = KreirajDinamickuKopiju2D(m);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++) std::cout<<p[i][j]<<" ";
		std::cout<<std::endl;
	}
	for(int i = 0; i<n; i++) delete[] p[i];
	delete[] p;
	}
	catch(std::bad_alloc){
		std::cout<<"Nedovoljno memorije";
	}
	return 0;
}

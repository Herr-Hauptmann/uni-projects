/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>

template <typename Tip>
std::set<Tip> Presjek(std::set<Tip> s1, std::set<Tip> s2){
	std::set<Tip> ret;
	for(auto x: s1){
		for(auto y: s2){
			if(x==y){
				ret.insert(x);
			}
		}
	}
	return ret;
}
template <typename Tip>
std::set<Tip> Unija(std::set<Tip> s1, std::set<Tip> s2){
	std::set<Tip> ret;
	for(auto x: s1) ret.insert(x);
	for(auto x: s2) ret.insert(x);
	return ret;
}
int main ()
{
	return 0;
}
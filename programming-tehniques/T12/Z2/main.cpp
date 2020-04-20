/* 
    TP 16/17 (Tutorijal 12, Zadatak 2)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <set>
#include <utility>

template<typename Tip>
std::set<Tip> operator+(const std::set<Tip>& s1, const std::set<Tip>& s2){
	std::set<Tip> unija;
	for(auto x: s1) unija.insert(x);
	for(auto x: s2) unija.insert(x);
	return unija;
}

template<typename Tip>
std::set<Tip> operator*(const std::set<Tip> &s1, const std::set<Tip> &s2){
	std::set<Tip> presjek;
	for(auto x: s1){
		for(auto y: s2){
			if(x==y) presjek.insert(x);
		}
	}
	return presjek;
}
template<typename Tip>
std::ostream& operator<<(std::ostream& tok, std::set<Tip> s){
	tok<<"{";
	auto it = s.begin();
	for(int i = 0; i < s.size(); i++){
		if(i != s.size() - 1) tok<<*it<<",";
		else tok<<*it;
		it++;
	}
	tok<<"}";
	return tok;
}

template<typename Tip>
std::set<Tip> operator +=(std::set<Tip> &s1, const std::set<Tip> &s2){
	for(auto x: s2) s1.insert(x);
	return s1;
}

template<typename Tip>
std::set<Tip> operator *= (std::set<Tip> &s1, const std::set<Tip> &s2){
	s1 = s1 * s2;
	return s1;
}

template<typename Tip1, typename Tip2>
std::set<std::pair<Tip1,Tip2>> operator%(const std::set<Tip1> s1, const std::set<Tip2> s2){
	std::set<std::pair<Tip1,Tip2>> dekart;
	for(auto x: s1)
	for(auto y: s2)
	dekart.insert({x,y});
	return dekart;
}

template<typename Tip1, typename Tip2>
std::ostream& operator<<(std::ostream &tok, std::pair<Tip1,Tip2> p){
	return tok<<"("<<p.first<<","<<p.second<<")";
}
	
int main ()
{
	return 0;
}
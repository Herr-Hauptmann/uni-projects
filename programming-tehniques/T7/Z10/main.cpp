/* 
    TP 16/17 (Tutorijal 7, Zadatak 10)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>
std::function<int(int)> Kompozicija(std::function<int(int)>f,std::function<int(int)>g){
	return [f,g](int x){return f(g(x));};
}
std::function<int(int)> IteriranaFunkcija(int (f)(int), int n){
	if(n<=0) return [](int x){return x;};
	if(n==1) return [f](int x){return f(x);};
	auto ret = Kompozicija(f,f);
	for(int i = 2; i<n; i++){
		ret = Kompozicija(ret,f);
	}
	return [ret](int x){return ret(x);};
}
int main ()
{
	return 0;
}
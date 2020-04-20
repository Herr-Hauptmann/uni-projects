/* 
    TP 16/17 (Tutorijal 7, Zadatak 5)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
using pokshared = std::shared_ptr<std::string>;
int main ()
{
	
	std::cout<<"Koliko zelite recenica: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite recenice: "<<std::endl;
	std::cin.ignore(1000,'\n');
	try{
	std::shared_ptr<pokshared> p(new pokshared[n]{},[](pokshared *p){ delete[] p;});

	try {

		try {
			for(int i = 0; i<n; i++) {
				p.get()[i] = std::make_shared<std::string>();
				std::getline(std::cin, *p.get()[i]);


			}
		} catch(...) {
			for(int i = 0; i<n; i++) p.get()[i]=nullptr;
			p = nullptr;
			std::cout<<"Problemi s memorijom!";
			return 0;
		}
	
	std::sort(p.get(),p.get()+n,[](pokshared p1,pokshared p2)->bool{
		return *p1<*p2;
		});
		
	
	std::cout<<"Sortirane recenice: "<<std::endl;
	for(int i = 0; i<n; i++) {
		std::cout<<*p.get()[i]<<std::endl;
	}
	for(int i = 0; i<n; i++) p.get()[i]=nullptr;
	p = nullptr;
	
	} catch(...) {
		p=nullptr;
		throw;
	}
	}catch(...) {
		std::cout<<"Problemi s memorijom!";

	}

	return 0;
}
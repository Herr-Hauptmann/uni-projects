/* 
    TP 16/17 (Tutorijal 7, Zadatak 3)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <algorithm>
int main ()
{
	std::cout<<"Koliko zelite recenica: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite recenice: "<<std::endl;
	std::cin.ignore(1000,'\n');
	std::string** p = nullptr;
	try {
		p = new std::string*[n]{};
		try {
			for(int i = 0; i<n; i++) {
				//std::string buffer;
				p[i] = new std::string{};
				std::getline(std::cin, *p[i]);

			}
		} catch(...) {
			for(int i = 0; i<n; i++) delete p[i];
			delete[] p;
			p = nullptr;
			std::cout<<"Problemi s memorijom!";
			return 0;
		}
	
	std::sort(p,p+n,[](std::string* p1,std::string* p2)->bool{
		return *p1<*p2;
		});
		
	
	std::cout<<"Sortirane recenice: "<<std::endl;
	for(int i = 0; i<n; i++) {
		std::cout<<*p[i]<<std::endl;
	}
	for(int i = 0; i<n; i++) delete p[i];
	delete[] p;
	p = nullptr;
	
	} catch(...) {
		delete[] p;
		p=nullptr;
		std::cout<<"Problemi s memorijom!";

	}

	return 0;
}
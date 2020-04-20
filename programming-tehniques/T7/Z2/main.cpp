/* 
    TP 16/17 (Tutorijal 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
int main ()
{
	std::cout<<"Koliko zelite recenica: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite recenice: "<<std::endl;
	std::cin.ignore(1000,'\n');
	char** p = nullptr;
	try {
		p = new char*[n]{};
		try {
			for(int i = 0; i<n; i++) {
				char buffer[1000];
				std::cin.getline(buffer, sizeof buffer);
				p[i] = new char[std::strlen(buffer)+1];
				std::strcpy(p[i],buffer);
			}
		} catch(...) {
			for(int i = 0; i<n; i++) delete[] p[i];
			delete[] p;
			p = nullptr;
			std::cout<<"Problemi s memorijom!";
			return 0;
		}
	
	std::sort(p,p+n,[](char* p1,char* p2)->bool{
		if(std::strcmp(p1,p2)<0) return true;
		else return false;
		});
		
	
	std::cout<<"Sortirane recenice: "<<std::endl;
	for(int i = 0; i<n; i++) {
		std::cout<<p[i]<<std::endl;
	}
	for(int i = 0; i<n; i++) delete[] p[i];
	delete[] p;
	p = nullptr;
	} catch(...) {
		delete[] p;
		p=nullptr;
		std::cout<<"Problemi s memorijom!";

	}

	return 0;
}
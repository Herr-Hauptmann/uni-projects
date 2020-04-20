/* TP, 2018/2019, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <string>
#include <vector>

bool JeLiSlovo(char c)
{
	if(c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9') return true;
	else return false;
}

bool Simetricna(std::string rijec)
{
	bool simetricna = true;
	int vel = rijec.size();
	for(int i = 0; i<vel; i++) {
		if(rijec.at(i)>='A'&&rijec.at(i)<='Z') rijec.at(i)+=32;
	}
	for(int i = 0; i<vel/2; i++) {
		if(rijec.at(i)!=rijec.at(vel-1-i)) simetricna = false;
	}
	return simetricna;
}

std::vector<std::string> NadjiSimetricneRijeci(std::string recenica)
{
	int razmak=1;
	std::string buffer;
	std::vector<std::string> v;
	for(int i=0; i<recenica.size(); i++) {
		if(razmak==1 && JeLiSlovo(recenica.at(i))) {
			razmak=0;
			int j = i;
			while(j<recenica.size() && JeLiSlovo(recenica.at(j))) {
				buffer.push_back(recenica.at(j));
				j++;
			}
			if(Simetricna(buffer) && buffer.size()>=2) v.push_back(buffer);
			buffer.resize(0);
		}
		if(!JeLiSlovo(recenica.at(i))) razmak=1;

	}
	return v;
}


int main ()
{
	std::string recenica;
	std::cout<<"Unesite recenicu: "<<std::endl;
	std::getline(std::cin,recenica);
	std::vector<std::string> v = NadjiSimetricneRijeci(recenica);
	if(v.size()==0) {
		std::cout<<"Recenica ne sadrzi simetricne rijeci!";
		return 0;
	} else {
		std::cout<<"Simetricne rijeci unutar recenice su: "<<std::endl;
		for(int i=0; i<v.size(); i++) {
			std::cout<<v.at(i)<<std::endl;
		}
	}

	return 0;
}

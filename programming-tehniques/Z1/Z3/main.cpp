/* TP, 2018/2019, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;
Matrica KreirajMatricu(int broj_redova, int broj_kolona)
{
	return Matrica (broj_redova, std::vector<int>(broj_kolona));
}
int BrojCifara(int a)
{
	int broj_cifara = 0;
	if(a<0) {
		broj_cifara++;
		a=-a;
	}
	while(a!=0) {
		a/=10;
		broj_cifara++;
	}
	return broj_cifara;
}
int NajvecaSirina(Matrica m)
{
	if(m.size()==0) return 0;
	long int maxi = BrojCifara(m.at(0).at(0));
	for(long int i = 0; i<m.size(); i++) {
		for(long int j = 0; j<m.at(i).size(); j++) {
			if(BrojCifara(m.at(i).at(j))>BrojCifara(maxi)) maxi = m.at(i).at(j);
		}
	}
	return BrojCifara(maxi);
}

Matrica KroneckerovProizvod(Matrica a, Matrica b)
{
	bool prva = true, druga = true;
	Matrica prazna;
	if(a==prazna || b==prazna) return prazna;
	if(a.size()==0 || a.at(0).size()==0) prva = false;
	if(b.size()==0 || b.at(0).size()==0) druga = false;
	for(int i = 0; i<a.size(); i++) {
		if(a.at(0).size() != a.at(i).size()) prva = false;
	}
	for(int i = 0; i<b.size(); i++) {
		if(b.at(0).size() != b.at(i).size()) druga = false;
	}
	if(!prva && !druga) throw std::domain_error("Parametri nemaju formu matrice");
	if(!prva) throw std::domain_error("Prvi parametar nema formu matrice");
	if(!druga) throw std::domain_error("Drugi parametar nema formu matrice");
	Matrica c = KreirajMatricu(a.size()*b.size(),a.at(0).size()*b.at(0).size());

	for(int i = 0; i<a.size(); i++) {
		for(int j = 0; j<a.at(0).size(); j++) {
			int pocetniRed = i*b.size();
			int pocetnaKol = j*b.at(0).size();
			for(int k = 0; k<b.size(); k++) {
				for(int l = 0; l<b.at(0).size(); l++) {
					c.at(pocetniRed+k).at(pocetnaKol+l) = a.at(i).at(j)*b.at(k).at(l);
				}
			}
		}
	}

	return c;

}


int main ()
{
	int v1,s1;
	std::cout<<"Unesite dimenzije prve matrice: "<<std::endl;
	std::cin>>v1>>s1;
	Matrica a = KreirajMatricu(v1,s1);
	std::cout<<"Unesite elemente prve matrice: "<<std::endl;
	for(int i = 0; i<v1; i++) {
		for(int j = 0; j<s1; j++) {
			int x;
			std::cin>>x;
			a.at(i).at(j)=x;

		}
	}
	int v2,s2;
	std::cout<<"Unesite dimenzije druge matrice: "<<std::endl;
	std::cin>>v2>>s2;
	Matrica b = KreirajMatricu(v2,s2);
	std::cout<<"Unesite elemente druge matrice: "<<std::endl;
	for(int i = 0; i<v2; i++) {
		for(int j = 0; j<s2; j++) {
			int x;
			std::cin>>x;
			b.at(i).at(j)=x;

		}
	}

	auto c = KroneckerovProizvod(a,b);
	int sirina = NajvecaSirina(c);
	std::cout<<"Njihov Kroneckerov proizvod glasi: "<<std::endl;
	for(int i = 0; i<c.size(); i++){
		for(int j = 0; j<c.at(i).size(); j++){
			std::cout<<std::setw(sirina+1)<<std::right<<c.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	return 0;
}

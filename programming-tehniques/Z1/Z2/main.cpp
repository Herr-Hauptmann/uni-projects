/* TP, 2018/2019, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <complex>
#include <vector>
#include <stdexcept>
typedef std::vector<std::vector<int>> Matrica;


std::complex<int> MaxElement(Matrica m, int i, int j)
{
	int max_i = i;
	int max_j = j;
	
	if(m.at(0).size()==1){
		if(i==0){
			if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) return std::complex<int>(i+1,j);
		}
		if(i==m.size()-1){
			if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) return std::complex<int>(i-1,j);
		}
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) max_i=i+1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) max_i=i-1;
		return std::complex<int>(max_i,max_j);
	}
	else if(m.size()==1){
		if(j==0){
			if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) return std::complex<int>(i,j+1);
		}
		if(j==m.at(0).size()-1){
			if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) return std::complex<int>(i,j-1);
		}
		if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) max_j=j+1;
		if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) max_j=j-1;
		return std::complex<int>(max_i,max_j);
	}
	else if(i==0 && j==0) {
		if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) {
			max_j = j+1;
		}

		if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) {
			max_i = i+1;
		}
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j+1)) {
			max_i = i+1;
			max_j = j+1;
		}
		return std::complex<int>(max_i,max_j);

	} else if(i==0 && j==m.at(0).size()-1) {
		if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) {
			max_j=j-1;
		}
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) {
			max_i=i+1;
		}
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j-1)) {
			max_i=i+1;
			max_j=j-1;
		}
		return std::complex<int>(max_i,max_j);
	} else if(i==m.size()-1 && j==0) {
		if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) max_j=j+1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) max_i=i-1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j+1)) {
			max_i=i-1;
			max_j=j+1;
		}
		return std::complex<int>(max_i,max_j);
	} else if(i==m.size()-1 && j==m.at(0).size()-1) {
		if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) max_j=j-1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) max_i=i-1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j-1)) {
			max_i=i-1;
			max_j=j-1;
		}
		return std::complex<int>(max_i,max_j);

	} else if(i==0) {
		if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) max_j=j+1;
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j+1)) {
			max_i=i+1;
			max_j=j+1;
		}
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) max_i=i+1;
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j-1)) {
			max_i=i+1;
			max_j=j-1;
		}
		if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) max_j=j-1;
		return std::complex<int>(max_i,max_j);
	} else if(i==m.size()-1) {
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) max_i=i-1;
		if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) max_j=j+1;
		if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) max_j=j-1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j+1)) {
			max_i=i-1;
			max_j=j+1;
		}
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j-1)) {
			max_i=i-1;
			max_j=j-1;
		}

	} else if(j==0) {
		if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) max_j=j+1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) max_i=i-1;
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) max_i=i+1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j+1)) {
			max_i=i-1;
			max_j=j+1;
		}
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j+1)) {
			max_i=i+1;
			max_j=j+1;
		}
		return std::complex<int>(max_i,max_j);
	}
	else if(j==m.at(0).size()-1){
		if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) max_j=j-1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) max_i=i-1;
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) max_i=i+1;
		if(m.at(max_i).at(max_j)<m.at(i-1).at(j-1)){
			max_i=i-1;
			max_j=j-1;
		}
		if(m.at(max_i).at(max_j)<m.at(i+1).at(j-1)){
			max_i=i+1;
			max_j=j-1;
		}
		return std::complex<int>(max_i,max_j);
	}
		else{
			if(m.at(max_i).at(max_j)<m.at(i-1).at(j)) max_i=i-1;
			if(m.at(max_i).at(max_j)<m.at(i-1).at(j+1)){
				max_i=i-1;
				max_j=j+1;
			}
			if(m.at(max_i).at(max_j)<m.at(i).at(j+1)) max_j=j+1;
			if(m.at(max_i).at(max_j)<m.at(i+1).at(j+1)){
				max_i=i+1;
				max_j=j+1;
			}
			if(m.at(max_i).at(max_j)<m.at(i+1).at(j)) max_i=i+1;
			if(m.at(max_i).at(max_j)<m.at(i+1).at(j-1)){
				max_i=i+1;
				max_j=j-1;
			}
			if(m.at(max_i).at(max_j)<m.at(i).at(j-1)) max_j=j-1;
			if(m.at(max_i).at(max_j)<m.at(i-1).at(j-1)){
				max_i=i-1;
				max_j=j-1;
			}
			return std::complex<int>(max_i,max_j);
		}
	
	
	return std::complex<int>(max_i,max_j);
}


bool JeLiVrh(Matrica m, int i, int j)
{
	if(m.size()==1 && m.at(0).size()==1) return true;
	else if(m.at(0).size()==1){
		if(i==m.size()-1){
			if(m.at(i).at(j)>=m.at(i-1).at(j)) return true;
			else return false;
		}
		if(i==0){
			if(m.at(i).at(j)>=m.at(i+1).at(j)) return true;
			else return false;
		}
		if(m.at(i).at(j)>=m.at(i+1).at(j) && m.at(i).at(j)>=m.at(i-1).at(j)) return true;
		else return false;
	}
	else if(m.size()==1){
		if(j==m.at(0).size()-1){
			if(m.at(i).at(j)>=m.at(i).at(j-1)) return true;
			else return false;
		}
		if(j==0){
			if(m.at(i).at(j)>=m.at(i).at(j+1)) return true;
			else return false;
		}
		if(m.at(i).at(j)>=m.at(i).at(j+1) && m.at(i).at(j-1)) return true;
		else return false;
	}
	else if (i==0 && j==0) {
		if(m.at(i).at(j)>=m.at(i).at(j+1) && m.at(i).at(j)>=m.at(i+1).at(j)&&m.at(i).at(j)>=m.at(i+1).at(j+1)) return true;
		else return false;
	} else if(i==0 && j==m.at(0).size()-1) {
		if(m.at(i).at(j)>=m.at(i).at(j-1)&& m.at(i).at(j)>=m.at(i+1).at(j) &&m.at(i).at(j)>=m.at(i+1).at(j-1)) return true;
		else return false;
	} else if(i==m.size()-1 && j==0) {
		if(m.at(i).at(j)>=m.at(i).at(j+1) && m.at(i).at(j)>=m.at(i-1).at(j) && m.at(i).at(j)>=m.at(i-1).at(j+1)) return true;
		else return false;
	} else if(i==m.size()-1 && j==m.at(0).size()-1) {
		if(m.at(i).at(j)>=m.at(i).at(j-1) && m.at(i).at(j)>=m.at(i-1).at(j) && m.at(i).at(j)>=m.at(i-1).at(j-1)) return true;
		else return false;
	} else if(i==0) {
		if(m.at(i).at(j)>=m.at(i).at(j+1) && m.at(i).at(j)>=m.at(i).at(j-1)&&m.at(i).at(j)>=m.at(i+1).at(j)&&m.at(i).at(j)>=m.at(i+1).at(j+1)&&m.at(i).at(j)>=m.at(i+1).at(j-1)) return true;
		else return false;
	} else if(i==m.size()-1) {
		if(m.at(i).at(j)>=m.at(i).at(j+1) && m.at(i).at(j)>=m.at(i).at(j-1) && m.at(i).at(j)>=m.at(i-1).at(j) && m.at(i).at(j)>=m.at(i-1).at(j-1) && m.at(i).at(j)>=m.at(i-1).at(j+1)) return true;
		else return false;
	} else if(j==0) {
		if(m.at(i).at(j)>=m.at(i-1).at(j) && m.at(i).at(j)>=m.at(i-1).at(j+1) && m.at(i).at(j)>=m.at(i).at(j+1) && m.at(i).at(j)>=m.at(i+1).at(j) && m.at(i).at(j)>=m.at(i+1).at(j+1)) return true;
			else return false;
			} else if(j==m.at(0).size()-1) {
		if(m.at(i).at(j)>=m.at(i-1).at(j) && m.at(i).at(j)>=m.at(i-1).at(j-1) && m.at(i).at(j)>=m.at(i).at(j-1) && m.at(i).at(j)>=m.at(i+1).at(j-1) && m.at(i).at(j)>=m.at(i+1).at(j)) return true;
		else return false;
	} else {
		if(m.at(i).at(j)>=m.at(i-1).at(j) && m.at(i).at(j)>=m.at(i-1).at(j+1) && m.at(i).at(j)>=m.at(i).at(j+1) && m.at(i).at(j)>=m.at(i+1).at(j+1) && m.at(i).at(j)>=m.at(i+1).at(j)&&m.at(i).at(j)>=m.at(i+1).at(j-1)&&m.at(i).at(j)>=m.at(i).at(j-1)&&m.at(i).at(j)>=m.at(i-1).at(j-1)) return true;
		else return false;

	}
 return false;
}

std::complex<double> VrhMatrice(Matrica m, int red, int kolona)
{
	Matrica prazna;
	if(m==prazna) throw std::domain_error("Nekorektna matrica");
	if(m.at(0).size()==0 || m.size()==0) throw std::domain_error("Nekorektna matrica");
	if(red>m.size() || kolona>m.at(0).size() || red<0 || kolona<0) throw std::range_error("Nekorektna pocetna pozicija");
	for(int i = 0; i<m.size(); i++)
		if(m.at(i).size() != m.at(0).size()) throw std::domain_error("Nekorektna matrica");
	std::complex<double> z(red,kolona);
	while(1) {
		if(JeLiVrh(m,z.real(),z.imag())) {
			return z;
		} else {
			z=MaxElement(m,z.real(),z.imag());
		}
	}



}


int main ()
{
	int red, kolona;
	std::cout<<"Unesite broj redova i kolona matrice:"<<std::endl;
	std::cin>>red>>kolona;
	Matrica m(red,std::vector<int>(kolona));
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	for(int i = 0; i<red; i++){
		for(int j = 0; j<kolona; j++){
			int x;
			std::cin>>x;
			m.at(i).at(j)=x;
		}
	}
	std::cout<<"Unesite poziciju odakle zapocinje pretraga:"<<std::endl;
	int x,y;
	std::cin>>x>>y;
	std::complex<double> rez;
	try{
	rez = VrhMatrice(m,x,y);
	}
	catch(std::range_error greska){
		std::cout<<"Greska: "<<greska.what();
		return 0;
	}
	catch(std::domain_error e){
		std::cout<<e.what();
	}
	std::cout<<"Nadjen je vrh matrice na poziciji "<<std::real(rez)<<" "<<std::imag(rez)<<std::endl;
	std::cout<<"Njegova vrijednost je "<<m.at(rez.real()).at(rez.imag());
	return 0;
}

/* 
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
const double pi = 4*std::atan(1);
class Krug{
double poluprecnik;
public:
explicit Krug(double r){
	if(r<=0) throw std::domain_error("Neispravan poluprecnik");
	poluprecnik = r;
}
void Postavi(double r){
	if(r<=0) throw std::domain_error("Neispravan poluprecnik");
	poluprecnik = r;
}
double DajPoluprecnik() const{
	return poluprecnik;
}
double DajObim() const{
	return 2*poluprecnik*pi;
}
double DajPovrsinu() const{
	return poluprecnik*poluprecnik*pi;
}
void Skaliraj(double parametar){
	if(parametar<=0) throw std::domain_error("Neispravan faktor skaliranja");
	poluprecnik*=parametar;
}
void Ispisi() const{
	std::cout<<std::fixed<<std::setprecision(5)<<"R="<<DajPoluprecnik()<<" O="<<DajObim()<<" P="<<DajPovrsinu();
}
};
class Valjak{
	Krug baza;
	double visina;
	public:
	Valjak(double r, double h): baza(r){
		if(h<0) throw std::domain_error("Neispravna visina");
		visina = h;
	}
	void Postavi(double r, double h){
		if(r<=0) throw std::domain_error("Neispravan poluprecnik");
		if(h<=0) throw std::domain_error("Neispravna visina");
		baza.Postavi(r);
		visina = h;
	}
	Krug DajBazu() const{
		return baza;
	}
	double DajPoluprecnikBaze() const{
		return baza.DajPoluprecnik();
	}
	double DajVisinu() const{
		return visina;
	}
	double DajPovrsinu() const{
		return (2*baza.DajPovrsinu() + 2*baza.DajPoluprecnik()*pi*visina);
	}
	double DajZapreminu() const{
		return baza.DajPovrsinu()*visina;
	}
	void Skaliraj(double parametar){
		if(parametar<=0) throw std::domain_error("Neispravan faktor skaliranja");
		visina*=parametar;
		baza.Postavi(baza.DajPoluprecnik()*parametar);
	}
	void Ispisi() const{
		std::cout<<std::fixed<<std::setprecision(5)<<"R="<<DajPoluprecnikBaze()<<" H="<<DajVisinu()<<" P="<<DajPovrsinu()<<" V="<<DajZapreminu();
	}
};
int main ()
{
	return 0;
}
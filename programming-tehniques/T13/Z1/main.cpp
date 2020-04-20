/* 
    TP 16/17 (Tutorijal 13, Zadatak 1)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <new>
#include <memory>
class Lik{
	public:
	virtual void IspisiSpecificnosti() const = 0;
	virtual double DajObim() const = 0;
	virtual double DajPovrsinu() const = 0;
	virtual void Ispisi(){
		IspisiSpecificnosti();
		std::cout<<std::endl<<"Obim: "<<DajObim()<<" Povrsina: "<<DajPovrsinu()<<std::endl;
	}
	virtual ~Lik(){}
};

class Krug: public Lik{
	double poluprecnik;
	public:
	Krug(double poluprecnik){
		if(poluprecnik <= 0) throw std::domain_error("Neispravni parametri");
		Krug::poluprecnik = poluprecnik;
	}
	Krug(const Krug& k){
		if(k.poluprecnik <= 0) throw std::domain_error("Neispravni parametri");
		Krug::poluprecnik = k.poluprecnik;
	}
	void IspisiSpecificnosti() const override{
		std::cout<<"Krug poluprecnika "<<poluprecnik<<std::endl;
	}
	double DajObim() const override{
		return 2*poluprecnik*4*atan(1);
	}
	double DajPovrsinu() const override{
		return poluprecnik*poluprecnik*4*atan(1);
	}
};

class Pravougaonik: public Lik{
	double a, b;
	public:
	Pravougaonik(double a, double b){
		if( a <= 0 || b <= 0) throw std::domain_error("Neispravni parametri");
		Pravougaonik::a = a; Pravougaonik::b = b;
	}
	Pravougaonik(const Pravougaonik& p){
		if(p.a <= 0 || p.b <= 0) throw std::domain_error("Neispravni parametri");
		a = p.a; b = p.b;
	}
	void IspisiSpecificnosti() const override{
		std::cout<<"Pravougaonik sa stranicama duzine "<<a<<" i "<<b<<std::endl;
	}
	double DajObim() const override{
		return 2*a+2*b;
	}
	double DajPovrsinu() const override{
		return a*b;
	}
};

class Trougao: public Lik{
	double a, b, c;
	public:
	Trougao(double i, double j, double k){
		if(i <= 0 || j <= 0 || k <= 0) throw std::domain_error("Neispravni parametri");
		if(i + j <= k) throw std::domain_error("Neispravni parametri");
		if(i + k <= j) throw std::domain_error("Neispravni parametri");
		if(j + k <= i) throw std::domain_error("Neispravni parametri");
		a = i; b = j; c = k;
	}
	double DajObim() const override{
		return a + b + c;
	}
	double DajPovrsinu() const override{
		double s = (a + b + c) / 2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	void IspisiSpecificnosti() const override{
		std::cout<<"Trougao sa stranicama duzine "<<a<<", "<<b<<" i "<<c<<std::endl;
		}
};
int main ()
{
	std::cout<<"Koliko zelite likova: ";
	int n;
	std::cin>>n;
	std::vector<std::shared_ptr<Lik>> likovi(n);
	for(int i = 0; i < n; i++){
		std::cin.clear();
		std::cin.ignore(10000,'\n');
		std::cout<<"Lik "<<i+1<<": ";
		char slovo, comma;
		std::cin>>slovo;
		if(slovo == 'P'){
			double a, b;
			std::cin>>a>>comma>>b;
			if(!std::cin || comma != ',' || std::cin.peek() != '\n'){
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
				i--;
				continue;
			}
			try{
				likovi[i] = std::make_shared<Pravougaonik>(a,b);
			}
			catch(...){
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
				i--;
				continue;
			}
		}
		
	 else if(slovo == 'T'){
			double a, b, c;
			char znak = '1';
			std::cin>>a>>znak;
			if(znak == ',') std::cin>>b>>znak>>c;
			if(!std::cin || znak != ',' || std::cin.peek() != '\n'){
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
				i--;
				continue;
			}
			try{
				likovi[i] = std::make_shared<Trougao>(a,b,c);
			}
			catch(...){
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
				i--;
				continue;
			}
		}
		
		else if(slovo == 'K'){
			double p;
			std::cin>>p;
			if(!std::cin || std::cin.peek() != '\n'){
				std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
				i--;
				continue;
			}
		
		try{
			likovi[i] = std::make_shared<Krug>(p);
		}
		catch(...){
			std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
			i--;
			continue;
		}
		}
		else{
			std::cout<<"Pogresni podaci, ponovite unos!"<<std::endl;
			i--;
			continue;
		}
	}
	std::cout<<std::endl;
	for(auto x: likovi) x->Ispisi();
	return 0;
}
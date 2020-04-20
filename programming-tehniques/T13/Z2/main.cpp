/* 
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <stdexcept>

class ApstraktniStudent{
	protected:
	std::string ime;
	std::string prezime;
	int broj_indeksa;
	double prosjek;
	int broj_polozenih;
	public:
	ApstraktniStudent(std::string ime, std::string prezime, int broj_indeksa): ime(ime), prezime(prezime), broj_indeksa(broj_indeksa), broj_polozenih(0),prosjek(5){}
	virtual ~ApstraktniStudent(){}
	std::string DajIme() const { return ime; }
	std::string DajPrezime() const {return prezime; }
	int DajBrojIndeksa() const {return broj_indeksa; }
	int DajBrojPolozenih() const { return broj_polozenih;}
	double DajProsjek() const {return prosjek; }
	void RegistrirajIspit(int ocjena){
		if(ocjena > 10 || ocjena < 5) throw std::domain_error("Neispravna ocjena");
		if(ocjena == 5) return;
		double suma = prosjek * broj_polozenih;
		broj_polozenih++;
		prosjek = (suma + ocjena) / broj_polozenih;
	}
	void PonistiOcjene() { broj_polozenih = 0; prosjek = 5; }
	virtual void IspisiPodatke() const = 0;
	virtual ApstraktniStudent* DajKopiju() const = 0;
};

class StudentBachelor: public ApstraktniStudent{
	public:
	StudentBachelor(std::string ime, std::string prezime, int broj_indeksa): ApstraktniStudent(ime,prezime,broj_indeksa){}
	void IspisiPodatke() const override{
		std::cout<<"Student bachelor studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl;
		std::cout<<"ima prosjek "<<DajProsjek()<<"."<<std::endl;
	}
	ApstraktniStudent* DajKopiju() const override {return new StudentBachelor(*this);}
};

class StudentMaster: public ApstraktniStudent{
int godina_diplomiranja;
public:
StudentMaster(std::string ime, std::string prezime, int broj_indeksa, int godina_diplomiranja): ApstraktniStudent(ime,prezime,broj_indeksa), godina_diplomiranja(godina_diplomiranja){}
ApstraktniStudent* DajKopiju() const override{ return new StudentMaster(*this);}
void IspisiPodatke() const override{
	std::cout<<"Student master studija "<<DajIme()<<" "<<DajPrezime()<<", sa brojem indeksa "<<DajBrojIndeksa()<<","<<std::endl;
		std::cout<<"zavrsio bachelor studij godine "<<godina_diplomiranja<<",ima prosjek "<<DajProsjek()<<"."<<std::endl;
	
}
};
int main ()
{
	return 0;
}
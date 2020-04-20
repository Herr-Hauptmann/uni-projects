/* 
    TP 16/17 (Tutorijal 13, Zadatak 4)
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
class Student{
	ApstraktniStudent* p;
	public:
	void Test() const{if(!p) throw std::logic_error("Nespecifiran student!");}
	Student(){p = nullptr;}
	Student(const ApstraktniStudent& student): p(student.DajKopiju()){}
	Student(const Student &student){
		if(!student.p) p = nullptr;
		else p = student.p->DajKopiju();
	}
	Student(Student &&s){
		p = s.p;
		s.p = nullptr;
	}
	Student &operator = (const Student &student){
		ApstraktniStudent* pok(nullptr);
		if(student.p != nullptr) pok = student.p->DajKopiju();
		delete p;
		p = pok;
		return *this;
	}
	
	Student& operator = (Student&& student){
		std::swap(p,student.p);
		return *this;
	}
	std::string DajIme() const {return p->DajIme();}
	std::string DajPrezime() const{return p->DajPrezime();}
	int DajBrojIndeksa() const {return p->DajBrojIndeksa();}
	int DajBrojPolozenih() const{return p->DajBrojPolozenih();}
	void RegistrirajIspit(int ocjena){
		p->RegistrirajIspit(ocjena);
	}
	double DajProsjek() const{return p->DajProsjek();}
	void PonistiOcjene(){p->PonistiOcjene();}
	void IspisiPodatke() const {p->IspisiPodatke();}
	
	
	~Student(){delete p;}
};
int main ()
{
	return 0;
}
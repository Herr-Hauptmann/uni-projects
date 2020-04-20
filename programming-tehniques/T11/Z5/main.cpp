/* 
    TP 16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <new>
#include <memory>
#include <algorithm>
#include <vector>
class Tim
{
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_poraza;
	int broj_datih;
	int broj_primljenih;
	int broj_poena;
	int broj_nerijesenih;
public:
	Tim(const char* p)
	{
		if(std::strlen(p)>20) throw std::range_error("Predugacko ime tima");
		std::strcpy(ime_tima,p);
		broj_datih=0;
		broj_odigranih=0;
		broj_pobjeda=0;
		broj_poraza=0;
		broj_poena=0;
		broj_primljenih=0;
		broj_nerijesenih=0;
	}
	Tim(const Tim& t)
	{
		if(std::strlen(t.DajImeTima())>20) throw std::range_error("Predugacko ime tima");
		std::strcpy(ime_tima,t.DajImeTima());
		broj_datih=t.broj_datih;
		broj_odigranih=t.broj_odigranih;
		broj_pobjeda=t.broj_pobjeda;
		broj_poraza=t.broj_poraza;
		broj_poena=t.broj_poena;
		broj_primljenih=t.broj_primljenih;
		broj_nerijesenih=t.broj_nerijesenih;

	}
	void ObradiUtakmicu(int broj_datih1, int broj_primljenih1)
	{
		if(broj_datih1 < 0 || broj_primljenih1 < 0) throw std::range_error("Neispravan broj golova");
		broj_datih+=broj_datih1;
		broj_primljenih+=broj_primljenih1;
		if(broj_datih1 > broj_primljenih1) {
			broj_poena+=3;
			broj_pobjeda++;
		}
		if(broj_datih1 == broj_primljenih1) {
			broj_poena+=1;
			broj_nerijesenih++;
		}
		if(broj_datih1<broj_primljenih1)	broj_poraza++;


		broj_odigranih++;

	}
	const char* DajImeTima() const
	{
		return ime_tima;
	}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return broj_datih-broj_primljenih;
	}
	void IspisiPodatke()
	{
		std::cout<<std::setw(20)<<std::left<<ime_tima;
		std::cout<<std::setw(4)<<std::right<<broj_odigranih<<std::setw(4)<<broj_pobjeda<<std::setw(4)<<broj_nerijesenih<<std::setw(4)
		         <<broj_poraza<<std::setw(4)<<broj_datih<<std::setw(4)<<std::setw(4)<<broj_primljenih<<std::setw(4)<<broj_poena;
		std::cout<<std::endl;

	}
	friend class Liga;

};

class Liga
{
	int broj_timova;
	std::vector<std::shared_ptr<Tim>> timovi;
public:
	friend class Tim;
	explicit Liga(){}
	explicit Liga(int velicina_lige):broj_timova(0){timovi.resize(velicina_lige,nullptr);}
	explicit Liga(std::initializer_list<Tim> lista_timova)
	{
		timovi.resize(lista_timova.size(),nullptr);
		auto p = lista_timova.begin();
		for(int i = 0; i < lista_timova.size(); i++) {
			timovi.at(i) = std::make_shared<Tim>(*p);
			p++;
		}
		broj_timova = lista_timova.size();
	}
	~Liga()
	{
		for(int i = 0; i < timovi.size(); i++) timovi.at(i) = nullptr;
	}
	Liga(const Liga& l): broj_timova(l.broj_timova)
	{
	timovi.resize(l.broj_timova,nullptr);
	for(int i = 0; i < l.broj_timova; i++) timovi.at(i) = std::make_shared<Tim>(*l.timovi.at(i));
	}
	Liga(Liga&& l)
	{
		std::swap(broj_timova,l.broj_timova);
		timovi.resize(broj_timova,nullptr);
		for(int i = 0; i < broj_timova; i++) timovi.at(i) = l.timovi.at(i);
		for(int i = 0; i < broj_timova; i++) l.timovi.at(i) = nullptr;
		l.broj_timova=0;
		
	}

	Liga& operator = (const Liga& l)
	{
		if(broj_timova < l.broj_timova) {
			timovi.resize(l.broj_timova,nullptr);
			for(int i = broj_timova; i < l.broj_timova; i++) timovi.at(i) = std::make_shared<Tim>(*l.timovi.at(i));
		} else {
			timovi.resize(l.broj_timova);
		}

		broj_timova = l.broj_timova;
		for(int i = 0; i < broj_timova; i++) *timovi[i] = *l.timovi[i];
		return *this;
	}

	Liga& operator =(Liga&& l)
	{
		std::swap(broj_timova, l.broj_timova);
		timovi.resize(l.timovi.size(),nullptr);
		for(int i = 0; i < broj_timova; i++) std::swap(timovi.at(i),l.timovi.at(i));
		l.broj_timova = 0;
		return *this;
	}
	void DodajNoviTim(const char ime_tima_dodaj[])
	{
		for(int i = 0; i < broj_timova; i++) {
			if(strcmp(timovi[i]->ime_tima,ime_tima_dodaj)==0) throw std::logic_error("Tim vec postoji");
		}
		timovi[broj_timova] = std::make_shared<Tim>(ime_tima_dodaj);
		broj_timova++;
	}
	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2);
	void IspisiTabelu();
};
void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1, int rezultat_2)
{
	bool pronadjen = false;
	for(int i = 0; i < broj_timova; i++) {
		if(strcmp(timovi[i]->ime_tima,tim1) == 0) {
			pronadjen = true;
			timovi[i]->Tim::ObradiUtakmicu(rezultat_1,rezultat_2);
			break;
		}
	}
	if(pronadjen == false) throw std::logic_error("Tim nije nadjen");
	pronadjen = false;
	for(int i = 0; i < broj_timova; i++) {
		if(strcmp(timovi[i]->ime_tima,tim2) == 0) {
			pronadjen = true;
			timovi[i]->Tim::ObradiUtakmicu(rezultat_2,rezultat_1);
			break;
		}
	}
	if(pronadjen == false) throw std::logic_error("Tim nije nadjen");

}

void Liga::IspisiTabelu()
{
	std::sort(timovi.begin(),timovi.begin()+broj_timova,[](std::shared_ptr<Tim> tim1, std::shared_ptr<Tim> tim2)->bool {
		if(tim1->broj_poena != tim2->broj_poena) return tim1->broj_poena > tim2->broj_poena;
		if(tim1->DajGolRazliku() != tim2->DajGolRazliku()) return tim1->DajGolRazliku() > tim2->DajGolRazliku();
		if(strcmp(tim1->ime_tima,tim2->ime_tima)<0) return true;
		else return false;
	});
	for(int i = 0; i < broj_timova; i++) timovi[i]->IspisiPodatke();
}


int main ()
{
	// AT7: Provjera ispravne implementacije pomjerajućeg operatora dodjele i provjera na plitko kopiranje

Liga l1{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo", "FK Sloboda", "FK Krupa", "FK Radnik Bijeljina"};
l1.RegistrirajUtakmicu("FK Sloboda", "HSK Zrinjski",1,1);
	
Liga l2{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};
Liga l3{"NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo","NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo","NK Zeljeznicar", "HSK Zrinjski", "FK Sarajevo"};
	
//l3 = std::move(l1);
l2 = l1;
	
std::cout << "Liga 1:" << std::endl;
l1.IspisiTabelu();
std::cout << std::endl  << "Liga 2:" << std::endl;
l2.IspisiTabelu();
std::cout << std::endl  << "Liga 3:" << std::endl;
//l3.IspisiTabelu();
	return 0;
}

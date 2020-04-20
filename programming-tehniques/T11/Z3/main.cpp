/* 
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <iomanip>
class Tim{
char ime_tima[20];
int broj_odigranih;
int broj_pobjeda;
int broj_poraza;
int broj_datih;
int broj_primljenih;
int broj_poena;
int broj_nerijesenih;
public:
Tim(const char* p){
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
void ObradiUtakmicu(int broj_datih1, int broj_primljenih1){
	if(broj_datih1 < 0 || broj_primljenih1 < 0) throw std::range_error("Neispravan broj golova");
	broj_datih+=broj_datih1; broj_primljenih+=broj_primljenih1;
	if(broj_datih1 > broj_primljenih1) {
		broj_poena+=3;
		broj_pobjeda++;
	}
	if(broj_datih1 == broj_primljenih1){
	broj_poena+=1;
	broj_nerijesenih++;
	}
	if(broj_datih1<broj_primljenih1)	broj_poraza++;
		
	
	broj_odigranih++;
	
}
const char* DajImeTima() const { return ime_tima;}
int DajBrojPoena() const { return broj_poena;}
int DajGolRazliku() const { return broj_datih-broj_primljenih;}
void IspisiPodatke(){
	std::cout<<std::setw(20)<<std::left<<ime_tima;
	std::cout<<std::setw(4)<<std::right<<broj_odigranih<<std::setw(4)<<broj_pobjeda<<std::setw(4)<<broj_nerijesenih<<std::setw(4)
	<<broj_poraza<<std::setw(4)<<broj_datih<<std::setw(4)<<std::setw(4)<<broj_primljenih<<std::setw(4)<<broj_poena;
	std::cout<<std::endl;
	
}

};
int main ()
{
	return 0;
}
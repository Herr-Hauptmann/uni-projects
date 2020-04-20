/* 
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
class StedniRacun{
double novac;
public:
StedniRacun(double pare = 0){
	if(pare<0) throw std::logic_error("Nedozvoljeno pocetno stanje");
	novac=pare;
}
void Ulozi(double iznos){
	if(novac+iznos<0) throw std::logic_error("Transakcija odbijena");
	novac+=iznos;
}
void Podigni(double iznos){
	if(iznos>novac) throw std::logic_error("Transakcija odbijena");
	novac-=iznos;
}
double DajStanje() const {
	return novac;
}
void ObracunajKamatu(double kamatna_stopa){
	if(kamatna_stopa<0) throw std::logic_error("Nedozvoljena kamatna stopa");
	double iznos = (novac*kamatna_stopa)/100;
	novac+=iznos;
}


};
int main ()
{
	int x;
	std::cout<<"Unesite pocetnu vrijednost stednog racuna";
	std::cin>>x;
	StedniRacun racun(x);
	std::cout<<racun.DajStanje();
	racun.Ulozi(200);
	racun.Podigni(60.2);
	racun.ObracunajKamatu(0.2);
	std::cout<<racun.DajStanje();
	return 0;
}
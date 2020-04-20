/* 
    TP 16/17 (Tutorijal 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
const double pi = 4*std::atan(1);
double Reduciraj(double ugao){
	while(ugao>=2*pi) ugao-=2*pi;
	while(ugao<0) ugao+=2*pi;
	return ugao;
	}
int sekunde(double ugao){
		return ugao*360*60*60/(2*pi);
	}
	
class Ugao{
	double ugao;
	public:
	Ugao(double rad = 0){
		ugao = Reduciraj(rad);
	}
	Ugao(double stepeni, double minute, double sekunde){
		ugao = Reduciraj((stepeni + minute/60. + sekunde/3600.) * pi/180);
	}
	void Postavi(double rad){
		ugao=Reduciraj(rad);
	}
	void Postavi(int stepeni, int minute, int sekunde){
		ugao=Reduciraj((stepeni+minute/60. + sekunde/3600.)*pi/180);
	}
	double DajRadijane() const {return ugao;}
	void OcitajKlasicneJednacine(int &stepeni, int &minute, int &sekunde){
		stepeni = int(180*ugao/pi);
		minute = int(180*ugao/pi*60);
		sekunde = int(180*ugao/pi*3600);
	}
	int DajStepene() const{
		return sekunde(ugao)/3600;
	}
	int DajMinute() const{
		return (sekunde(ugao)/60)%60;
	}
	int DajSekunde() const{
		return sekunde(ugao)%60;
	}
	void Ispisi() const {
		std::cout<<std::fixed<<std::setprecision(5)<<ugao;
	}
	void IspisiKlasicno() const {
		std::cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec ";
	}
	Ugao& SaberiSa(const Ugao& u){
		ugao = Reduciraj(ugao + u.DajRadijane() + 5e-8);
		return *this;
	}
	Ugao& PomnoziSa(double x){
		ugao=Reduciraj(ugao*x);
		return *this;
	}
	friend Ugao ZbirUglova(const Ugao& u1, const Ugao& u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao& u, double x);
};
Ugao ZbirUglova(const Ugao& u1, const Ugao& u2){
		return Reduciraj(u1.DajRadijane() + u2.DajRadijane());
	}
Ugao ProduktUglaSaBrojem(const Ugao& u, double x){
return Reduciraj(u.DajRadijane()*x);
}
int main ()
{
	return 0;
}
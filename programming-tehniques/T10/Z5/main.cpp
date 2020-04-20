/* 
    TP 16/17 (Tutorijal 10, Zadatak 5)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
const double pi = 4*std::atan(1);
void Normala(int &h, int &m, int &s){
	while(s<0){
		s=60+s;
		if(m==0){
			m = 59;
			if(h==0)
			h=59;
		}
		else m--;
	}
	if(s>60){
		int temp = s/60;
		s-=temp*60;
		m+=temp;
	}
	while(m<0){
		m=60+m;
		if(h==0) h=59;
		else h--;
	}
	if(m>60){
		int tmp = m/60;
		m-=tmp*60;
		h+=tmp;
	}
	while(h<0) h+=360;
	if(h>360);
	int tmp = h/360;
	h-=tmp*360;
}
double Reduciraj(double ugao){
	while(ugao>=2*pi) ugao-=2*pi;
	while(ugao<0) ugao+=2*pi;
	return ugao;
	}
int sekunde(double ugao){
		return ugao*360*60*60/(2*pi);
	}
	
class Ugao{
	int stepeni, minute, sek;
	public:
	Ugao(double rad = 0){
		double ugao = Reduciraj(rad);
		stepeni = sekunde(ugao)/3600;
		minute = (sekunde(ugao)/60)%60;
		sek = sekunde(ugao)%60;
		Normala(stepeni,minute,sek);
		
	}
	Ugao(double s, double m, double sec){
	stepeni = s; minute = m; sek = sec,
	Normala(stepeni,minute,sek);
	}
	void Postavi(double rad){
		double ugao = Reduciraj(rad);
		stepeni = sekunde(ugao)/3600;
		minute = (sekunde(ugao)/60)%60;
		sek = sekunde(ugao)%60;
		Normala(stepeni,minute,sek);
	}
	void Postavi(int s, int m, int sec){
    stepeni = s; minute = m; sek = sec;
	Normala(stepeni,minute,sek);	
	}
	double DajRadijane() const {return Reduciraj((stepeni + minute/60.+ sek/3600.)*pi/180);}
	void OcitajKlasicneJednacine(int &s, int &m, int &sec){
		s = stepeni;
		m = minute;
		sec = sek;
	}
	int DajStepene() const{
		return stepeni;
	}
	int DajMinute() const{
		return minute;
	}
	int DajSekunde() const{
		return sek;
	}
	void Ispisi() const {
		std::cout<<std::fixed<<std::setprecision(5)<<DajRadijane();
	}
	void IspisiKlasicno() const {
		std::cout<<DajStepene()<<"deg "<<DajMinute()<<"min "<<DajSekunde()<<"sec ";
	}
	Ugao& SaberiSa(const Ugao& u){
		double ugao = Reduciraj(DajRadijane() + u.DajRadijane() + 5e-8);
		stepeni = sekunde(ugao)/3600;
		minute = (sekunde(ugao)/60)%60;
		sek = sekunde(ugao)%60;
		return *this;
	}
	Ugao& PomnoziSa(double x){
		double ugao=Reduciraj(DajRadijane()*x);
		stepeni = sekunde(ugao)/3600;
		minute = (sekunde(ugao)/60)%60;
		sek = sekunde(ugao)%60;
		return *this;
	}
	friend Ugao ZbirUglova(const Ugao& u1, const Ugao& u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao& u, double x);
};
Ugao ZbirUglova(const Ugao& u1, const Ugao& u2){
		return Reduciraj(u1.DajRadijane() + u2.DajRadijane() + 5e-8);
	}
Ugao ProduktUglaSaBrojem(const Ugao& u, double x){
return Reduciraj(u.DajRadijane()*x);
}
int main ()
{
	return 0;
}
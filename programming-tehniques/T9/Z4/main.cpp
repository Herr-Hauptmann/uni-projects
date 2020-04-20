/* 
    TP 16/17 (Tutorijal 9, Zadatak 4)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
class Sat{
    int sati,minute,sekunde;
    public:
        static bool DaLiJeIspravno(int sati, int minute, int sekunde){
            if(!(sati>=0&&sati<=23) || !(minute>=0&&minute<=59) || !(sekunde>=0&&sekunde<=59)) return false;
            else return true;
        }
        void Postavi(int s, int m, int sek){
            if(!DaLiJeIspravno(s,m,sek)) throw std::domain_error("Neispravno vrijeme");
            else{
                sati = s; minute = m; sekunde = sek;
            }
        }
        void PostaviNormalizirano(int s, int m, int sek){
            if(DaLiJeIspravno(s,m,sek)) {
             sati = s; minute = m; sekunde = sek;
                    return;
            }
            else{
                m+=sek/60;
                if(sek>=0) sek=sek%60;
                else {
                sek=60+(sek%60);
                m-=1;
                }
                s+=m/60;
                if(m>=0) m=m%60;
                else{ m=60+(m%60);
                s-=1;
                }
                if(s>23) s=s%24;
                if(s<0){
                    if(std::abs(s)>23) s=s%24;
                    s=24+s;
                }
            }
             sati = s; minute = m; sekunde = sek;
        }
        Sat Sljedeci(){
            sekunde+=1;
            if(!DaLiJeIspravno(sati,minute,sekunde)) PostaviNormalizirano(sati,minute,sekunde);
            return *this;
        }
        Sat Prethodni(){
            sekunde-=1;
            if(!DaLiJeIspravno(sati,minute,sekunde))PostaviNormalizirano(sati,minute,sekunde);
            return *this;
        }
        Sat PomjeriZa(int parametar){
        sekunde+=parametar;
        if(!DaLiJeIspravno(sati,minute,sekunde)) PostaviNormalizirano(sati,minute,sekunde);
        return *this;
        }
        void Ispisi() const{
            std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":";
            std::cout<<std::setw(2)<<std::setfill('0')<<minute<<":";
            std::cout<<std::setw(2)<<std::setfill('0')<<sekunde<<std::endl;
        }
        int DajSate() const{
            return sati;
        }
        int DajMinute() const{
            return minute;
        }
        int DajSekunde() const{
        return sekunde;
        }
        static int Razmak(const Sat &s1, const Sat &s2);
        friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2);

};
int BrojSekundiIzmedju(const Sat &s1, const Sat &s2){
            return (s1.sati*3600+s1.minute*60+s1.sekunde)-(s2.sati*3600+s2.minute*60+s2.sekunde);
            }
 int Sat::Razmak(const Sat &s1, const Sat &s2){
            return (s1.sati*3600+s1.minute*60+s1.sekunde)-(s2.sati*3600+s2.minute*60+s2.sekunde);
 }
int main()
{
    Sat s;
    s.PostaviNormalizirano(0,0,-1);
    s.Ispisi();
    return 0;
}
/* 
    TP 16/17 (Tutorijal 9, Zadatak 5)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
class Sat{
    int sekunde;
    public:
        static bool DaLiJeIspravno(int sati, int minute, int sekunde){
            if(!(sati>=0&&sati<=23) || !(minute>=0&&minute<=59) || !(sekunde>=0&&sekunde<=59)) return false;
            else return true;
        }
        void Postavi(int s, int m, int sek){
            if(!DaLiJeIspravno(s,m,sek)) throw std::domain_error("Neispravno vrijeme");
            else{
                sekunde = s*3600 + m*60 + sek; 
            }
        }
        void PostaviNormalizirano(int s, int m, int sek){
            if(DaLiJeIspravno(s,m,sek)) {
             sekunde = s*3600 + m*60 + sek;
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
             sekunde = s*3600 + m*60 + sek;
        }
        Sat Sljedeci(){
            sekunde+=1;
            if(!DaLiJeIspravno(sekunde/3600,(sekunde%3600)/60,(sekunde%3600)%60)) PostaviNormalizirano(sekunde/3600,(sekunde%3600)/60,sekunde%60);
            return *this;
        }
        Sat Prethodni(){
            sekunde-=1;
            if(!DaLiJeIspravno(sekunde/3600,(sekunde%3600)/60,(sekunde%3600)%60))PostaviNormalizirano(sekunde/3600,(sekunde%3600)/60,sekunde%60);
            return *this;
        }
        Sat PomjeriZa(int parametar){
        sekunde+=parametar;
        if(!DaLiJeIspravno(sekunde/3600,(sekunde%3600)/60,(sekunde%3600)%60)) PostaviNormalizirano(sekunde/3600,(sekunde%3600)/60,(sekunde%3600)%60);
        return *this;
        }
        void Ispisi() const{
            std::cout<<std::setw(2)<<std::setfill('0')<<sekunde/3600<<":";
            std::cout<<std::setw(2)<<std::setfill('0')<<(sekunde%3600)/60<<":";
            std::cout<<std::setw(2)<<std::setfill('0')<<(sekunde%3600)%60<<std::endl;
        }
        int DajSate() const{
            return sekunde/3600;
        }
        int DajMinute() const{
            return (sekunde%3600)/60;
        }
        int DajSekunde() const{
        return (sekunde%3600)%60;
        }
        static int Razmak(const Sat &s1, const Sat &s2);
        friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2);

};
int BrojSekundiIzmedju(const Sat &s1, const Sat &s2){
            return s1.sekunde-s2.sekunde;
            }
 int Sat::Razmak(const Sat &s1, const Sat &s2){
            return s1.sekunde-s2.sekunde;
 }
int main()
{
    Sat s;
    s.PostaviNormalizirano(0,0,-1);
    s.Ispisi();
    return 0;
}
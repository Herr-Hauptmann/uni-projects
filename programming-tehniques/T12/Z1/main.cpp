/* 
    TP 16/17 (Tutorijal 12, Zadatak 1)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <ostream>
class Sat{
    int sati,minute,sekunde;
    public:
    Sat(){
        sati = 0; minute = 0; sekunde = 0;
    }
         Sat(int s, int m, int sek){
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
        Sat& operator++(){
            sekunde+=1;
            if(!DaLiJeIspravno(sati,minute,sekunde)) PostaviNormalizirano(sati,minute,sekunde);
            return *this;
        }
        Sat operator++(int){
            Sat pomocna(*this);
            sekunde+=1;
            if(!DaLiJeIspravno(sati,minute,sekunde)) PostaviNormalizirano(sati,minute,sekunde);
            return pomocna;
        }
        Sat& operator--(){
            sekunde-=1;
            if(!DaLiJeIspravno(sati,minute,sekunde)) PostaviNormalizirano(sati,minute,sekunde);
            return *this;
        }
        Sat operator--(int){
        	Sat pomocna(*this);
            sekunde-=1;
            if(!DaLiJeIspravno(sati,minute,sekunde))PostaviNormalizirano(sati,minute,sekunde);
            return pomocna;
        }
        Sat& operator +=(int parametar){
        sekunde+=parametar;
        if(!DaLiJeIspravno(sati,minute,sekunde)) PostaviNormalizirano(sati,minute,sekunde);
        return *this;
        }
        inline Sat& operator-=(int parametar){
        	*this += -parametar;
        	return *this;
        }
      friend std::ostream& operator<<(std::ostream &tok, const Sat& s1);
        int DajSate() const{
            return sati;
        }
        int DajMinute() const{
            return minute;
        }
        int DajSekunde() const{
        return sekunde;
        }
        friend Sat operator-(Sat s1, int pomak);
        friend Sat operator+(Sat s1, int pomak);
        friend int operator-(const Sat& s1, const Sat& s2);
        friend int operator+(const Sat& s1, const Sat& s2);
        int Razmak(const Sat &s1, const Sat &s2);

};
Sat operator-(Sat s1, int pomak){
            Sat ret(s1);
            ret -= pomak;
            return ret;
            }
Sat operator+(Sat s1, int pomak){
            Sat ret(s1);
            ret += pomak;
            return ret;
            }
 int Sat::Razmak(const Sat &s1, const Sat &s2){
            return (s1.sati*3600+s1.minute*60+s1.sekunde)-(s2.sati*3600+s2.minute*60+s2.sekunde);
 }
 
std::ostream& operator<<(std::ostream &tok, const Sat& s1){
            tok<<std::setw(2)<<std::setfill('0')<<s1.sati<<":";
            tok<<std::setw(2)<<std::setfill('0')<<s1.minute<<":";
            tok<<std::setw(2)<<std::setfill('0')<<s1.sekunde<<std::endl;
            return tok;
        }
int operator-(const Sat& s1, const Sat& s2){
    int razlika;
    razlika = (s1.sati*3600+s1.minute*60+s1.sekunde)-(s2.sati*3600+s2.minute*60+s2.sekunde);
    return razlika;
}
int operator+(const Sat& s1, const Sat& s2){
    int zbir;
    zbir = (s1.sati*3600+s1.minute*60+s1.sekunde)-(s2.sati*3600+s2.minute*60+s2.sekunde);
    return zbir;
}


        
int main()
{
    Sat s;
    s.PostaviNormalizirano(0,0,-1);
    s++,
    std::cout<<s;
    return 0;
}
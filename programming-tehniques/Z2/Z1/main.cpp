/* TP, 2018/2019
*/
#include <iostream>
#include <string>
#include <limits>

bool STATUS = true;
enum class Smjer {Nalijevo, Nadesno};
enum class Pravci {Sjever, Istok, Jug, Zapad};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {Aktiviraj, Deaktiviraj, Nalijevo, Nadesno, Idi, Kraj};
void AktivirajRobota()
{
    STATUS = true;
}
void DeaktivirajRobota()
{
    STATUS = false;
}
void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu)
{
    Pravci niz[] = {Pravci::Sjever,Pravci::Istok,Pravci::Jug,Pravci::Zapad};
    if(STATUS==false) return;
    else {
        if(int(na_koju_stranu)==1) {
            if(int(orijentacija)+1>3) orijentacija = niz[0];
            else orijentacija = niz[int(orijentacija)+1];
        } else {
            if(int(orijentacija)-1<0) orijentacija = niz[3];
            else orijentacija = niz[int(orijentacija)-1];
        }
    }

}
void Idi(int &x, int &y, Pravci orijentacija, int korak)
{
    if(STATUS==false) return;
    else {
        if(int(orijentacija)==1 || int(orijentacija)==3) {
            if(int(orijentacija)==3) korak=-korak;
            long int check = x + korak;
            if(check>static_cast<long int>(std::numeric_limits<int>::max())) {
                x = std::numeric_limits<int>::max();
            } else if(check<static_cast<long int>(std::numeric_limits<int>::min())) {
                x = std::numeric_limits<int>::min();
            } else {
                x += korak;
            }

        } else {
            if(int(orijentacija)==2) korak=-korak;
            long int check = y + korak;
            if(check>static_cast<long int>(std::numeric_limits<int>::max())) {
                y = std::numeric_limits<int>::max();
            } else if(check<static_cast<long int>(std::numeric_limits<int>::min())) {
                y = std::numeric_limits<int>::min();
            } else {
                y += korak;
            }

        }

    }


}
void IspisiPoziciju(int x, int y, Pravci orijentacija)
{
    std::string niz[]= {"sjever","istok","jug","zapad"};
    if(STATUS) {
        std::cout<<"Robot je trenutno aktivan, nalazi se na poziciji ("<<x<<","<<y<<") i gleda na "<<niz[int(orijentacija)]<<"."<<std::endl;
    } else
        std::cout<<"Robot je trenutno neaktivan, nalazi se na poziciji ("<<x<<","<<y<<") i gleda na "<<niz[int(orijentacija)]<<"."<<std::endl;

}
void PrijaviGresku(KodoviGresaka kod_greske)
{
    std::string niz[] = {"Nerazumljiva komanda!\n", "Komanda trazi parametar koji nije naveden!\n", "Zadan je suvisan parametar nakon komande!\n","Parametar komande nije ispravan!\n"};
    std::cout<<niz[int(kod_greske)];
    std::cin.ignore(100000,'\n');

}
void IzvrsiKomandu(Komande komanda, int parametar, int &x, int &y, Pravci &orijentacija)
{
    int f = int(komanda);
    if(f==0) AktivirajRobota();
    if(f==1) DeaktivirajRobota();
    if(f==2) {
        Smjer na_koju_stranu = Smjer::Nalijevo;
        Rotiraj(orijentacija, na_koju_stranu);
    }
    if(f==3) {
        Smjer na_koju_stranu = Smjer::Nadesno;
        Rotiraj(orijentacija, na_koju_stranu);
    }
    if(f==4) Idi(x,y,orijentacija,parametar);
    IspisiPoziciju(x,y,orijentacija);

}
bool UnosKomande(Komande &komanda, int &parametar, KodoviGresaka &kod_greske)
{
    char c,t='6';
    char dodatni_parametar;
    std::cout<<"Unesi komandu: ";
    while(1) {
        c = std::cin.get();
        if(c=='\n') break;
        if(c!='A' && c!='L' && c!='I' && c!='K' && c!='D' && c!=' ' && t=='6') {
            kod_greske = KodoviGresaka::PogresnaKomanda;
            return false;
        }
        if((c=='A' || c=='L' || c=='D' || c=='I' || c=='K') && t=='6') {
            t=c;
            break;
        }

    }
    if(t=='L') {
        while(1) {
            c = std::cin.get();
            if(c=='\n') break;
            if(c!=' ') {
                kod_greske = KodoviGresaka::SuvisanParametar;
                return false;
            }
        }
        komanda = Komande::Nalijevo;
        return true;
    }
    if(t=='D') {
        while(1) {
            c = std::cin.get();
            if(c=='\n') break;
            if(c!=' ') {
                kod_greske = KodoviGresaka::SuvisanParametar;
                return false;
            }
        }
        komanda = Komande::Nadesno;
        return true;
    }
    if(t=='A' && std::cin.peek()==10) {
        kod_greske = KodoviGresaka::NedostajeParametar;
        return false;
    }
    if(t=='A') {
        if(std::cin.peek()==' ') {
            kod_greske = KodoviGresaka::NeispravanParametar;
            return false;
        }
        bool plus = false;
        bool minus = false;
        while(1) {
            c = std::cin.get();
            if(c=='\n') break;
            if(c!=' ' && c!='+' && c!='-') {
                kod_greske = KodoviGresaka::PogresnaKomanda;
                return false;
            }
            if(c=='+') plus = true;
            if(c=='-') minus = true;
        }
        if(plus && minus) {
            kod_greske = KodoviGresaka::SuvisanParametar;
            return false;
        } else if(plus) {
            komanda = Komande::Aktiviraj;
            return true;
        } else if(minus) {
            komanda = Komande::Deaktiviraj;
            return true;
        } else {
            kod_greske = KodoviGresaka::NedostajeParametar;
            return false;
        }

    }
    if(t=='K') {
        while((c = std::cin.get())!='\n') {
            if(c!=' ') {
                kod_greske = KodoviGresaka::SuvisanParametar;
                return false;
            }
        }
        komanda = Komande::Kraj;
        return true;

    }
    if(t=='I' && std::cin.peek()=='\n') {
        kod_greske = KodoviGresaka::NedostajeParametar;
        return false;
    }
    if(t=='I' && !(std::cin.peek()>='0'&&std::cin.peek()<='9')) {
        kod_greske = KodoviGresaka::NeispravanParametar;
        return false;
    }

    if(t=='I') {
        int broj = 0;
        bool minus = false;
        bool flag = false;
        while(1) {
            c = std::cin.get();
            if(c=='\n') break;
            if(c!=' ' && !(c>='0'&&c<='9') && (c!='-' && (std::cin.peek()>='0' && std::cin.peek()<='9'))) {
                kod_greske = KodoviGresaka::SuvisanParametar;
                return false;
            }
            if(c=='-' && (std::cin.peek()>='0' && std::cin.peek()<='9')) minus = true;
            if((std::cin.peek()>='0' && std::cin.peek()<='9') || (c>='0'&&c<='9') ) {
                flag = true;
                break;
            }


        }
        if(c=='-') c = std::cin.get();
        while(1) {
            if(!(c>='0'&&c<='9')) break;
            broj = broj*10 + c-'0';
            c = std::cin.get();
        }
        if(c!='\n') {
            while(1) {
                c = std::cin.get();
                if(c=='\n') break;
                if(c!=' ') {
                    kod_greske = KodoviGresaka::SuvisanParametar;
                    return false;
                }
            }
        }
        if(!flag) {
            kod_greske = KodoviGresaka::NedostajeParametar;
            return false;
        }
        if(minus) broj=-broj;
        parametar=broj;
        komanda = Komande::Idi;
    }
    return true;
}

int main ()
{
    Pravci orijentacija = Pravci::Sjever;
    int x, y;
    x = 0;
    y = 0;
    int parametar;
    Komande komanda;
    KodoviGresaka kod_greske;
    IspisiPoziciju(x,y,orijentacija);
    for(;;) {
        if(UnosKomande(komanda,parametar,kod_greske)) {
            if(int(komanda)==5) break;
            IzvrsiKomandu(komanda,parametar,x,y,orijentacija);
        } else PrijaviGresku(kod_greske);

    }
    std::cout<<"Dovidjenja!";
    return 0;
}

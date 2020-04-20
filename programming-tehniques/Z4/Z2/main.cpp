//TP 2018/2019: Zadaća 4, Zadatak 2
#include <iostream>
#include <string>
//enum Pol {Musko,Zensko};
int BrojCifara(long long int x)
{
    int brojac = 0;
    while(x != 0) {
        brojac++;
        x/=10;
    }
    return brojac;
}
long long int SastaviJMBG(int c[])
{
    long long int jmbg = 0;
    for(int i = 0; i < 13; i++) jmbg=jmbg*10 + c[i];
    return jmbg;
}
int BrojDana(int mjesec, int godina)
{
    if(mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) return 30;
    if(mjesec != 2) return 31;
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) return 29;
    return 28;
}
class GradjaninBiH
{
public:
    enum Pol {Musko,Zensko};
private:
    long long int jmbg;
    std::string ime_i_prezime;
    int dan_rodjenja;
    int mjesec_rodjenja;
    int godina_rodjenja;
    int sifra_regije;
    int kod;
    Pol pol;
    GradjaninBiH* prethodni = nullptr;
    static GradjaninBiH* posljednji;

    void RastaviJMBG(int c[], long long int jmbg)
    {
        if(BrojCifara(jmbg) == 12) c[0] = 0;
        for(int i = 0; i < 13; i++) {
            c[12-i] = jmbg%10;
            jmbg/=10;
        }
    }

public:
    GradjaninBiH(std::string ime_i_prezime, long long int jmbg);
    GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, Pol pol);
    long long int DajJMBG() const;
    std::string DajImeIPrezime() const;
    int DajDanRodjenja() const;
    int DajMjesecRodjenja() const;
    int DajGodinuRodjenja() const;
    int DajSifruRegije() const;
    Pol DajPol() const;
    void PromijeniImeIPrezime(std::string novo_ime);
    GradjaninBiH(const GradjaninBiH& g) = delete;
    GradjaninBiH& operator=(const GradjaninBiH& g) = delete;
    ~GradjaninBiH()
    {
        if(this->prethodni == nullptr && posljednji != this) {
            auto p = posljednji;
            while(p->prethodni != this) p = p->prethodni;
            p->prethodni = nullptr;
        }
        if(posljednji == this && this->prethodni == nullptr) {
            posljednji = nullptr;
        }
        if(posljednji == this && this->prethodni != nullptr) {
            posljednji = this->prethodni;
            this->prethodni = nullptr;
        }
        if(this->prethodni != nullptr) {
            auto p = posljednji;
            while(p->prethodni != this) p = p->prethodni;
            p->prethodni = this->prethodni;
            this->prethodni = nullptr;
        }


    }
};
GradjaninBiH* GradjaninBiH::posljednji = nullptr;


GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, long long int jmbg)
{
    
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    int c[13] {};
    RastaviJMBG(c, jmbg);
    int tmp = 0;
    for(int i = 7, r =0 ; i > 1; i--,r++ ) tmp += i*(c[r] + c[r+6]);
    tmp = 11 - tmp % 11;
    if(tmp == 11 && c[12] != 0 || tmp == 10 || tmp != c[12] && tmp != 11) throw std::logic_error("JMBG nije validan");
    int dan_rodjenja, mjesec_rodjenja, godina_rodjenja, sifra_regije, kod;
    Pol pol;
    dan_rodjenja = c[0]*10 + c[1];
    mjesec_rodjenja = c[2]*10 + c[3];
    godina_rodjenja = c[4]*100 + c[5]*10 + c[6];
    if(c[4] == 9) godina_rodjenja = 1000 + godina_rodjenja;
    if(c[4] == 0) godina_rodjenja = 2000 + godina_rodjenja;
    if(c[4] != 9 && c[4] != 0) throw std::logic_error("JMBG nije validan");
    if(posljednji != nullptr) prethodni = posljednji;
    posljednji = this;
    for(auto p = posljednji->prethodni; p != nullptr; p = p->prethodni) {
        if(p->jmbg == jmbg) throw std::logic_error("Vec postoji gradjanin sa istim JMBG");
    }
    sifra_regije = c[7] * 10 + c[8];
    kod = c[9] * 100 + c[10] * 10 + c[11];
    if(kod>=0 && kod <500) pol = Musko;
    else pol = Zensko;
    if(dan_rodjenja < 1 || mjesec_rodjenja < 1 || godina_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja > BrojDana(mjesec_rodjenja,godina_rodjenja))
        throw std::logic_error("JMBG nije validan");
    GradjaninBiH::dan_rodjenja = dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    GradjaninBiH::kod = kod;
    GradjaninBiH::pol = pol;
    GradjaninBiH::jmbg = jmbg;


}

GradjaninBiH::GradjaninBiH(std::string ime_i_prezime, int dan_rodjenja, int mjesec_rodjenja, int godina_rodjenja, int sifra_regije, GradjaninBiH::Pol pol)
{
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    if(dan_rodjenja < 1 || mjesec_rodjenja < 1 || godina_rodjenja < 1 || mjesec_rodjenja > 12 || dan_rodjenja > BrojDana(mjesec_rodjenja,godina_rodjenja))
        throw std::logic_error("Neispravni podaci");
    if(sifra_regije<0 || sifra_regije>99) throw std::logic_error("Neispravni podaci");
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
    GradjaninBiH::dan_rodjenja = dan_rodjenja;
    GradjaninBiH::mjesec_rodjenja = mjesec_rodjenja;
    GradjaninBiH::godina_rodjenja = godina_rodjenja;
    GradjaninBiH::sifra_regije = sifra_regije;
    GradjaninBiH::pol = pol;
    if(pol == GradjaninBiH::Pol::Musko) kod = 0;
    else kod = 500;
    if(posljednji != nullptr) prethodni = posljednji;
    posljednji = this;
    for(auto p = this; p != nullptr; p=p->prethodni) {
        if( p != this && p->dan_rodjenja == dan_rodjenja && p->mjesec_rodjenja == mjesec_rodjenja && p->godina_rodjenja == godina_rodjenja && p->sifra_regije == sifra_regije) {
            kod = p->kod;
            kod++;
            break;
        }
    }
    int c[13] {};
    if(BrojCifara(dan_rodjenja) > 1) {
        c[1] = dan_rodjenja%10;
        dan_rodjenja/=10;
        c[0] = dan_rodjenja;
    } else {
        c[0] = 0;
        c[1] = dan_rodjenja;
    }
    if(BrojCifara(mjesec_rodjenja) > 1) {
        c[3] = mjesec_rodjenja%10;
        mjesec_rodjenja/=10;
        c[2] = mjesec_rodjenja;
    }
    c[6] = godina_rodjenja%10;
    godina_rodjenja /= 10;
    c[5] = godina_rodjenja%10;
    godina_rodjenja /= 10;
    c[4] = godina_rodjenja%10;
    if(BrojCifara(sifra_regije) > 1) {
        c[8] = sifra_regije%10;
        sifra_regije /= 10;
        c[7] = sifra_regije%10;
    } else {
        c[7] = 0;
        c[8] = sifra_regije;
    }
    bool flag = true;
    int kod_tmp = kod;
    do {
        c[11] = kod%10;
        kod /= 10;
        c[10] = kod%10;
        kod /= 10;
        c[9] = kod%10;

        c[12] = 11 - ((7*(c[0] + c[6])) + 6*(c[1] + c[7]) + 5*(c[2]+c[8]) + 4*(c[3]+c[9]) + 3*(c[4] + c[10]) + 2*(c[5] + c[11]))%11;
        if(c[12] == 10) {
            kod = kod_tmp;
            kod++;
            continue;
        } else {
            c[12] = 0;
            break;
        }
    } while(flag);
    GradjaninBiH::jmbg = SastaviJMBG(c);



}

int GradjaninBiH::DajDanRodjenja() const
{
    return dan_rodjenja;
}

int GradjaninBiH::DajMjesecRodjenja() const
{
    return mjesec_rodjenja;
}

int GradjaninBiH::DajGodinuRodjenja() const
{
    return godina_rodjenja;
}

long long int GradjaninBiH::DajJMBG() const
{
    return jmbg;
}

int GradjaninBiH::DajSifruRegije() const
{
    return sifra_regije;
}

GradjaninBiH::Pol GradjaninBiH::DajPol() const
{
    return pol;
}

std::string GradjaninBiH::DajImeIPrezime() const
{
    return ime_i_prezime;
}

void GradjaninBiH::PromijeniImeIPrezime(std::string ime_i_prezime)
{
    GradjaninBiH::ime_i_prezime = ime_i_prezime;
}

int main ()
{
    std::cout<<"Koliko gradjana zelite unijeti po JMBG? "<<std::endl;
    int n;
    std::cin>>n;
    GradjaninBiH** p = new GradjaninBiH*[n];
    std::string spol[] = {"musko.","zensko."};
    for(int i = 0; i < n; i++) {
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::string ime_i_prezime;
        std::cin.ignore(10000,'\n');
        std::getline(std::cin,ime_i_prezime);
        long long int jmbg;
        std::cout<<std::endl<<"Unesite JMBG: ";
        std::cin>>jmbg;
        try {
            p[i] = new GradjaninBiH(ime_i_prezime,jmbg);
        } catch(std::bad_alloc) {
            std::cout<<"Memorijska greska";
        } catch(std::logic_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
            continue;
        }
        std::cout<<std::endl<<"Unijeli ste gradjanina "<<p[i]->DajImeIPrezime()<<" rodjenog "<<p[i]->DajDanRodjenja()
                 <<"."<<p[i]->DajMjesecRodjenja()<<"."<<p[i]->DajGodinuRodjenja()<< " u regiji "<<p[i]->DajSifruRegije()<<", "<<spol[p[i]->DajPol()]<<std::endl;
    }
    std::cout<<"Koliko gradjana zelite unijeti po datumu rodjenja, regiji i polu? "<<std::endl;
    int n2;
    std::cin>>n2;
    GradjaninBiH** p2 = new GradjaninBiH*[n2];
    for(int i = 0; i < n2; i++) {
        std::cout<<"Unesite ime i prezime (u istom redu): ";
        std::cin.ignore(10000,'\n');
        std::string ime_i_prezime;
        std::getline(std::cin,ime_i_prezime);
        std::cout<<std::endl<<"Unesite datum rodjenja (format dd/mm/gggg): ";
        int dan, mjesec, godina;
        char znak1, znak2;
        std::cin>>dan>>znak1>>mjesec>>znak2>>godina;
        std::cout<<std::endl<<"Unesite sifru regije: ";
        int sifra;
        std::cin>>sifra;
        std::cout<<std::endl<<"Unesite M za musko, Z za zensko: ";
        char c;
        GradjaninBiH::Pol spol;
        std::cin>>c;
        if(c=='M' || c=='m') spol = GradjaninBiH::Musko;
        else spol = GradjaninBiH::Zensko;
        try {
            p2[i] = new GradjaninBiH(ime_i_prezime,dan,mjesec,godina,sifra,spol);
        } catch(std::bad_alloc) {
            std::cout<<"Memorijska greska";
        } catch(std::logic_error e) {
            std::cout<<e.what()<<std::endl;
            i--;
            continue;
        }
        std::cout<<std::endl<<"Unijeli ste gradjanina "<<p2[i]->DajImeIPrezime()<<" JMBG: "<<p2[i]->DajJMBG()<<"."<<std::endl;
    }
    for(int i = 0; i < n; i++) delete p[i];
    delete[] p;
    for(int i = 0; i < n2; i++) delete p2[i];
    delete[] p2;
    return 0; 
}

//TP 2018/2019: Tutorijal 14, Zadatak 2
#include <iostream>
#include <ios>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdexcept>

class Spremnik{
    protected:
    std::string naziv_predmeta;
    double tezina;
    public:
    Spremnik(double tezina, std::string naziv_predmeta){
        Spremnik::tezina = tezina; Spremnik::naziv_predmeta = naziv_predmeta;
    }
    double DajTezinu() const{return tezina;};
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual Spremnik* DajKopiju() const = 0;
    virtual ~Spremnik(){};
};

class Sanduk: public Spremnik{
    int broj_predmeta;
    double tezina_predmeta;
    public:
    Sanduk(double tezina, std::string naziv_predmeta, int broj_predmeta, double tezina_predmeta): Spremnik(tezina,naziv_predmeta){
        Sanduk::broj_predmeta = broj_predmeta; Sanduk::tezina_predmeta = tezina_predmeta;
    }
    double DajUkupnuTezinu() const override{
        return tezina + broj_predmeta*tezina_predmeta;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj:"<<naziv_predmeta<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" kg"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" kg"<<std::endl;
    }
    
    Spremnik* DajKopiju() const override{return new Sanduk(*this);}
};

class Bure: public Spremnik{
    double tezina_predmeta;
    public:
    Bure(double tezina, std::string naziv_predmeta, double tezina_predmeta): Spremnik(tezina,naziv_predmeta){
        Bure::tezina_predmeta = tezina_predmeta;
    }
    double DajUkupnuTezinu() const override{
        return tezina + tezina_predmeta;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj:"<<naziv_predmeta<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" kg"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" kg"<<std::endl;
        
    }
    Spremnik* DajKopiju() const override{ return new Bure(*this);}
};

class Skladiste{
    Spremnik** r;
    int  max_br, broj_reg;
    public:
    explicit Skladiste(int max): max_br(max), broj_reg(0), r(new Spremnik*[max]{}){};
    Skladiste(const Skladiste& s){
        for(int i = 0; i < max_br; i++) delete r[i];
        delete[] r;
        broj_reg = s.broj_reg;
        max_br = s.max_br;
        r = new Spremnik*[max_br]{};
        for(int i = 0; i < broj_reg; i++) r[i] = s.r[i]->DajKopiju();
    }
    Skladiste(Skladiste &&s){
    r = s.r; max_br = s.max_br; broj_reg = s.broj_reg;
    s.r = nullptr; broj_reg = 0; s.max_br = 0;
    }
    Skladiste& operator=(Skladiste s){
        std::swap(r,s.r);
        std::swap(max_br,s.max_br);
        std::swap(broj_reg,s.broj_reg);
        return *this;
    }
    void DodajSanduk(double tezina, std::string naziv_predmeta, int broj,double tezina_predmeta){
        if(broj_reg == max_br) throw std::domain_error("Popunjeno skladiste");
        r[broj_reg] = new Sanduk(tezina,naziv_predmeta,broj,tezina_predmeta);
        broj_reg++;

    }
    void DodajBure(double tezina, std::string naziv_predmeta, double tezina_predmeta){
        if(broj_reg == max_br) throw std::domain_error("Popunjeno skladiste");
        r[broj_reg] = new Bure(tezina,naziv_predmeta,tezina_predmeta);
        broj_reg++;

    }
    Spremnik& DajNajtezi(){
        if(broj_reg==0) throw std::domain_error("Skladiste je prazno");
        auto p = std::min_element(r,r+broj_reg,[](Spremnik* s1, Spremnik* s2)->bool{
            return s1->DajTezinu() < s2->DajTezinu();
        });
        return **p;
    }
    Spremnik& DajNajlaksi(){
        if(broj_reg==0) throw std::domain_error("Skladist je prazno");
        auto p = std::min_element(r,r+broj_reg,[](Spremnik* s1, Spremnik* s2)->bool{
            return s1->DajTezinu() < s2->DajTezinu();
        });
        return **p;
    }
    int BrojPreteskih(double n){
        return std::count_if(r,r+broj_reg,[n](Spremnik* s)->bool{
            return s->DajUkupnuTezinu() > n;
        });
        
    }
    void IzlistajSkladiste() const{
        Spremnik **p = r;
        std::sort(p,p+broj_reg,[](Spremnik* s1, Spremnik* s2)->bool{
            return s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu();
        });
        for(int i = 0; i < broj_reg; i++) p[i]->Ispisi();
    }
    void UcitajIzDatoteke(std::string s){
        for(int i = 0; i < broj_reg; i++) delete r[i];
        broj_reg = 0;
        std::ifstream tok(s);
        if(!tok) throw std::logic_error("Trazena datoteka ne postoji");
        for(;;){
            if(!tok) break;
            char vrsta;
            tok>>vrsta;
            std::string spremnik;
            std::getline(tok,spremnik);
            if(vrsta == 'S'){
                double tezina;
                double tezina_predmeta;
                int broj_predmeta;
                tok>>tezina>>broj_predmeta>>tezina_predmeta;
                DodajSanduk(tezina,spremnik,broj_predmeta,tezina_predmeta);
                tok.ignore(10000,'\n');
            }
            else if(vrsta == 'B'){
                double tezina, tezina_predmeta;
                tok>>tezina>>tezina_predmeta;
                DodajBure(tezina,spremnik,tezina_predmeta);
                tok.ignore(10000,'\n');
            }
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    } 
    ~Skladiste(){
        for(int i = 0; i < max_br; i++) delete r[i];
        delete[] r;
    }
};





int main ()
{
    {//AT1
    std::ofstream f ("ABC.TXT");
    f << "S Tepsije" << std::endl
      << "10 5 3" << std::endl
      << "S Nesto" << std::endl
      << "1000 2 400.5" << std::endl
      << "B Ulje neko" << std::endl
      << "60.1 50";
    f.close();
    Skladiste s (10);
    s.UcitajIzDatoteke("ABC.TXT");
    const Skladiste &cs = s;
    cs.IzlistajSkladiste(); //cs je const
}
	return 0;
}
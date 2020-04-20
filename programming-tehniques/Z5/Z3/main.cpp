//TP 2018/2019: Zadaća 5, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
class Spremnik{
    protected:
    double tezina;
    std::string naziv_predmeta;
    public:
    Spremnik(double tezina, std::string naziv_predmeta){
        Spremnik::tezina = tezina; Spremnik::naziv_predmeta = naziv_predmeta;
    }
    double DajTezinu() const{
        return tezina;
    }
    virtual double DajUkupnuTezinu() const = 0;
    virtual void Ispisi() const = 0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const = 0;
    virtual ~Spremnik(){}
};
class Sanduk: public Spremnik{
    std::vector<double> tezine;
    public:
    Sanduk(double tezina, std::string naziv_predmeta, std::vector<double> v): Spremnik(tezina,naziv_predmeta){
        tezine = v;
    }
    double DajUkupnuTezinu() const override{
        double suma;
        suma = tezina;
        for(int i = 0; i < tezine.size(); i++) suma+=tezine.at(i);
        return suma;
    }
    
    std::shared_ptr<Spremnik> DajKopiju() const override{
        return std::make_shared<Sanduk>(*this);
    }
    
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Sanduk"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv_predmeta<<std::endl;
        std::cout<<"Tezine predmeta:";
        for(auto &x: tezine) std::cout<<" "<<x;
        std::cout<<" (kg)"<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Vreca: public Spremnik{
    double tezina_praha;
    public:
    Vreca(double tezina, std::string naziv_predmeta, double tezina_praha): Spremnik(tezina,naziv_predmeta){
        Vreca::tezina_praha = tezina_praha;
    }
    double DajUkupnuTezinu() const override{
        return tezina + tezina_praha;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override{
        return std::make_shared<Vreca>(*this);
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Vreca"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv_predmeta<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Tezina pohranjene materije: "<<tezina_praha<<" (kg)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};

class Bure: public Spremnik{
    double rho;
    double zapremina;
    public:
    Bure(double tezina, std::string naziv_predmeta, double rho, double zapremina): Spremnik(tezina,naziv_predmeta){
        Bure::rho = rho; Bure::zapremina = zapremina;
    }
    std::shared_ptr<Spremnik> DajKopiju() const override{
        return std::make_shared<Bure>(*this);
    }
    double DajUkupnuTezinu() const override{
        double suma = tezina;
        suma+= rho * zapremina * 1e-3;
        return suma;
    }
    void Ispisi() const override{
        std::cout<<"Vrsta spremnika: Bure"<<std::endl;
        std::cout<<"Sadrzaj: "<<naziv_predmeta<<std::endl;
        std::cout<<"Vlastita tezina: "<<tezina<<" (kg)"<<std::endl;
        std::cout<<"Specificna tezina tecnosti: "<<rho<<" (kg/m^3)"<<std::endl;
        std::cout<<"Zapremina tecnosti: "<<zapremina<<" (l)"<<std::endl;
        std::cout<<"Ukupna tezina: "<<this->DajUkupnuTezinu()<<" (kg)"<<std::endl;
    }
};
class Skladiste{
    std::vector<std::shared_ptr<Spremnik>> roba;
    public:
    Skladiste(const Skladiste& s){
        roba.resize(s.roba.size(),nullptr);
        try{
        for(int i = 0; i < s.roba.size(); i++){
            roba.at(i) = s.roba[i]->DajKopiju();
        }
        }
        catch(...){
            std::cout<<"Problemi s memorijom!";
        }
    }
    Skladiste(){};
    
    Skladiste& operator=(const Skladiste& s){
        if(this == &s) return *this;
        roba.resize(0);
        for(int i = 0; i < s.roba.size(); i++) roba.push_back(s.roba[i]->DajKopiju());
        return *this;
    }
    
    Spremnik* DodajSanduk(double tezina, std::string naziv_predmeta, std::vector<double> v){
        roba.emplace_back(std::make_shared<Sanduk>(tezina,naziv_predmeta,v));
        return roba.at(roba.size()-1).get();
    }
    
    Spremnik* DodajVrecu(double tezina, std::string naziv_predmeta, double tezina_praha){
        roba.emplace_back(std::make_shared<Vreca>(tezina,naziv_predmeta,tezina_praha));
        return roba.at(roba.size()-1).get();
    }
    
    Spremnik* DodajBure(double tezina, std::string naziv_predmeta, double rho, double zapremina){
        roba.emplace_back(std::make_shared<Bure>(tezina,naziv_predmeta,rho,zapremina));
        return roba.at(roba.size()-1).get();
    }
    Spremnik* DodajSpremnik(Spremnik* s, bool vlasnistvo){
        if(vlasnistvo){
            roba.push_back(std::shared_ptr<Spremnik>(s));
        }
        else{
            roba.push_back(s->DajKopiju());
        }
        return roba.at(roba.size()-1).get();
    }
    void BrisiSpremnik(Spremnik* s){
        for(int i = 0; i < roba.size(); i++){
            if(s == roba[i].get()) roba.erase(roba.begin()+i);
        }
    }
    
    Spremnik& DajNajtezi() {
        if(roba.size() == 0) throw std::range_error("Skladiste je prazno");
        auto p = std::max_element(roba.begin(),roba.end(),[](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)->bool{
            return s1->DajTezinu() < s2->DajTezinu();
        });
        return **p;
    }
    Spremnik& DajNajlaksi() {
        if(roba.size() == 0) throw std::range_error("Skladiste je prazno");
        auto p = std::min_element(roba.begin(),roba.end(),[](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)->bool{
            return s1->DajTezinu() < s2->DajTezinu();
        });
        return **p;
    }
    Spremnik& DajNajlaksi() const = delete;
    Spremnik& DajNajtezi() const = delete;
    int BrojPreteskih(double n){
        return std::count_if(roba.begin(),roba.end(),[n](std::shared_ptr<Spremnik> s)->bool{
            return s->DajUkupnuTezinu() > n;
        });
    }
    
    void IzlistajSkladiste() const{
        auto rambo = roba;
        std::sort(rambo.begin(),rambo.end(),[](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2)->bool{
            return s1->DajUkupnuTezinu() > s2->DajUkupnuTezinu();
        });
        for(int i = 0; i < rambo.size(); i++) rambo[i]->Ispisi();
    }
    void UcitajIzDatoteke(std::string ime){
        roba.resize(0);
        std::ifstream tok(ime);
        if(!tok) std::logic_error("Trazena datoteka ne postoji");
        for(;;){
            if(!tok) break;
            char slovo;
            tok>>slovo>>std::ws;
            std::string naziv;
            std::getline(tok,naziv);
            if(slovo == 'S'){
                double tezina;
                int broj_predmeta;
                tok>>tezina>>broj_predmeta;
                std::vector<double> tezine(broj_predmeta,0);
                double x;
                for(int i = 0; i < broj_predmeta; i++){
                    tok>>x;
                    tezine[i] = x;
                }
                DodajSanduk(tezina,naziv,tezine);
                tok.ignore(1000,'\n');
            }
            else if(slovo == 'V'){
                double tezina, tezina_materije;
                tok>>tezina>>tezina_materije;
                DodajVrecu(tezina,naziv,tezina_materije);
                tok.ignore(1000,'\n');
            }
            else if(slovo == 'B'){
                double tezina, rho, zapremina;
                tok>>tezina>>rho>>zapremina;
                DodajBure(tezina,naziv,rho,zapremina);
                tok.ignore(1000,'\n');
            }
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
        }
        if(tok.bad()) throw std::logic_error("Problemi pri citanju datoteke");
    }
    ~Skladiste(){}
};

int main ()
{
   {//AT1
    std::ofstream f ("ABC.TXT");
    f << "S Tepsije" << std::endl
      << "10 5 3 7 8 9 10" << std::endl
      << "S Nesto" << std::endl
      << "1000 2 400.5 200" << std::endl
      << "B Ulje neko" << std::endl
      << "60.1 50 77";
    f.close();
    Skladiste s;
    s.UcitajIzDatoteke("ABC.TXT");
    const Skladiste &cs = s;
    cs.IzlistajSkladiste(); //cs je const
}
	return 0;
}
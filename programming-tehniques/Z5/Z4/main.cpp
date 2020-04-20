//TP 2018/2019: Zadaća 5, Zadatak 4
#include <iostream>
#include <vector>
#include <string>
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

class PolimorfniSpremnik{
    std::shared_ptr<Spremnik> p;
    public:
    PolimorfniSpremnik(){p = nullptr;}
    PolimorfniSpremnik(const Spremnik& s){
    p = s.DajKopiju();
    }
    void Ispisi() const{
        if(!p) throw std::logic_error("Nespecificiran spremnik");
        p->Ispisi();
    }
    std::shared_ptr<Spremnik> DajKopiju() const{
    if(!p) throw std::logic_error("Nespecificiran spremnik");
        auto ret = p->DajKopiju();
        return ret;
    }
    double DajTezinu() const{
    if(!p) throw std::logic_error("Nespecificiran spremnik");
        return p->DajTezinu();
    }
    double DajUkupnuTezinu() const{
    if(!p) throw std::logic_error("Nespecificiran spremnik");
        return p->DajUkupnuTezinu();
    }
    PolimorfniSpremnik& operator=(const Spremnik& s){
        p = s.DajKopiju();
        return *this;
    }
    PolimorfniSpremnik& operator =(Spremnik&& s){
        p = s.DajKopiju();
        return *this;
    }
   };

int main ()
{
    try
    {

        PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70));
        PolimorfniSpremnik s2, s3, s4;
        s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5});
        s3 = Vreca(0.1, "Patak", 15.5);
        std::cout << s1.DajTezinu() << std::endl;
        std::cout << s2.DajUkupnuTezinu() << std::endl;
        s3.Ispisi();
        s1 = s2;
        s1.Ispisi();
        s4.DajTezinu();
    }
    catch(std::logic_error le)
    {
        std::cout << le.what();
    }

	return 0;
}
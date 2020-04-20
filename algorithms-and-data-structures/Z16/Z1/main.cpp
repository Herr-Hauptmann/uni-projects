#include <iostream>
#include <utility>
#include <vector>
#include <string>
template <typename TipKljuca, typename TipVrijednosti>
class Mapa
{
public:
    Mapa() {};
    virtual ~Mapa() {};
    virtual TipVrijednosti& operator[](TipKljuca kljuc) = 0;
    virtual TipVrijednosti operator[](TipKljuca kljuc) const = 0;
    virtual int brojElemenata() const = 0;
    virtual void obrisi() = 0;
    virtual void obrisi(const TipKljuca& kljuc) = 0;
};

template <typename TipKljuca, typename TipVrijednosti>
class NizMapa: public Mapa<TipKljuca, TipVrijednosti>
{
    int br_elemenata;
    int kapacitet;
    std::pair<TipKljuca, TipVrijednosti>* niz;
public:
    NizMapa()
    {
        niz = new std::pair<TipKljuca, TipVrijednosti>[500];
        br_elemenata = 0;
        kapacitet = 500;
    }
    NizMapa(const NizMapa<TipKljuca, TipVrijednosti> &m)
    {
        this->br_elemenata = m.br_elemenata;
        this->kapacitet = m.kapacitet;
        this->niz = new std::pair<TipKljuca, TipVrijednosti>[kapacitet];
        for(int i = 0; i < br_elemenata; i++) this->niz[i] = m.niz[i];
    }
    int brojElemenata() const
    {
        return br_elemenata;
    }
    TipVrijednosti& operator[](TipKljuca kljuc)
    {
        
        for(int i = 0; i < br_elemenata; i++){
            if(niz[i].first == kljuc) return niz[i].second;
        }
        if(br_elemenata == kapacitet){
            kapacitet *= 2;
            auto temp = new std::pair<TipKljuca, TipVrijednosti>[kapacitet];
            for(int i = 0; i < br_elemenata; i++) temp[i] = niz[i];
            delete[] niz;
            niz = temp;
        }
        niz[br_elemenata++] = std::pair<TipKljuca,TipVrijednosti>(TipKljuca(),TipVrijednosti());
        niz[br_elemenata - 1].second = TipVrijednosti();
        niz[br_elemenata - 1].first = kljuc;
        return niz[br_elemenata - 1].second;
    }
    TipVrijednosti operator[](TipKljuca kljuc) const 
    {
        for(int i = 0; i < br_elemenata; i++){
            if(niz[i].first == kljuc) return niz[i].second;
        }
        return TipVrijednosti();
    }

    void obrisi() override
    {
        delete[] niz;
        br_elemenata = 0;
        kapacitet = 500;
        niz = new std::pair<TipKljuca,TipVrijednosti>[kapacitet];
    }
    void obrisi(const TipKljuca& kljuc) override
    {
        for(int i = 0; i < br_elemenata; i++){
            if(niz[i].first == kljuc){
                for(int j = i; j < br_elemenata - 1; j++) niz[j] = niz[j + 1];
                br_elemenata--;
            }
        }
    }
    NizMapa<TipKljuca, TipVrijednosti>& operator=(const NizMapa<TipKljuca,TipVrijednosti>& m)
    {
        if(this == &m) return *this;
        this->obrisi();
        delete[] this->niz;
        this->kapacitet = m.kapacitet;
        this->br_elemenata = m.br_elemenata;
        this->niz = new std::pair<TipKljuca, TipVrijednosti>[kapacitet];
        for(int i = 0; i < br_elemenata; i++) this->niz[i] = m.niz[i];
        return *this;
    }
    ~NizMapa()
    {
        delete[] niz;
    }
};

void test_1(){
    NizMapa<std::string, std::string> mapa;
    mapa["Arctic Monkeys"] = "Alex Turner";
    mapa["Metallica"] = "James Hetfield";
    mapa["Pink Floyd"] = "David Gilimour";
    std::cout << mapa.brojElemenata() << std::endl;
    std::cout << mapa["Arctic Monkeys"] << std::endl;
    mapa.obrisi("Metallica");
    std::cout << mapa["Metallica"] << std::endl;
    mapa.obrisi();
    std::cout << mapa.brojElemenata() << std::endl;
}

void test_2(){
    NizMapa<int, std::string> mapa;
    mapa[1] = "David Gilimour";
    mapa[2] = "Ozzy Osburne";
    mapa[3] = "Eric Clapton";
    mapa[4] = "Keith Richards";
    std::cout << mapa[1] << " " << mapa[2] << " " << mapa[3] << " " << mapa[4] << std::endl;
    std::cout << mapa[5] << std::endl;
    mapa.obrisi(2);
    std::cout << mapa[2]  << std::endl;
}

void test_3(){
    const Mapa<int, int>* m;
    NizMapa<int, int> mapa;
    for(int i = 0; i < 10; i++) mapa[i] = i * i;
    m = &mapa;
    std::cout << (*m)[22] << std::endl;
    mapa.obrisi(2);
    std::cout << mapa[2] << std::endl;
}

void test_4(){
    NizMapa<int, double> mapa;
    for(int i = 1; i <= 10; i++) mapa[i] = 1. / i;
    std::cout << mapa.brojElemenata() << std::endl;
    mapa.obrisi(4);
    mapa.obrisi(2);
    std::cout << mapa.brojElemenata() << std::endl;
    std::cout << mapa[1] << " " << mapa[9] << std::endl;
}

void test_5(){
    NizMapa<std::string, std::vector<int> > mapa;
    mapa["Eric Clapton"] = {1,2,3,4,5};
    mapa["David Gilimour"] = {1,2,3};
    mapa["John Mayer"] = {1,2};
    std::cout << mapa["Eric Clapton"].size() << " " << mapa["David Gilimour"].size() << " " << mapa["John Mayer"].size() << std::endl;
}


int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}

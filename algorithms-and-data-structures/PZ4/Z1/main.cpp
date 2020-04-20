#include <iostream>
#include <stdexcept>
template <typename Tip>
struct Cvor {
    Tip el;
    Cvor *veza;
};

template <typename Tip>
class Red
{
    Cvor<Tip>* celoPok;
    Cvor<Tip>* kraj;
    int broj_el;
public:


    Red()
    {
        celoPok = nullptr;
        kraj = nullptr;
        broj_el = 0;
    }
    
    void stavi(const Tip& el)
    {
        if(broj_el == 0) {
            celoPok = new Cvor<Tip> {el,nullptr};
            kraj = celoPok;
            broj_el++;
        } else {
            kraj->veza = new Cvor<Tip> {el,nullptr};
            kraj = kraj->veza;
            broj_el++;
        }
    }
    
    Red(const Red<Tip>& r){
        this->broj_el = 0;
        for(auto p = r.celoPok; p != nullptr; p = p->veza){
            this->stavi(p->el);
        }
    }
    
    Tip skini()
    {
        if(broj_el == 0) throw std::range_error("Red je prazan!");
        Tip ret = celoPok->el;
        Cvor<Tip>* p = celoPok;
        celoPok = celoPok->veza;
        delete p;
        broj_el--;
        return ret;
    }
    
    void brisi(){
        if(broj_el == 0) return;
        Cvor<Tip>* p2 = nullptr;
        for(auto p = celoPok; p != nullptr; p = p->veza) {
            delete p2;
            p2 = p;
        }
        delete p2;
        this->broj_el = 0;
    }
    
    Red<Tip>& operator=(const Red<Tip>& r){
        if(this == &r) return *this;
        if(this->broj_el != 0) this->brisi();
        for(auto p = r.celoPok; p != nullptr; p = p->veza){
            this->stavi(p->el);
        }
        this->broj_el = r.broj_el;
        return *this;
    }

    Tip& celo()
    {
        if(broj_el == 0) throw std::range_error("Red je prazan!");
        return celoPok->el;
    }

    Tip celo() const{
        if(broj_el == 0) throw std::range_error("Red je prazan!");
        return celoPok->el;
    }

    int brojElemenata() const
    {
        return broj_el;
    }

    ~Red()
    {
        if(broj_el == 0) return;
        Cvor<Tip>* p2 = nullptr;
        for(auto p = celoPok; p != nullptr; p = p->veza) {
            delete p2;
            p2 = p;
        }
        delete p2;
    }
};

// rucni testovi by @derekwetrust
bool Test1(){
    Red<int> r;
    for(int i = 1; i <= 10; i++) r.stavi(i);
    if(r.brojElemenata() != 10){
        std::cout<<"Ne valja!";
        return false;
    }
    if(r.celo() != 1){
        std::cout<<"Ne valja!";
        return false;
    }
    for(int i = 1; i <= 5; i++){
        if(r.skini() != i){
            std::cout<<"Ne valja!";
            return false;
        }
    }
    if(r.brojElemenata() != 5 || r.celo() != 6){
        std::cout<<"Ne valja!";
        return false;
    }
    return true;
}

bool Test2(){
    Red<double> r;
    try{
        r.skini();
        return false;
    }
    catch(std::range_error e){
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
    try{
        r.celo();
        return false;
    }
    catch(std::range_error e){
        std::cout<<"Izuzetak: "<<e.what()<<std::endl;
    }
    
    for(int i = 1; i <= 10; i++) r.stavi(i);
    Red<double> r2(r);
    if(r2.brojElemenata() != r.brojElemenata()) return false;
    for(int i = 1; i <= 10; i++){
        if(r.skini() != r2.skini()) return false;
    }
    for(int i = 1; i <= 10; i++) r.stavi(i);
    r2.brisi();
    r2 = r;
    if(r2.brojElemenata() != r.brojElemenata()) return false;
    for(int i = 1; i <= 10; i++){
        if(r.skini() != r2.skini()) return false;
    }
    return true;
}



int main(){
    if(Test1()) std::cout<<"Test1 uspješan!";
    std::cout<<std::endl;
    if(Test2()) std::cout<<"Test2 uspješan!";
    else std::cout<<"Ne valja!";
    std::cout<<std::endl;
    
    
    return 0;
}

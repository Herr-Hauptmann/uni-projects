#include <iostream>
#include <stdexcept>
template <typename Tip>
class Lista
{
public:
    Lista() {}
    virtual int brojElemenata() const = 0;
    virtual Tip& trenutni() = 0;
    virtual bool prethodni() = 0;
    virtual bool sljedeci() = 0;
    virtual void pocetak() = 0;
    virtual void kraj() = 0;
    virtual void obrisi() = 0;
    virtual void dodajIspred(const Tip& el) = 0;
    virtual void dodajIza(const Tip& el) = 0;
    virtual Tip& operator[](int n) = 0;
    virtual ~Lista() {}
};

template <typename Tip>
class NizLista: public Lista<Tip>
{
protected:
    Tip** pok;
    int broj_el;
    int index;
    int kapacitet;
public:
    NizLista()
    {
        broj_el = 0;
        index = 0;
        kapacitet = 10;
        pok = new Tip* [10] {};
    }
    NizLista(const NizLista<Tip>& niz)
    {
        this->broj_el = niz.broj_el;
        this->kapacitet = niz.kapacitet;
        this->index = niz.index;
        this->pok = new Tip*[kapacitet] {};
        for(int i = 0; i < niz.broj_el; i++) this->pok[i] = new Tip(*niz.pok[i]);
    }
    void postaviIndex(int n)
    {
        index = n;
    }
    void postaviKapacitet(int n)
    {
        kapacitet = n;
    }
    Tip** dajPok()
    {
        return pok;
    }
    void postaviBrojEl(int n)
    {
        broj_el = n;
    }
    int brojElemenata() const override
    {
        return broj_el;
    }
    Tip& trenutni()
    {
        if(broj_el == 0) throw std::logic_error("nesto");
        return *pok[index];
    }
    Tip trenutni() const
    {
        if(broj_el == 0) throw std::logic_error("nesto");
        return *pok[index];
    }

    bool prethodni()
    {
        if(!broj_el || !index) return false;
        index--;
        return true;
    }
    bool sljedeci()
    {
        if(!broj_el || index == broj_el - 1) return false;
        index++;
        return true;
    }
    void pocetak()
    {
        index = 0;
    }
    void kraj()
    {
        if(broj_el != 0) index = broj_el - 1;
        else index = 0;
    }
    void obrisi()
    {
        if(broj_el == 0) return;
        if(index == 0) {
            delete pok[0];
            pok[0] = nullptr;
            for(int i = 0; i < broj_el - 1; i++) pok[i] = pok[i+1];
            broj_el--;
            return;
        }
        if(index == broj_el - 1) {
            delete pok[index];
            pok[index] = nullptr;
            broj_el--;
            index--;
            return;
        }
        delete pok[index];
        pok[index] = nullptr;
        for(int i = index; i < broj_el - 1; i++) {
            pok[i] = pok[i+1];
        }
        broj_el--;
    }
    void dodajIza(const Tip& el)
    {
        if(broj_el == 0) {
            pok[0] = new Tip(el);
            broj_el++;
            return;
        }
        if(kapacitet < broj_el + 1) {
            Tip** p2 = pok;
            pok = new Tip*[kapacitet + int(kapacitet / 2)] {};
            for(int i = 0; i < broj_el; i++) pok[i] = p2[i];
            delete[] p2;
            kapacitet += int(kapacitet / 2);
        }
        for(int i = broj_el - 1; i >= index + 1; i--) {
            pok[i + 1] = pok[i];
        }
        pok[index + 1] = new Tip(el);
        broj_el++;
    }
    void dodajIspred(const Tip& el)
    {
        if(broj_el == 0) {
            pok[0] = new Tip(el);
            broj_el++;
            return;
        }
        if(kapacitet < broj_el + 1) {
            Tip** p2 = pok;
            pok = new Tip*[kapacitet + int(kapacitet / 2)] {};
            for(int i = 0; i < broj_el; i++) pok[i] = new Tip(*p2[i]);
            for(int i = 0; i < broj_el; i++) delete p2[i];
            delete[] p2;
            kapacitet += int(kapacitet / 2);
        }
        if(index == 0) {
            for(int i = broj_el - 1; i >= index; i--) pok[i+1] = pok[i];
            pok[0] = new Tip(el);
            index++;
            broj_el++;
            return;

        }
        for(int i = broj_el - 1; i >= index; i--) {
            pok[i + 1] = pok[i];
        }
        pok[index] = new Tip(el);
        broj_el++;
        index++;
    }

    Tip& operator[](int n)
    {
        if(n < 0 || n > broj_el - 1) throw std::logic_error("1");
        return *pok[n];
    }
    Tip operator[](int n) const
    {
        if(n < 0 || n > broj_el - 1) throw std::logic_error("1");
        return *pok[n];
    }
    void operator=(const NizLista<Tip>& niz)
    {
        index = niz.index;
        if(kapacitet < niz.kapacitet) {
            for(int i = 0; i < kapacitet; i++) delete pok[i];
            delete[] pok;
            kapacitet = niz.kapacitet;
            pok = new Tip*[kapacitet] {};
        }
        for(int i = 0; i < broj_el; i++) delete pok[i];
        broj_el = niz.broj_el;
        for(int i = 0; i < broj_el; i++) pok[i] = new Tip(*niz.pok[i]);
    }
    ~NizLista()
    {
        for(int i = 0; i < broj_el; i++) delete pok[i];
        delete[] pok;
    }

};
template <typename Tip>
struct Cvor {
    Tip element;
    Cvor *veza;
};
template <typename Tip>
class JednostrukaLista: public Lista<Tip>
{
    Cvor<Tip>* poc;
    Cvor<Tip>* tr;
    int  broj_el, kapacitet;
public:
    // konstruktor
    JednostrukaLista()
    {
        broj_el = 0;
        poc = nullptr;
        tr = nullptr;
    }
    //kopirajuci konstruktor
    JednostrukaLista(const JednostrukaLista<Tip>& lista)
    {
        this->poc = nullptr;
        this->broj_el = lista.broj_el;
        Cvor<Tip>* p;
        for(p = lista.poc; p->veza != nullptr; p = p->veza) {
            if(!this->poc) {
                this->poc = new Cvor<Tip> {p->element,p->veza};
                this->tr = poc;
            } else {
                tr->veza = new Cvor<Tip> {p->element,p->veza};
                tr = tr->veza;
            }
        }
        this->tr->veza = nullptr;
        this->tr = lista.tr;
    }
    int brojElemenata() const override
    {
        return broj_el;
    }

    Tip& trenutni()
    {
        if(broj_el == 0) throw std::logic_error("2");
        return tr->element;
    }
    Tip trenutni() const
    {
        if(broj_el == 0) throw std::logic_error("2");
        return tr->element;
    }
    bool prethodni()
    {
        if(!broj_el) return false;
        if(tr == poc) return true;
        Cvor<Tip>* p = nullptr;
        for(p = poc; p->veza != tr; p = p->veza);
        tr = p;
        return true;
    }
    bool sljedeci()
    {
        if(!broj_el) return false;
        if(tr->veza == nullptr) return false;
        tr = tr->veza;
        return true;
    }
    void pocetak()
    {
        tr = poc;
    }
    void kraj()
    {
        if(broj_el != 0) {
            for(tr; tr->veza != nullptr; tr = tr->veza);
        }
    }

    void obrisi()
    {
        if(broj_el == 0) throw;
        if(broj_el == 1) {
            delete tr;
            poc = nullptr;
            tr = nullptr;
            broj_el--;
            return;
        }
        if(tr->veza == nullptr) {
            Cvor<Tip>* p = tr;
            this->prethodni();
            delete p;
            tr->veza = nullptr;
            broj_el--;
            return;
        }
        if(tr == poc) {
            Cvor<Tip>* p = tr->veza;
            delete tr;
            tr = p;
            poc = tr;
            broj_el--;
            return;
        }
        Cvor<Tip>* p = tr;
        this->prethodni();
        tr->veza = p->veza;
        delete p;
        tr = tr->veza;
        broj_el--;
    }

    void dodajIza(const Tip& el)
    {
        if(broj_el == 0) {
            poc = new Cvor<Tip> {el,nullptr};
            tr = poc;
            broj_el++;
            return;
        }
        if(tr->veza == nullptr) {
            tr->veza = new Cvor<Tip> {el,nullptr};
            broj_el++;
            return;
        }
        auto p = tr->veza;
        tr->veza = new Cvor<Tip> {el,p};
        broj_el++;
    }

    void dodajIspred(const Tip& el)
    {
        if(broj_el == 0) {
            poc = new Cvor<Tip> {el,nullptr};
            tr = poc;
            broj_el++;
            return;
        }
        if(tr == poc) {
            poc = new Cvor<Tip> {el, nullptr};
            poc->veza = tr;
            broj_el++;
            return;
        }
        auto p = poc;
        for(p = poc; p->veza != tr; p = p->veza);
        p->veza = new Cvor<Tip> {el,tr};
        broj_el++;
    }
    Tip& operator [](int n)
    {
        if(n < 0 || n >= broj_el) throw std::logic_error("3");
        auto p = poc;
        for(int i = 0; i < n; i++) {
            p = p->veza;
        }
        return p->element;
    }
    Tip operator [](int n) const
    {
        if(n < 0 || n >= broj_el) throw std::logic_error("3");
        auto p = poc;
        for(int i = 0; i < n; i++) {
            p = p->veza;
        }
        return p->element;
    }

    void operator =(const JednostrukaLista<Tip> lista)
    {
        if(broj_el != 0) {
            Cvor<Tip>* p2 = nullptr;
            for(auto p = poc; p != nullptr; p = p->veza) {
                delete p2;
                p2 = p;
            }
            delete p2;
        }
        this->poc = nullptr;
        this->broj_el = lista.broj_el;
        Cvor<Tip>* p;
        for(p = lista.poc; p->veza != nullptr; p = p->veza) {
            if(!this->poc) {
                this->poc = new Cvor<Tip> {p->element,p->veza};
                this->tr = poc;
            } else {
                tr->veza = new Cvor<Tip> {p->element,p->veza};
                tr = tr->veza;
            }
        }
        this->tr->veza = nullptr;
        this->tr = lista.tr;
    }

    ~JednostrukaLista()
    {
        if(broj_el == 0) return;
        Cvor<Tip>* p2 = nullptr;
        for(auto p = poc; p != nullptr; p = p->veza) {
            delete p2;
            p2 = p;
        }
        delete p2;
    }
};

// Rucni testovi provjere! by @derekwetrust

void NizListaKonstruktor()
{
    NizLista<int> niz;
    if(niz.brojElemenata() != 0) std::cout<<"Ne valja!\n";
    std::cout<<"Konstruktor radi!\n";
}

void NizListaKopKonstuktor()
{
    NizLista<int> niz;
    for(int i = 1; i <= 5; i++) niz.dodajIspred(i);
    NizLista<int> niz2(niz);
    if(niz2[0] != 2 || niz2[1] != 3 || niz[2] != 4 || niz2[3] != 5 || niz[4] != 1) {
        std::cout<<"Ne valja!"<<std::endl;
        return;
    }
    std::cout<<"Copy konstruktor radi!\n";
}

void NizListaBrEl()
{
    NizLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIspred(i);
    if(niz.brojElemenata() == 10) std::cout<<"brojElemenata() radi!\n";
}

void NizListaTrenutni()
{
    NizLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    if(niz.trenutni() != 1) {
        std::cout<<"Ne valja!";
        return;
    }
    niz.obrisi();
    if(niz.trenutni() != 5) {
        std::cout<<"Ne valja!";
        return;
    }
    std::cout<<"trenutni() radi!\n";
}

void  NizListaPrethodni()
{
    NizLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    niz.prethodni();
    if(niz.trenutni() != 5) {
        std::cout<<"Ne valja!";
        return;
    }
    niz.obrisi();
    if(niz.trenutni() != 1) {
        std::cout<<"Ne valja!";
        return;
    }
    std::cout<<"prethodni() radi!\n";

}

void NizListaSljedeci()
{
    NizLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    niz.prethodni();
    niz.prethodni();
    niz.sljedeci();
    if(niz.trenutni() != 5) {
        std::cout<<"Ne valja!";
        return;
    }
    niz.obrisi();
    if(niz.trenutni() != 1) {
        std::cout<<"Ne valja!";
        return;
    }
    std::cout<<"sljedeci() radi!\n";
}

void NizListaPocetak()
{
    NizLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    niz.pocetak();
    if(niz.trenutni() != 2) {
        std::cout<<"Ne valja\n";
        return;
    }
    std::cout<<"pocetak() radi!\n";

}
void NizListaKraj()
{
    NizLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    niz.prethodni();
    niz.prethodni();
    niz.prethodni();
    niz.kraj();
    if(niz.trenutni() != 1) {
        std::cout<<"Ne valja\n";
        return;
    }
    std::cout<<"kraj() radi!\n";
}

void NizListaObrisi(){
    NizLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIza(i);
    niz.sljedeci();
    niz.sljedeci();
    niz.obrisi();
    if(niz.trenutni() == 3) std::cout<<"Ne valja!\n";
    else std::cout<<"obrisi() radi!\n";
}

void NizListaIndeks(){
    NizLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIza(i);
    bool flag = true;
    for(int i = 0; i < 10; i++){
        if(niz[i] != niz.trenutni()){
            flag = false;
            break;
        }
        niz.sljedeci();
    }
    if(flag) std::cout<<"operator[] radi!\n";
    else std::cout<<"Ne valja!\n";
    
}

void NizListaIspred(){
    NizLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIspred(i);
    bool flag = true;
    for(int i = 0; i < 4; i++){
        if(niz[i] != i + 2){
            flag = false;
            break;
        }
    }
    if(niz[niz.brojElemenata() - 1] != 1) flag = false;
    if(flag) std::cout<<"dodajIspred() radi!\n";
    else std::cout<<"Ne valja!\n";
    
}

void NizListaIza(){
      NizLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIza(i);
    bool flag = true;
    for(int i = 1; i < 10; i++){
        if(niz[i] != 10 - (i - 1)){
            flag = false;
            break;
        }
    }
    if(flag) std::cout<<"dodajIza() radi!\n";
    else std::cout<<"Ne valja!\n";
}
// Provjera za JednostrukaLista<>
void JednostrukaListaBrEl(){
    JednostrukaLista<int> l;
    for(int i = 1; i <= 5; i++) l.dodajIza(i);
    if(l.brojElemenata() != 5) std::cout<<"Ne valja!";
    else std::cout<<"brojElemenata() radi!\n";
}

void JednostrukaListaTrenutni(){
    JednostrukaLista<int> l;
    for(int i = 1; i <= 5; i++) l.dodajIza(i);
    if(l.trenutni() != 1)
    {
    std::cout<<"Ne valja!";
    return;
    }
    l.sljedeci();
    for(int i = 5; i >= 2; i--){
        if(l.trenutni() != i){
            std::cout<<"Nevalja!\n";
           return;
        }
        l.sljedeci();
    }
    std::cout<<"trenutni() radi!\n";
}
void  JednostrukaListaPrethodni()
{
    JednostrukaLista<int> l;
    for(int i = 1; i <= 5; i++) {
        l.dodajIspred(i);
    }
    l.prethodni();
    if(l.trenutni() != 5) {
        std::cout<<"Ne valja!";
        return;
    }
    l.obrisi();
    if(l.trenutni() != 1) {
        std::cout<<"Ne valja!";
        return;
    }
    std::cout<<"prethodni() radi!\n";

}
void JednostrukaListaSljedeci()
{
    JednostrukaLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    niz.prethodni();
    niz.prethodni();
    niz.sljedeci();
    if(niz.trenutni() != 5) {
        std::cout<<"Ne valja!";
        return;
    }
    niz.obrisi();
    if(niz.trenutni() != 1) {
        std::cout<<"Ne valja!";
        return;
    }
    std::cout<<"sljedeci() radi!\n";
}
void JednostrukaListaPocetak()
{
    JednostrukaLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    niz.pocetak();
    if(niz.trenutni() != 2) {
        std::cout<<"Ne valja\n";
        return;
    }
    std::cout<<"pocetak() radi!\n";

}
void JednostrukaListaKraj()
{
    JednostrukaLista<int> niz;
    for(int i = 1; i <= 5; i++) {
        niz.dodajIspred(i);
    }
    niz.prethodni();
    niz.prethodni();
    niz.prethodni();
    niz.kraj();
    if(niz.trenutni() != 1) {
        std::cout<<"Ne valja\n";
        return;
    }
    std::cout<<"kraj() radi!\n";
}
void JednostrukaListaObrisi(){
    JednostrukaLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIza(i);
    niz.sljedeci();
    niz.sljedeci();
    niz.obrisi();
    if(niz.trenutni() == 3) std::cout<<"Ne valja!\n";
    else std::cout<<"obrisi() radi!\n";
}

void JednostrukaListaIndeks(){
    JednostrukaLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIza(i);
    bool flag = true;
    for(int i = 0; i < 10; i++){
        if(niz[i] != niz.trenutni()){
            flag = false;
            break;
        }
        niz.sljedeci();
    }
    if(flag) std::cout<<"operator[] radi!\n";
    else std::cout<<"Ne valja!\n";
    
}

void JednostrukaListaIspred(){
    JednostrukaLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIspred(i);
    bool flag = true;
    for(int i = 0; i < 4; i++){
        if(niz[i] != i + 2){
            flag = false;
            break;
        }
    }
    if(niz[niz.brojElemenata() - 1] != 1) flag = false;
    if(flag) std::cout<<"dodajIspred() radi!\n";
    else std::cout<<"Ne valja!\n";
    
}

void JednostrukaListaIza(){
      JednostrukaLista<int> niz;
    for(int i = 1; i <= 10; i++) niz.dodajIza(i);
    bool flag = true;
    for(int i = 1; i < 10 ; i++){
        if(niz[i] != 10 - (i - 1)  ){
            flag = false;
            break;
        }
    }
    if(flag) std::cout<<"dodajIza() radi!\n";
    else std::cout<<"Ne valja!\n";
}
// Napomena: Funkcije provjere su se mogle izvesti kao genericke što bi jako reduciralo kod
// ali to nije izvedeno iz jednog prostor razloga - III semestar, vremenski mi nije dozvolio (jer se nisam odmah sjetio da tako implementiram)
int main()
{
    std::cout<<"NizLista provjera:"<<std::endl<<std::endl;
    // provjera za NizLista
    NizListaKonstruktor();
    NizListaKopKonstuktor();
    NizListaBrEl();
    NizListaTrenutni();
    NizListaPrethodni();
    NizListaSljedeci();
    NizListaPocetak();
    NizListaKraj();
    NizListaObrisi();
    NizListaIndeks();
    NizListaIspred();
    NizListaIza();
    
    // provjera za JednoStrukaLista
    std::cout<<"JednostrukaLista provjera:"<<std::endl<<std::endl;
    JednostrukaListaBrEl();
    JednostrukaListaTrenutni();
    JednostrukaListaPrethodni();
    JednostrukaListaSljedeci();
    JednostrukaListaPocetak();
    JednostrukaListaKraj();
    JednostrukaListaObrisi();
    JednostrukaListaIndeks();
    JednostrukaListaIspred();
    JednostrukaListaIza();

    return 0;
}

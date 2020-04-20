#include <iostream>
#include <stdexcept>
template <typename Tip>
class Lista
{
public:
    Lista() {}
    virtual int brojElemenata() const = 0;
    virtual Tip& trenutni() = 0;
    virtual Tip trenutni() const = 0;
    virtual bool prethodni() = 0;
    virtual bool sljedeci() = 0;
    virtual void pocetak() = 0;
    virtual void kraj() = 0;
    virtual void obrisi() = 0;
    virtual void dodajIspred(const Tip& el) = 0;
    virtual void dodajIza(const Tip& el) = 0;
    virtual Tip& operator[](int n) = 0;
    virtual Tip operator[](int n) const = 0;
    virtual ~Lista() {}
};
template <typename Tip>
struct Cvor {
    Tip el;
    Cvor* next;
    Cvor* prev;
};
template <typename Tip>
class DvostrukaLista : public Lista<Tip>
{
    int broj_el;
    Cvor<Tip>* poc;
    Cvor<Tip>* tr;
    Cvor<Tip>* zadnji;
    int tr_index;
public:
    DvostrukaLista()
    {
        broj_el = 0;
        tr_index = 0;
        poc = nullptr;
        zadnji = nullptr;
        tr = nullptr;
    }
    // kopirajuci konstruktor
    DvostrukaLista(const DvostrukaLista<Tip> & l)
    {
        this->broj_el = l.broj_el;
        auto p = l.poc;
        tr = nullptr;
        Cvor<Tip>* temp;
        for(p; p != nullptr; p = p->next) {
            if(!tr) {
                this->poc = new Cvor<Tip> {p->el,nullptr,nullptr};
                tr = poc;
                zadnji = poc;
            } else {
                tr->next = new Cvor<Tip> {p->el,nullptr,tr};
                tr = tr->next;
            }
        }
        zadnji = tr;
        tr->next = nullptr;
        tr_index = l.tr_index;
        tr = poc;
        for(int i = 0; i < tr_index; i++) tr = tr->next;
    }

    int brojElemenata() const override
    {
        return broj_el;
    }

    Tip& trenutni() override
    {
        if(broj_el == 0) throw std::logic_error("Lista je prazna!");
        return tr->el;
    }
     Tip trenutni() const override
    {
        if(broj_el == 0) throw std::logic_error("Lista je prazna!");
        return tr->el;
    }
   

    bool prethodni()
    {
        if(broj_el == 0) return false;
        if(!tr->prev) return true;
        tr = tr->prev;
        tr_index--;
        return true;
    }

    bool sljedeci() override
    {
        if(tr->next == nullptr) return false;
        tr = tr->next;
        tr_index++;
        return true;
    }

    void pocetak() override
    {
        tr = poc;
        tr_index = 0;
    }
    void kraj()
    {
        tr = zadnji;
        tr_index = broj_el - 1;
    }

    void obrisi()
    {
        if(broj_el == 0) throw;
        if(broj_el == 1) {
            delete tr;
            poc = nullptr;
            tr = nullptr;
            zadnji = nullptr;
            broj_el--;
            return;
        }
        if(tr->next == nullptr) {
            Cvor<Tip>* p = tr;
            this->prethodni();
            delete p;
            tr->next = nullptr;
            zadnji = tr;
            broj_el--;
            return;
        }
        if(tr == poc) {
            Cvor<Tip>* p = tr->next;
            delete tr;
            tr = p;
            poc = tr;
            tr->prev = nullptr;
            broj_el--;
            return;
        }
        Cvor<Tip>* p = tr->prev;
        Cvor<Tip>* q = tr->next;
        delete tr;
        q->prev = p;
        p->next = q;
        tr = q;
        broj_el--;
    }

    void dodajIspred(const Tip& e) override
    {
        if(broj_el == 0) {
            poc = new Cvor<Tip> {e,nullptr,nullptr};
            tr = poc;
            zadnji = poc;
            broj_el++;
            return;
        }
        if(tr == poc) {
            poc = new Cvor<Tip> {e,tr,nullptr};
            tr->prev = poc;
            tr_index++;
            broj_el++;
            return;
        }
        auto p = tr->prev;
        p->next = new Cvor<Tip> {e,tr,p};
        tr->prev = p->next;
        broj_el++;
        tr_index++;
    }

    void dodajIza(const Tip& el)
    {
        if(broj_el == 0) {
            poc = new Cvor<Tip> {el,nullptr,nullptr};
            tr = poc;
            zadnji = poc;
            broj_el++;
            return;
        }
        if(tr->next == nullptr) {
            tr->next = new Cvor<Tip> {el,nullptr,tr};
            zadnji = tr->next;
            broj_el++;
            return;
        }
        auto p = tr->next;
        tr->next = new Cvor<Tip> {el,p,tr};
        p->prev = tr->next;
        broj_el++;
    }
    Tip& operator [](int n) override
    {
        if(n < 0 || n >= broj_el) throw std::logic_error("3");
        if(!broj_el) throw std::logic_error("Prazna lista!");
        if(n == broj_el - 1) return zadnji->el;
        if(n == 0) return poc->el;
        if(n == tr_index) return tr->el;
        if(n < tr_index && tr_index - n < n) {
            auto p = tr;
            for(int i = 0; i < tr_index - n; i++) p = p->prev;
            return p->el;
        }
        else if(n < tr_index && tr_index - n >= n) {
            auto p = poc;
            for(int i = 0; i < n; i++) p = p->next;
            return p->el;
        } else if(n > tr_index && broj_el - n - 1 < n - tr_index) {
            auto p = zadnji;
            for(int i = 0; i < broj_el - 1 - n; i++) p = p->prev;
            return p->el;
        } else {
            auto p = tr;
            for(int i = 0; i < n - tr_index; i++) p = p->next;
            return p->el;
        }
    }
     Tip operator [](int n) const override
    {
        if(n < 0 || n >= broj_el) throw std::logic_error("3");
        if(!broj_el) throw std::logic_error("Prazna lista!");
        if(n == broj_el - 1) return zadnji->el;
        if(n == 0) return poc->el;
        if(n == tr_index) return tr->el;
        if(n < tr_index && tr_index - n < n) {
            auto p = tr;
            for(int i = 0; i < tr_index - n; i++) p = p->prev;
            return p->el;
        }
        else if(n < tr_index && tr_index - n >= n) {
            auto p = poc;
            for(int i = 0; i < n; i++) p = p->next;
            return p->el;
        } else if(n > tr_index && broj_el - n - 1 < n - tr_index) {
            auto p = zadnji;
            for(int i = 0; i < broj_el - 1 - n; i++) p = p->prev;
            return p->el;
        } else {
            auto p = tr;
            for(int i = 0; i < n - tr_index; i++) p = p->next;
            return p->el;
        }
    }
    DvostrukaLista<Tip>& operator =(const DvostrukaLista<Tip>& lista)
    {
        if(this == &lista) return *this;
        Cvor<Tip>* p = nullptr;
        if(broj_el != 0) {
            for(; poc != nullptr; poc = poc->next) {
                delete p;
                p = poc;
            }
            delete p;
        }
        this->poc = nullptr;
        this->broj_el = lista.broj_el;
        for(p = lista.poc; p != nullptr; p = p->next) {
            if(!this->poc) {
                this->poc = new Cvor<Tip> {p->el,p->next,nullptr};
                this->tr = poc;
            } else {
                tr->next = new Cvor<Tip> {p->el,nullptr,tr};
                tr = tr->next;
            }
        }
        tr->next = nullptr;
        zadnji = tr;
        tr = poc;
        tr_index = lista.tr_index;
        for(int i = 0; i < tr_index; i++) tr=tr->next;
        return *this;
    }


    ~DvostrukaLista()
    {
        if(broj_el == 0) return;
        if(broj_el == 1) {
            delete poc;
        } else {
            Cvor<Tip>* p = nullptr;
            for(; poc != nullptr; poc = poc->next) {
                delete p;
                p = poc;
            }
            delete p;
            broj_el = 0;
            tr_index = 0;
            poc = nullptr;
            zadnji = nullptr;
            tr = nullptr;
        }
    }
};
template<typename Tip>
Tip dajMaksimum(const Lista<Tip>& n)
{
    if(n.brojElemenata() == 0) throw std::domain_error("Prazna lista!");
    DvostrukaLista<Tip> d = dynamic_cast<DvostrukaLista<Tip>&>(const_cast<Lista<Tip>&>(n));
    d.pocetak();
    Tip max = d.trenutni();
    for(int i = 0; i < d.brojElemenata(); i++){
        if(d.trenutni() > max) max = d.trenutni();
                d.sljedeci();
    }
    return max;
}

//rucni testovi provjere by @derekwetrust :)
void testMax1(){
    DvostrukaLista<double> dl;
    dl.dodajIza(23);
    dl.dodajIza(99);
    dl.dodajIza(-123);
    dl.dodajIza(288);
    dl.dodajIza(-99);
    if(dajMaksimum(dl) != 288) std::cout<<"testMax1: failed!"<<std::endl;
    else std::cout<<"testMax1: succueded!"<<std::endl;
}
void testMax2(){
    DvostrukaLista<int> dl;
    try{
        dajMaksimum(dl);
        std::cout<<"testMax2: failed!"<<std::endl;
    }
    catch(...){
        std::cout<<"testMax2: succueded!"<<std::endl;
    }
}
void testMax3(){
    DvostrukaLista<int> dl;
    for(int i = 0; i < 100; i++) dl.dodajIza(i*(i-1) % 13);
    if(dajMaksimum(dl) != 12){
        std::cout<<"test3: failed!"<<std::endl;
        return;
    }
    std::cout<<"testMax3: succeded!"<<std::endl;
}
void test1(){
    DvostrukaLista<int> dl;
    for(int i = 0; i < 10; i++) dl.dodajIza(i);
    if(dl.trenutni() != 0){
        std::cout<<"test1: failed!";
        return;
    }
    dl.sljedeci();
    dl.sljedeci();
    if(dl.trenutni() != 8){
        std::cout<<"test1: failed!";
        return;
    }
    dl.pocetak();
    if(dl.trenutni() != 0){
         std::cout<<"test1: failed!";
        return;
    }
    dl.kraj();
    if(dl.trenutni() != 1){
     std::cout<<"test1: failed!";
     return;
    }
    dl.prethodni();
    dl.prethodni();
    if(dl.trenutni() != 3){
        std::cout<<"test1: failed!";
        return;
    }
    for(int i = 0; i < 10; i++) dl.obrisi();
    if(dl.brojElemenata() != 0){
        std::cout<<"test1: failed!";
        return;
    }
    for(int i = 0; i < 10; i++) dl.dodajIspred(i);
    DvostrukaLista<int> dl2(dl);
    for(int i = 0; i < dl2.brojElemenata(); i++){
        if(dl[i] != dl2[i]){
            std::cout<<"test1: failed!";
            return;
        }
    }
    DvostrukaLista<int> dl3 = dl2;
     for(int i = 0; i < dl3.brojElemenata(); i++){
        if(dl2[i] != dl3[i]){
            std::cout<<"test1: failed!";
            return;
        }
    }
    std::cout<<"test1: succueded!"<<std::endl;
}
int main()
{
    testMax1();
    testMax2();
    testMax3();
    test1();
    return 0;
}

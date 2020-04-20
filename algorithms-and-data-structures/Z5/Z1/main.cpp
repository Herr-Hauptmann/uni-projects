#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
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
struct Node{
    public:
    TipKljuca kljuc;
    TipVrijednosti vrijednost;
    Node* next = nullptr;
};

//
template <typename TipKljuca, typename TipVrijednosti>
class HashMapaLan: public Mapa<TipKljuca, TipVrijednosti>
{
    // radi grdne sintakse
    typedef Node<TipKljuca,TipVrijednosti> node;
    int br_elemenata;
    int kapacitet;
    node** niz;
    unsigned int (*hash)(TipKljuca,unsigned int) = 0;
public:
    HashMapaLan()
    {
        br_elemenata = 0;
        kapacitet = 200;
        niz = new node*[kapacitet]{};
    }
    int brojElemenata() const
    {
        return br_elemenata;
    }
    unsigned int definisiHashFunkciju(unsigned int (*fun)(TipKljuca, unsigned int))
    {
        hash = fun;
    }

    HashMapaLan(const HashMapaLan<TipKljuca,TipVrijednosti>& hmapa)
    {
        kapacitet = hmapa.kapacitet;
        hash = hmapa.hash;
        br_elemenata = hmapa.br_elemenata;
        niz = new node*[kapacitet]{};
        for(int i = 0; i < kapacitet; i++) {
            if(hmapa.niz[i] != nullptr){
            niz[i] = new node();
            niz[i]->kljuc = hmapa.niz[i]->kljuc;
            niz[i]->vrijednost = hmapa.niz[i]->vrijednost;
            auto p = hmapa.niz[i]->next;
            auto r = niz[i];
            while(p != nullptr){
               r->next = new node();
                r->next->kljuc = p->kljuc;
                r->next->vrijednost = p->vrijednost;
                r->next->next = nullptr;
                p = p->next;
                r = r->next;
            }
        }
      }
    }
    HashMapaLan<TipKljuca,TipVrijednosti>& operator =(const HashMapaLan<TipKljuca,TipVrijednosti>& hmapa)
    {
        if(this == &hmapa) return *this;
        for(int i = 0; i < kapacitet; i++) delete niz[i];
        delete[] niz;
        kapacitet = hmapa.kapacitet;
        br_elemenata = hmapa.br_elemenata;
        this->niz = new node*[kapacitet]{};
         for(int i = 0; i < kapacitet; i++) {
            if(hmapa.niz[i] != nullptr){
            niz[i] = new node();
            niz[i]->kljuc = hmapa.niz[i]->kljuc;
            niz[i]->vrijednost = hmapa.niz[i]->vrijednost;
            auto p = hmapa.niz[i]->next;
            auto r = niz[i];
            while(p != nullptr){
                r->next = new node();
                r->next->kljuc = p->kljuc;
                r->next->vrijednost = p->vrijednost;
                r->next->next = nullptr;
                p = p->next;
                r = r->next;
            }
        }
      }
        return *this;
    }
    void obrisi(const TipKljuca& kljuc)
    {
        if(hash == nullptr) throw "Nije defisana hash funkcija!";
        if(br_elemenata == 0) throw "HashMapa je prazna!";
        unsigned int index = hash(kljuc, kapacitet);
        if(niz[index] != nullptr){
            if(niz[index]->kljuc == kljuc){
                auto p = niz[index];
                if(p->next == nullptr){
                    delete p;
                    niz[index] = nullptr;
                }
                else{
                    niz[index] = p->next;
                    delete p;
                }
                br_elemenata--;
                return;
            }
            auto p = niz[index];
            while(p != nullptr && p->next->kljuc != kljuc) p = p->next;
            auto tmp = p->next;
            p->next = tmp->next;
            delete tmp;
            br_elemenata--;
        }
        else{
            throw "Brisite nepostojeci element!";
        }
    }
    TipVrijednosti& operator [](TipKljuca kljuc)
    {
        if(hash == nullptr) throw "Nije defisana hash funkcija!";
        int index = hash(kljuc,kapacitet);
        if(niz[index] == nullptr){
            niz[index] = new node();
            niz[index]->kljuc = kljuc;
            niz[index]->vrijednost = TipVrijednosti();
            niz[index]->next = nullptr;
            br_elemenata++;
            return niz[index]->vrijednost;
        }
        else{
            auto p = niz[index];
            while(p != nullptr){
                if(p->kljuc == kljuc) return p->vrijednost;
                p = p->next;
            }
            p = niz[index];
            if(kljuc < niz[index]->kljuc){
                auto p = niz[index];
                niz[index] = new node();
                niz[index]->kljuc = kljuc;
                niz[index]->vrijednost = TipVrijednosti();
                niz[index]->next = p;
                br_elemenata++;
                return niz[index]->vrijednost;
            }
            while(p->next != nullptr && kljuc > p->next->kljuc) p = p->next;
            auto tmp = p->next;
            p->next = new node();
            p->next->kljuc = kljuc;
            p->next->vrijednost = TipVrijednosti();
            p->next->next = tmp;
            br_elemenata++;
            return p->next->vrijednost;
        }
    }
    TipVrijednosti operator [](TipKljuca kljuc) const
    {
        if(hash == nullptr) throw "Nije definasan hash funkcija!";
        unsigned int index = hash(kljuc, kapacitet);
        if (niz[index] != nullptr) {
            auto p = niz[index];
            while(p != nullptr) {
                if(p->kljuc == kljuc) return p->vrijednost;
                p = p->next;
            }
        }
        return TipVrijednosti();
    }

    void obrisi()
    {
        for(int i = 0; i < kapacitet; i++){
            if(niz[i] != nullptr){
                auto p = niz[i];
                auto q = p->next;
                while(q != nullptr){
                    delete p;
                    p = q;
                    q = q->next;
                }
                delete p;
            }
        }
        delete[] niz;
        niz = new node*[kapacitet]{};
        br_elemenata = 0;
    }

    ~HashMapaLan()
    {
         for(int i = 0; i < kapacitet; i++){
            if(niz[i] != nullptr){
                auto p = niz[i];
                auto q = p->next;
                while(q != nullptr){
                    delete p;
                    p = q;
                    q = q->next;
                }
                delete p;
            }
        }
        delete[] niz;
    }
};

// predefinicija klase UsmjereniGraf zbog izvedbe klasa Grana i Cvor
template <typename TipOznake>
class UsmjereniGraf;
// 
template <typename TipOznake>
class GranaIterator;
// klasa Cvor
template<typename TipOznake>
class Cvor
{
    int redniBroj;
    UsmjereniGraf<TipOznake>* graf;
public:
    Cvor(UsmjereniGraf<TipOznake>* graf, int redniBroj): graf(graf), redniBroj(redniBroj) {}
    TipOznake dajOznaku() const
    {
        return graf->dajOznakuCvora(redniBroj);
    }
    void postaviOznaku(TipOznake oznaka)
    {
        graf->postaviOznakuCvora(redniBroj, oznaka);
    }
    int dajRedniBroj() const
    {
        return redniBroj;
    }
};
// klasa Grana
template <typename TipOznake>
class Grana
{
    UsmjereniGraf<TipOznake>* graf;
    int polazni, dolazni;
public:
    Grana(UsmjereniGraf<TipOznake>* graf, int polazni, int dolazni): graf(graf), polazni(polazni), dolazni(dolazni) {}
    float dajTezinu() const
    {
        return graf->dajTezinuGrane(polazni, dolazni);
    }
    void postaviTezinu(float tezina)
    {
        graf->postaviTezinuGrane(polazni, dolazni, tezina);
    }

    TipOznake dajOznaku() const{
    return graf->dajOznakuGrane(polazni, dolazni);
    }
    void postaviOznaku(TipOznake oznaka)
    {
        graf->postaviOznakuGrane(polazni, dolazni, oznaka);
    }

    Cvor<TipOznake> dajPolazniCvor() const
    {
        return graf->dajCvor(polazni);
    }
    Cvor<TipOznake> dajDolazniCvor() const
    {
        return graf->dajCvor(dolazni);
    }

};

template <typename TipOznake>
class UsmjereniGraf
{

public:
    UsmjereniGraf(int brojCvorova) {}
    virtual ~UsmjereniGraf() {}

    virtual int dajBrojCvorova() const = 0;
    virtual void postaviBrojCvorova(int brojCvorova) = 0;

    virtual void dodajGranu(int polazni, int dolazni, float tezina) = 0;
    virtual void obrisiGranu(int polazni, int dolazni) = 0;
    virtual void postaviTezinuGrane(int polazni, int dolazni, float tezina) = 0;
    virtual float dajTezinuGrane(int polazni, int dolazni) = 0;
    virtual bool postojiGrana(int polazni, int dolazni) = 0;

    virtual void postaviOznakuCvora(int cvor, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuCvora(int cvor) const = 0;

    virtual void postaviOznakuGrane(int polazni, int dolazni, TipOznake oznaka) = 0;
    virtual TipOznake dajOznakuGrane(int polazni, int dolazni) const = 0;

    Grana<TipOznake> dajGranu(int polazni, int dolazni) 
    {
        return Grana<TipOznake>(this, polazni, dolazni);
    }
    Cvor<TipOznake> dajCvor(int cvor) 
    {
        return Cvor<TipOznake>(this,cvor);
    }
    
    virtual GranaIterator<TipOznake> dajGranePocetak() = 0;
    virtual GranaIterator<TipOznake> dajGraneKraj() = 0;
    
   virtual GranaIterator<TipOznake> dajSjedecuGranu(int polazni, int dolazni) = 0;
    
};
template<typename TipOznake>
class GranaIterator{
  UsmjereniGraf<TipOznake>* graf;
  int polazni, dolazni;
  public:
  GranaIterator(UsmjereniGraf<TipOznake>* graf, int polazni, int dolazni): graf(graf), polazni(polazni), dolazni(dolazni){}
  Grana<TipOznake>  operator*(){
      return Grana<TipOznake>(graf, polazni, dolazni);
  }
  bool operator==(const GranaIterator& iter) const{
      return graf == iter.graf && polazni == iter.polazni && dolazni == iter.dolazni;
  }
  bool operator!=(const GranaIterator& iter) const{
      return !(*this == iter);
  }
  GranaIterator<TipOznake>& operator++(){
      if(polazni == -1 && dolazni == -1) throw "Greska!";
      GranaIterator g =  graf->dajSjedecuGranu(polazni,dolazni);
      polazni = g.polazni;
      dolazni = g.dolazni;
      return *this;
  }
  GranaIterator<TipOznake> operator++(int){
      GranaIterator tmp(*this);
      ++(*this);
      return tmp;
  }

};
template <typename Tip>
struct Element{
    int cvor;
    float tezina;
    Tip oznaka;
};
template<typename TipOznake>
class ListaGraf: public UsmjereniGraf<TipOznake> {
std::vector<std::list<Element<TipOznake>>> l;
std::vector<TipOznake> oznakeCvorova;
void ispravanCvor(int redniBroj) const{
    if(redniBroj < -1 || redniBroj >= dajBrojCvorova()) throw "Greska!";
}
void ispravnaGrana(int polazni, int dolazni) const{
    ispravanCvor(polazni);
    ispravanCvor(dolazni);
}
void postojiLiGrana(int polazni, int dolazni) const {
int x = polazni;
int y = dolazni;
if(!postojiGrana(x, y)) throw "Greska";
ispravnaGrana(polazni,dolazni);
}
typename std::list<Element<TipOznake>>::iterator traziElement(int i, int j){
    auto it = l[i].begin();
    while(it != l[i].end()){
        if(j == it->cvor) return it;
        else if(j < it->cvor) return l[i].end();
        it++;
    }
    return it;
}
typename std::list<Element<TipOznake>>::const_iterator traziElement(int i, int j) const{
    auto it = l[i].begin();
    while(it != l[i].end()){
        if(j == it->cvor) return it;
        else if(j < it->cvor) return l[i].end();
        it++;
    }
    return it;
}
public:
        ListaGraf(int brojCvorova): UsmjereniGraf<TipOznake>(brojCvorova){
            if(brojCvorova < 0) throw "Greska!";
            l = std::vector<std::list<Element<TipOznake>>>(brojCvorova, std::list<Element<TipOznake>>());
            oznakeCvorova = std::vector<TipOznake>(brojCvorova);
        }
        int dajBrojCvorova() const { return l.size(); }
        void postaviBrojCvorova(int n){
            if(n < dajBrojCvorova()) throw "Greska!";
            l.resize(n);
            oznakeCvorova.resize(n);
        }
        void dodajGranu(int polazni, int dolazni, float tezina=0){
            ispravnaGrana(polazni,dolazni);
            auto it = l[polazni].begin();
            while(it != l[polazni].end() && dolazni > it->cvor) it++;
            Element<TipOznake> temp;
            temp.cvor = dolazni;
            temp.tezina = tezina;
            temp.oznaka = TipOznake();
            l[polazni].insert(it,temp);
        }
        void obrisiGranu(int polazni, int dolazni){
            postojiLiGrana(polazni,dolazni);
            l[polazni].erase(traziElement(polazni,dolazni));
        }
        void postaviTezinuGrane(int polazni, int dolazni, float tezina=0){
            postojiLiGrana(polazni,dolazni);
            traziElement(polazni,dolazni)->tezina = tezina;
            
        }
        float dajTezinuGrane(int polazni, int dolazni) {
            postojiLiGrana(polazni,dolazni);
            return traziElement(polazni,dolazni)->tezina;
        }
        bool postojiGrana(int polazni, int dolazni){
            ispravnaGrana(polazni,dolazni);
            return traziElement(polazni,dolazni) != l[polazni].end();
        }
        bool postojiGrana(int polazni, int dolazni) const{
            ispravnaGrana(polazni,dolazni);
            return traziElement(polazni,dolazni) != l[polazni].end();
        }
        void postaviOznakuCvora(int cvor, TipOznake oznaka){
            ispravanCvor(cvor);
            oznakeCvorova[cvor] = oznaka;
        }
        TipOznake dajOznakuCvora(int cvor) const{
            ispravanCvor(cvor);
            return oznakeCvorova[cvor];
        }
        void postaviOznakuGrane(int polazni, int dolazni, TipOznake oznaka){
            postojiLiGrana(polazni, dolazni);
            traziElement(polazni, dolazni)->oznaka = oznaka;
        }
        TipOznake dajOznakuGrane(int polazni, int dolazni) const{
            postojiLiGrana(polazni,dolazni);
            return traziElement(polazni,dolazni)->oznaka;
        }
        Grana<TipOznake> dajGranu(int polazni, int dolazni){
            postojiLiGrana(polazni,dolazni);
            return Grana<TipOznake>(this,polazni,dolazni);
        }
        Cvor<TipOznake> dajCvor(int cvor){
            ispravanCvor(cvor);
            return Cvor<TipOznake>(this,cvor);
        }
        GranaIterator<TipOznake> dajGranePocetak() { return ++GranaIterator<TipOznake>(this,0,-1); }
        GranaIterator<TipOznake> dajGraneKraj() { return GranaIterator<TipOznake>(this,dajBrojCvorova(),0); }
        GranaIterator<TipOznake> dajSjedecuGranu(int polazni, int dolazni){
            return GranaIterator<TipOznake>(this,polazni++,dolazni++);
        }
};
template <typename Tip>
void dfs(UsmjereniGraf<Tip>* graf, std::vector<Cvor<Tip>>& dfsobilazak, Cvor<Tip> cvor){
    cvor.postaviOznaku(1);
    dfsobilazak.push_back(cvor);
    for(GranaIterator<Tip> it = graf->dajGranePocetak(); it != graf->dajGraneKraj(); ++it){
        Cvor<Tip> s = (*it).dajDolazniCvor();
        if((((*it).dajPolazniCvor().dajRedniBroj() == cvor.dajRedniBroj()) && s.dajOznaku() != 1 )) dfs(graf,dfsobilazak,s);
    }
}
template <typename Tip>
void bfs(UsmjereniGraf<Tip>* graf, std::vector<Cvor<Tip>> &bfsobilazak, Cvor<Tip> cvor) {
    cvor.postaviOznaku(1);
    bfsobilazak.push_back(cvor);
    std::queue<Cvor<Tip>> q;
    q.push(cvor);
    while(!q.empty()) {
        Cvor<Tip> c=q.front();
        q.pop();
        for(GranaIterator<Tip> it=graf->dajGranePocetak();it!=graf->dajGraneKraj();it++) {
            Cvor<Tip> susjed=(*it).dajDolazniCvor();
            if((*it).dajPolazniCvor().dajRedniBroj()==c.dajRedniBroj() && susjed.dajOznaku()!=1) {
                susjed.postaviOznaku(1);
                bfsobilazak.push_back(susjed);
                q.push(susjed);
            }
        }
    }
}
int main()
{
   UsmjereniGraf<bool> *g = new ListaGraf<bool>(6);
    g->dodajGranu(0, 1, 2.5);
    g->dodajGranu(1, 0, 1.2);
    g->dodajGranu(1, 2, 0.1);
    g->dodajGranu(0, 0, 3.14);
    for (GranaIterator<bool> iter = g->dajGranePocetak();
         iter != g->dajGraneKraj(); ++iter)
      std::cout << "(" << (*iter).dajPolazniCvor().dajRedniBroj() << ","
           << (*iter).dajDolazniCvor().dajRedniBroj() << ") -> "
           << (*iter).dajTezinu() << "; ";
  delete g;



    return 0;
}

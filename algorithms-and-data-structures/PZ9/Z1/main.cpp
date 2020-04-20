#include <iostream>
#include <string>
#include <utility>
#include <vector>
 
unsigned int nekihash(int ulaz, unsigned int max) {
    return ulaz+1;
}
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
template <typename TipKljuca, typename TipVrijednosti>
struct Cvor {
    TipKljuca kljuc;
    TipVrijednosti vrijednost;
    Cvor* lijevi;
    Cvor* desni;
    Cvor* roditelj;
};
template <typename TipKljuca, typename TipVrijednosti>
class BinStabloMapa: public Mapa<TipKljuca, TipVrijednosti>
{
    // da ne bi pisali uvijek full naziv
    typedef Cvor<TipKljuca,TipVrijednosti> cvor;
    cvor* poc;
    int broj_el;
    cvor* newNode(TipKljuca k, TipVrijednosti v, cvor* lijevi, cvor* desni, cvor* rod)
    {
        cvor* ret = new Cvor<TipKljuca,TipVrijednosti>();
        ret->kljuc = k;
        ret->vrijednost = v;
        ret->desni = desni;
        ret->lijevi = lijevi;
        ret->roditelj = rod;
        return ret;
    }
public:
    BinStabloMapa()
    {
        poc = nullptr;
        broj_el = 0;
    }
    int brojElemenata() const
    {
        return broj_el;
    }
    void kopiraj(cvor* cvor1, cvor* &cvor2, cvor* prethodni = nullptr){
        if(cvor1 != nullptr){
            cvor2 = new cvor();
            cvor2->kljuc = cvor1->kljuc;
            cvor2->vrijednost = cvor1->vrijednost;
            cvor2->roditelj = prethodni;
            kopiraj(cvor1->lijevi,cvor2->lijevi,cvor2);
            kopiraj(cvor1->desni,cvor2->desni,cvor2);
        }
    }
    BinStabloMapa(const BinStabloMapa<TipKljuca,TipVrijednosti> &b){
        kopiraj(b.poc,this->poc);
        this->broj_el = b.brojElemenata();
    }
    BinStabloMapa<TipKljuca, TipVrijednosti> operator=(const BinStabloMapa<TipKljuca,TipVrijednosti> &b){
        if(this == &b) return *this;
        this->obrisi();
        kopiraj(b.poc,this->poc);
        this->broj_el = b.brojElemenata();
        return *this;
    }

    TipVrijednosti& operator[](TipKljuca kljuc) override
    {

        if(broj_el == 0) {
            poc = newNode(kljuc, TipVrijednosti(), nullptr, nullptr, nullptr);
            broj_el++;
            return poc->vrijednost;
        }
        cvor* p = poc;
        cvor* q = nullptr;
        while(p != nullptr) {
            q = p;
            if(kljuc > p->kljuc) {
                p = p -> desni;
            } else if(kljuc < p -> kljuc) {
                p = p -> lijevi;
            } else {
                return p->vrijednost;
            }
        }
        if(q->kljuc < kljuc) {
            TipVrijednosti v = TipVrijednosti();
            q->desni = newNode(kljuc,v,nullptr,nullptr,q);
            broj_el++;
            return q->desni->vrijednost;
        } else {
            TipVrijednosti v = TipVrijednosti();
            q->lijevi = newNode(kljuc,v,nullptr,nullptr,q);
            broj_el++;
            return q->lijevi->vrijednost;
        }
    }
    TipVrijednosti operator[](TipKljuca kljuc) const
    {
        cvor* p = poc;
        cvor* q = nullptr;
        while(p != nullptr) {
            q = p;
            if(kljuc > p->kljuc) {
                p = p -> desni;
            } else if(kljuc < p -> kljuc) {
                p = p -> lijevi;
            } else {
                return p->vrijednost;
            }
        }
        return TipVrijednosti();
    }
    void obrisi(const TipKljuca& kljuc)
    {
        cvor* p=poc, *rod=nullptr;
        while(p!=nullptr && kljuc!=p->kljuc) {
            rod=p;
            if(kljuc<p->kljuc) p=p->lijevi;
            else p=p->desni;
        }
        if(p==nullptr) return;
        cvor* m;
        if(p->lijevi==nullptr) m=p->desni;
        else {
            if(p->desni==nullptr) m=p->lijevi;
            else {
                cvor* pm=p, *tmp;
                m=p->lijevi;
                tmp=m->desni;
                while(tmp!=nullptr) {
                    pm=m;
                    m=tmp;
                    tmp=m->desni;
                }
                if(pm!=p) {
                    pm->desni=m->lijevi;
                    m->lijevi=p->lijevi;
                }
                m->desni=p->desni;
            }
        }
        if(rod==nullptr) poc=m;
        else {
            if(p==rod->lijevi) rod->lijevi=m;
            else rod->desni=m;
        }
        delete p;
        broj_el--;
    }
    void obrisi_r(Cvor<TipKljuca,TipVrijednosti>* r)
    {
        if(r != nullptr) {
            obrisi_r(r->lijevi);
            obrisi_r(r->desni);
            delete r;
        }
    }
    void obrisi()
    {
       // obrisi_r(poc);
       while(poc != nullptr) obrisi(poc->kljuc);
        broj_el = 0;
    }

    ~BinStabloMapa()
    {
        obrisi();
    }


};
template <typename TipKljuca, typename TipVrijednosti>
class HashMapa: public Mapa<TipKljuca, TipVrijednosti>{
    int br_elemenata;
    int kapacitet;
    std::pair<TipKljuca, TipVrijednosti>* niz;
    unsigned int (*hash)(TipKljuca,unsigned int) = 0;
    public:
    HashMapa(){
        br_elemenata = 0;
        kapacitet = 200;
        niz = new std::pair<TipKljuca,TipVrijednosti>[200];
    }
    int brojElemenata() const{
        return br_elemenata;
    }
    unsigned int definisiHashFunkciju(unsigned int (*fun)(TipKljuca, unsigned int)) {hash = fun;}
    
    HashMapa(const HashMapa<TipKljuca,TipVrijednosti>& hmapa){
        kapacitet = hmapa.kapacitet;
        hash = hmapa.hash;
        br_elemenata = hmapa.br_elemenata;
        niz = new std::pair<TipKljuca,TipVrijednosti>[kapacitet];
        for(int i = 0; i < kapacitet; i++) niz[i] = hmapa.niz[i];
    }
    HashMapa<TipKljuca,TipVrijednosti>& operator =(const HashMapa<TipKljuca,TipVrijednosti>& hmapa){
        if(this == &hmapa) return *this;
        delete[] this->niz;
        kapacitet = hmapa.kapacitet;
        br_elemenata = hmapa.br_elemenata;
        this->niz = new std::pair<TipKljuca,TipVrijednosti>[kapacitet];
        for(int i = 0; i < kapacitet; i++) this->niz[i] = hmapa.niz[i];
        return *this;
    }
    void obrisi(const TipKljuca& kljuc){
        for(int i = 0; i < kapacitet; i++){
            if(niz[i].first == kljuc){
                for(int j = i; j < kapacitet - 1; j++)
                  niz[j] = niz[j+1];
                 i--;
                 br_elemenata--;
            }
        }
    }
    TipVrijednosti& operator [](TipKljuca kljuc){
        if(hash == nullptr) throw "Nije defisana hash funkcija!";
        for(int i = 0; i < kapacitet; i++)
         if(niz[i].first == kljuc) return niz[i].second;
        int index = hash(kljuc,kapacitet);
        while(index < kapacitet && niz[index].first != TipKljuca()) index++;
        if(index >= kapacitet){
            std::pair<TipKljuca,TipVrijednosti>* temp = new std::pair<TipKljuca,TipVrijednosti>[kapacitet];
            for(int i = 0; i < kapacitet; i++) temp[i] = this->niz[i];
            delete[] this->niz;
            this->niz = new std::pair<TipKljuca,TipVrijednosti>[kapacitet + 50];
            for(int i = 0; i < kapacitet; i++) this->niz[i] = temp[i];
            delete[] temp;
            kapacitet += 50;
        }
        niz[index].first = kljuc;
        br_elemenata++;
        return niz[index].second;
    }
    TipVrijednosti operator [](TipKljuca kljuc) const{
        if(hash == nullptr) throw "Nije definasan hash funkcija!";
        for(int i = 0; i < kapacitet; i++)
         if(niz[i].first == kljuc) return niz[i].second;
        return TipVrijednosti(); 
    }
    
    void obrisi(){
        delete[] niz;
        niz = new std::pair<TipKljuca, TipVrijednosti>[kapacitet];
        br_elemenata = 0;
    }
    
    ~HashMapa(){
        delete[] niz;
    }
    
    
    
    
    
    
};
void generisi(Mapa<int,int> &m, int vel) {
    srand(time(NULL));
    for(int i(0);i<vel;i++)
        m[i]=rand();
}
int main(){
    BinStabloMapa<int,int> b;
NizMapa<int,int> n;
HashMapa<int,int> hm;
hm.definisiHashFunkciju(nekihash);
clock_t vrijeme1 = clock();
generisi(b,7500);
clock_t vrijeme2 = clock();
double ukvrijeme1 = (vrijeme2 - vrijeme1) / (CLOCKS_PER_SEC / 1000);

clock_t vrijeme3 = clock();
generisi(n,7500);
clock_t vrijeme4 = clock();
double ukvrijeme2 = (vrijeme4 - vrijeme3) / (CLOCKS_PER_SEC / 1000);
clock_t vrijeme33 = clock();
generisi(hm,7500);
clock_t vrijeme44 = clock();
double ukvrijeme22 = (vrijeme44 - vrijeme33) / (CLOCKS_PER_SEC / 1000);

// Binarno stablo ubacivanje za ovaj slucaj ima losije performanse zbog randomiziranih podataka za razliku od Niz i Hash mape
std::cout << "Binarno stablo mapa ubacivanje: " << ukvrijeme1/7500 << "ms, NizMapa ubacivanje: " << ukvrijeme2/750 << " ms" << "HashMapa ubacivanje: " << ukvrijeme22 / 7500 << "ms" << std::endl;
  clock_t vrijeme5=clock();
    for(int i(0);i<7500;i++)
        b[i];
    clock_t vrijeme6=clock();
    double ukvrijeme3=(vrijeme6-vrijeme5)/(CLOCKS_PER_SEC/1000);

    clock_t vrijeme7=clock();
    for(int i(0);i<7500;i++)
        n[i];
    clock_t vrijeme8=clock();
    double ukvrijeme4=(vrijeme8-vrijeme7)/(CLOCKS_PER_SEC/1000);
    
    clock_t vrijeme77=clock();
    for(int i(0);i<7500;i++)
        hm[i];
    clock_t vrijeme88=clock();
    double ukvrijeme44=(vrijeme8-vrijeme7)/(CLOCKS_PER_SEC/1000);
    /* Pristup kod binarno stabla zahtjeva logn, dok kod niz mape O(n) */
    /* slican zakljucak vrijedi i za pristup, hashmapa daje dobre performanse zbog hash funkcije */
    std::cout << "Binarno stablo pristup: " << ukvrijeme3/7500 << " ms " << std::endl << "Niz mapa pristup: " << ukvrijeme4/7500 << " ms " << std::endl << "HashMapa pristup: " << ukvrijeme44/7500 << " ms " << std::endl;


    return 0;
}

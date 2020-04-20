#include <iostream>
#include <iomanip>
template <typename TipKljuca, typename TipVrijednosti>
struct Cvor {
    TipKljuca kljuc;
    TipVrijednosti vrijednost;
    Cvor* lijevi;
    Cvor* desni;
    Cvor* roditelj;
};
template <typename TipKljuca, typename TipVrijednosti>
struct CvorAVL {
   TipKljuca kljuc;
    TipVrijednosti vrijednost;
    CvorAVL* lijevi;
    CvorAVL* desni;
    CvorAVL* roditelj;
    int balans;
};
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
// da ne bi morali ovu pisati full naziv svaki put

template <typename TipKljuca, typename TipVrijednosti>
class AVLStabloMapa: public Mapa<TipKljuca, TipVrijednosti>{
    typedef CvorAVL<TipKljuca, TipVrijednosti> node;
    node* poc;
    int broj_el;
    node* trazi(const TipKljuca& k, node* &n){
        node* p = n;
        while(p != nullptr && p->kljuc != k){
            if(p->kljuc < k) p = p->lijevi;
            p = p->desni;
        }
        return p;
    }
    void kopiraj(node* cvor1, node* &cvor2, node* prethodni = nullptr){
        if(cvor1 != nullptr){
            cvor2 = new node();
            cvor2->kljuc = cvor1->kljuc;
            cvor2->vrijednost = cvor1->vrijednost;
            cvor2->balans = cvor1->balans;
            cvor2->roditelj = prethodni;
            kopiraj(cvor1->lijevi,cvor2->lijevi,cvor2);
            kopiraj(cvor1->desni,cvor2->desni,cvor2);
        }
    }
    node* newNodeAVL(TipKljuca k, TipVrijednosti v, node* lijevi, node* desni, node* rod)
    {
        node* ret = new CvorAVL<TipKljuca,TipVrijednosti>();
        ret->kljuc = k;
        ret->vrijednost = v;
        ret->desni = desni;
        ret->lijevi = lijevi;
        ret->roditelj = rod;
        ret->balans = 0;
        return ret;
    }
    // rightRotate - rotiraj udesni
    void rightRotate(node* &cvor) {
        if(cvor->roditelj && cvor->roditelj->lijevi==cvor){
            cvor->roditelj->lijevi=cvor->lijevi;
        }
        else if(cvor->roditelj){
            cvor->roditelj->desni=cvor->lijevi;
        }
        node* pomocni=cvor->lijevi;
        bool jelImalijevi=false;
        if(cvor->lijevi->desni) {
            cvor->lijevi=pomocni->desni;
            pomocni->desni->roditelj=cvor;
            pomocni->desni=nullptr;
            jelImalijevi=true;
        }
        pomocni->roditelj=cvor->roditelj;
        if(cvor->roditelj){
            cvor->roditelj=pomocni;
        }
        else {
            cvor->roditelj=pomocni;
            poc=pomocni;
        }
        pomocni->desni=cvor;
        pomocni->balans=0;
        cvor->balans=0;
        if(!jelImalijevi){
            cvor->lijevi=nullptr;
        }
    }
    void leftRotate(node* &cvor) {
        if(cvor->roditelj && cvor->roditelj->lijevi==cvor) {
            cvor->roditelj->lijevi=cvor->desni;
        }
        else if(cvor->roditelj) {
            cvor->roditelj->desni=cvor->desni;
        }
        node* pomocni=cvor->desni;
        bool jelImadesni=false;
        if(cvor->desni->lijevi) {
            cvor->desni=pomocni->lijevi;
            pomocni->lijevi->roditelj=cvor;
            pomocni->lijevi=nullptr;
            jelImadesni=true;
        }
        pomocni->roditelj=cvor->roditelj;
        if(cvor->roditelj){
            cvor->roditelj=pomocni;
        }
        else {
            cvor->roditelj=pomocni;
            poc=pomocni;
        }
        pomocni->lijevi=cvor;
        cvor->balans=0;
        pomocni->balans=0;
        if(!jelImadesni){
            cvor->desni=nullptr;
        }
    }
    // azurirajBalans
    void azurirajBalans(node* cvor){
        if(cvor == nullptr) return;
        if(cvor->roditelj == nullptr) return;
        node* parent = cvor->roditelj;
        if(parent->lijevi == cvor) parent->balans++;
        else parent->balans--;
        if(parent->balans == 0) return;
        if(parent->balans < -1 && cvor->balans > 0){
            rightRotate(cvor);
            leftRotate(parent);
        }
        else if(parent->balans > 1 && cvor->balans < 0 ){
            leftRotate(cvor);
            rightRotate(parent);
        }
        else if(parent->balans < -1){
            leftRotate(parent);
        }
        else if(parent->balans > 1){
            rightRotate(parent);
        }
        else azurirajBalans(parent);
    }
    void insert(node* &z){
        node *y=0, *x=poc;
        while(x!=0){
            y=x;
            if(z->kljuc < x->kljuc) x=x->lijevi;
            else x=x->desni;
        }
        bool imaLiBurazera=false;
        if(y==0){
            poc=z;
            broj_el++;
            imaLiBurazera=true;
        }
        else{
            if(z->kljuc < y->kljuc){
                y->lijevi=z;
                z->roditelj=y;
                broj_el++;
                if(y->desni) {
                    imaLiBurazera=true;
                    y->balans=0;
                }
            }
            else{
                y->desni=z;
                z->roditelj=y;
                broj_el++;
                if(y->lijevi) {
                    imaLiBurazera=true;
                    y->balans=0;
                }
            }
        }
        if(!imaLiBurazera) azurirajBalans(z);
    }
    public:
    // bezparametarski konstruktor
     AVLStabloMapa()
    {
        poc = nullptr;
        broj_el = 0;
    }
    int brojElemenata() const
    {
        return broj_el;
    }
    // kopirajuci konstruktor
    AVLStabloMapa(const AVLStabloMapa<TipKljuca,TipVrijednosti> &b){
        kopiraj(b.poc,this->poc);
        this->broj_el = b.brojElemenata();
    }
    // operator = 
    AVLStabloMapa<TipKljuca, TipVrijednosti> operator=(const AVLStabloMapa<TipKljuca,TipVrijednosti> &b){
        if(this == &b) return *this;
        this->obrisi();
        kopiraj(b.poc,this->poc);
        this->broj_el = b.brojElemenata();
        return *this;
    }
      TipVrijednosti& operator[](TipKljuca kljuc) override
    {

        if(broj_el == 0) {
            poc = newNodeAVL(kljuc, TipVrijednosti(), nullptr, nullptr, nullptr);
            broj_el++;
            return poc->vrijednost;
        }
        node* p = poc;
        node* q = nullptr;
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
        node* tmp = newNodeAVL(kljuc,TipVrijednosti(),nullptr,nullptr,nullptr);
        this->insert(tmp);
        return tmp->vrijednost;
    }
    TipVrijednosti operator[](TipKljuca kljuc) const
    {
        node* p = poc;
        node* q = nullptr;
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
    void obrisi(const TipKljuca &k){
        node *p=poc, *q=0;
        node *tmp=0, *pp=0, *rp=0;
        while(p!=0 && k!=p->kljuc){
            q=p;
            if(k<p->kljuc) p=p->lijevi;
            else p=p->desni;
        }
        if(p==0) throw std::logic_error("Nije pronadjen element");
        if(p->lijevi==0) rp=p->desni;
        else if(p->desni==0) rp=p->lijevi;
        else{
            pp=p;
            rp=p->lijevi;
            tmp=rp->desni;
            while(tmp!=0){
                pp=rp;
                rp=tmp;
                tmp=rp->desni;
            }
            if(pp!=p){
                pp->desni=rp->lijevi;
                rp->lijevi=p->lijevi;
                pp->roditelj=rp;
                rp->roditelj=q;
                if(pp->desni) pp->desni->roditelj=pp;
            }
            rp->desni=p->desni;
            p->desni->roditelj=rp;
        }
        if(q==0) {
            poc=rp;
            if(poc) poc->roditelj=nullptr;
        }
        else if(p==q->lijevi) {
            q->lijevi=rp;
            if(rp) rp->roditelj=q;
        }
        else {
            q->desni=rp;
            if(rp) rp->roditelj=q;
        }
        if(p->roditelj && p->roditelj->lijevi==p) p->roditelj->balans--;
        else if(p->roditelj) p->roditelj->balans++;
        delete p;
        broj_el--;
    }
    void obrisi_r(node* r)
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

    ~AVLStabloMapa()
    {
        obrisi();
    }
    
};

int main() {
// Test brisanja
AVLStabloMapa <float, float> m;
m[5] = 5;
m[3] = 3;
m[7] = 7;
m[8] = 8;
m[1] = 1;
m[2] = 2;
m[0.5] = 0.5;
m[4] = 4;
m[1.5] = 1.5;
m[3.5] = 3.5;
m[4.5] = 4.5;

// Proba
std::cout << std::setprecision(2) << m[4.5] << " ";
// Brisanje slucaj 1
m.obrisi(8);
std::cout << m[7] << " " << m[8] << " "; 
// Ovim smo ponovo dodali kljuc 8 u mapu
// Brisanje slucaj 2
m[8] = 8;
m.obrisi(7);
std::cout << m[5] << " " << m[8] << " " << m[7] << " ";
// Brisanje slucaj 3
m.obrisi(3);
std::cout << m[2] << " " << m[1.5] << " " << m[1] << " ";
std::cout << m[0.5] << " " << m[3] << " ";
// Brisanje korijena
m.obrisi(5);
m[3] = 3;
std::cout << m[8] << " " << m[1.5] << " " << m[3];
std::cout << " " << m[5] << " ";
// Da li je roditelj korektno azuriran?
m.obrisi(7);
std::cout << m[8] << " " << m[7];
    return 0;
}

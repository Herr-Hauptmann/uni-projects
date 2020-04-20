//TP 2018/2019: Zadaća 5, Zadatak 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iterator>
class Berza{
  std::vector<int> feninzi;  
  int min_cijena, max_cijena;
  public:
  Berza(int min_cijena, int max_cijena);
  explicit Berza(int max_cijena);
  void RegistrirajCijenu(int nova_cijena);
  int DajBrojRegistriranihCijena() const{
      return feninzi.size();
  }
  void BrisiSve(){ feninzi.resize(0);}
  int DajMaksimalnuCijenu() const;
  int DajMinimalnuCijenu() const;
  bool operator !() const{
     if(feninzi.size() == 0) return true;
     return false;
  }
  int DajBrojCijenaVecihOd(int n) const;
  void Ispisi() const;
  int operator [](int indeks) const;
  Berza& operator++();
  Berza operator++(int);
  Berza& operator--();
  Berza operator--(int);
  Berza operator-();
  Berza& operator+=(int y){
      *this = *this + y;
      return *this;
  }
  Berza& operator-=(int y){
      *this = *this - y;
      return *this;
  }
  Berza& operator-=(const Berza& b){
      *this = *this - b;
      return *this;
  }
friend bool operator==(const Berza& b1, const Berza& b2);
friend bool operator !=(const Berza& b1, const Berza& b2);
friend Berza operator+(const Berza& b, int y);
friend Berza operator+(int y, const Berza& b);
friend Berza operator-(const Berza& b, int y);
friend Berza operator-(int y, const Berza& b);
friend Berza operator-(const Berza& x, const Berza& y);
  
};
Berza::Berza(int min_cijena, int max_cijena){
    if(min_cijena < 0 || max_cijena < 0) throw std::range_error("Ilegalne granice cijene");
    Berza::min_cijena = min_cijena;
    Berza::max_cijena = max_cijena;
}

Berza::Berza(int max_cijena){
    if(max_cijena < 0) throw std::range_error("Ilegalne granice cijene"),
    min_cijena = 0;
    Berza::max_cijena = max_cijena;
}

void Berza::RegistrirajCijenu(int nova_cijena){
    if(nova_cijena < min_cijena || nova_cijena > max_cijena) throw std::range_error("Ilegalna cijena");
    feninzi.push_back(nova_cijena);
}

int Berza::DajMaksimalnuCijenu() const{
    if(feninzi.size() == 0) throw std::range_error("Nema registriranih cijena");
    auto p = std::max_element(feninzi.begin(),feninzi.end());
    return *p;
}

int Berza::DajMinimalnuCijenu() const{
    if(feninzi.size() == 0) throw std::range_error("Nema registriranih cijena");
    auto p = std::min_element(feninzi.begin(),feninzi.end());
    return *p;
}

int Berza::DajBrojCijenaVecihOd(int n) const{
    if(feninzi.size() == 0) throw std::range_error("Nema registriranih cijena");
    int brojac = std::count_if(feninzi.begin(),feninzi.end(),std::bind(std::greater<int>(),std::placeholders::_1,n));
    return brojac;
}

void Berza::Ispisi() const{
    std::vector<double> marke(feninzi.size());
    std::copy(feninzi.begin(),feninzi.end(),marke.begin());
    std::sort(marke.begin(),marke.end(),std::greater<double>());
    std::transform(marke.begin(),marke.end(),marke.begin(),std::bind(std::divides<double>(),std::placeholders::_1,100));
    std::copy(marke.begin(),marke.end(),std::ostream_iterator<double>(std::cout<<std::fixed<<std::setprecision(2),"\n"));
    
}

int Berza::operator[](int indeks) const{
    if(indeks > feninzi.size() || indeks < 1) throw std::range_error("Neispravan indeks");
    return feninzi.at(indeks-1);
}

Berza& Berza::operator++(){
    std::transform(feninzi.begin(),feninzi.end(),feninzi.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    if(this->DajBrojCijenaVecihOd(max_cijena) > 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(feninzi.begin(),feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,min_cijena));
    if(broj != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}

Berza Berza::operator++(int){
    Berza ret(*this);
    std::transform(feninzi.begin(),feninzi.end(),feninzi.begin(),std::bind(std::plus<int>(),std::placeholders::_1,100));
    if(this->DajBrojCijenaVecihOd(max_cijena) > 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(feninzi.begin(),feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,min_cijena));
    if(broj != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return ret;
}

Berza& Berza::operator--(){
    std::transform(feninzi.begin(),feninzi.end(),feninzi.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    if(this->DajBrojCijenaVecihOd(max_cijena) > 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(feninzi.begin(),feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,min_cijena));
    if(broj != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}

Berza Berza::operator--(int){
    Berza ret(*this);
    std::transform(feninzi.begin(),feninzi.end(),feninzi.begin(),std::bind(std::minus<int>(),std::placeholders::_1,100));
    if(this->DajBrojCijenaVecihOd(max_cijena) > 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(feninzi.begin(),feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,min_cijena));
    if(broj != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return ret;
}

Berza Berza::operator-(){
    Berza ret(*this);
    int tmp = min_cijena + max_cijena;
    std::transform(ret.feninzi.begin(),ret.feninzi.end(),ret.feninzi.begin(),std::bind(std::minus<int>(),tmp,std::placeholders::_1));
    return ret;
}

Berza operator+(const Berza& b, int y){
    Berza ret(b);
    std::transform(ret.feninzi.begin(),ret.feninzi.end(),ret.feninzi.begin(),std::bind(std::plus<int>(),std::placeholders::_1,y));
    if(ret.DajBrojCijenaVecihOd(b.max_cijena) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(ret.feninzi.begin(),ret.feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,ret.min_cijena));
    if(broj != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return ret;
}

Berza operator-(const Berza& b, int y){
    Berza ret(b);
    std::transform(ret.feninzi.begin(),ret.feninzi.end(),ret.feninzi.begin(),std::bind(std::minus<int>(),std::placeholders::_1,y));
    if(ret.DajBrojCijenaVecihOd(b.max_cijena) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(ret.feninzi.begin(),ret.feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,ret.min_cijena));
    if(broj != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return ret;
}

Berza operator-(const Berza& x, const Berza& y){
    if(x.feninzi.size() != y.feninzi.size() || x.max_cijena != y.max_cijena || x.min_cijena != y.min_cijena) throw std::domain_error("Nesaglasni operandi");
    Berza ret = x;
    std::transform(x.feninzi.begin(),x.feninzi.end(),y.feninzi.begin(),ret.feninzi.begin(),std::minus<int>());
    if(ret.DajBrojCijenaVecihOd(ret.max_cijena) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(ret.feninzi.begin(),ret.feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,ret.min_cijena));
    if(broj != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return ret;
} 

Berza operator+(int y, const Berza& b){
    return b+y;
}

Berza operator-(int y, const Berza& b){
    Berza ret(b);
    try{
    std::transform(ret.feninzi.begin(),ret.feninzi.end(),ret.feninzi.begin(),std::bind(std::minus<int>(),y,std::placeholders::_1));
    }
    catch(...){
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    }
    if(ret.DajBrojCijenaVecihOd(b.max_cijena) != 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    int broj = std::count_if(ret.feninzi.begin(),ret.feninzi.end(),std::bind(std::less<int>(),std::placeholders::_1,ret.min_cijena));
    if(broj != 0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return ret;
    
}

bool operator==(const Berza& b1,  const Berza& b2){
    if(b1.max_cijena != b2.max_cijena || b1.min_cijena != b2.min_cijena || b1.feninzi.size() != b2.feninzi.size()) return false;
    return b1.feninzi == b2.feninzi;
}

bool operator !=(const Berza& b1, const Berza& b2){
    if(b1.max_cijena != b2.max_cijena || b1.min_cijena != b2.min_cijena || b1.feninzi.size() != b2.feninzi.size()) return true;
    return b1.feninzi != b2.feninzi;
}










int main ()
{
  /*  
    Berza b(0,20);
    b.RegistrirajCijenu(0);
    Berza a(2,44);
    a.RegistrirajCijenu(4);
    try{
        a-b;
        b.Ispisi();
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    } 
   // vlastiti ATovi
    Berza b(0,20);
    Berza a(0,20);
    b.RegistrirajCijenu(1); b.RegistrirajCijenu(2); b.RegistrirajCijenu(3);
    a.RegistrirajCijenu(4); a.RegistrirajCijenu(5); a.RegistrirajCijenu(6);
    // Daj broj registriranih cijena
    std::cout<<b.DajBrojRegistriranihCijena()<<" "<<a.DajBrojRegistriranihCijena()<<std::endl;
    //Daj Max i Min cijenu
    std::cout<<b.DajMinimalnuCijenu()<<" "<<b.DajMaksimalnuCijenu()<<std::endl;
    //Daj Broj vecih od
    std::cout<<b.DajBrojCijenaVecihOd(1)<<" "<<b.DajBrojCijenaVecihOd(26)<<std::endl;
    //Brisi sve
    Berza c = b;
    c.BrisiSve();
    c.Ispisi();
    //indeksiranje
    std::cout<<b[2]<<std::endl;
    //++ prefiksni i sufiksni
    Berza d(0,100000);
    d.RegistrirajCijenu(1);
    d.RegistrirajCijenu(2);
    ++d;
    d.Ispisi();
    d++;
    d.Ispisi();
    //prefiksni i sufkisni --
    --d;
    d.Ispisi();
    d--;
    d.Ispisi();
    //unarni -
    Berza k = d;
    k = -k;
    k.Ispisi();
    // += i -= 
    d+=100;
    d.Ispisi();
    d-=100;
    d.Ispisi();
    // +, -, sa Berza i int
    d = 100 + d;
    d = d + 100;
    d = d - 100;
    d = 1000 - d;
    d.Ispisi();
    //test berza - berza
    a = a - a;
    a.Ispisi();
    // test != i ==
    Berza h = b;
    std::cout<<true;
    if(a==b) std::cout<<"zgembo";
    else if(h == b) std::cout<<"zgecet";
    else std::cout<<"hrkljus";
   // */
}
/* 
    TP 16/17 (Tutorijal 12, Zadatak 6)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
template <typename TipEl>
class Matrica {
    int br_redova, br_kolona;
    TipEl** elementi;
    char ime_matrice;
    static TipEl** AlocirajMemoriju(int br_redova, int br_kolona);
    static void DealocirajMemoriju(TipEl** elementi, int br_redova);
    void KopirajElemente(TipEl** elementi);
 
public:
    Matrica(int br_redova, int br_kolona, char ime = 0);
    Matrica(const Matrica& m);
    Matrica(Matrica&& m);
    ~Matrica() { DealocirajMemoriju(elementi, br_redova); }
    Matrica& operator=(const Matrica& m);
    Matrica& operator=(Matrica&& m);
    template<typename TipEl1>
    friend std::istream& operator>>(std::istream &tok, Matrica<TipEl1> &m);
    template<typename TipEl2>
    friend std::ostream& operator<<(std::ostream& tok, const Matrica<TipEl2> &m);
    template <typename Tip2>
    friend Matrica<Tip2> operator+(const Matrica<Tip2>& m1, const Matrica<Tip2>& m2);
    template <typename TipEl7>
    friend Matrica<TipEl7> operator-(const Matrica<TipEl7>& m1,const Matrica<TipEl7>& m2);
    template<typename Tip3>
    friend Matrica<Tip3> operator*(const Matrica<Tip3>& m1, const Matrica<Tip3>& m2);
    template<typename Tip3>
    friend Matrica<Tip3> operator*=(Matrica<Tip3>& m1, const Matrica<Tip3>& m2);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator*(Matrica<TipElemenata> &m, double skalar);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator*(double broj, const Matrica<TipElemenata> &m);
    template <typename TipElemenata>
    friend Matrica<TipElemenata> operator*=(Matrica<TipElemenata> &m, double skalar);
 
    template <typename Tip4>
    Matrica<Tip4>& operator+=(const Matrica<Tip4> m){
        *this = *this + m;
        return *this;
    }
    template <typename Tip5>
    Matrica<Tip5>& operator-=(const Matrica<Tip5> m){
        *this = *this - m;
        return *this;
    }
    TipEl* &operator[](int indeks){ return elementi[indeks];}
    TipEl* operator[](int indeks)const{ return elementi[indeks];}
    TipEl &operator()(int i, int j){
        if(i < 1 || i > this->br_redova || j < 1 || j > this->br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    TipEl operator()(int i, int j)const{
        if(i < 1 || i > this->br_redova || j < 1 || j > this->br_kolona) throw std::range_error("Neispravan indeks");
        return elementi[i-1][j-1];
    }
    operator std::string() const{
        std::string s;
        s.push_back('{');
        for(int i = 0; i < this->br_redova; i++){
            s.push_back('{');
            for(int j = 0; j < this->br_kolona; j++){
                auto el = int(elementi[i][j]);
                std::string pom = std::to_string(el);
                s+=pom;
                if(j != this-> br_kolona -1) s.push_back(',');
            }
            s.push_back('}');
            if(i!=(this->br_redova-1)) s.push_back(',');
        }
           s.push_back('}');
            return s;
    }    

    
};

template <typename TipEl>
TipEl** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
    TipEl** elementi = new TipEl* [br_redova] {};
    try {
        for (int i = 0; i < br_redova; i++)
            elementi[i] = new TipEl[br_kolona];
    }
    catch (...) {
        DealocirajMemoriju(elementi, br_redova);
        throw;
    }
    return elementi;
}
template <typename TipElemenata>
Matrica<TipElemenata> operator*(Matrica<TipElemenata> &m, double skalar){
  for(int i = 0; i<m.br_redova; i++){
   for(int j = 0; j<m.br_kolona; j++) m.elementi[i][j]*=skalar;
  }
  return m;
 }
template <typename TipElemenata>
Matrica<TipElemenata> operator*=(Matrica<TipElemenata> &m, double skalar){
  for(int i = 0; i<m.br_redova; i++){
   for(int j = 0; j<m.br_kolona; j++) m.elementi[i][j]*=skalar;
  }
  return m;
 }
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl** elementi, int br_redova)
{
    for (int i = 0; i < br_redova; i++)
        delete[] elementi[i];
    delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime)
    : br_redova(br_redova)
    , br_kolona(br_kolona)
    , ime_matrice(ime)
    , elementi(AlocirajMemoriju(br_redova, br_kolona))
{
}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl** elementi)
{
    for (int i = 0; i < br_redova; i++)
        for (int j = 0; j < br_kolona; j++)
            Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl>& m)
    : br_redova(m.br_redova)
    , br_kolona(m.br_kolona)
    , ime_matrice(m.ime_matrice)
    , elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
    KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl>&& m)
    : br_redova(m.br_redova)
    , br_kolona(m.br_kolona)
    , elementi(m.elementi)
    , ime_matrice(m.ime_matrice)
{
    m.br_redova = 0;
    m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator=(const Matrica<TipEl>& m)
{
    if (br_redova < m.br_redova || br_kolona < m.br_kolona) {
        TipEl** novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
        DealocirajMemoriju(elementi, br_redova);
        elementi = novi_prostor;
    }
    else if (br_redova > m.br_redova)
        for (int i = m.br_redova; i < br_redova; i++)
            delete elementi[i];
    br_redova = m.br_redova;
    br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice;
    KopirajElemente(m.elementi);
    return *this;
}
template <typename TipEl>
Matrica<TipEl>& Matrica<TipEl>::operator=(Matrica<TipEl>&& m)
{
    std::swap(br_redova, m.br_redova);
    std::swap(br_kolona, m.br_kolona);
    std::swap(ime_matrice, m.ime_matrice);
    std::swap(elementi, m.elementi);
    return *this;
}
 
template <typename TipEl1>
std::istream& operator>>(std::istream& tok, Matrica<TipEl1>& m)
{
    for (int i = 0; i < m.br_redova; i++)
        for (int j = 0; j < m.br_kolona; j++) {
            std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            tok >> m.elementi[i][j];
        }
        return tok;
}
template <typename TipEl>
std::ostream& operator<<(std::ostream& tok, const Matrica<TipEl>& m)
{
	int sirina_ispisa = tok.width();
    for (int i = 0; i < m.br_redova; i++) {
        for (int j = 0; j < m.br_kolona; j++)
            tok << std::setw(sirina_ispisa) << m.elementi[i][j];
        tok << std::endl;
    }
    return tok;
}
template <typename TipEl>
Matrica<TipEl> operator+(const Matrica<TipEl>& m1,const Matrica<TipEl>& m2)
{
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
     for (int i = 0; i < m1.br_redova; i++)
        for (int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = 0;
    for (int i = 0; i < m1.br_redova; i++)
        for (int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}
template <typename TipEl>
Matrica<TipEl> operator-(const Matrica<TipEl>& m1,const Matrica<TipEl>& m2)
{
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
        throw std::domain_error("Matrice nemaju jednake dimenzije!");
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for (int i = 0; i < m1.br_redova; i++)
        for (int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = 0;
    for (int i = 0; i < m1.br_redova; i++)
        for (int j = 0; j < m1.br_kolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
    return m3;
}
template <typename Tip3>
Matrica<Tip3> operator*(const Matrica<Tip3>& m1, const Matrica<Tip3>& m2){
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  Matrica<Tip3> m3(m1.br_redova,m2.br_kolona,'C');
  for(int i = 0; i<m1.br_redova; i++){
   for(int j = 0; j<m2.br_kolona; j++){
    m3.elementi[i][j]=0;
    for(int k = 0; k<m2.br_redova; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
   }
  }
  return m3;
 }
 template <typename Tip3>
Matrica<Tip3> operator*=(Matrica<Tip3>& m1, const Matrica<Tip3>& m2){
    if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  Matrica<Tip3> m3(m1.br_redova,m2.br_kolona,'C');
  for(int i = 0; i<m1.br_redova; i++){
   for(int j = 0; j<m2.br_kolona; j++){
    m3.elementi[i][j]=0;
    for(int k = 0; k<m2.br_redova; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
   }
  }
  m1 = m3;
  return m1;
 }

 template <typename TipElemenata>
Matrica<TipElemenata> operator*(double broj, const Matrica<TipElemenata> &m){
    Matrica<TipElemenata> m3(m.br_redova,m.br_kolona);
    for(int i = 0; i < m.br_redova; i++)
    for(int j = 0; j < m.br_kolona; j++)
    m3.elementi[i][j] = 0;
    
    for(int i = 0; i < m.br_redova; i++)
    for(int j = 0; j < m.br_kolona; j++)
    m3.elementi[i][j]=broj*m.elementi[i][j];
    
    return m3;
}

int main()
{
  //AT 5 testiranje izraza koji kombinuje više operatora, unosa i ispisa
  int m,n;
  std::cout << "Unesi broj redova i kolona za matrice:\n";
  std::cin >> m >> n;
  try {
    Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    std::cout << "Unesi matricu A:\n";
    std::cin >> a;
    std::cout << "Unesi matricu B:\n";
    std::cin >> b;
   a= (a + b) * ((3 * a) - b);
 
std::cout << std::setw(4) << a;
  }
catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
  }
    catch(std::domain_error e) {
    std::cout << e.what();
  }
    catch(std::range_error e) {
    std::cout << e.what();
  }
    return 0;
}
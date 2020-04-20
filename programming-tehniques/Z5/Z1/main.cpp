//TP 2018/2019: Zadaća 5, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <list>
#include <utility>
template <typename TipEl, template <typename...> class Kontejner = std::vector>
 class Tok {
 Kontejner<TipEl> kolekcija;
 public:
 template <typename TipEl2, template <typename...> class Kontejner2>
 friend class Tok; // Stvara prijateljstvo između različitih vrsta tokova
 //Konstruktor 1
 template <typename IterTip>
 Tok(IterTip pocetak, const IterTip iza_kraja){
  std::copy(pocetak,iza_kraja,std::back_inserter(kolekcija));
 }
 //
 //Konstruktor 2
 template <typename IterabilniKontejner>
 Tok(const IterabilniKontejner &kontejner){
 std::copy(std::begin(kontejner),std::end(kontejner),std::back_inserter(kolekcija));
 }
 //
 //Konstruktor 3
 Tok(std::initializer_list<TipEl> lista){
   std::copy(std::begin(lista),std::end(lista),std::back_inserter(kolekcija));

 }
 //
 //Metoda Opseg
 static Tok<TipEl, Kontejner> Opseg(TipEl poc, TipEl kraj, TipEl korak = 1){
  Tok<TipEl, Kontejner> ret{};
  for(auto p = poc; p <= kraj; p=p+korak){
   ret.kolekcija.insert(std::end(ret.kolekcija),p);
  }
  return ret;
 }
 //
 //Metoda Velicina
 unsigned int Velicina() const{
  unsigned int velicina = 0;
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) velicina++;
  return velicina;
 }
 //
 //Metoda Prazan
 bool Prazan() const{
  if(this->Velicina() == 0) return true;
  return false;
 }
 //
 //Metoda Limitraj
 Tok<TipEl, Kontejner> Limitiraj(unsigned int n) const{
  Tok<TipEl, Kontejner> ret{};
  if(n > this->Velicina()){ 
   ret = *this;
   return ret;}
  int brojac = 0;
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++){
   if(brojac == n) break;
   ret.kolekcija.insert(std::end(ret.kolekcija),*p);
   brojac++;
  }
  return ret;
 }
 //
 //Metoda Preskoci
 Tok<TipEl, Kontejner> Preskoci(unsigned int n) const{
  Tok<TipEl, Kontejner> ret{};
  if(n > this->Velicina()) return ret;
  auto p = std::begin(kolekcija);
  for(int i = 0; i < n; i++) p++;
  for(p; p != std::end(kolekcija); p++) ret.kolekcija.insert(std::end(ret.kolekcija),*p);
  return ret;
 }
 //
 //Metoda obrnut
 Tok<TipEl, Kontejner> Obrnut() const{
  Tok<TipEl,Kontejner> obrnut{};
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) obrnut.kolekcija.insert(std::begin(obrnut.kolekcija),*p);
  return obrnut;
 }
 //
 //Metoda Akcija
 Tok<TipEl, Kontejner> Akcija(std::function<void(void)> akcija) const{
  akcija();
  auto ret = *this;
  return ret;
 }
 //
 //Metoda ZaSvaki
 void ZaSvaki(std::function<void(TipEl)> akcija) const{
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) akcija(*p);
 }
 //
 //Metoda Filtriraj
 Tok<TipEl, Kontejner> Filtriraj(std::function<bool(TipEl)> predikat) const{
  Tok<TipEl, Kontejner> ret{};
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++){
   if(predikat(*p)) ret.kolekcija.insert(std::end(ret.kolekcija),*p);
  }
  return ret;
 }
 //
 //Metoda PronadjiPrvi
 TipEl PronadjiPrvi() const{
  if(this->Velicina() == 0) throw std::logic_error("Tok je prazan");
  auto p = std::begin(kolekcija);
  return *p;
 }
 //
 //Metoda PronadjiPosljednji
 TipEl PronadjiPosljednji() const{
  if(this->Velicina() == 0) throw std::logic_error("Tok je prazan");
  auto p = std::begin(kolekcija);
  for(int i = 0; i < this->Velicina()-1; i++) p++;
  return *p;
 }
 //
 //Metoda ZadovoljavaBaremJedan
 bool ZadovoljavaBaremJedan(std::function<bool(TipEl)> kriterij) const{
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) if(kriterij(*p)) return true;
  return false;
 }
 //
 //Metoda ZadovoljavaNijedan
 bool ZadovoljavaNijedan(std::function<bool(TipEl)> kriterij) const{
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) if(kriterij(*p)) return false;
  return true;
 }
 //
 //Metoda ZadovoljavajuSvi
 bool ZadovoljavajuSvi(std::function<bool(TipEl)> kriterij) const{
   for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) if(!kriterij(*p)) return false;
   return true;
 }
 //
 //Metoda Akumuliraj
 TipEl Akumuliraj(TipEl inicijalna, std::function<TipEl(TipEl, TipEl)> akumulator) const{
  if(this->Velicina() == 0) return inicijalna;
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) inicijalna = akumulator(inicijalna,*p);
  return inicijalna;
 }
 //
 //Metoda Akumuliraj 2
 TipEl Akumuliraj(std::function<TipEl(TipEl, TipEl)> akumulator) const{
  if(this->Velicina() == 0) throw std::logic_error("Tok je prazan");
  auto p = std::begin(kolekcija);
  TipEl ak = *p;
  p++;
  for(p; p != std::end(kolekcija); p++){
   ak = akumulator(ak,*p);
  }
  return ak;
 }
 //
 //Metida Sortirano
 Tok<TipEl, Kontejner> Sortirano(std::function<bool(TipEl, TipEl)> komparator
 = [](TipEl x, TipEl y) { return x < y; }) const{
  Tok<TipEl, Kontejner> ret = *this;
  std::sort(std::begin(ret.kolekcija),std::end(ret.kolekcija),komparator);
  return ret;
 }
 //
 //Metoda Unikatno
 Tok<TipEl, Kontejner> Unikatno(std::function<bool(TipEl, TipEl)> komparator
 = [](TipEl x, TipEl y) { return x == y; }) const{
  Tok<TipEl, Kontejner> ret{};
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++){
   bool duplikat = false;
   for(auto q = std::begin(ret.kolekcija); q != std::end(ret.kolekcija); q++){
    if(*q == *p){
     duplikat = true;
     break;
    }
   }
   if(!duplikat) ret.kolekcija.insert(std::end(ret.kolekcija),*p);
  }
  return ret;
 }
 //
 //Metoda Proviri
 Tok<TipEl, Kontejner> Proviri(std::function<void(TipEl)> akcija) const{
  auto ret = *this;
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) akcija(*p);
  return ret;
 }
 //
 //Metoda Minimalan
 TipEl Minimalan(std::function<bool(TipEl, TipEl)> komparator
 = [](TipEl x, TipEl y) { return x < y; }) const{
  if(this->Velicina() == 0) throw std::logic_error("Tok je prazan");
  auto p = std::min_element(std::begin(kolekcija),std::end(kolekcija),komparator);
  return *p;
 }
 //
 //Metoda Maksimalan
 TipEl Maksimalan(std::function<bool(TipEl, TipEl)> komparator = [](TipEl x, TipEl y) { return x > y; }) const{
  if(this->Velicina() == 0) throw std::logic_error("Tok je prazan");
  auto p = std::min_element(std::begin(kolekcija),std::end(kolekcija),komparator);
  return *p;
 }
 //
 //Metoda Sakupi
 template <typename Kont2>
 Kont2 Sakupi(std::function<void(Kont2 &, TipEl)> kombinator) const{
  Kont2 kont;
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) kombinator(kont,*p);
  return kont;
 }
 //
 //Metoda Mapiraj
 template <typename TipEl2>
 Tok<TipEl2, Kontejner> Mapiraj(std::function<TipEl2(TipEl)> maper) const{
  Tok<TipEl2, Kontejner> ret{};
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++) ret.kolekcija.insert(std::end(ret.kolekcija),maper(*p));
  return ret;
 }
 //
 //Metoda MapirajPoravnato
 template <typename TipEl2>
 Tok<TipEl2, Kontejner> MapirajPoravnato(std::function<Tok<TipEl2, Kontejner>(TipEl)> maper) const{
  Tok<TipEl2, Kontejner> ret{};
  for(auto p = std::begin(kolekcija); p != std::end(kolekcija); p++){
   auto tmp = maper(*p);
   for(auto q = std::begin(tmp.kolekcija); q != std::end(tmp.kolekcija); q++) ret.kolekcija.insert(std::end(ret.kolekcija),*q);
  }
  return ret;
 }
 };
 


int main (){



	return 0;
}
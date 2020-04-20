#include <iostream>
#include <vector>
#include <string>
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

// klasa Matrica
template <typename TipOznake>
class MatricaGraf: public UsmjereniGraf<TipOznake>{
    struct PodaciGrane {
        TipOznake oznaka;
        float tezina;
        bool postoji;
    };
    std::vector<std::vector<PodaciGrane> > matrica;
    std::vector<TipOznake> oznakeCvorova;
    public:
    MatricaGraf(int brojCvorova): UsmjereniGraf<TipOznake>(brojCvorova) {
        oznakeCvorova.resize(brojCvorova, TipOznake());
        PodaciGrane nepostojeca;
        nepostojeca.postoji = false;
        matrica.resize(brojCvorova);
        for(int i = 0; i < brojCvorova; i++) matrica[i].resize(brojCvorova, nepostojeca);
    }
    

    int dajBrojCvorova() const{
        return matrica.size();
    }
    void postaviBrojCvorova(int brojCvorova){
        if(brojCvorova < matrica.size()) throw "Greska, ne moze se smanjiti broj cvorova";
        oznakeCvorova.resize(brojCvorova);
        PodaciGrane nepostojeca;
        nepostojeca.postoji = false;
        
        for(int i = 0; i < matrica.size(); i++)
         matrica[i].resize(brojCvorova, nepostojeca);
        
        std::vector<PodaciGrane> prazanRed(brojCvorova, nepostojeca);
        matrica.resize(brojCvorova, prazanRed);
    }

    void dodajGranu(int polazni, int dolazni, float tezina){
        PodaciGrane g;
        g.tezina = tezina;
        g.postoji = true;
        matrica[polazni][dolazni] = g;
    }
    void obrisiGranu(int polazni, int dolazni){
        matrica[polazni][dolazni].postoji = false;
    }
    void postaviTezinuGrane(int polazni, int dolazni, float tezina){
        matrica[polazni][dolazni].tezina = tezina;
    }
    float dajTezinuGrane(int polazni, int dolazni){
        return matrica[polazni][dolazni].tezina;
    }
    bool postojiGrana(int polazni, int dolazni){
        return matrica[polazni][dolazni].postoji;
    }

    void postaviOznakuCvora(int cvor, TipOznake oznaka){
        oznakeCvorova[cvor] = oznaka;
    }
    TipOznake dajOznakuCvora(int cvor) const{
        return oznakeCvorova[cvor];
    }

    void postaviOznakuGrane(int polazni, int dolazni, TipOznake oznaka){
        matrica[polazni][dolazni].oznaka = oznaka;
    }
    TipOznake dajOznakuGrane(int polazni, int dolazni) const{
        return matrica[polazni][dolazni].oznaka;
    }
    
    GranaIterator<TipOznake> dajSjedecuGranu(int polazni, int dolazni){
        for(int i = polazni; i < matrica.size(); i++){
            for(int j = 0; j < matrica.size(); j++){
            if(i == polazni && j <= dolazni) continue;
            if(matrica[i][j].postoji) return GranaIterator<TipOznake> (this, i, j);
            }
        }
        return GranaIterator<TipOznake> (this, -1, -1);
    }
    GranaIterator<TipOznake> dajGranePocetak(){
        GranaIterator<TipOznake> it(this, 0, -1);
        return ++it;
    }
    GranaIterator<TipOznake> dajGraneKraj(){
     GranaIterator<TipOznake> it(this, -1, -1);
     return it;
    }
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


int main()
{
  UsmjereniGraf<std::string> *g = new MatricaGraf<std::string>(4);
  g->dodajGranu(0, 1, 2.5);
  g->dodajGranu(1, 2, 1.2);
  g->dodajGranu(1, 3, 0.1);
  g->dodajGranu(3, 3, -4.0);
  g->postaviOznakuGrane(3, 3, "aa");
  g->dajGranu(0,1).postaviOznaku("bb");
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (g->postojiGrana(i,j))
        std::cout << "(" << i << "," << j << ") -> '" << g->dajOznakuGrane(i, j) << "','" << g->dajGranu(i, j).dajOznaku() << "'; ";
  delete g;
  return 0;
}

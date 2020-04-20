//TP 2018/2019: Zadaća 5, Zadatak 6
#include <iostream>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <functional>
template <typename TipElemenata>
 class DatotecniKontejner {
 std::fstream tok;

 public:
 DatotecniKontejner(const std::string &ime_datoteke):tok(ime_datoteke, std::ios::binary | std::ios::out | std::ios::ate){
     tok.close();
     tok.open(ime_datoteke,std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
     if(tok.bad()) throw std::logic_error("Problemi prilikom otvaranja ili kreiranja datoteke");
 }
 int DajVelicinu(){
     tok.seekg(0,std::ios::end);
     return tok.tellg();
 }
 void DodajNoviElement(const TipElemenata &element){
     TipElemenata e = element;
     if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
     tok.seekp(0,std::ios::end);
     tok.write(reinterpret_cast<char*>(&e),sizeof e);
     tok.flush();
     if(tok.bad()) throw std::logic_error("Problemi prilikom pristupa datoteci");
     tok.seekg(0,std::ios::cur);
     tok.seekp(0,std::ios::beg);
 }
 int DajBrojElemenata(){
     if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
     tok.seekg(0,std::ios::end);
     int velicina = tok.tellg();
     tok.seekg(0,std::ios::end);
     return velicina / sizeof(TipElemenata);
 }
 TipElemenata DajElement(int pozicija){
     if(pozicija < 0 || pozicija > DajBrojElemenata()-1) throw std::range_error("Neispravna pozicija");
     TipElemenata e;
     tok.seekg(pozicija*sizeof(TipElemenata),std::ios::beg);
     tok.read(reinterpret_cast<char*>(&e),sizeof e);
     if(tok.bad()) throw std::logic_error("Problemi prilikom pristupa datoteci");
     return e;
 }
 void IzmijeniElement(int pozicija, const TipElemenata &element){
     if(pozicija < 0 || pozicija > DajBrojElemenata()-1) throw std::range_error("Neispravna pozicija");
     if(!tok) throw std::logic_error("Problemi prilikom pristupa datoteci");
     TipElemenata e = element;
     tok.seekp(pozicija*sizeof(element), std::ios::beg);
     tok.write(reinterpret_cast<char*>(&e), sizeof e);
     if(tok.bad()) throw std::logic_error("Problemi prilikom pristupa datoteci");
     
 }
 void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata &)>kriterij = std::less<TipElemenata>()){
     for(int i = 0; i < DajBrojElemenata() - 1; i++){
         TipElemenata x;
         TipElemenata y;
         for(int j = i; j < DajBrojElemenata(); j++){
         x = DajElement(i);
         y = DajElement(j);
         if(!kriterij(x,y)){
             IzmijeniElement(j,x); IzmijeniElement(i,y);
         }
         }
         
     }
 }
 };


int main ()
{
   
	return 0;
}
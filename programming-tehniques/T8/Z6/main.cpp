//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>
template<typename TipElementa>
struct Cvor {
    TipElementa element;
    Cvor* veza;
};
template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni)
{
    Cvor<TipElemenata>* pocetak = nullptr, *prethodni;
    while(1) {
        TipElemenata broj;
        std::cin>>broj;
        if(broj==zavrsni) break;
        Cvor<TipElemenata>* novi = new Cvor<TipElemenata> {broj,nullptr};
        if(!pocetak) pocetak = novi;
        else  prethodni->veza=novi;
         prethodni = novi;
        
    }
    return pocetak;
}
template <typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak)
{
    int brojac=0;
    for(auto p = pocetak; p!=nullptr; p=p->veza) brojac++;
    return brojac;
}
template <typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak)
{
    TipElemenata suma{};
    for(auto p = pocetak; p!=nullptr; p=p->veza) suma=suma + p->element;
    return suma;
}
template <typename TipElemenata>
int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag)
{
    int brojac=0;
    for(auto p = pocetak; p!=nullptr; p=p->veza) if(p->element>prag) brojac++;
    return brojac;
}
template <typename TipElemenata>
void UnistiListu(Cvor<TipElemenata> *pocetak)
{
    int brojac=0;
    Cvor<TipElemenata>* kraj = nullptr;
    if(pocetak==nullptr) return;
   
    bool flag = true;
    for(auto p = pocetak; p!=nullptr; p=p->veza ) {
        if(flag) {
            flag=false;
            kraj = p;
        } else {
            delete kraj;
            kraj = p;
        }
    }
    delete kraj;
}


    int main () {
        std::cout<<"Unesite slijed brojeva (0 za kraj): ";
        auto p = KreirajPovezanuListu<double>(0);
        std::cout<<"U slijedu ima "<<BrojVecihOd(p,double(SumaElemenata(p)/BrojElemenata(p)))<<" brojeva vecih od njihove aritmeticke sredine";
        UnistiListu(p);
        return 0;
    }

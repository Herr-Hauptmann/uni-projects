//TP 2018/2019: Zadaća 3, Zadatak 5
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
struct Dijete{
    std::string ime;
    Dijete* sljedeci=nullptr;
};
Dijete *KreirajPovezanuListu(std::vector<std::string> dica){
    Dijete* pocetak = nullptr, *prethodni;
    int n = dica.size();
    for(int i = 0; i<n; i++){
        Dijete* novi = new Dijete;
        novi->ime = dica.at(i);
        if(!pocetak) pocetak = novi;
        else prethodni->sljedeci = novi;
        prethodni = novi;
    }
    prethodni->sljedeci = pocetak;
    return pocetak;
}
int DuzinaImena(std::string s){
    int brojac=0;
    for(int i = 0; i<s.length(); i++){
        if(s.at(i)>='a'&&s.at(i)<='z' || s.at(i)>='A'&&s.at(i)<='Z' || s.at(i)>='0'&&s.at(i)<='9') brojac++;
    }
    return brojac;
}

void IspisiDicu(std::vector<std::set<std::string>> dica){
    for(int i = 0; i<dica.size(); i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto p = dica.at(i).begin(); p!=dica.at(i).end(); p++){
            if(p==dica.at(i).begin()) std::cout<<*p;
            else std::cout<<", "<<*p;
            }
            std::cout<<std::endl;
    }
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djeca, int k){
    if(k<=0 || k>djeca.size()) throw std::logic_error("Razvrstavanje nemoguce");
    int n = djeca.size();
    auto pok_lista = KreirajPovezanuListu(djeca);
    std::vector<std::set<std::string>> timovi;
    timovi.resize(k);
    if(n%k==0){
        auto p = pok_lista;
        auto kraj = p;
        for(int i = 0; i<n-1; i++) kraj=kraj->sljedeci;
        Dijete* prethodni = nullptr;
        for(int i = 0; i<k; i++){
            for(int j = 0; j<n/k; j++){
                timovi.at(i).insert(p->ime);
                 int duzina = DuzinaImena(p->ime);
                 if(!prethodni){
                     kraj->sljedeci = p->sljedeci;
                     delete p;
                     p=kraj->sljedeci;
                 }
                 else{
                     if(prethodni!=p){
                     prethodni->sljedeci = p->sljedeci,
                     delete p;
                     p=prethodni->sljedeci;
                     }
                     else{ 
                         delete p;
                         p=nullptr;
                     }
                 }
                 for(int q = 0; q<duzina-1; q++){
                     if(p!=nullptr){
                    prethodni = p;
                     p=p->sljedeci;
                     }
                 }
            }
        }
    }
    else{
        auto p = pok_lista;
        auto kraj = p;
        for(int i = 0; i<n-1; i++) kraj=kraj->sljedeci;
        
        int i = 0;
        Dijete* prethodni = nullptr;
        for(i; i<n%k; i++){
            for(int j = 0; j<n/k+1; j++){
                timovi.at(i).insert(p->ime);
                int duzina = DuzinaImena(p->ime);
               if(!prethodni){
                   kraj->sljedeci=p->sljedeci;
                   delete p;
                   p=kraj->sljedeci;
               }
               else{
                   if(p!=prethodni){
                       prethodni->sljedeci=p->sljedeci;
                       delete p;
                       p=prethodni->sljedeci;
                   }
                   else{
                       delete p;
                       p=nullptr;
                   }
               }
               for(int q = 0; q<duzina-1; q++){
                   if(p!=nullptr){
                       prethodni=p;
                       p=p->sljedeci;
                   }
               }

            }
        }
        for(int v = 0; v<k-(n%k); v++){
            for(int j = 0; j<n/k; j++){
                timovi.at(v+i).insert(p->ime);
                int duzina = DuzinaImena(p->ime);
               if(p!=prethodni){
                   prethodni->sljedeci=p->sljedeci;
                   delete p;
                   p=prethodni->sljedeci;
               }
               else{
                   delete p;
                   p=nullptr;
               }
               for(int q = 0; q<duzina-1; q++){
                   if(p!=nullptr){
                       prethodni=p;
                       p=p->sljedeci;
                   }
               }

            }
        } 
    }
    return timovi;

}
int main ()
{
    std::cout<<"Unesite broj djece: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite imena djece: ";
    std::vector<std::string> djeca(n);
    std::cin.ignore(1000,'\n');
    for(int i = 0; i<n; i++){
        std::getline(std::cin,djeca.at(i));
    }
    std::cout<<std::endl<<"Unesite broj timova: ";
    int k;
    std::cin>>k;
    std::vector<std::set<std::string> > timovi;
    try{
    timovi = Razvrstavanje(djeca,k);
    }
    catch(std::logic_error e){
        std::cout<<"Izuzetak: "<<e.what();
        return 0;
    }
    IspisiDicu(timovi);
    
	return 0;
}
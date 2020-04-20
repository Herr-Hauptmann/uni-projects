//TP 2018/2019: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <stdexcept>
#include <list>
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
    std::list<std::string> lista(djeca.size());
    int r = 0;
    for(auto p = lista.begin(); p!=lista.end(); p++,r++) *p = djeca.at(r);
    std::vector<std::set<std::string>> timovi;
    timovi.resize(k);
    if(n%k==0){
        auto p = lista.begin();
        for(int i = 0; i<k; i++){
            for(int j = 0; j<n/k; j++){
                timovi.at(i).insert(*p);
                 int duzina = DuzinaImena(*p);
                 auto q = p;
                 p++;
                lista.erase(q);

                 for(int h = 0; h<duzina-1; h++){
                     if(p==lista.end()) p=lista.begin();
                     p++;
                 }
                 if(p==lista.end()) p=lista.begin();

            }
        }
    }
    else{
        auto p = lista.begin();
        int i = 0;
        for(i; i<n%k; i++){
            for(int j = 0; j<n/k+1; j++){
                timovi.at(i).insert(*p);
                int duzina = DuzinaImena(*p);
                auto q = p;
                p++;
                lista.erase(q);
                for(int h = 0; h<duzina-1; h++){
                    if(p==lista.end()) p = lista.begin();
                    p++;
                }
                if(p==lista.end()) p = lista.begin();

            }
        }
        for(int v = 0; v<k-(n%k); v++){
            for(int j = 0; j<n/k; j++){
                timovi.at(v+i).insert(*p);
                int duzina = DuzinaImena(*p);
                 auto q = p;
                 p++;
                lista.erase(q);

                 for(int h = 0; h<duzina-1; h++){
                     if(p==lista.end()) p=lista.begin();
                     p++;
                 }
                 if(p==lista.end()) p=lista.begin();

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
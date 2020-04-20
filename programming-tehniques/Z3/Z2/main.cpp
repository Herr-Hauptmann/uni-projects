//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <set>
bool JeLiSB(char c)
{
    if(c>='a'&&c<='z' || c>='A'&&c<='Z' || c>='0'&&c<='9') return true;
    return false;
}
std::string SpustiDole(std::string s)
{
    for(int i = 0; i<s.length(); i++) {
        if(s.at(i)>='A'&&s.at(i)<='Z') s.at(i)+=32;
    }
    return s;
}

void IspisiIndeksPojmova(const std::map<std::string,std::set<int>>& mapa)
{
    if(mapa.size()==0) std::cout<<"Neispravna";
    for(auto p = mapa.begin(); p!=mapa.end(); p++) {
        std::cout<<p->first<<":";
        for(auto p1 = p->second.begin(); p1!=p->second.end(); p1++) {
            if(p1==p->second.begin()) std::cout<<" "<<*p1;
            else std::cout<<","<<*p1;
        }
        std::cout<<std::endl;
    }
}
std::set<int> PretraziIndeksPojmova(std::string s, const std::map<std::string,std::set<int>> &mapa)
{
    std::set<int> ret;
    if(!mapa.count(s)) throw std::logic_error("Pojam nije nadjen");
    else ret = mapa.at(s);
    return ret;

}

std::map<std::string,std::set<int>> KreirajIndeksPojmova(std::string s)
{
    std::map<std::string,std::set<int>> mapa;
    bool razmak=true;
    for(int i = 0; i<s.length(); i++) {
        if(razmak==true) {
            razmak=false;
            std::string buffer;
            int j = i;
            for(j; j<s.size(); j++) {
                if(!JeLiSB(s.at(j))) break;
                buffer.push_back(s.at(j));
            }
            buffer=SpustiDole(buffer);
            if(buffer!="") mapa[SpustiDole(buffer)].insert(i);
        }
        if(!(JeLiSB(s.at(i)))) razmak=true;
    }
    return mapa;
}

int main ()
{
    std::cout<<"Unesite tekst: ";
    std::string s;
    std::getline(std::cin,s);
    auto mapa = KreirajIndeksPojmova(s);
    IspisiIndeksPojmova(mapa);
    for(;;) {
        std::string trazi;
        std::cout<<"Unesite rijec: ";
        std::cin>>trazi;
        if(trazi==".") break;
        try {
            auto skup = PretraziIndeksPojmova(SpustiDole(trazi),mapa);
            for(auto p = skup.begin(); p!=skup.end(); p++) {
                if(p==skup.begin()) std::cout<<*p;
                else std::cout<<" "<<*p;
            }
            std::cout<<std::endl;
        } catch(...) {
            std::cout<<"Unesena rijec nije nadjena!"<<std::endl;
        }
    }

    return 0;
}

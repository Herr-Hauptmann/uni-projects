//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
std::string UpperCase(std::string s){
    for(int i = 0; i<s.size(); i++){
        if(s.at(i)>='a'&& s.at(i)<='z') s.at(i) -=32;
    }
    return s;
}

void ZadrziDuplikate(std::vector<std::string> &v){
    for(int i = 0; i<v.size(); i++){
        bool duplikat = false;
        for(int j = i+1; j<v.size(); j++){
            if(v.at(i)==v.at(j)){
                duplikat = true;
                for(int k = j; k<v.size()-1; k++){
                    v.at(k) = v.at(k+1);
                }
                v.resize(v.size()-1);
                j--;
            }
        }
        if(!duplikat){
            for(int j = i; j<v.size() - 1; j++) v.at(j) = v.at(j+1);
            v.resize(v.size()-1);
            i--;
        }
    }
}

void IzdvojiKrajnjeRijeci(std::vector<std::string> &rijeci, std::string &najveci, std::string &najmanji ){
    if(rijeci.size()==0){
        najveci = std::string("");
        najmanji=std::string("");
        return;
    }
    std::string max = rijeci.at(0);
    std::string min = rijeci.at(0);
    for(int i = 1; i<rijeci.size(); i++){
        if(UpperCase(rijeci.at(i)) > UpperCase(min)) min = rijeci.at(i);
        if(UpperCase(max) > UpperCase(rijeci.at(i))) max = rijeci.at(i);
        }
        najveci = max;
        najmanji = min;
}

int main ()
{
    std::vector<std::string> s;
    std::cout<<"Koliko zelite unijeti rijeci: ";
    int n;
    std::cin>>n;
    std::cout<<"Unesite rijeci: "<<std::endl;
    s.resize(n);
    for(int i = 0; i<n; i++){
        std::cin>>s.at(i);
    }
    std::string prva;
    std::string zadnja;
    IzdvojiKrajnjeRijeci(s,prva,zadnja);
    std::cout<<"Prva rijec po abecednom poretku je: "<<prva<<std::endl;
    std::cout<<"Posljednja rijec po abecednom poretku je: "<<zadnja<<std::endl;
    std::cout<<"Rijeci koje se ponavljaju su:";
    ZadrziDuplikate(s);
    for(int i = 0; i<s.size(); i++) std::cout<<" "<<s.at(i);
    
    
    
	return 0;
}
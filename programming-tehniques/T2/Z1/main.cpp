//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

bool DaLiJeProst(long n)
{
    bool prost = true;
    if(n<=1) return false;
    for(unsigned long i = 2; i<=sqrt(n); i++) {
        if(n%i==0) {
            prost = false;
            break;
        }
    }

    return prost;
}

std::vector<int> ProstiBrojeviUOpsegu(long a, long b)
{
    std::vector<int> v;
    for(long i = a; i<=b; i++) {
        if(DaLiJeProst(i)) {
            v.push_back(i);
        }
    }

    return v;
}




int main ()
{
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    long a, b;
    //std::cout<<DaLiJeProst(11);
    std::cin>>a>>b;
    auto v = ProstiBrojeviUOpsegu(a,b);
    if(v.size() == 0) {
        std::cout<<"Nema prostih brojeva u rasponu od "<<a<<" do "<<b<<"!";
    } else {
        std::cout<<"Prosti brojevi u rasponu od "<<a<<" do "<<b<<" su: ";
        for(unsigned long i=0; i<v.size(); i++) {
            if(i==v.size()-1) std::cout<<v[i]<<std::endl;
            else std::cout<<v[i]<<", ";
        }
    }
    return 0;
}

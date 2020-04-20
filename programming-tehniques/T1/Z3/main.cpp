//TP 2016/2017: Tutorijal 1, Zadatak 3
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    int a,b;
    std::cout<<"Unesite pocetnu i krajnju vrijednost: ";
    std::cin>>a>>b;
    std::cout<<std::endl;
    int visina = b - a;
    std::cout<<"+---------+----------+----------+-----------+";
    std::cout<<std::endl;
    std::cout<<"| Brojevi | Kvadrati | Korijeni | Logaritmi |";
    std::cout<<std::endl;
    std::cout<<"+---------+----------+----------+-----------+";
    std::cout<<std::endl;


    for(int i = 0; i<=visina; i++) {
        for(int j = 0; j<4; j++) {
            if(j==0) std::cout<<"| "<<std::setw(8)<<std::left<<a<<"|";
            if(j==1){
            std::cout<<std::setw(9)<<std::right<<std::setprecision(4)<<a*a;
            std::cout<<" |";
            }
             if(j==2){
            std::cout<<std::setw(9)<<std::right<<std::fixed<<std::setprecision(3)<<sqrt(a);
            std::cout<<" |";
            }
             if(j==3){
            std::cout<<std::setw(10)<<std::right<<std::fixed<<std::setprecision(5)<<log(a);
            std::cout<<" |";
            }
        }
        a++;
        std::cout<<std::endl;
    }
    std::cout<<"+---------+----------+----------+-----------+";

    return 0;
}

//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>
#include <sstream>
int republikaGrcka(double a)
{
    double suma=0;
    int x = a;
    for(int i=1; i<x; i++) {
        if(x%i==0) suma+=i;
    }
    if(abs(suma-a)<0.00001) return 0;
    else if(suma-a>0.00001) return 1;
    else return -1;
}


int main()
{
    double broj;
    while(1) {
        std::cout<<"Unesite prirodan broj ili 0 za kraj: ";
        std::cin>>broj;
        if(broj<0 || !(std::cin) || (broj-int(broj)>0.000001)) {
            std::cout<<"Niste unijeli prirodan broj!"<<std::endl;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            continue;
        }
        if(broj==0) {
            std::cout<<"Dovidjenja!";
            break;
        }

        if(republikaGrcka(broj) == 0) std::cout<<"Broj "<<broj<<" je savrsen!"<<std::endl;
        if(republikaGrcka(broj) == 1) std::cout<<"Broj "<<broj<<" je obilan!"<<std::endl;
        if(republikaGrcka(broj) == -1) std::cout<<"Broj "<<broj<<" je manjkav!"<<std::endl;


    }



    return 0;
}

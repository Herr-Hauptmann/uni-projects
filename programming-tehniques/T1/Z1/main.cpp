//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    int duzina, sirina, dubina, promjer,brojPlocica;
    std::cout<<"Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin>>duzina>>sirina>>dubina;
    std::cout<<"Unesite sirinu plocice u centimetrima: ";
    std::cin>>promjer;
    std::cout<<std::endl;
    if(((duzina*100)%promjer)==0 && ((sirina*100)%promjer)==0 && ((dubina*100)%promjer)==0 ) {
        brojPlocica=(duzina*sirina*10000)/(promjer*promjer) + 2*((duzina*dubina*10000)/(promjer*promjer)) + 2*((dubina*sirina*10000)/(promjer*promjer));
        std::cout<<"Za poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m"<<" sa plocicama dimenzija "<<promjer<<"x"<<promjer<<"cm"<<std::endl<<"potrebno je "
                 <<brojPlocica<<" plocica."<<std::endl;

    } else std::cout<<"Poplocavanje bazena dimenzija "<<duzina<<"x"<<sirina<<"x"<<dubina<<"m"<<" sa plocicama dimenzija "<<promjer<<"x"<<promjer<<"cm"<<std::endl
                        <<"nije izvodljivo bez lomljenja plocica!"<<std::endl;
    return 0;
}

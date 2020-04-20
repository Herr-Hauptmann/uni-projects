//TP 2017/2018: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>
#include <stdexcept>
int NijeRazmak(char c)
{
    if(c!=' ') return 1;
    else return 0;
}
std::string IzdvojiRijec(std::string s, int redni_broj)
{
    int razmak = 1, trenutna_rijec=0;
    std::string povratna_rijec;

    for(int i = 0; i<s.size(); i++) {
        if(NijeRazmak(s[i]) && razmak==1) {
            razmak=0;
            trenutna_rijec++;
            if(trenutna_rijec==redni_broj) {

                int j = i;
                while(s[j]!=' ' && j<s.size()) {
                    povratna_rijec.push_back(s[j]);
                    j++;
                }
                return povratna_rijec;
            }
        }
        if(s[i]==' ') razmak = 1;

    }
    if(redni_broj!=trenutna_rijec) throw std::range_error("IZUZETAK: Pogresan redni broj rijeci!");

    return povratna_rijec;
}


int main ()
{
    std::string recenica;
    std::string rijec;
    std::cout<<"Unesite redni broj rijeci: ";
    int redni_broj;
    std::cin>>redni_broj;
    std::cin.ignore(10000,'\n');
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,recenica);
    try{
        rijec = IzdvojiRijec(recenica,redni_broj);
    }
    catch(std::range_error izuzetak){
        std::cout<<izuzetak.what();
        return 0;
    }
    std::cout<<"Rijec na poziciji "<<redni_broj<<" je "<<rijec;
    
    return 0;
}

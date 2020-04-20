//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <string>

template<typename NumerckiTip>
void UnosBroja(const std::string& s1, const std::string& s2, NumerckiTip &broj){
    NumerckiTip temp;
    while(1){
        std::cout<<s1<<std::endl;
        std::cin>>temp;
        if(!std::cin || std::cin.peek()!='\n'){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<s2<<std::endl;
            continue;
        }
        else break;
    }
    broj=temp;
    return;
}

int main ()
{
    double baza;
    UnosBroja("Unesite bazu: ","Neispravan unos, pokusajte ponovo...",baza);
    int n;
    UnosBroja("Unesite cjelobrojni eksponent: ","Neispravan unos, pokusajte ponovo...",n);
    double rezultat=1;
    if(n==0) rezultat=1;
    if(n>0){
        for(int i = 0; i<n; i++) rezultat*=baza;
    }
    if(n<0){
        for(int i=0; i<abs(n); i++) rezultat*=baza;
        rezultat = 1/rezultat;
        
    }
    std::cout<<baza<<" na "<<n<<" iznosi "<<rezultat;
	return 0;
}
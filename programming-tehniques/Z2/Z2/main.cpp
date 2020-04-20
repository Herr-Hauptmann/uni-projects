#include <iostream>
#include <cmath>
#include <stdexcept>
int KvadratniDjelilac(int n)
{
    int MaxDjelilac = 1;
    for(int i = 2; i<n-1; i++) if(n%i==0 && n%(i*i)==0) MaxDjelilac = i;
    return MaxDjelilac;
}
void RastavaBroja(int n, int &p, int &q)
{
    if(n<=0) throw std::domain_error("Broj koji se rastavlja mora biti prirodan");
    q=KvadratniDjelilac(n);
    p=n/(q*q);

}
int main()
{
    int n;
    std::cout<<"Unesite prirodan broj"<<std::endl;
    std::cin>>n;
    int p,q;
    try {
        RastavaBroja(n,p,q);
    } catch(std::domain_error e) {
        std::cout<<"Izuzetak: "<<e.what()<<"!";
        return 0;
    }
    std::cout<<p<<" "<<q;
    return 0;
}

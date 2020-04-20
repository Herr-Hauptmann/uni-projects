//TP 2017/2018: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout<<"Unesite broj elemenata: "<<std::endl;
    std::cin>>n;
    std::complex<double> suma(0,0);
    std::complex<double> z;
    for(int i = 0; i<n; i++ ){
        std::cout<<"Z_"<<i+1<<" = ";
        std::cin>>z;
        suma+=1./z;
    }
    
    std::cout<<"\nParalelna veza ovih elemenata ima impedansu Z_ = "<<1./suma<<".";
	return 0;
}

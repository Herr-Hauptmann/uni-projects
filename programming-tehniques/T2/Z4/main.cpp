//TP 2017/2018: Tutorijal 2, Zadatak 4
#include <iostream>
#include <complex>

int main ()
{
    int n;
    std::cout<<"Unesite broj elemenata: "<<std::endl;
    std::cin>>n;
    std::complex<double> suma(0,0);
    std::complex<double> z;
    double re, im;
    for(int i = 0; i<n; i++ ){
        std::cout<<"R"<<i+1<<" = ";
        std::cin>>re;
        std::cout<<"X"<<i+1<<" = ";
        std::cin>>im;
        z = {re,im};
        std::cout<<std::endl;

        suma+=1./z;
    }
    
    std::cout<<"Paralelna veza ovih elemenata ima R = "<<(1./suma).real()<<" i X = "<<(1./suma).imag()<<".";
	return 0;
}

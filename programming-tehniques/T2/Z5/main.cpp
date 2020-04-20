//TP 2017/2018: Tutorijal 2, Zadatak 5
#include <iostream>
#include <complex>

int main ()
{
    int n;
    double PI = 4*atan(1);
    std::cout<<"Unesi broj elemenata: "<<std::endl;
    std::cin>>n;
    std::complex<double> suma(0,0);
    std::complex<double> z;
    double modul, fi;
    for(int i = 0; i<n; i++ ){
        std::cout<<"Z"<<i+1<<" = ";
        std::cin>>modul;
        std::cout<<"fi"<<i+1<<" = ";
        std::cin>>fi;
        fi = fi * PI / 180;
        z = std::polar(modul,fi);
        suma+=1./z;
        std::cout<<std::endl;
    }
    
    z = 1. / suma;
    std::cout<<"Paralelna veza ovih elemenata ima Z = "<<abs(z)<<" i fi = "<<std::arg(z)*180/PI<<".";
	return 0;
}
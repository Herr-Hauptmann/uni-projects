//TP 2017/2018: ZSR 1, Zadatak 2
#include <iostream>

int main ()
{
    int brzina;
    std::cout<<"Unesite brzinu broda u cvorovima: ";
    std::cin>>brzina;
    
    const int milja = 1852;
    
    double brzinaRealna = double((brzina * milja))/1000;
    
    std::cout<<"Brzina u kilometrima na sat je: "<<brzinaRealna<<" km/h.";

    
	return 0;
}

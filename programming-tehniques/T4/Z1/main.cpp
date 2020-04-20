//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>
int Cifre(long long int n, int &c_min, int &c_max){
    int max, min,broj_cifara=0;
    if(n==0){
        c_max=0;
        c_min=0;
        return 1;
    }
    max = abs(n%10);
    min  = max;
    while(n!=0){
        int a = abs(n%10);
        if(a>max) max=a;
        if(a<min) min=a;
        broj_cifara++;
        n/=10;
    }
    c_max = max;
    c_min = min;
    return broj_cifara;
}
int main ()
{
int mini, maxi;
long long int broj;
std::cout<<"Unesite broj: ";
std::cin>>broj;
int cifre = Cifre(broj, mini, maxi);
std::cout<<"Broj "<<broj<<" ima "<<cifre<<" cifara, najveca je "<<maxi<<" a najmanja "<<mini<<".";
	return 0;
}
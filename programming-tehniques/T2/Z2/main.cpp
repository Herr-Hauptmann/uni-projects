//TP 2017/2018: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>
#include <cmath>

bool TestPerioda(std::vector<double> v, int p){
    bool tacanPeriod = true;
    if(p>=v.size() || p<=0) return false;
    for(int i = 0; i<v.size(); i++){
        for(int j = i; j<v.size(); j+=p){
            if(fabs(v.at(i) - v.at(j)) > 0.00001){
                tacanPeriod = false;
                return tacanPeriod;
            }
        }
        
    }
    return tacanPeriod;
    
}

int OdrediOsnovniPeriod(std::vector<double> v){
    int p = 0;
    for(int i = 1; i < v.size(); i++){
        if(TestPerioda(v,i)){
            p = i;
            break;
        }
    }
    
    return p;
}



int main ()
{
    std::vector<double> v;
    std::cout<<"Unesite slijed brojeva (0 za kraj): ";
    double a;
    while(std::cin>>a, a!=0) v.push_back(a);
    a = OdrediOsnovniPeriod(v);
    if(a!=0) std::cout<<"Slijed je periodican sa osnovnim periodom "<<a<<".";
    else std::cout<<"Slijed nije periodican!";
    
	return 0;
}

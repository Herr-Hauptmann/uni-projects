//TP 2017/2018: Tutorijal 3, Zadatak 5
#include <iostream>
#include <iostream>
#include <deque>

int SumaCifara(int n){
    int suma = 0;
    while(n!=0){
        int a = n%10;
        suma+=a;
        n/=10;
    }
    return suma;
}

std::deque<int> IzdvojiElemente (std::deque<int> v, bool parne){
    std::deque<int> x;
    for(int i=v.size()-1; i>=0; i--){
        if(parne){
            if(SumaCifara(v.at(i))%2==0) x.push_front(v.at(i));
        }
        else{
        if(SumaCifara(v.at(i))%2!=0) x.push_front(v.at(i));    
        }
    }
    
    return x;
}

int main ()
{
    std::deque<int> a;
    std::deque<int> b;
    std::deque<int> c;
    int n;
    std::cout<<"Koliko zelite unijeti elemenata: ";
    std::cin>>n;
    if(n<=0){ std::cout<<"Broj elemenata mora biti veci od 0!";
    return 0;    
    }
    std::cout<<"Unesite elemente: ";

    for(int i = 0; i<n; i++){
    int x;
    std::cin>>x;
    a.push_back(x);
    }
    
    b = IzdvojiElemente(a,true);
    c = IzdvojiElemente(a, false);
    for(int i = 0; i<b.size(); i++){
        if(i==b.size()-1) std::cout<<b[i];
        else std::cout<<b[i]<<",";
    }
    std::cout<<std::endl;
    for(int i = 0; i<c.size(); i++){
        if(i==c.size()-1) std::cout<<c[i];
        else std::cout<<c[i]<<",";
    }
    
	return 0;
}

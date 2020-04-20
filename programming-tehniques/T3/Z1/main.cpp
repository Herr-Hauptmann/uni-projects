//TP 2017/2018: Tutorijal 3, Zadatak 1
#include <iostream>
#include <vector>

int SumaCifara(int n){
    int suma = 0;
    while(n!=0){
        int a = n%10;
        suma+=a;
        n/=10;
    }
    return suma;
}

std::vector<int> IzdvojiElemente (std::vector<int> v, bool parne){
    std::vector<int> x;
    for(int i : v){
        if(parne){
            if(SumaCifara(i)%2==0) x.push_back(i);
        }
        else{
        if(SumaCifara(i)%2!=0) x.push_back(i);    
        }
    }
    
    return x;
}

int main ()
{
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> c;
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
    for(int i : b){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    for(int i : c){
        std::cout<<i<<" ";
    }
    
	return 0;
}

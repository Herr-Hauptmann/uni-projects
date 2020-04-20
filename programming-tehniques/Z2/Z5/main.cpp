/* TP, 2018/2019
*/
#include <iostream>
#include <type_traits>
#include <string>
#include <deque>
#include <algorithm>
#include <limits>
template<typename PokTip>
bool ZaSve(PokTip p1, PokTip p2, bool F(typename std::remove_reference<decltype(*p1)>::type x)){
    bool flag = true;
    while(p1!=p2){
        if(!F(*p1)){
            flag = false;
            break;
        }
        p1++;
    }
    return flag;
}
template<typename PokTip>
bool MakarJedan(PokTip p1, PokTip p2, bool F(typename std::remove_reference<decltype(*p1)>::type x)){
    bool flag = false;
    while(p1!=p2){
        if(F(*p1)){
            flag = true;
            break;
        }
        p1++;
    }
    return flag;
}

template<typename PokTip>
auto Akumuliraj(PokTip p1, PokTip p2, typename
std::remove_reference<decltype(*p1)>::type F(typename std::remove_reference<decltype(*p1)>::type x, 
typename std::remove_reference<decltype(*p1)>::type y), typename std::remove_reference<decltype(*p1)>::type a0 = 1)->typename std::remove_reference<decltype(*p1)>::type{
while(p1!=p2){
    a0 = F(a0,*p1);
    p1++;
}
return a0;
}


int main ()
{
    std::string s;
    std::cout<<"Unesite string: ";
    std::getline(std::cin,s);
    if(ZaSve(s.begin(),s.end(),[](char c){
    if(c>='0'&&c<='9' || c>='a'&&c<='z' || c>='A'&&c<='Z') return true;
    return false;})) std::cout<<"Uneseni string sadrzi samo slova i cifre"<<std::endl;
    else std::cout<<"Uneseni string sadrzi i druge znakove osim slova i cifara"<<std::endl;
    int niz[10];
    std::cout<<"Unesite niz od 10 brojeva: ";
    std::for_each(niz,niz+10,[](int &x){
        int y;
        std::cin>>y;
        x=y;
    });
    if(MakarJedan(niz,niz+10,[](int x){
        if(x<0) x=-x;
        int y = x;
        int suma = 0;
        while(y!=0){
            suma+=y%10;
            y/=10;
        }
        if(x%suma==0) return true;
        else return false;
        })) std::cout<<"U nizu ima brojeva djeljivih sa sumom svojih cifara"<<std::endl;
    else std::cout<<"U nizu nema brojeva djeljivih sa sumom svojih cifara"<<std::endl;
    std::deque<double> dek(10);
    std::cout<<"Unesite dek od 10 elemenata: "<<std::endl;
    std::for_each(dek.begin(),dek.end(),[](double& x){
        double y;
        std::cin>>y;
        x=y;
    });
    std::cout<<"Suma deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x, double y){
        return x+y;
    },0)<<"    "<<std::endl;
    std::cout<<"Produkt deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x, double y){
        return x*y;
    })<<std::endl;
    std::cout<<"Najveci elemenat deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x, double y){
    return (x-y>0.00001) ? x : y;  
    },dek.at(0))<<std::endl;
    std::cout<<"Najmanji elemenat deka: "<<Akumuliraj(dek.begin(),dek.end(),[](double x, double y){
    return (y-x>0.00001) ? x : y;  
    },dek.at(0))<<std::endl;
    
    
    
	return 0;
}
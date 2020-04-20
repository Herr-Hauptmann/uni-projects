/* TP, 2018/2019
*/
#include <iostream>
#include <vector>
#include <deque> 

template <typename Tip1, typename Tip2, typename Tip3>
Tip3 SimetricnaRazlikaBlokova(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 p5)
{
    int vel1 = p2 - p1;
    int vel2 = p4 - p3;
    int brojac = 0;
    for(int i = 0; i < vel1; i++) {
        bool Ponavljanje = false;
        for(int j = 0; j < vel2; j++) {
            if(p1[i]==p3[j]) {
                Ponavljanje = true;
                break;
            }
        }
        if(!Ponavljanje) {
            bool Ponavljanje2 = false;
            for(int j = 0; j<brojac; j++) {
                if(p1[i]==p5[j]) {
                    Ponavljanje2 = true;
                    break;
                }
            }
            if(!Ponavljanje2) p5[brojac++] = p1[i];
        }

    }
    for(int i = 0; i < vel2; i++) {
        bool Ponavljanje = false;
        for(int j = 0; j < vel1; j++) {
            if(p3[i]==p1[j]) {
                Ponavljanje = true;
                break;
            }
        }
        if(!Ponavljanje) {
            bool Ponavljanje2 = false;
            for(int j = 0; j<brojac; j++) {
                if(p3[i]==p5[j]) {
                    Ponavljanje2 = true;
                    break;
                }
            }
            if(!Ponavljanje2) p5[brojac++] = p3[i];
        }

    }
    
    return p5+brojac;
}



int main ()
{
    int niz[100];
    int n;
    std::cout<<"Unesite broj elemenata niza"<<std::endl;
    std::cin>>n;
    std::cout<<"Unesite elemente niza"<<std::endl;
    for(int i = 0; i<n; i++){
        std::cin>>niz[i];
    }
    std::cout<<"Unesite broj elemenata deka"<<std::endl;
    int n2;
    std::cin>>n2;
    std::deque<int> dek(n2);
    std::cout<<"Unesite elemente deka"<<std::endl;
    for(int i = 0; i<n2; i++) std::cin>>dek.at(i);
    std::vector<int> v(200);
    int stvarnaVel = SimetricnaRazlikaBlokova(niz,niz+n,dek.begin(),dek.end(),v.begin()) - v.begin();
    v.resize(stvarnaVel);
    if(v.size()==0) std::cout<<"Blokovi nemaju simetricnu razliku";
    else{
        std::cout<<"Simetricna razlika blokova je:";
        for(int i = 0; i<v.size(); i++) std::cout<<" "<<v.at(i);
    }
    
    
    return 0;
}

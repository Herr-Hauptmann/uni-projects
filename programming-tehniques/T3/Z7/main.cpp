//TP 2017/2018: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<int>> Matrica;
Matrica KreirajMatricu(int broj_redova, int broj_kolona){
    return Matrica (broj_redova, std::vector<int>(broj_kolona));
}

int BrojCifara(int a){
    int broj_cifara = 0;
    if(a<0) {
        broj_cifara++;
        a=-a;
    }
    while(a!=0) {
        a/=10;
        broj_cifara++;
    }
    return broj_cifara;
    
}

int NajvecaSirina(Matrica m)
{
    if(m.size()==0) return 0;
    long int maxi = BrojCifara(m.at(0).at(0));
    for(long int i = 0; i<m.size(); i++) {
        for(long int j = 0; j<m[i].size(); j++) {
            if(BrojCifara(m[i][j])>BrojCifara(maxi)) maxi = m.at(i).at(j);
            }
    }
    
    return BrojCifara(maxi);
    
}
Matrica PascalovTrougao(int n)
{
    if(n==0) return KreirajMatricu(0,0);
    if(n<0){
     throw std::domain_error("Broj redova ne smije biti negativan");   
    } 
    Matrica m;
    m.resize(n);
    int j = 1;
    for(int i = 0; i<n; i++) {
        for(int k = 0; k<j; k++) {
            if(k==0 || k==j-1) m.at(i).push_back(1);
            else m.at(i).push_back(m[i-1][k] + m[i-1][k-1]);
        }
        j++;

    }

    return m;
}
int main ()
{
    std::cout<<"Unesite broj redova: "<<std::endl;
    int n;
    std::cin>>n;
    Matrica m = PascalovTrougao(n);
    int sirina = NajvecaSirina(m);
    for(int i = 0; i<m.size(); i++){
        for(int j = 0; j<m[i].size(); j++){
            std::cout<<std::setw(sirina+1)<<std::right<<m[i][j];
        }
        std::cout<<std::endl;
    }
    return 0;
}

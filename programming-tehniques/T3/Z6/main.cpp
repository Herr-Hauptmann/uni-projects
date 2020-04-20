//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <iomanip>
#include <vector>
typedef std::vector<std::vector<int>> Matrica;

Matrica KreirajMatricu(int broj_redova, int broj_kolona){
    return Matrica (broj_redova, std::vector<int>(broj_kolona));
}

Matrica KroneckerovProizvod(std::vector<int> a, std::vector<int> b)
{
    Matrica c = KreirajMatricu(a.size(),b.size());
    for(int i = 0; i<a.size(); i++) {
        for(int j = 0; j<b.size(); j++) {
            c[i][j]=a[i]*b[j];
        }
    }
    return c;
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
int main ()
{
    int n1, n2;
    std::vector<int> a;
    std::vector<int> b;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>>n1;
    std::cout<<"Unesite elemente prvog vektora: ";
    for(int i = 0; i<n1; i++) {
        int x;
        std::cin>>x;
        a.push_back(x);
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>n2;
    std::cout<<"Unesite elemente drugog vektora: "<<std::endl;
    for(int i = 0; i<n2; i++) {
        int x;
        std::cin>>x;
        b.push_back(x);
    }
    
    Matrica c = KroneckerovProizvod(a,b);
    int sirina = NajvecaSirina(c);
    
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            std::cout<<std::setw(sirina+1)<<std::right<<c.at(i).at(j);
        }
        std::cout<<std::endl;
    }


    return 0;
}

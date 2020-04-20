#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica FormirajMatricu(int broj_redova, int broj_kolona){
    return Matrica(broj_redova, std::vector <int> (broj_kolona));
}

int BrojRedova(Matrica m){
    return m.size();
}

int BrojKolona(Matrica m){
    return m[0].size();
}

Matrica UnesiMatricu(int broj_redova, int broj_kolona){
    auto m=(FormirajMatricu(broj_redova,broj_kolona);
    for(int i=0; i<broj_redova; i++){
        for(int j=0; j<broj_kolona; j++){
            std::cin >> m[i][j];
        }
    }
    return m;
}

void IspisiMatricu(Matrica m){
    for(int i=0; i<BrojRedova(m); i++){
        for(int j=0; j<BrojKolona(m); j++){
            std::cout << std::setw(4) << std::right << double (m[i][j]) ;
        }
        std::cout << std::endl;
    }
}


Matrica Posebna_matrica(Matrica m){
    
    for(int i=1; i<BrojRedova(m) ;i++){
        for(int j=1; j<BrojKolona(m); j++){
            m[i][j]=m[i-1][j-1]+0.38*m[i-1][j-1];
        }
    }
    
return m;
}


Matrica Posebna_matrica2(Matrica m){
    
    auto k=Posebna_matrica(m);
    
     for(int i=1; i<BrojRedova(k) ;i++){
        for(int j=0; j<BrojKolona(k); j++){
            k[i][0]=k[i-1][BrojKolona(k)-1];
        }
    }
    
    
return k;
}


int main(){
    
    int M;
    std::cout << "Unesi M: ";
    std::cin >> M;
    
    int N;
    std::cout << "Unesi N: ";
    std::cin >> N;
    
    std::cout << "Unesi elemente matrice: ";
    
    Matrica m=UnesiMatricu(M,N);
    std::cout << std::endl;
    
    Matrica D = Posebna_matrica2(m);
    
    IspisiMatricu(D);
    
    
    return 0;
}
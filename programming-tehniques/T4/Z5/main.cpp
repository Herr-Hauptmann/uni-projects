//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>

template<typename Kolekcija>
Kolekcija Presjek( Kolekcija &v1, Kolekcija &v2){
Kolekcija c;
for(int i = 0; i<v1.size(); i++){
    bool duplikat = 0;
    for(int j = 0; j<v2.size(); j++){
        if(v1.at(i) == v2.at(j)) duplikat = 1;
    }
    bool ponavljanje = 0;
    for(int k = 0; k<c.size(); k++){
        if(v1.at(i)== c.at(k)) ponavljanje=1;
    }
    
    if(duplikat && !ponavljanje) c.push_back(v1.at(i));
}

//vector<double> Presjek (vector<double)

return c;
}

int main ()
{
    std::cout<<"Test za realne brojeve..."<<std::endl;
    int broj_elemenata1;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>>broj_elemenata1;
    std::cout<<"Unesite elemente prvog vektora: ";
    std::vector<double> v1;
    for(int i = 0; i<broj_elemenata1; i++){
        double x;
        std::cin>>x;
        v1.push_back(x);
    }
    int broj_elemenata2;
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>broj_elemenata2;
    std::vector<double> v2;
    std::cout<<"Unesite elemente drugog vektora: ";
    for(int i = 0; i<broj_elemenata2; i++){
        double x;
        std::cin>>x;
        v2.push_back(x);
    }
    std::vector<double> v3 = Presjek(v1,v2);
    std::cout<<"Zajednicki elementi su:";
    for(int i = 0; i<v3.size(); i++) std::cout<<" "<<v3.at(i);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Test za stringove..."<<std::endl;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    int vel1;
    std::cin>>vel1;
    std::cout<<"Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    std::vector<std::string> s1(vel1);
    std::cin.ignore(10000,'\n');
    for(int i = 0; i<vel1; i++){
        std::getline(std::cin,s1.at(i));
    }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    int vel2;
    std::cin>>vel2;
    std::cout<<"Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    std::vector<std::string> s2(vel2);
    std::cin.ignore(10000,'\n');
    for(int i = 0; i<vel2; i++){
        std::getline(std::cin,s2.at(i));
        
    }
    std::vector<std::string> s3 = Presjek(s1,s2);
    std::cout<<"Zajednicki elementi su:"<<std::endl;
    for(int i = 0; i<s3.size(); i++) std::cout<<s3.at(i)<<std::endl;
    
    
	return 0;
}
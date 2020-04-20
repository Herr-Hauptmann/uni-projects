/* TP, 2018/2019
*/
#include <iostream>
#include <string>
#include <algorithm>
std::string DigniGaGore(std::string s){
    std::string s2;
    for(auto a : s) s2.push_back(toupper(a));
    return s2;
}
bool KriterijSortiranja(std::string s1, std::string s2){
    if(s1.size()==s2.size()) return DigniGaGore(s1)<DigniGaGore(s2);
    else return s1.size() < s2.size();
}
void SortirajPoDuzini(std::string* pok, int vel){
    if(vel==0) throw;
    std::sort(pok,pok+vel,KriterijSortiranja);
}
bool PretraziBinarno(std::string* pok, int vel, std::string trazi){
    return std::binary_search(pok,pok+vel,trazi,KriterijSortiranja);
}
int main ()
{
    std::cout<<"Unesite broj rijeci: ";
    int n;
    std::cin>>n;
    auto p = new std::string[n];
    std::cout<<"Unesite rijeci: ";
    for(int i = 0; i<n; i++) std::cin>>p[i];
    SortirajPoDuzini(p,n);
    std::cout<<"Sortirane rijeci:";
    for(int i = 0; i<n; i++) std::cout<<" "<<p[i];
    std::cout<<std::endl;
    std::cout<<"Unesite rijec za pretragu: ";
    std::string trazi;
    std::cin>>trazi;
    if(PretraziBinarno(p,n,trazi)) std::cout<<"Rijec '"<<trazi<<"' se nalazi u nizu."<<std::endl;
    else std::cout<<"Rijec '"<<trazi<<"' se ne nalazi u nizu."<<std::endl;
    delete[] p;
    p = nullptr;
    
	return 0;
}
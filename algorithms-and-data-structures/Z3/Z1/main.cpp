#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int getMaxDigit(vector<int> &a)
{
    int max = a[0];
    for(int i = 1; i < a.size(); i++)
        if(a[i] > max) max = a[i];
    max = abs(max);
    int numDigit = 0;
    while(max > 0) {
        numDigit++;
        max /= 10;
    }
    return numDigit;
}
int stepen(int a, int n)
{
    if(n == 0) return 1;
    if(n % 2 == 0) return stepen(a, n / 2) * stepen(a, n / 2);
    else return stepen(a, (n - 1) / 2) * stepen(a, (n - 1) / 2) * a;
}
void radixSort(vector<int>& a)
{
    int max = getMaxDigit(a);
    vector<queue<int>> c(10);
    for(int i = 1; i <= max; i++) {
        for(int j = 0; j < a.size(); j++)
            c[int((a[j] % stepen(10,i)) / stepen(10,i-1))].push(a[j]);
        a.resize(0);
        for(int j = 0; j < 10; j++) {
            while(!c[j].empty()) {
                a.push_back(c[j].front());
                c[j].pop();
            }
        }
    }
}
int roditelj(int i){
    return (i-1) / 2;
}
int lijevo_dijete(int i){
    return 2 * i + 1;
}
int desno_dijete(int i){
    return 2 * i + 2;
}
bool je_li_list(int i, vector<int>& a){
    return i >= a.size() / 2 && i <= a.size();
}
void popravi_dolje(vector<int>& a, int i, int &velicina){
    int veci, dd;
    while(!(i >= velicina / 2 && i < velicina)){
    veci = lijevo_dijete(i);
    dd = desno_dijete(i);
    if(dd < velicina && a[dd] > a[veci]){
        veci = dd;
    }
    if(a[i] > a[veci]) return;
    std::swap(a[i],a[veci]);
    i = veci;
    }
}
void popravi_gore(vector<int> &a, int i){
    while(i != 0 &&  a[i] > a[roditelj(i)]){
        std::swap(a[i],a[roditelj(i)]);
        i = roditelj(i);
    }
}
void stvoriGomilu(vector<int> &a){
    int velicina = a.size();
    for(int i = a.size() / 2; i >= 0; i--) popravi_dolje(a,i,velicina);
}
void umetniUGomilu(vector<int> &a, int umetnuti, int &velicina){
    a.push_back(umetnuti);
    velicina++;
    popravi_gore(a,velicina-1);
    
}
int izbaciPrvi(vector<int> &a, int &velicina){
    if(velicina == 0) throw std::range_error("Gomila je prazna!");
    velicina--;
    swap(a[0],a[velicina]);
    if(velicina != 0) popravi_dolje(a,0,velicina);
    return a[velicina];
}
void gomilaSort(vector<int> &a){
    stvoriGomilu(a);
    int velicina = a.size();
    for(int i = 0; i <= a.size() - 2; i++) izbaciPrvi(a,velicina);
}
int main()
{
      

    vector<int> a;
    a.push_back(545);
    a.push_back(1545);
    a.push_back(4536);
    a.push_back(124121);
    a.push_back(1);
    a.push_back(95468);
    int velicina = a.size();
    stvoriGomilu(a);
    umetniUGomilu(a,100000,velicina);   
    umetniUGomilu(a,3,velicina);   
    umetniUGomilu(a,1,velicina);  
    umetniUGomilu(a,100,velicina); 
    umetniUGomilu(a,200,velicina);  
    for(int i(0);i<a.size();i++){
        cout<<a[i]<<" ";
    }
    gomilaSort(a);
    for(int i(0);i<a.size();i++){
        cout<<a[i]<<" ";
    }
}

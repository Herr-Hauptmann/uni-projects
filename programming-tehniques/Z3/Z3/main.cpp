//TP 2018/2019: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <new>
#include <type_traits>
template <typename TipElemenata>
 struct Matrica {
 int br_redova, br_kolona;
 TipElemenata **elementi = nullptr; // VEOMA BITNA INICIJALIZACIJA!
 };
template <typename TipElemenata>
 void UnistiMatricu(Matrica<TipElemenata> &mat) {
 if(!mat.elementi) return;
 for(int i = 0; i < mat.br_redova; i++) delete[] mat.elementi[i];
 delete[] mat.elementi;
 mat.elementi = nullptr;
 }
template <typename TipElemenata>
 Matrica<TipElemenata> StvoriMatricu(int br_redova, int br_kolona) {
 Matrica<TipElemenata> mat;
 mat.br_redova = br_redova; mat.br_kolona = br_kolona;
 mat.elementi = new TipElemenata*[br_redova]{};
 try {
 for(int i = 0; i < br_redova; i++)
 mat.elementi[i] = new TipElemenata[br_kolona];
 }
 catch(...) {
 UnistiMatricu(mat);
 throw;
 }
 return mat;
 }
template <typename TipElemenata>
 void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
 for(int i = 0; i < mat.br_redova; i++)
 for(int j = 0; j < mat.br_kolona; j++) {
 std::cout << ime_matrice
 << "(" << i + 1 << "," << j + 1 << ") = ";
 std::cin >> mat.elementi[i][j];
 }
 }
template <typename TipElemenata>
 void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false) {
 for(int i = 0; i < mat.br_redova; i++) {
 for(int j = 0; j < mat.br_kolona; j++) std::cout << std::setprecision(preciznost) << std::setw(sirina_ispisa) << mat.elementi[i][j];
 std::cout << std::endl;
 }
 if(treba_brisati==true){
  Matrica<TipElemenata> brisi = mat;
  UnistiMatricu<TipElemenata>(brisi);
 }
 
 }
template <typename TipElemenata>
 Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1,
 const Matrica<TipElemenata> &m2) {
 if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
 throw std::domain_error("Matrice nemaju jednake dimenzije!");
 auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova, m1.br_kolona);
 for(int i = 0; i < m1.br_redova; i++)
 for(int j = 0; j < m1.br_kolona; j++)
 m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
 return m3;
 }
 template<typename TipElemenata>
 void PostaviMatricu( Matrica<TipElemenata> &m,double vrijednost){
  for(int i = 0; i<m.br_redova; i++)
  for(int j = 0; j<m.br_kolona; j++)
  m.elementi[i][j] = vrijednost;
 
 }
 template<typename TipElemenata>
 void JedinicnaMatrica(Matrica<TipElemenata> &m){
  for(int i = 0; i<m.br_redova; i++){
  for(int j = 0; j<m.br_kolona; j++){
   if(i==j) m.elementi[i][j] = 1;
   else m.elementi[i][j] = 0;
  }
  }
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
  if(m1.br_kolona != m2.br_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
  auto m3 = StvoriMatricu<TipElemenata>(m1.br_redova,m2.br_kolona);
  for(int i = 0; i<m1.br_redova; i++){
   for(int j = 0; j<m2.br_kolona; j++){
    m3.elementi[i][j]=0;
    for(int k = 0; k<m2.br_redova; k++) m3.elementi[i][j]+=m1.elementi[i][k]*m2.elementi[k][j];
   }
  }
  return m3;
 }
 template<typename TipElemenata> 
 void DubokaKopija(Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2){
  m1 = StvoriMatricu<TipElemenata>(m2.br_redova, m2.br_kolona);
  for(int i = 0; i<m2.br_redova; i++)
  for(int j = 0; j<m2.br_kolona; j++)
  m1.elementi[i][j] = m2.elementi[i][j];
 }
 
 template <typename TipElemenata>
 void PomnoziSaSkalarom(Matrica<TipElemenata> &m, double skalar){
  for(int i = 0; i<m.br_redova; i++){
   for(int j = 0; j<m.br_kolona; j++) m.elementi[i][j]*=skalar;
  }
 }
 template <typename TipElemenata>
 void ZbirMatricaV2(Matrica<TipElemenata> &m1, Matrica<TipElemenata> &m2 ){
  if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona) throw std::domain_error("Matrice nisu saglasne");
  for(int i=0; i<m1.br_redova; i++)
  for(int j=0; j<m1.br_kolona; j++) m1.elementi[i][j] += m2.elementi[i][j];
 }
 template <typename TipElemenata>
 Matrica<TipElemenata> MatricniPolinom(const Matrica<TipElemenata> &m, const std::vector<TipElemenata> &v){
  if(m.br_redova != m.br_kolona) throw std::domain_error("Matrica mora biti kvadratna");
  bool prazan = true;
  for(int i = 0; i<v.size(); i++){
   if(v.at(i)!=0){
    prazan = false; 
    break;
   }
  }
  if(prazan){
   auto p = StvoriMatricu<TipElemenata>(m.br_redova, m.br_kolona);
   PostaviMatricu(p,0);
   return p;
  }
  Matrica<TipElemenata> mat, stepen,temp;
  try{
   mat=StvoriMatricu<TipElemenata>(m.br_redova,m.br_kolona);
   JedinicnaMatrica<TipElemenata>(mat);
   PomnoziSaSkalarom<TipElemenata>(mat,v.at(0));
   DubokaKopija(stepen,m);
   for(int i = 1; i<v.size(); i++){
    temp = stepen;
    stepen=ProduktMatrica<TipElemenata>(stepen,m);
    PomnoziSaSkalarom<TipElemenata>(temp,v.at(i));
    ZbirMatricaV2<TipElemenata>(mat,temp);
    UnistiMatricu<TipElemenata>(temp);
   }

  }
  catch(...){
   std::cout<<"Memorijska greska";
  }
  UnistiMatricu<TipElemenata>(stepen);
  UnistiMatricu<TipElemenata>(temp);
  return mat;
 }

int main ()
{
 std::cout<<"Unesite dimenziju kvadratne matrice: ";
 int n;
 std::cin>>n;
 auto m = StvoriMatricu<double>(n,n);
 m.br_kolona=n;
 m.br_redova=n;
 std::cout<<"Unesite elemente matrice A: "<<std::endl;
 UnesiMatricu('A',m);
 std::cout<<"Unesite red polinoma: ";
 int r;
 std::cin>>r;
 std::vector<double> v;
 std::cout<<"Unesite koeficijente polinoma: ";
 for(int i = 0; i<=r; i++){
  int x;
  std::cin>>x;
  v.push_back(x);
 }
 Matrica<double> m2;
 m2.br_kolona = n; m2.br_kolona = n;
 m2 = MatricniPolinom<double>(m,v);
 IspisiMatricu(m2,10);
 UnistiMatricu<double>(m);
 UnistiMatricu<double>(m2);
	return 0;
}
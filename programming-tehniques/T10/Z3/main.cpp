/* 
    TP 16/17 (Tutorijal 10, Zadatak 3)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
class Vektor3d {
 double koordinate[3];
 mutable int brojac_ispisa=0;
public:
Vektor3d(){
	koordinate[0] = 0; koordinate[1] = 0; koordinate[2] = 0;
}
Vektor3d(double x, double y, double z){
	koordinate[0] = x; koordinate[1] = y; koordinate[2] = z;
}
Vektor3d(const Vektor3d &v){
koordinate[0] = v.DajX(); koordinate[1] = v.DajY(); koordinate[2] = v.DajZ();
brojac_ispisa = 0;
}
 void Postavi(double x, double y, double z) {
 Vektor3d::koordinate[0] = x; Vektor3d::koordinate[1] = y; Vektor3d::koordinate[2] = z;
 }
 void Ocitaj(double &x, double &y, double &z) const {
 x = Vektor3d::koordinate[0]; y = Vektor3d::koordinate[1]; z = Vektor3d::koordinate[2];
 }
 void Ispisi() const {
 std::cout << "{" << koordinate[0] << "," << koordinate[1] << "," << koordinate[2] << "}";
 brojac_ispisa++;
 }
 double DajX() const { return koordinate[0]; }
 double DajY() const { return koordinate[1]; }
 double DajZ() const { return koordinate[2]; }
 double DajDuzinu() const { return sqrt(koordinate[0] * koordinate[0] + koordinate[1] * koordinate[1] + koordinate[2] * koordinate[2]); }
Vektor3d &PomnoziSaSkalarom(double s) {
 koordinate[0] *= s; koordinate[1] *= s; koordinate[2] *= s;
 return *this;
 }
 Vektor3d &SaberiSa(const Vektor3d &v) {
 koordinate[0] += v.koordinate[0]; koordinate[1] += v.koordinate[1]; koordinate[2] += v.koordinate[2];
 return *this;
 }
 void PostaviX(double x){
 	koordinate[0]=x;
 }
 void PostaviY(double y){
 	koordinate[1]=y;
 }
 void PostaviZ(double z){
 	koordinate[2]=z;
 }
 int DajBrojIspisa()const{
 	return brojac_ispisa;
 }
 friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2){
  Vektor3d v3;
  v3.koordinate[0] = v1.koordinate[0] + v2.koordinate[0]; v3.koordinate[1] = v1.koordinate[1] + v2.koordinate[1];
  v3.koordinate[2] = v1.koordinate[2] + v2.koordinate[2];
  return v3;
 }
};
 int main(){
  return 0;
 }
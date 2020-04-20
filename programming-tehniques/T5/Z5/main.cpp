/* 
    TP 2018/2019: Tutorijal 5, Zadatak 5
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <cmath>
#include <iomanip>
double Inverz(double x){
	return 1/x;
}
double Kub(double x){
	return x*x*x;
}
double TrapeznoPravilo(double Integral(double), double a, double b, int n){
	double Suma = 0;
	for(int i = 1; i<=n-1; i++) Suma+=Integral(a + (b-a)/n * i);
	return ((b-a) / n) * (Integral(a)/2 +  Integral(b)/2 + Suma);
}

int main ()
{
	std::cout<<"Unesite broj podintervala: ";
	int n;
	std::cin>>n;
	std::cout<<"Za taj broj podintervala priblizne vrijednosti integrala iznose: "<<std::endl;
	std::cout<<"- Za funkciju sin x na intervalu (0,pi): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo(sin,0,4*atan(1),n)<<std::endl;
	std::cout<<"- Za funkciju x^3 na intervalu (0,10): "<<std::fixed<<std::setprecision(2)<<TrapeznoPravilo(Kub,0,10,n)<<std::endl;
	std::cout<<"- Za funkciju 1/x na intervalu (1,2): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo(Inverz,1,2,n);
	return 0;
}
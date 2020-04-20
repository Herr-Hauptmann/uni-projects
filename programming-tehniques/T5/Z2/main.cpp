/* 
    TP 2018/2019: Tutorijal 5, Zadatak 2
	
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
template<typename IterTip1, typename IterTip2>
IterTip2 RazmijeniBlokove(IterTip1 p1, IterTip1 p2, IterTip2 p3){
	auto pomocna = *p1;
	while(p1 != p2){
		pomocna = *p1;
		*p1 = *p3;
		*p3 = pomocna;
		p1++; p3++;
	} 
	return p3;
}
int main ()
{
	return 0;
}
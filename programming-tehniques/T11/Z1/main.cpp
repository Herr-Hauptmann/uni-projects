/* 
    TP 16/17 (Tutorijal 11, Zadatak 1)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
class NeobicnaKlasa{
	int atribut;
	public:
	 explicit NeobicnaKlasa(int a ){
		std::cout<<"Direktna inicijalizacija"<<std::endl;
		atribut = a;
	}
	

		NeobicnaKlasa(double d){
		std::cout<<"Kopirajuca inicijalizacija"<<std::endl;
		atribut = d;
	}

	
	
};
int main ()
{
	NeobicnaKlasa a = 5;
	NeobicnaKlasa b(a);
	return 0;
}
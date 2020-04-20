/* TP, 2018/2019, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
// pomocna funkcija za obrtanje cifara broja
int ObrniCifre(int n)
{
	int y=0;
	if(n==0) return 0;
	if(n<0) n=-n;
	while(n!=0) {
		y=y*10+(n%10);
		n/=10;
	}
	return y;
}
// pomocna funkcija za ispitivanje palindromske otpornosti broja
int PalindromskiBroj(int x)
{
	if(x<0) x=-x;
	if(x==ObrniCifre(x)) return 0;
	int brojac = 0;
	while(1) {
		x = x + ObrniCifre(x);
		brojac++;
		if(x==ObrniCifre(x)) break;
	}
	return brojac;
}

std::vector<int> PalindromskaOtpornost(std::vector<int> v)
{
	std::vector<int> x;
	for(int i = 0; i<v.size(); i++) {
		x.push_back(PalindromskiBroj(v.at(i)));

	}

	return x;
}


int main ()
{
	int n;
	std::cout<<"Koliko zelite unijeti elemenata: ";
	std::cin>>n;
	std::vector<int> v;
	std::cout<<"Unesite elemente: ";

	for(int i = 0; i<n; i++) {
		int a;
		std::cin>>a;
		v.push_back(a);
	}

	std::vector<int> k = PalindromskaOtpornost(v);

	for(int i = 0; i<v.size(); i++) {
		std::cout<<"Palindromska otpornost broja "<<v.at(i)<<" iznosi "<<k.at(i)<<std::endl;
	}
	return 0;
}

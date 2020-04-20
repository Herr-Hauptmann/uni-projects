/* 
    TP 2018/2019: Tutorijal 6, Zadatak 3
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
#include <new>
int** KreirajTrougao(int n){
	if(n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
	int** a = nullptr;
	try{
	a = new int*[n];
	for(int i = 0; i<n; i++){
		a[i] = new int[2*i+1];
		for(int j = 0; j<2*i+1; j++){
			if(i>j) a[i][j] = i+1-j;
			else a[i][j] = j+1-i;
		}
	}
	return a;

	}
	catch(std::bad_alloc){
		for(int i = 0; i<n; i++) delete[] a[i];
		delete[] a;
		throw std::bad_alloc();
	}
	
}
int main ()
{
	std::cout<<"Koliko zelite redova: ";
	int n;
	std::cin>>n;
	int ** m = nullptr;
	try{
     m=KreirajTrougao(n);
     for(int i = 0; i<n; i++){
		for(int j = 0; j<i*2+1; j++) std::cout<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
		for(int i = 0; i<n; i++) delete[] m[i];
		delete[] m;
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
		return 0;
	}
	catch(std::bad_alloc e){
		std::cout<<"Izuzetak: Nedovoljno memorije!";
		return 0;
	}
	
	return 0;
}
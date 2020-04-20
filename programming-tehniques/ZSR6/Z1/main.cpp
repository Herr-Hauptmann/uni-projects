#include <iostream>
#include <new>
#include <stdexcept>
#include <string>

int main ()
{
	std::cout<<"Unesite broj recenica: ";
	int n; 
	std::cin>>n;
	std::cin.ignore(10000,'\n');
	
	std::string *pok=new std::string[n];
	
	
	std::cout<<"Unesite recenice: ";
	
	
	for(int i = 0; i<n; i++){
	    std::string pomocni;
	    std::getline(std::cin, pomocni);
	    pok[i]=pomocni;
	}
	return 0;
}
//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>

void IzvrniString(std::string& s){
    char temp;
    int vel = s.length();
    for(int i = 0; i<vel/2; i++){
    temp = s.at(i);
    s.at(i) = s.at(vel-i-1);
    s.at(vel-i-1) = temp;
    }
}
int main ()
{
    std::string d;
    std::cout<<"Unesi string: ";
    std::getline(std::cin,d);
    std::cout<<"Izvrnuti string je: ";
    IzvrniString(d);
    std::cout<<d;
	return 0;
}
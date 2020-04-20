//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <iomanip>
struct Vrijeme{
    int sati,minute,sekunde;
};
void TestirajVrijeme(Vrijeme &v){
    if(!(v.sati>=0&&v.sati<=23) ||!(v.minute>=0&&v.minute<=59)|| !(v.sekunde>=0&&v.sekunde<=59)) throw std::domain_error("Neispravno vrijeme");
}
void IspisiVrijeme(Vrijeme &v){
    try{
        TestirajVrijeme(v);
    }
    catch(...){
        throw;
    }
    std::cout<<std::setfill('0')<<std::setw(2)<<v.sati<<":";
    std::cout<<std::setfill('0')<<std::setw(2)<<v.minute<<":";
    std::cout<<std::setfill('0')<<std::setw(2)<<v.sekunde<<std::endl;
}
Vrijeme SaberiVrijeme(Vrijeme v1, Vrijeme v2){
    try{
        TestirajVrijeme(v1);
        TestirajVrijeme(v2);
    }
    catch(...){
        throw;
    }
    Vrijeme res;
    int pomocna = (v1.sati * 3600) + (v2.sati * 3600) + (v1.minute * 60) + (v2.minute * 60) + v1.sekunde + v2.sekunde;
    int brojac = 0;
    while(pomocna>=3600){
        brojac++;
        pomocna-=3600;
    }
    if(brojac>=24) brojac-=24;
    res.sati = brojac;
    brojac = 0;
    while(pomocna>=60){
        brojac++;
        pomocna-=60;
    }
    res.minute = brojac;
    res.sekunde = pomocna;
    return res;
}
int main ()
{
    Vrijeme v1, v2;
    std::cout<<"Unesite prvo vrijeme (h m s): ";
    std::cin>>v1.sati;
    std::cin>>v1.minute;
    std::cin>>v1.sekunde;
    try{
        TestirajVrijeme(v1);
    }
    catch(std::domain_error e){
        std::cout<<e.what();
        return 0;
    }
    std::cout<<"Unesite drugo vrijeme (h m s): ";
    std::cin>>v2.sati;
    std::cin>>v2.minute;
    std::cin>>v2.sekunde;
    try{
        TestirajVrijeme(v2);
    }
    catch(std::domain_error e){
        std::cout<<e.what();
        return 0;
    }
    Vrijeme v3;
    try{
    v3 = SaberiVrijeme(v1,v2);
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
    std::cout<<"Prvo vrijeme: ";
    IspisiVrijeme(v1);
    std::cout<<"Drugo vrijeme: ";
    IspisiVrijeme(v2);
    std::cout<<"Zbir vremena: ";
    IspisiVrijeme(v3);
	return 0;
}
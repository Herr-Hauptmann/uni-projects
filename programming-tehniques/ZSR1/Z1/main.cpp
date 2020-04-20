//TP 2017/2018: ZSR 1, Zadatak 1
#include <iostream>

int main ()
{
    int h1, m1, s1,h2,m2,s2;
    std::cout<<"Unesite prvo vrijeme (h m s): ";
    std::cin>>h1>>m1>>s1;
    std::cout<<"Unesite drugo vrijeme (h m s): ";
    std::cin>>h2>>m2>>s2;
    
    int ukupno1 = h1*3600 + m1*60 + s1;
    int ukupno2 = h2*3600 + m2*60 + s2;
    
    int razlika = abs(ukupno1 - ukupno2);
    
    int h3=0, m3=0, s3=0;
    
    while(razlika>=3600){
        h3++;
        razlika-=3600;
    }
    
    while(razlika>=60){
        m3++;
        razlika-=60;
    }
    
    while(razlika>0){
        s3++;
        razlika-=1;
    }
    
    std::cout<<"Izmedju ova dva trenutka proteklo je "<<h3<<"h "<<m3<<"min "<<s3<<"s.";
    
    
	return 0;
}

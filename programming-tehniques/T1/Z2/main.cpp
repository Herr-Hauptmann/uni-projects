#include <cstdio>
#include <iostream>
#include <cmath>


int main()
{
    double a,b,c;
    std::cout<<"Unesite tri broja: ";
    std::cin>>a>>b>>c;
    if(a<=0 || b<=0 || c<=0) {
        std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!"<<std::endl;
        return 0;
    }
    if((a+b)<=c || (b+c)<=a || (a+c)<=b) {
        std::cout<<"Ne postoji trougao cije su duzine stranica "<<a<<", "<<b<<" i "<<c<<"!";
        return 0;
    }

    double obim = a + b + c;
    double s = (a + b + c) / 2;
    double P = sqrt(s*(s-a)*(s-b)*(s-c));

    double min;

    double gama = acos((a*a+b*b-c*c)/(2*a*b));
    double alfa = acos((c*c+b*b-a*a)/(2*c*b));
    double beta = acos((a*a+c*c-b*b)/(2*a*c));
    // std::cout<<alfa<<beta<<gama<<std::endl;


    min = gama;
    if(alfa-min < 0.00001) min = alfa;
    if(beta-min < 0.00001) min = beta;
    // std::cout<<min;

    double PI = 4*atan(1);
    min=min*(180/PI);

    int stepen=0, minuta=0, sekunda=0;

    double res = 3600*min;

    while(res-3600>=0) {
        stepen++;
        res-=3600;
    }

    while(res-60>=0) {
        minuta++;
        res-=60;
    }

    while(res-1>=0) {
        sekunda++;
        res-=1;
    }


    std::cout<<"Obim trougla sa duzinama stranica "<<a<<", "<<b<<" i "<<c<<" iznosi "<<obim<<"."<<std::endl;
    std::cout<<"Njegova povrsina iznosi "<<P<<"."<<std::endl;
    std::cout<<"Njegov najmanji ugao ima "<<stepen<<" stepeni, "<<minuta<<" minuta i "<<sekunda<<" sekundi.";



    return 0;
}

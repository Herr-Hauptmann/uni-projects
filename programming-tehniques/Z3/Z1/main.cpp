//TP 2018/2019: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <utility>
#include <stdexcept>
#include <vector>
#include <cmath>
double max(double a, double b)
{
    return (a<b) ? b : a;
}
double min(double a, double b)
{
    return (a<b) ? a : b;
}

double tezinskikoeficjent(int i,std::vector<std::pair<double,double>> cvorovi, double d )
{
    int n = cvorovi.size();
    double w = 0;
    int k = max(1,i-d);
    for(k; k<=min(i,n-d); k++) {
        double pomocna = 1;
        for(int j = k; j<=k+d; j++) {
            if(i-1==j-1) continue;
            pomocna*=1/(cvorovi.at(i-1).first-cvorovi.at(j-1).first);
        }
        w+=pow(-1,k-1)*pomocna;
    }
    return w;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi, double d)
{
    if(d<0 || d>cvorovi.size() || cvorovi.size()==0) throw std::domain_error("Nedozvoljen red");
    for(int i = 0; i<cvorovi.size(); i++) {
        for(int j = i+1; j<cvorovi.size(); j++) {
            if(cvorovi.at(i).first == cvorovi.at(j).first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w;
    for(int i = 0; i<cvorovi.size(); i++) w.push_back(tezinskikoeficjent(i+1,cvorovi,d));

    return [cvorovi,d,w](double x) {
        double suma1 = 0;
        for(int i = 0; i<cvorovi.size(); i++) {
            if(x==cvorovi.at(i).first) return cvorovi.at(i).second;
            suma1+= (w.at(i)/(x-cvorovi.at(i).first))*cvorovi.at(i).second;
        }
        double suma2 = 0;
        for(int i = 0; i<cvorovi.size(); i++) {
            suma2+= w.at(i)/(x-cvorovi.at(i).first);
        }
        return suma1/suma2;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, double d)
{
    if(x_min > x_max || delta_x<=0 || x_min==x_max) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    double temp = x_min;
    while(temp<=x_max) {
        cvorovi.push_back(std::make_pair(temp,f(temp)));
        temp+=delta_x;
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}

int main ()
{
    for(;;) {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int meni;
        std::cin>>meni;
        if(!std::cin) break;
        if(meni==1) {
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>>v(n);
            for(int i = 0; i<n; i++) {
                int x, y;
                std::cin>>x;
                std::cin>>y;
                v.at(i) = {x,y};
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    return 0;
                }
                try{
                std::cout<<"f("<<arg<<") = "<<BaricentricnaInterpolacija(v,d)(arg)<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<e.what();
                    return 0;
                }
            }
        } else {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x1,x2,dx;
            std::cin>>x1;
            std::cin>>x2;
            std::cin>>dx;
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    return 0;
                }
                try{
                std::cout<<"f("<<arg<<") = "<<arg*arg+std::sin(arg)<<" fapprox("<<arg<<") = "<<BaricentricnaInterpolacija([](double x) {
                    return x*x + std::sin(x);
                },x1,x2,dx,d)(arg)<<std::endl;
                }
                catch(std::domain_error e){
                    std::cout<<e.what();
                    return 0;
                }
            }

        }
    }
    return 0;
}

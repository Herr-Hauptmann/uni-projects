//TP 2018/2019: Tutorijal 14, Zadatak 1
#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <cstring>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

double ProsjecnaTemp(std::vector<double> v)
{
    double suma = 0;
    for(int i = 0; i < v.size(); i++) suma+=v.at(i);
    return suma / v.size();
}

bool RanijiDatum(int d1, int m1, int g1, int d2, int m2, int g2)
{
    if(g1 < g2) return true;
    if(g1 <= g2 && m1 < m2) return true;
    if(g1 <= g2 && m1 <= m2 && d1 < d2) return true;
    return false;
}

struct Metro {
    std::string naziv;
    int dan, mjesec, godina;
    std::vector<double> mjerenja;
};

int main ()
{
    std::vector<Metro> v;
    std::ifstream tok("TEMPERATURE.TXT");
    if(!tok) std::cout<<"Datoteka TEMPERATURE.TXT ne postoji!"<<std::endl;
    else {
        std::ofstream izlaz("IZVJESTAJ.TXT");
        for(;;) {
            int dan, mjesec, godina;
            char znak;
            tok>>dan>>znak>>mjesec>>znak>>godina;
            std::string naziv;
            std::vector<double> mjerenja;
            tok.ignore(10000,'\n');
            std::getline(tok,naziv);
            double x;
            while(1) {
                tok>>x;
                mjerenja.push_back(x);
                if(tok.peek() == ',') {
                    char znak;
                    tok>>znak;
                    continue;
                } else {
                    break;
                }
            }
            if(!tok.eof()) tok.clear();
            Metro m;
            m.naziv = naziv;
            m.dan = dan;
            m.mjesec = mjesec;
            m.godina = godina;
            m.mjerenja = mjerenja;
            v.push_back(m);
            if(!tok) break;
        }
        std::sort(v.begin(),v.end(),[](Metro m1, Metro m2)->bool{
            if(m1.dan == m2.dan && m1.godina == m2.godina && m1.mjesec == m2.mjesec)
            {
                return ProsjecnaTemp(m1.mjerenja) < ProsjecnaTemp(m2.mjerenja);
            }
            return RanijiDatum(m1.dan,m1.mjesec,m1.godina,m2.dan,m2.mjesec,m2.godina);
        });
        for(int i = 0; i < v.size(); i++) {
            izlaz<<std::fixed<<std::setprecision(0);
            izlaz<<v.at(i).naziv<<std::endl;
            for(int j = 0; j < v[i].naziv.size(); j++) izlaz<<"-";
            izlaz<<std::endl;
            izlaz<<"Datum mjerenja: "<<v[i].dan<<"/"<<v[i].mjesec<<"/"<<v[i].godina<<std::endl;
            auto max = std::max_element(v[i].mjerenja.begin(),v[i].mjerenja.end());
            auto min = std::min_element(v[i].mjerenja.begin(),v[i].mjerenja.end());
            izlaz<<"Minimalna temperatura: "<<*min<<std::endl;
            izlaz<<"Maksimalna temperatura: "<<*max<<std::endl;
            izlaz<<"Prosjecna temperatura: "<<std::fixed<<std::setprecision(2)<<ProsjecnaTemp(v[i].mjerenja)<<std::endl;
            izlaz<<std::endl;
        }
        izlaz.close();
        tok.close();
    }




    return 0;
}

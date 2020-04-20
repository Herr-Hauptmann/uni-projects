//TP 2018/2019: Tutorijal 14, Zadatak 4
#include <iostream>
#include <ios>
#include <fstream>
#include <cmath>
#include <stdexcept>

void IzvrniDatoteku(std::string ime_datoteke){
    std::fstream tok(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
    if(!tok) throw std::logic_error("Datoteka ne postoji");
    std::fstream tok2(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
    if(!tok2) throw std::logic_error("Datoteka ne postoji");
    tok.seekg(0,std::ios::end);
    int velicina = tok.tellg() / sizeof(double);
    for (int i = 0; i < velicina / 2; i++){
        tok.seekg(0,std::ios::beg);
        tok2.seekg(0,std::ios::end);
        tok.seekg(i*sizeof(double),std::ios::beg);
        tok2.seekg(int(velicina-i-1)*sizeof(double),std::ios::beg);
        double broj1, broj2;
        tok.read(reinterpret_cast<char*>(&broj1),sizeof broj1);
        tok2.read(reinterpret_cast<char*>(&broj2),sizeof broj2);
        //std::cout<<broj1<<" "<<broj2<<std::endl;
        tok.seekp(i*sizeof(double),std::ios::beg);
        tok2.seekp(int(velicina-i-1)*sizeof(double),std::ios::beg);
        tok.write(reinterpret_cast<char*>(&broj2),sizeof broj2);
        tok2.write(reinterpret_cast<char*>(&broj1),sizeof broj1);
    }
    tok.close(); tok2.close();
}

int main ()
{
    double niz[] = {-1, -2, -3, -4, -5, -5.5, -76, 1, 2, 3, 0, 100};
	double novi[12]{};
	std::ofstream f ("dat.bin", std::ios::binary);
	f.write((char *)niz, sizeof niz);
	f.close();
	IzvrniDatoteku("dat.bin");
	std::ifstream ff ("dat.bin", std::ios::binary);
	ff.read((char *)novi, sizeof novi);
	for (int i = 0; i < 12; ++i) std::cout << novi[i] << ", ";
	ff.close();
	return 0;
}
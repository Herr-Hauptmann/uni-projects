#include <iostream>
#include <stdexcept>
template <typename Tip>
class Stek
{
    Tip** p;
    int vrh_index;
    int br_elemenata;
    int kapacitet = 10;
public:
    Stek()
    {
        p = new Tip*[kapacitet];
        br_elemenata = 0;
        vrh_index = -1;
    }
    Stek(const Stek<Tip>& s){
        kapacitet = s.kapacitet;
        br_elemenata = s.br_elemenata;
        p = new Tip*[kapacitet];
        for(int i = 0; i < br_elemenata; i++) p[i] = new Tip(*s.p[i]);
        vrh_index = br_elemenata - 1;
    }
    void stavi(const Tip& el)
    {
        if(!(br_elemenata + 1 < kapacitet)) {
            Tip** q = p;
            p = new Tip*[kapacitet + int(kapacitet / 2)] {};
            for(int i = 0; i < br_elemenata; i++) p[i] = new Tip(*q[i]);
            for(int i = 0; i < br_elemenata; i++) delete q[i];
            delete[] q;
            p[br_elemenata] = new Tip(el);
            br_elemenata++;
            kapacitet += int(kapacitet / 2);
            vrh_index = br_elemenata - 1;
        } else {
            p[br_elemenata] = new Tip(el);
            br_elemenata++;
            vrh_index = br_elemenata - 1;
        }
    }

    void brisi()
    {
        if(br_elemenata != 0) {
            for(int i = 0; i < br_elemenata; i++) delete p[i];
            br_elemenata = 0;
            vrh_index = -1;
        }
    }

        Tip skini() {
            if(br_elemenata == 0){
                throw std::range_error("e");
                
            }
            Tip ret = *p[vrh_index];
            delete p[vrh_index];
            p[vrh_index] = nullptr;
            vrh_index--;
            br_elemenata--;
            return ret;
        }

        Tip& vrh() {
            if(br_elemenata == 0) throw std::logic_error("Prazan stek");
            return *p[vrh_index];
        }

        int brojElemenata() const {
            return br_elemenata;
        }
        Stek<Tip>& operator=(const Stek<Tip>& s) {
            if(&s == this) return *this;
            if(br_elemenata != 0) {
                for(int i = 0; i < br_elemenata; i++) delete p[i];
                delete[] p;
                p = nullptr;
            }
            if(p != nullptr) delete[] p;
            p = new Tip*[s.kapacitet];
            kapacitet = s.kapacitet;
            for(int i = 0; i < s.br_elemenata; i++) p[i] = new Tip(*s.p[i]);
            br_elemenata = s.br_elemenata;
            vrh_index = br_elemenata - 1;
            return *this;

        }
        ~Stek() {
            if(br_elemenata != 0) {
                for(int i = 0; i < br_elemenata; i++) delete p[i];
                delete[] p;
            }
            else delete[] p;
        }

    };
    
    
bool StekTest1(){
    Stek<int> s;
    if(s.brojElemenata() != 0) return false;
    for(int i = 0; i < 10; i++) s.stavi(i);
    if(s.brojElemenata() != 10) return false;
    int vel = s.brojElemenata();
    for(int i = 0; i < vel; i++) s.skini();
    if(s.brojElemenata() != 0) return false;
    for(int i = 0; i < 10; i++) s.stavi(i);
    s.vrh() = 63;
    if(s.skini() != 63) return false;
    s.brisi();
    if(s.brojElemenata() != 0) return false;
    for(int i = 0; i < 10; i++) s.stavi(i);
    Stek<int> s2(s);
    if(s2.brojElemenata() != s.brojElemenata()) return false;
    for(int i = 0; i < 10; i++){
        if(s.skini() != s2.skini()) return false;
    }
    for(int i = 0; i < 10; i++) s.stavi(i);
    s2 = s;
    if(s2.brojElemenata() != s.brojElemenata()) return false;
    for(int i = 0; i < 10; i++){
        if(s.skini() != s2.skini()) return false;
    }
    return true;
}

bool StekTest2(){
    try{
    Stek<int> s;
    for(int i = 0; i < 10; i++) s.stavi(i);
    for(int i = 0; i < 10; i++) s.skini();
    }
    catch(...){
        throw;
    }
    return true;
}

bool StekTest3(){
      Stek<int> s;
    try{
        s.vrh();
    }
    catch(...){
        throw;
    }
    return true;
}



int main(){
    std::cout<<"Test1: "<<std::boolalpha<<StekTest1()<<std::endl;
    try{
        StekTest2();
    }
    catch(...){
        std::cout<<"Dobar!"<<std::endl;
    }
    try{
     StekTest3();
    }
    catch(...){
        std::cout<<"Dobar 2!"<<std::endl;
    }
    return 0;
}

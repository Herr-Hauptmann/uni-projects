#include <iostream>
#include <vector>
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
    Stek(const Stek<Tip>& s)
    {
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

    Tip skini()
    {
        if(br_elemenata == 0) {
            throw std::range_error("e");

        }
        Tip ret = *p[vrh_index];
        delete p[vrh_index];
        p[vrh_index] = nullptr;
        vrh_index--;
        br_elemenata--;
        return ret;
    }

    Tip& vrh()
    {
        if(br_elemenata == 0) throw std::logic_error("Prazan stek");
        return *p[vrh_index];
    }

    int brojElemenata() const
    {
        return br_elemenata;
    }
    Stek<Tip>& operator=(const Stek<Tip>& s)
    {
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
    ~Stek()
    {
        if(br_elemenata != 0) {
            for(int i = 0; i < br_elemenata; i++) delete p[i];
            delete[] p;
        } else delete[] p;
    }

};

void pretraga(Stek<std::vector<int>>&s, int trazeni, std::vector<int> v = {})
{
    if(s.brojElemenata() == 0) {
        std::cout<<"Nema elementa"<<std::endl;
        return;
    }
    if(s.vrh().size() == 0) {
        pretraga(s, trazeni, s.skini());
        s.stavi(v);
    } else if(trazeni < s.vrh()[0]) {
        pretraga(s, trazeni, s.skini());
        s.stavi(v);
    } else {
        int l = 0;
        int r = s.vrh().size() - 1;
        while(l <= r) {
            int m = (int)(l + r) / 2;
            if(s.vrh()[m] > trazeni ) r = m - 1;
            else if(s.vrh()[m] < trazeni) l = m + 1;
            else {
                std::cout<<m<<" "<<s.brojElemenata()-1;
                s.stavi(v);
                return;
            }
        }
    std::cout<<"Nema elementa";
    s.stavi(v);
    return;
    }
}

void test1(){
    std::vector<int> veka;
    Stek<std::vector<int>> s;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++) veka.push_back(i*j);
        s.stavi(veka);
        veka.resize(0);
    }
    pretraga(s,1);
}

void test2(){
    Stek<std::vector<int>> s;
    pretraga(s,2);
}

void test3(){
    Stek<std::vector<int>> s;
    std::vector<int> veka;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++) veka.push_back(i*j);
        s.stavi(veka);
        veka.resize(0);
    }
    pretraga(s,-28);
}
void test4(){
    Stek<std::vector<int>> s;
    std::vector<int> veka;
    for(int i = 1; i <= 50; i++){
        for(int j = 1; j <= 50; j++ ) veka.push_back(i*j);
        s.stavi(veka);
        veka.resize(0);
    }
    pretraga(s,150);
}
int main()
{
    test1();
    test2();
    test3();
    return 0;
}

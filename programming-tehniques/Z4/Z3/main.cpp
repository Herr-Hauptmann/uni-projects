//TP 2018/2019: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <utility>
#include <initializer_list>
#include <new>
#include <memory>
#include <algorithm>
int BrojDana(int mjesec, int godina)
{
    if(mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) return 30;
    if(mjesec != 2) return 31;
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) return 29;
    return 28;
}
bool TestDatuma(int dan, int mjesec, int godina)
{
    if(dan < 1 || mjesec < 1 || godina < 1 || mjesec > 12 || dan > BrojDana(mjesec,godina)) return false;
    return true;
}
bool TestVremena(int sati, int minute)
{
    if(sati<0 && sati>23 || minute < 0 && minute > 59) return false;
    return true;
}
class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int,int,int> Ocitaj() const;
    void Ispisi() const;
};
Datum::Datum(int dan, int mjesec, int godina)
{
    if(!TestDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    if(!TestDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

std::tuple<int,int,int> Datum::Ocitaj() const
{
    auto ret = std::make_tuple(dan,mjesec,godina);
    return ret;
}

void Datum::Ispisi() const
{
    std::cout<<dan<<"/"<<mjesec<<"/"<<godina;

}

class Vrijeme
{
    int sati, minute;
public:
    void Postavi(int sati, int minute);
    std::pair<int,int> Ocitaj() const;
    void Ispisi() const;
};

void Vrijeme::Postavi(int sati, int minute)
{
    if(!TestVremena(sati,minute)) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}

std::pair<int,int> Vrijeme::Ocitaj() const
{
    auto ret = std::make_pair(sati,minute);
    return ret;
}

void Vrijeme::Ispisi() const
{
    std::cout<<std::setw(2)<<std::setfill('0')<<sati<<":"<<minute;
}

class Pregled
{
    std::string ime_pacijenta;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const std::string &ime_pacijenta, const Datum& datum_pregleda,
            const Vrijeme& vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): datum(datum_pregleda)
{
    auto v = vrijeme_pregleda.Ocitaj();
    int s = v.first;
    int min = v.second;
    vrijeme.Postavi(s,min);
    Pregled::ime_pacijenta = ime_pacijenta;
}
Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda):
    datum(dan_pregleda,mjesec_pregleda,godina_pregleda)
{
    vrijeme.Postavi(sati_pregleda,minute_pregleda);
    Pregled::ime_pacijenta = ime_pacijenta;
}
void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta)
{
    Pregled::ime_pacijenta = ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum& novi_datum)
{
    Pregled::datum = novi_datum;
}

void Pregled::PromijeniVrijeme(const Vrijeme& novo_vrijeme)
{
    vrijeme = novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed()
{
    auto t = datum.Ocitaj();
    datum.Postavi(std::get<0>(t),std::get<1>(t),std::get<2>(t)+1);
}

void Pregled::PomjeriDanUnazad()
{
    auto t = datum.Ocitaj();
    datum.Postavi(std::get<0>(t),std::get<1>(t),std::get<2>(t)-1);
}

std::string Pregled::DajImePacijenta() const
{
    return ime_pacijenta;
}

Datum Pregled::DajDatumPregleda() const
{
    return datum;
}

Vrijeme Pregled::DajVrijemePregleda() const
{
    return vrijeme;
}

bool Pregled::DolaziPrije(const Pregled& p1, const Pregled& p2)
{
    int d1,d2,m1,m2,g1,g2,s1,s2,min1,min2;
    auto t1 = p1.DajDatumPregleda().Ocitaj();
    auto t2 = p2.DajDatumPregleda().Ocitaj();
    auto par1 = p1.DajVrijemePregleda().Ocitaj();
    auto par2 = p2.DajVrijemePregleda().Ocitaj();
    g1 = std::get<0>(t1);
    m1 = std::get<1>(t1);
    d1 = std::get<2>(t1);
    g2 = std::get<0>(t2);
    m2 = std::get<1>(t2);
    d2 = std::get<2>(t2);
    s1 = std::get<0>(par1);
    min1 = std::get<1>(par1);
    s2 = std::get<0>(par2);
    min2 = std::get<1>(par2);
    if(g1 > g2) return false;
    if(g1 <= g2 && m1 > m2) return false;
    if(g1 <= g2 && m1 <= m2 && d1 > d2) return false;
    if(s1 > s2) return false;
    if(s1 <= s2 && min1 > min2) return false;
    return true;
}

void Pregled::Ispisi() const
{
    std::cout<<std::setw(30)<<std::left<<this->DajImePacijenta()<<" ";
    this->DajDatumPregleda().Ispisi();
    std::cout<<" ";
    this->DajVrijemePregleda().Ispisi();
    std::cout<<std::endl;
}

class Pregledi
{
    int max_broj_pregleda;
    int broj_pregleda;
    Pregled** pregledi = nullptr;
public:
    explicit Pregledi(int max_broj_pregleda);
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled* p);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled DajNajranijiPregled() const;
    Pregled& DajNajranijiPregled();
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum& datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(int max_broj_pregleda): max_broj_pregleda(max_broj_pregleda)
{
    try {
        pregledi = new Pregled*[max_broj_pregleda] {};
    } catch(...) {
        std::cout<<"Memorijska greska";
    }
}

Pregledi::~Pregledi()
{
    if(broj_pregleda != 0) {
        for(int i = 0; i < broj_pregleda; i++) delete pregledi[i];
        delete[] pregledi;
    }
}

Pregledi::Pregledi(const Pregledi& pregledi)
{
    Pregledi::max_broj_pregleda = pregledi.max_broj_pregleda;
    Pregledi::broj_pregleda = pregledi.broj_pregleda;
    try {
        Pregledi::pregledi = new Pregled*[max_broj_pregleda] {};
    } catch(...) {
        throw;
    }
    try {
        for(int i = 0; i < broj_pregleda; i++) {
            std::string ime = pregledi.pregledi[i]->DajImePacijenta();
            Datum datum = pregledi.pregledi[i]->DajDatumPregleda();
            Vrijeme vrijeme = pregledi.pregledi[i]->DajVrijemePregleda();
            Pregledi::pregledi[i] = new Pregled(ime,datum,vrijeme);
        }
    } catch(...) {
        for(int i = 0; i < broj_pregleda; i++) delete Pregledi::pregledi[i];
        delete[] Pregledi::pregledi;
        throw;
    }

}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    max_broj_pregleda = spisak_pregleda.size();
    broj_pregleda = max_broj_pregleda;
    int brojac = 0;
    try {
        for(auto p = spisak_pregleda.begin(); p != spisak_pregleda.end(); p++) {
            Pregledi::pregledi[brojac] = new Pregled(*p);
            brojac++;
        }
    } catch(...) {
        for(int i = 0; i < max_broj_pregleda; i++) delete pregledi[i];
        delete[] pregledi;
        throw;
    }
}

Pregledi& Pregledi::operator =(const Pregledi& pregledi){
    if(max_broj_pregleda < pregledi.max_broj_pregleda){
        for(int i = 0; i < max_broj_pregleda; i++) delete Pregledi::pregledi[i];
        delete[] Pregledi::pregledi;
        Pregledi::pregledi = nullptr;
        try{
            Pregledi::pregledi = new Pregled*[pregledi.max_broj_pregleda]{};
        }
        catch(...){
            throw;
        }
        max_broj_pregleda = pregledi.max_broj_pregleda;
        try{
            for(int i = 0; i < pregledi.broj_pregleda; i++) Pregledi::pregledi[i] = new Pregled(*pregledi.pregledi[i]);
        }
        catch(...){
            for(int i = 0; i < max_broj_pregleda; i++) delete Pregledi::pregledi[i];
            delete[] Pregledi::pregledi;
        }
    }
    else{
        for(int i = pregledi.max_broj_pregleda; i < max_broj_pregleda; i++) Pregledi::pregledi[i] = nullptr;
        max_broj_pregleda = pregledi.max_broj_pregleda;
        for(int i = 0; i < pregledi.broj_pregleda; i++){
            Pregledi::pregledi[i]->PromijeniDatum(pregledi.pregledi[i]->DajDatumPregleda());
            Pregledi::pregledi[i]->PromijeniPacijenta(pregledi.pregledi[i]->DajImePacijenta());
            Pregledi::pregledi[i]->PromijeniVrijeme(pregledi.pregledi[i]->DajVrijemePregleda());
        }
    }
    return *this;
}

Pregledi& Pregledi::operator =(Pregledi&& pregledi){
    std::swap(Pregledi::pregledi,pregledi.pregledi);
    std::swap(Pregledi::broj_pregleda,pregledi.broj_pregleda);
    std::swap(max_broj_pregleda,pregledi.max_broj_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum& datum_pregleda, const Vrijeme& vrijeme_pregleda){
    if(broj_pregleda == max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    else pregledi[broj_pregleda] = new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    if(broj_pregleda == max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    else pregledi[broj_pregleda] = new Pregled(ime_pacijenta,dan_pregleda,mjesec_pregleda,godina_pregleda,sati_pregleda,minute_pregleda);
    broj_pregleda++;
}

void Pregledi::RegistrirajPregled(Pregled* p){
    if(broj_pregleda == max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    else pregledi[broj_pregleda] = p;
    broj_pregleda++;
}

int Pregledi::DajBrojPregleda() const{
    if(broj_pregleda == 0) std::domain_error("Nema registriranih pregleda");
    return broj_pregleda;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum& datum) const{
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    int brojac = 0;
    brojac = std::count_if(pregledi,pregledi+broj_pregleda,[&datum](Pregled* p){
        auto t1 = p->DajDatumPregleda().Ocitaj();
        auto t2 = datum.Ocitaj();
        if(t1 == t2) return true;
        else return false;
    });
    return brojac;
}

Pregled& Pregledi::DajNajranijiPregled(){
    auto m = std::min_element(pregledi,pregledi+broj_pregleda,[](Pregled* p1, Pregled* p2)->bool{
        auto t1 = p1->DajDatumPregleda().Ocitaj();
        auto t2 = p2->DajDatumPregleda().Ocitaj();
        return t1 > t2;
    });
    
    return **m;
}

Pregled Pregledi::DajNajranijiPregled() const{
    auto m = std::min_element(pregledi,pregledi+broj_pregleda,[](Pregled* p1, Pregled* p2)->bool{
        auto t1 = p1->DajDatumPregleda().Ocitaj();
        auto t2 = p2->DajDatumPregleda().Ocitaj();
        return t1 > t2;
    });
    return **m;
}

void Pregledi::IsprazniKolekciju(){
    for(int i = 0; i < broj_pregleda; i++){
        delete pregledi[i];
        pregledi[i] = nullptr;
    }
    broj_pregleda = 0;
}







int main ()
{
    return 0;
}

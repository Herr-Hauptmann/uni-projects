//TP 2018/2019: Tutorijal 8, Zadatak 2
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
const int BrojPredmeta(8);
struct Datum {
 int dan, mjesec, godina;
};
struct Ucenik {
 std::string ime, prezime;
 Datum datum_rodjenja;
 int ocjene[BrojPredmeta];
 double prosjek;
 bool prolaz;
};
using PokUcenik = std::shared_ptr<Ucenik>;
int main() {
 void UnesiUcenike(std::vector<PokUcenik> &p_ucenici);
 void ObradiUcenike(std::vector<PokUcenik> &p_ucenici);
 void IspisiIzvjestaj(const std::vector<PokUcenik> &p_ucenici);
 void OslobodiMemoriju(std::vector<PokUcenik> &p_ucenici);
 int broj_ucenika;
 std::cout << "Koliko ima ucenika: ";
 std::cin >> broj_ucenika;
 try {
 std::vector<PokUcenik> p_ucenici(broj_ucenika);
 try {
 UnesiUcenike(p_ucenici); // Ovo može izazvati izuzetak!!!
 }
 catch(...) {
 OslobodiMemoriju(p_ucenici);
 throw;
 }
 ObradiUcenike(p_ucenici);
 IspisiIzvjestaj(p_ucenici);
 OslobodiMemoriju(p_ucenici);
 }
 catch(...) {
 std::cout << "Problemi sa memorijom...\n";
 }
 return 0;
}
void UnesiUcenike(std::vector<PokUcenik> &p_ucenici) {
 void UnesiJednogUcenika(PokUcenik p_ucenik);
 for(int i = 0; i < p_ucenici.size(); i++) {
 std::cout << "Unesite podatke za " << i + 1 << ". ucenika:\n";
 p_ucenici[i] = std::make_shared<Ucenik>();
 UnesiJednogUcenika(p_ucenici[i]);
 }
}
void UnesiJednogUcenika(PokUcenik p_ucenik) {
 void UnesiDatum(Datum &datum);
 void UnesiOcjene(int ocjene[], int broj_predmeta);
 std::cout << "  Ime: "; std::cin >> p_ucenik->ime;
 std::cout << "  Prezime: "; std::cin >> p_ucenik->prezime;
 std::cout << "  Datum rodjenja (D/M/G): ";
 UnesiDatum(p_ucenik->datum_rodjenja);
 UnesiOcjene(p_ucenik->ocjene, BrojPredmeta);
}
void UnesiDatum(Datum &datum) {
 char znak;
 std::cin >> datum.dan >> znak >> datum.mjesec >> znak >> datum.godina;
}
void UnesiOcjene(int ocjene[], int broj_predmeta) {
 for(int i = 0; i < broj_predmeta; i++) {
 std::cout << "  Ocjena iz " << i + 1 << ". predmeta: ";
 std::cin >> ocjene[i];
 }
}
void ObradiUcenike(std::vector<PokUcenik> &p_ucenici) {
 void ObradiJednogUcenika(PokUcenik p_ucenik);
 for(PokUcenik p_ucenik : p_ucenici) ObradiJednogUcenika(p_ucenik);
 std::sort(p_ucenici.begin(), p_ucenici.end(),
 [](const PokUcenik p_u1, const PokUcenik p_u2) {
 return p_u1->prosjek > p_u2->prosjek;
 });
}
void ObradiJednogUcenika(PokUcenik p_ucenik) {
 double suma_ocjena = 0;
 p_ucenik->prosjek = 1; p_ucenik->prolaz = false;
 for(int ocjena : p_ucenik->ocjene) {
 if(ocjena == 1) return;
 suma_ocjena += ocjena;
 }
 p_ucenik->prolaz = true;
 p_ucenik->prosjek = suma_ocjena / BrojPredmeta;
}
void IspisiIzvjestaj(const std::vector<PokUcenik> &p_ucenici) {
 void IspisiJednogUcenika(const PokUcenik p_ucenik);
 std::cout << std::endl;
 for(const PokUcenik p_ucenik : p_ucenici) IspisiJednogUcenika(p_ucenik);
}
void IspisiJednogUcenika(const PokUcenik p_ucenik) {
 void IspisiDatum(const Datum &datum);
 std::cout << "Ucenik " << p_ucenik->ime << " " << p_ucenik->prezime
 << " rodjen ";
 IspisiDatum(p_ucenik->datum_rodjenja);
 if(p_ucenik->prolaz)
 std::cout << " ima prosjek " << std::setprecision(3) << p_ucenik->prosjek;
 else
 std::cout << " mora ponavljati razred";
 std::cout << std::endl;
}
void IspisiDatum(const Datum &datum) {
 std::cout << datum.dan << "/" << datum.mjesec << "/" << datum.godina;
}
void OslobodiMemoriju(std::vector<PokUcenik> &p_ucenici) {
 for(PokUcenik p_ucenik : p_ucenici) p_ucenik = nullptr;
}

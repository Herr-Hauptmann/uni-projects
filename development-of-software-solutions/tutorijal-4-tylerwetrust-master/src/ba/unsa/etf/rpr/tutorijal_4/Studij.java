package ba.unsa.etf.rpr.tutorijal_4;

public class Studij {
    String naziv;
    Predmet[] obavezni;
    Predmet[] izborni;
    public Studij(String naziv, Predmet[] obavezni, Predmet[] izborni){}
    public Predmet[] dajObavezni() {return obavezni;}
    public Predmet[] dajIzborni() {return izborni;}
}

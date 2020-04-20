package com.rpr.t5;

public class Korisnik extends Osoba {
    private Racun racun;

    public void setRacun(Racun racun) {
        this.racun = racun;
    }

    public Korisnik(String ime, String prezime) {
        super(ime, prezime);
    }

    public Racun getRacun() {
        return racun;
    }

    public boolean dodajRacun(Racun r){
        if(racun == null){
            this.racun = new Racun(r.getBrojRacuna(), r.getKorisnikRacuna());
            return true;
        }
        return false;
    }
}

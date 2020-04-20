package com.rpr.t5;

public class Racun {
    private final Long brojRacuna;
    private final Osoba korisnikRacuna;

    public Double getStanjeRacuna() {
        return stanjeRacuna;
    }

    private Double stanjeRacuna;

    public boolean isOdobrenjePrekoracenja() {
        return odobrenjePrekoracenja;
    }

    private boolean odobrenjePrekoracenja;

    public Long getBrojRacuna() {
        return brojRacuna;
    }

    public Osoba getKorisnikRacuna() {
        return korisnikRacuna;
    }

    public Racun(Long brojRacuna, Osoba korisnikRacuna) {
        this.brojRacuna = brojRacuna;
        this.korisnikRacuna = korisnikRacuna;
        this.stanjeRacuna = 0d;
        this.odobrenjePrekoracenja = false;
    }

    public boolean izvrsiUplatu(Double d){
        if(d <= 0) return false;
        this.stanjeRacuna += d;
        return true;
    }

    public boolean izvrsiIsplatu(double d){
        if(d <= 0) return false;
        if(stanjeRacuna - d < 0 && !odobrenjePrekoracenja) return false;
        stanjeRacuna -= d;
        return true;
    }

    public void odobriPrekoracenje(){
        this.odobrenjePrekoracenja = true;
    }

    protected boolean provjeriOdobrenjePrekoracenja(){
        return odobrenjePrekoracenja;
    }
}

package com.rpr.t5.com.rpr.t5.util;

import com.rpr.t5.Korisnik;

import java.util.List;
import java.util.stream.Collectors;

public class Kredit {
    private Kredit(){}
    public static Double dajKreditnuSposobnost(KreditnaSposobnost funkcija, Korisnik korisnik){
        Double d = funkcija.provjeri(korisnik.getRacun());
        return d;
    }

    public static void ispisiSveKorisnikeBezPrekoracenja(List<Korisnik> korisnici){
        List<Korisnik> korisniciBezPrekoracenja = korisnici.stream()
                .filter(korisnik -> korisnik.getRacun().isOdobrenjePrekoracenja() == false).collect(Collectors.toList());

        korisniciBezPrekoracenja.stream().forEach(korisnik -> System.out.println(korisnik.getIme() + " " + korisnik.getPrezime() + "\n"));

    }

    public static void odobriPrekoracenje(List<Korisnik> korisnici){
        List<Korisnik> korisniciSaPrekoracenje = korisnici.stream()
                .filter(korisnik -> korisnik.getRacun().getStanjeRacuna() >= 10000).collect(Collectors.toList());

        korisniciSaPrekoracenje.stream().forEach(korisnik -> korisnik.getRacun().odobriPrekoracenje());

    }
}

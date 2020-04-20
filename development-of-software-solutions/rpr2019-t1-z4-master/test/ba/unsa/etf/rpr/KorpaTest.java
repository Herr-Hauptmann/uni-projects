package ba.unsa.etf.rpr;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class KorpaTest {

    @Test
    void dodajArtikl() {
        Artikl a = new Artikl("gibson", 2000, "666");
        Korpa korpa = new Korpa();
        for (int i = 0; i < 50; i++) korpa.dodajArtikl(a);
        assertEquals(false,korpa.dodajArtikl(a));
        Artikl[] niz = korpa.getArtikli();
        for (Artikl x : niz) {
            assertTrue(x.getNaziv().equals("gibson"));
            assertTrue(x.getCijena() == 2000);
            assertTrue(x.getKod().equals("666"));
        }
    }

    @Test
    void izbaciArtiklSaKodom() {
        Korpa korpa = new Korpa();
        korpa.dodajArtikl(new Artikl("gibson",2000,"666"));
        korpa.dodajArtikl(new Artikl("fender",2000,"111"));
        korpa.dodajArtikl(new Artikl("telecaster",2000,"222"));
        korpa.izbaciArtiklSaKodom("666");
        Artikl[] niz = korpa.getArtikli();
        for(Artikl x: niz){
            if(x != null)
            assertEquals(false,x.getKod().equals("666"));
        }

    }

    @Test
    void getArtikli() {
        Artikl a = new Artikl("gibson",2000,"666");
        Korpa korpa = new Korpa();
        for(int i = 0; i < 20; i++) korpa.dodajArtikl(a);
        Artikl[] niz = korpa.getArtikli();
        assertEquals("gibson",niz[0].getNaziv());

    }

    @Test
    void dajUkupnuCijenuArtikala() {
        Korpa korpa = new Korpa();
        korpa.dodajArtikl(new Artikl("gibson",2000,"666"));
        korpa.dodajArtikl(new Artikl("fender",2000,"111"));
        korpa.dodajArtikl(new Artikl("telecaster",2000,"222"));
        assertTrue(6000 == korpa.dajUkupnuCijenuArtikala());
    }
}
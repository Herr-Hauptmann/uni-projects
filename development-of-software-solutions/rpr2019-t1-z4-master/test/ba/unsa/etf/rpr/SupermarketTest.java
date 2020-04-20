package ba.unsa.etf.rpr;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SupermarketTest {

    @Test
    void dodajArtikl() {
        Supermarket supermarket = new Supermarket();
        Artikl a = new Artikl("gibson",2000,"666");
        supermarket.dodajArtikl(a);
        supermarket.dodajArtikl(a);
        supermarket.dodajArtikl(a);
        Artikl[] niz = supermarket.getArtikli();
        assertEquals("gibson",niz[0].getNaziv());
        assertEquals(2000,niz[0].getCijena());
        assertEquals("666",niz[0].getKod());
    }

    @Test
    void izbaciArtiklSaKodom() {
        Supermarket supermarket = new Supermarket();
        supermarket.dodajArtikl(new Artikl("gibson",2000,"666"));
        supermarket.dodajArtikl(new Artikl("fender",2000,"111"));
        supermarket.dodajArtikl(new Artikl("telecaster",2000,"222"));
        supermarket.izbaciArtiklSaKodom("666");
        Artikl[] niz = supermarket.getArtikli();
        for(Artikl x: niz){
            if(x != null)
                assertEquals(false,x.getKod().equals("666"));
        }

    }

    @Test
    void getArtikli() {
        Artikl a = new Artikl("gibson",2000,"666");
        Supermarket supermarket = new Supermarket();
        for(int i = 0; i < 20; i++) supermarket.dodajArtikl(a);
        Artikl[] niz = supermarket.getArtikli();
        assertEquals("gibson",niz[0].getNaziv());

    }
}
package ba.unsa.etf.rpr;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class ArtiklTest {

    @Test
    void getNaziv() {
        Artikl a = new Artikl("gibson",2000,"666");
        assertEquals("gibson",a.getNaziv());
    }

    @Test
    void setNaziv() {
        Artikl a = new Artikl("gibson",2000,"666");
        a.setNaziv("fender");
        assertEquals("fender",a.getNaziv());
    }

    @Test
    void getCijena() {
        Artikl a = new Artikl("gibson",2000,"666");
        assertEquals(2000,a.getCijena());
    }

    @Test
    void setCijena() {
        Artikl a = new Artikl("gibson",2000,"666");
        a.setCijena(22);
        assertEquals(22,a.getCijena());
    }

    @Test
    void getKod() {
        Artikl a = new Artikl("gibson",2000,"666");
        assertEquals("666",a.getKod());
    }

    @Test
    void setKod() {
        Artikl a = new Artikl("gibson",2000,"666");
        a.setKod("88");
        assertEquals("88",a.getKod());
    }
}
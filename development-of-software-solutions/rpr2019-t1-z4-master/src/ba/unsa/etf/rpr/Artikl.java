package ba.unsa.etf.rpr;

public class Artikl {
    private String naziv;
    private int cijena;
    private String kod;
    public Artikl(String naziv1, int cijena1, String kod1){
        naziv = naziv1; cijena = cijena1; kod = kod1;
    }

    public Artikl(Artikl a){
        naziv = a.getNaziv();
        cijena = a.getCijena();
        kod = a.getKod();
    }
    public String getNaziv() {
        return naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv = naziv;
    }

    public int getCijena() {
        return cijena;
    }

    public void setCijena(int cijena) {
        this.cijena = cijena;
    }

    public String getKod() {
        return kod;
    }

    public void setKod(String kod) {
        this.kod = kod;
    }


}

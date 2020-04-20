package ba.unsa.etf.rpr;

public class Korpa {
    private final int MAX_VALUE = 50;
    private static int brojArtikala = 0;
    public Artikl[] niz = null;
    public Korpa(){
        brojArtikala = 0;
        niz = new Artikl[MAX_VALUE];

    }

    public boolean dodajArtikl(Artikl a){
        brojArtikala++;
        if(brojArtikala > 50) return false;
            this.niz[brojArtikala-1] = new Artikl(a);
            return true;
    }
    public Artikl izbaciArtiklSaKodom(String kod){
        Artikl a = null;
        for(int i = 0; i < brojArtikala; i++){
            if(kod.equals(niz[i].getKod()) == true){
                a = niz[i];
                for(int j = i; j < brojArtikala - 1; j++) niz[j] = niz[j+1];
                brojArtikala--;
                niz[brojArtikala] = null;
                return a;
            }
        }
        return a;
    }
    public Artikl[] getArtikli(){
        return this.niz;
    }

    public int dajUkupnuCijenuArtikala(){
        int suma = 0;
        for(int i = 0; i < brojArtikala; i++) suma += niz[i].getCijena();
        return suma;
    }
}

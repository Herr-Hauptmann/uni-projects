package ba.unsa.etf.rpr;

public class Supermarket {
    private final int MAX_VALUE = 1000;
    public Artikl[] artikli = null;
    private static int brojArtikala = 0;
    public boolean dodajArtikl(Artikl a){
        brojArtikala++;
        if(brojArtikala < 1000) {
            artikli[brojArtikala-1] = new Artikl(a);
            return true;
        }
        return false;
    }
    public Supermarket(){
        artikli = new Artikl[1000];
        brojArtikala = 0;
    }
    public Artikl izbaciArtiklSaKodom(String kod){
        Artikl a = null;
        for(int i = 0; i < brojArtikala; i++){
            if(kod.equals(artikli[i].getKod())){
                a = this.artikli[i];
                for(int j = i; j < brojArtikala - 1; j++) artikli[j] = artikli[j+1];
                brojArtikala--;
                this.artikli[brojArtikala] = null;
                return a;
            }
        }
        return a;
    }
    public Artikl[] getArtikli(){
        return artikli;
    }


}

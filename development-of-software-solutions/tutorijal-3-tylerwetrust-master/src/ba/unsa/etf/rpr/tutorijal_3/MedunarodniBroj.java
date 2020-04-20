package ba.unsa.etf.rpr.tutorijal_3;

public class MedunarodniBroj extends TelefonskiBroj {
    private String drzava;
    private String broj;
    MedunarodniBroj(String drzava, String broj){
        this.drzava = new String(drzava);
        this.broj = new String(broj);
    }
    @Override
    public String ispisi(){
        return (drzava + broj);
    }
    @Override
    public int hashCode(){
        return this.hashCode();
    }
}

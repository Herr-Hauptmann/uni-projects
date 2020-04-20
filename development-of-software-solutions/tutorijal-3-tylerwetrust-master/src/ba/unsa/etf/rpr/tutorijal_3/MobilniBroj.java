package ba.unsa.etf.rpr.tutorijal_3;
import java.lang.String;

public class MobilniBroj extends TelefonskiBroj {
    private int mobilnaMreza;
    private String broj;
    MobilniBroj(int mobilnaMreza, String broj) {
        this.mobilnaMreza = mobilnaMreza;
        this.broj = new String(broj);
    }
    @Override
    public String ispisi(){
        String s = "";
        s+= "0" + mobilnaMreza + "/" + broj;
        return s;
    }
    @Override
    public int hashCode(){
        return broj.hashCode();
    }
}

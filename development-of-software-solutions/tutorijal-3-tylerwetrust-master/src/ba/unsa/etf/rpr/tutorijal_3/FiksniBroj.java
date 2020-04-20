package ba.unsa.etf.rpr.tutorijal_3;
import ba.unsa.etf.rpr.tutorijal_3.Grad;


public class FiksniBroj extends TelefonskiBroj implements Comparable{
    private Grad grad;
    private String broj;

    FiksniBroj(Grad grad, String broj){
        this.grad =  grad;
        this.broj = new String(broj);
        this.broj = grad.dajPozivni(grad) + "/" + broj;
    }

    public Grad getGrad(){
        return this.grad;
    }

    @Override
    public String ispisi(){
        return broj;
    }

    @Override
    public int hashCode(){
        return broj.hashCode();
    }

    @Override
    public int compareTo(Object o){
       if(o instanceof FiksniBroj) o = (FiksniBroj) o;
        return this.ispisi().compareTo(( (FiksniBroj) o).ispisi());
    }



}

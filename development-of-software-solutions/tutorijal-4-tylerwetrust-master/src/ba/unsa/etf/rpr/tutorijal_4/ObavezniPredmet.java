package ba.unsa.etf.rpr.tutorijal_4;

import java.util.ArrayList;

public class ObavezniPredmet extends Predmet {
    abstract String naziv;
    abstract int etcs;
    ArrayList<Student> spisakStudenta;

    ObavezniPredmet(String[] naziv, int etcs){
        this.naziv = String(naziv);
        this.etcs = etcs;
    }

    public void upisiStudenta(Student s){
        spisakStudenta.add(s);
    }

    public String dajSpisak(){
        String ret = "";
        for(Student s: spisakStudenta){
            ret += s.dajIme() + "\n";
        }
        return ret;
    }

    public int dajEtcs(){
        return etcs;
    }
}

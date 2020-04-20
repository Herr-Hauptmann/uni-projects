package ba.unsa.etf.rpr.tutorijal_4;

import java.util.ArrayList;

abstract public class Predmet {
    abstract String naziv;
    abstract int etcs;
    abstract ArrayList<Student> spisakStudenta;
    abstract Predmet(String naziv, int etcs);
    abstract public int dajEtcs();
}

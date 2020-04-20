package ba.unsa.etf.rpr.tutorijal8;

import java.io.Serializable;
import java.util.ArrayList;

public class UN implements Serializable {
    private ArrayList<Drzava> lista;

    public ArrayList<Drzava> getLista() {
        return lista;
    }

    public void setLista(ArrayList<Drzava> lista) {
        this.lista = lista;
    }

    public UN(){}

    public UN(ArrayList<Drzava> lista) {
        this.lista = lista;
    }
}

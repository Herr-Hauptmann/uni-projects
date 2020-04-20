package ba.unsa.etf.rpr;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;

public class Drzava {
    private SimpleIntegerProperty id = new SimpleIntegerProperty();
    private SimpleStringProperty naziv = new SimpleStringProperty();
    private SimpleObjectProperty<Grad> glavniGrad = new SimpleObjectProperty<>();

    public Drzava() {
    }

    public Drzava(int id, String naziv, Grad glavniGrad) {
        this.setId(id);
        this.setNaziv(naziv);
        this.setGlavniGrad(glavniGrad);
    }

    public int getId() {
        return id.get();
    }

    public void setId(int id) {
        this.id.set(id);
    }

    public String getNaziv() {
        return naziv.get();
    }

    public void setNaziv(String naziv) {
        this.naziv.set(naziv);
    }

    public Grad getGlavniGrad() {
        return glavniGrad.get();
    }

    public void setGlavniGrad(Grad glavniGrad) {
        this.glavniGrad.set(glavniGrad);
    }
    @Override
    public String toString() {
        return naziv.get();
    }
}
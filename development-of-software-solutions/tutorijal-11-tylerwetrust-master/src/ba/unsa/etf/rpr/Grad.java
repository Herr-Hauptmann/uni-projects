package ba.unsa.etf.rpr;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;

public class Grad {
    private SimpleIntegerProperty id = new SimpleIntegerProperty();

    public int getPostanskiBroj() {
        return postanskiBroj.get();
    }

    public SimpleIntegerProperty postanskiBrojProperty() {
        return postanskiBroj;
    }

    public void setPostanskiBroj(int postanskiBroj) {
        this.postanskiBroj.set(postanskiBroj);
    }

    private SimpleIntegerProperty postanskiBroj = new SimpleIntegerProperty();
    private SimpleStringProperty naziv = new SimpleStringProperty();

    public int getId() {
        return id.get();
    }

    public SimpleIntegerProperty idProperty() {
        return id;
    }

    public void setId(int id) {
        this.id.set(id);
    }

    public String getNaziv() {
        return naziv.get();
    }

    public SimpleStringProperty nazivProperty() {
        return naziv;
    }

    public void setNaziv(String naziv) {
        this.naziv.set(naziv);
    }

    public int getBrojStanovnika() {
        return brojStanovnika.get();
    }

    public SimpleIntegerProperty brojStanovnikaProperty() {
        return brojStanovnika;
    }

    public void setBrojStanovnika(int brojStanovnika) {
        this.brojStanovnika.set(brojStanovnika);
    }

    public Drzava getDrzava() {
        return drzava.get();
    }

    public SimpleObjectProperty<Drzava> drzavaProperty() {
        return drzava;
    }

    public void setDrzava(Drzava drzava) {
        this.drzava.set(drzava);
    }

    private SimpleIntegerProperty brojStanovnika = new SimpleIntegerProperty();
    private SimpleObjectProperty<Drzava> drzava = new SimpleObjectProperty<>();

    public String getSlikaPath() {
        return slikaPath.get();
    }

    public SimpleStringProperty slikaPathProperty() {
        return slikaPath;
    }

    public void setSlikaPath(String slikaPath) {
        this.slikaPath.set(slikaPath);
    }

    private SimpleStringProperty slikaPath = new SimpleStringProperty();
    public Grad(int id, String naziv, int brojStanovnika, Drzava drzava, int postanskiBroj) {
        this.id.set(id);
        this.naziv.set(naziv);
        this.brojStanovnika.set(brojStanovnika);
        this.drzava.set(drzava);
        this.slikaPath.set("");
        this.postanskiBroj.set(postanskiBroj);
    }
    public Grad(int id, String naziv, int brojStanovnika, Drzava drzava, String path, int postanskiBroj) {
        this.id.set(id);
        this.naziv.set(naziv);
        this.brojStanovnika.set(brojStanovnika);
        this.drzava.set(drzava);
        this.slikaPath.set(path);
        this.postanskiBroj.set(postanskiBroj);
    }

    public Grad() {
    }

    @Override
    public String toString() {
        return this.getNaziv();
    }
}
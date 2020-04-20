package ba.unsa.etf.rpr;

import javafx.beans.property.SimpleObjectProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.sql.*;
import java.util.ArrayList;
import java.util.Scanner;

public class GeografijaDAO{
    public static GeografijaDAO instance = null;
    private PreparedStatement obrisiGradUpit;
    private PreparedStatement nadjiGradUpit;
    private Connection conn;
    private PreparedStatement glavniGradUpit, dajDrzavuUpit, obrisiDrzavuUpit, obrisiGradoveZaDrzavu, nadjiDrzavuUpit;
    private PreparedStatement dajGradUpit, dajGradoveUpit, dodajGradUpit, odrediIdGradUpit, dodajDrzavuUpit, odrediIdDrzavaUpit, promijeniGradUpit, dajDrzaveUpit;
    private ObservableList<Grad> gradoviList = FXCollections.observableArrayList();
    private ObservableList<Drzava> drzaveList = FXCollections.observableArrayList();
    private SimpleObjectProperty<Grad> trenutniGrad = new SimpleObjectProperty<>();
    private SimpleObjectProperty<Drzava> trenutnaDrzava = new SimpleObjectProperty<>();

    private GeografijaDAO()  {
        try {
            conn= DriverManager.getConnection("jdbc:sqlite:baza.db");
        } catch (SQLException e) {
            e.printStackTrace();
        }
        try {
            glavniGradUpit=conn.prepareStatement("SELECT grad.id, grad.naziv, grad.broj_stanovnika, grad.drzava FROM grad, drzava WHERE grad.drzava=drzava.id AND drzava.naziv=?");
        } catch (SQLException e) {
            regenerisiBazu();
            try {
                glavniGradUpit=conn.prepareStatement("SELECT grad.id, grad.naziv, grad.broj_stanovnika, grad.drzava FROM grad, drzava WHERE grad.drzava=drzava.id AND drzava.naziv=?");
            } catch (SQLException e1) {
                e1.printStackTrace();
            }
        }
        try {

            dajDrzavuUpit = conn.prepareStatement("SELECT * FROM DRZAVA WHERE id=?");
            dajGradUpit = conn.prepareStatement("SELECT * FROM grad WHERE id=?");
            glavniGradUpit=conn.prepareStatement("SELECT grad.id, grad.naziv, grad.broj_stanovnika, grad.drzava FROM grad, drzava WHERE grad.drzava=drzava.id AND drzava.naziv=?");
            dajDrzavuUpit = conn.prepareStatement("SELECT * FROM drzava WHERE id=?");
            obrisiDrzavuUpit = conn.prepareStatement("DELETE FROM drzava WHERE naziv=?");
            obrisiGradoveZaDrzavu = conn.prepareStatement("DELETE FROM grad WHERE drzava=?");
            nadjiDrzavuUpit=conn.prepareStatement("SELECT * FROM drzava WHERE naziv=?");
            dajGradoveUpit=conn.prepareStatement("SELECT * FROM grad ORDER BY broj_stanovnika DESC");
            dajDrzaveUpit=conn.prepareStatement("SELECT * FROM drzava ORDER BY naziv DESC");
            dodajGradUpit=conn.prepareStatement("INSERT INTO grad VALUES(?,?,?,?)");
            odrediIdGradUpit=conn.prepareStatement("SELECT Max(id)+1 FROM grad");
            dodajDrzavuUpit=conn.prepareStatement("INSERT INTO drzava VALUES(?,?,?)");
            odrediIdDrzavaUpit=conn.prepareStatement("SELECT Max(id)+1 FROM drzava");
            promijeniGradUpit=conn.prepareStatement("UPDATE grad SET naziv=?, broj_stanovnika=?, drzava=? WHERE id=?");
            obrisiGradUpit = conn.prepareStatement("DELETE FROM grad WHERE id=?");
            nadjiGradUpit = conn.prepareStatement("SELECT * FROM grad WHERE naziv=?");
        } catch (SQLException e) {
            e.printStackTrace();
        }
        gradoviList.addAll(this.gradovi());
        drzaveList.addAll(this.drzave());
        trenutniGrad.set(gradoviList.get(0));
        trenutnaDrzava.set(drzaveList.get(0));

    }

    private void regenerisiBazu() {
        Scanner ulaz = null;
        try {
            ulaz = new Scanner(new FileInputStream("baza.db.sql"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String sqlUpit = "";
        while(ulaz.hasNext()){
            sqlUpit += ulaz.nextLine();
            if(sqlUpit.charAt(sqlUpit.length() - 1) == ';'){
                Statement stm = null;
                try {
                    stm = conn.createStatement();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
                try {
                    stm.execute(sqlUpit);
                    sqlUpit = "";
                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        }
        ulaz.close();
    }

    public static GeografijaDAO getInstance(){
        if(instance == null) instance = new GeografijaDAO();
        return instance;
    }
    public static void removeInstance(){
        if(instance==null) return;
        instance.close();
        instance=null;
    }
    public void close(){
        try{
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public Grad glavniGrad(String drzava){
        try {
            glavniGradUpit.setString(1,drzava);
            ResultSet rs = glavniGradUpit.executeQuery();
            if(!rs.next()) return null;
            return dajGradIzResultSeta(rs);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }

    }

    private Grad dajGradIzResultSeta(ResultSet rs) throws SQLException {
        Grad grad = new Grad(rs.getInt(1), rs.getString(2), rs.getInt(3), null);
        grad.setDrzava(dajDrzavu(rs.getInt(4), grad));
        return grad;
    }

    private Drzava dajDrzavu(int id, Grad grad) {
        try {
            dajDrzavuUpit.setInt(1, id);
            ResultSet rs = dajDrzavuUpit.executeQuery();
            if(!rs.next()) return null;
            return dajDrzavuIzResultSeta(rs, grad);
        } catch (SQLException e) {
            e.printStackTrace();
        }
     return null;
    }

    private Grad dajGrad(int id) {
        try {
            dajGradUpit.setInt(1,id); //prepared statement smo vec u konstruktoru DAO definisali, ovdje ga fillujemo podacima
            ResultSet rs = dajGradUpit.executeQuery();
            if(!rs.next()) return null; //ne postoji grad sa tim id-om
            return dajGradIzResultSeta(rs);
        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }

    private Drzava dajDrzavuIzResultSeta(ResultSet rs, Grad grad) throws SQLException {
        return new Drzava(rs.getInt(1), rs.getString(2), grad);
    }

    public void obrisiDrzavu(String nazivDrzave){
        try {
            nadjiDrzavuUpit.setString(1,nazivDrzave);
            ResultSet rs = nadjiDrzavuUpit.executeQuery();
            if(!rs.next()) return;
            Drzava drzava = dajDrzavuIzResultSeta(rs, null);
            obrisiGradoveZaDrzavu.setInt(1,rs.getInt(1));
            obrisiGradoveZaDrzavu.executeUpdate();
            obrisiDrzavuUpit.setInt(1,drzava.getId());
            obrisiDrzavuUpit.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public ArrayList<Grad> gradovi(){
        ArrayList<Grad> lista = new ArrayList<>();
        try {
            ResultSet rs = dajGradoveUpit.executeQuery();
            while(rs.next()){
                Grad grad = dajGradIzResultSeta(rs);
                lista.add(grad);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return lista;
    }
    public ObservableList<Drzava> drzave(){
        ObservableList<Drzava> lista = FXCollections.observableArrayList();
        try {
            ResultSet rs = dajDrzaveUpit.executeQuery();
            while(rs.next()){
                Drzava drzava = dajDrzavuIzResultSeta(rs,null);
                lista.add(drzava);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return lista;
    }

    public void dodajGrad(Grad grad){
        try {
            ResultSet rs = odrediIdGradUpit.executeQuery();
            int id = 1;
            if(rs.next()){
                id = rs.getInt(1);
            }
            dodajGradUpit.setInt(1,id);
            dodajGradUpit.setString(2,grad.getNaziv());
            dodajGradUpit.setInt(3,grad.getBrojStanovnika());
            dodajGradUpit.setInt(4,grad.getDrzava().getId());
            dodajGradUpit.executeUpdate();
            grad.setId(id);
            gradoviList.add(grad);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void dodajDrzavu(Drzava drzava){
        try {
            ResultSet rs = odrediIdDrzavaUpit.executeQuery();
            int id = 1;
            if(rs.next()) id = rs.getInt(1);
            dodajDrzavuUpit.setInt(1,id);
            dodajDrzavuUpit.setString(2,drzava.getNaziv());
            dodajDrzavuUpit.setInt(3,drzava.getGlavniGrad().getId());
            dodajDrzavuUpit.executeUpdate();
            drzava.setId(id);
            drzaveList.add(drzava);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void izmijeniGrad(Grad grad){
        try {
            promijeniGradUpit.setString(1,grad.getNaziv());
            promijeniGradUpit.setInt(2,grad.getBrojStanovnika());
            promijeniGradUpit.setInt(3,grad.getDrzava().getId());
            promijeniGradUpit.setInt(4,grad.getId());
            promijeniGradUpit.executeUpdate();
            gradoviList.removeIf(o -> o.getId() == grad.getId());
            gradoviList.add(grad);
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }

    public Drzava nadjiDrzavu(String nazivDrzave){
        try {
            nadjiDrzavuUpit.setString(1,nazivDrzave);
            ResultSet rs = nadjiDrzavuUpit.executeQuery();
            return dajDrzavuIzResultSeta(rs, dajGrad(rs.getInt(3)));
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
    public Grad nadjiGrad(String nazivGrada){
        try {
            nadjiGradUpit.setString(1,nazivGrada);
            ResultSet rs = nadjiGradUpit.executeQuery();
            return dajGradIzResultSeta(rs);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
    public ObservableList<Grad> getGradovi(){
        return gradoviList;
    }

    public void obrisiGrad(Grad grad){
        try{
            obrisiGradUpit.setInt(1, grad.getId());
            obrisiGradUpit.executeUpdate();
            gradoviList.remove(grad);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
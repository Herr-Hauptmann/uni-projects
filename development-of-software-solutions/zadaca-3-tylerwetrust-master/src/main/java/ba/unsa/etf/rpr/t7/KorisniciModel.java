package ba.unsa.etf.rpr.t7;

import javafx.beans.property.SimpleObjectProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.*;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class KorisniciModel {
   // private static KorisniciModel instance;
    private ObservableList<Korisnik> korisnici = FXCollections.observableArrayList();
    private SimpleObjectProperty<Korisnik> trenutniKorisnik = new SimpleObjectProperty<>();
    private Connection conn;
    private PreparedStatement dajKorisnikeUpit, dodajKorisnikaUpit, dajIdKorisnika, izmijeniKorisnika, obrisiKorisnika;
    private PreparedStatement dajSveKorisnike;

    /* kako je potreno podatke cuvati u bazi, modifikovat cemo KorisniciModel klasu tako da
    implementira osnovne ideje DAO */
    public KorisniciModel() {
        try {
            conn = DriverManager.getConnection("jdbc:sqlite:korisnici.db");
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try {
            dajKorisnikeUpit = conn.prepareStatement("SELECT id, ime, prezime, username, password FROM korisnik");
        } catch (SQLException e) {
            regenerisiBazu();
            try {
                dajKorisnikeUpit = conn.prepareStatement("SELECT id, ime, prezime, username, password FROM korisnik");
            } catch (SQLException ex) {
                System.out.println("Ozbiljni problemi sa bazom...");
                ex.printStackTrace();
            }
            //e.printStackTrace();
        }

        try {
            dodajKorisnikaUpit = conn.prepareStatement("INSERT INTO korisnik VALUES (?,?,?,?,?,?,?)");
            dajIdKorisnika = conn.prepareStatement("SELECT Max(id)+1 FROM korisnik");
            izmijeniKorisnika = conn.prepareStatement("UPDATE korisnik SET ime=?, prezime=?, email=?, username=?, password=?, slika=? WHERE id=?");
            dajSveKorisnike = conn.prepareStatement("SELECT * FROM korisnik");
            obrisiKorisnika = conn.prepareStatement("DELETE FROM korisnik WHERE id=?");

        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
    public Connection getConn(){
        return conn;
    }
    public void diskonektuj() {
        try {
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void regenerisiBazu() {
        Scanner ulaz = null;
        try {
            ulaz = new Scanner(new FileInputStream("korisnik.sql"));
            String sqlUpit = "";
            while (ulaz.hasNext()) {
                sqlUpit += ulaz.nextLine();
                if ( sqlUpit.length() > 1 && sqlUpit.charAt( sqlUpit.length()-1 ) == ';') {
                    try {
                        Statement stmt = conn.createStatement();
                        stmt.execute(sqlUpit);
                        sqlUpit = "";
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
            }
            ulaz.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    // pomocna funkcija koja, jer se @Start u testovima ne poziva ispravno na Windows OS-u
    public void regenerisi() {
        Connection c;
        try {
            c = DriverManager.getConnection("jdbc:sqlite:korisnici.db");
            PreparedStatement obrisiSve = c.prepareStatement("delete from korisnik");
            obrisiSve.executeUpdate();

            Scanner ulaz = new Scanner(new FileInputStream("korisnik.sql"));
            StringBuilder upit = new StringBuilder();
            while (ulaz.hasNext()) {
                upit.append(ulaz.nextLine());
                if (upit.length() > 1) {
                    if (upit.charAt(upit.length() - 1) == ';') {
                        PreparedStatement stmt = c.prepareStatement(upit.toString());
                        stmt.execute();
                        upit = new StringBuilder();
                    }
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void napuni() {
        /*
        korisnici.add(new Korisnik("Vedran", "Ljubović", "vljubovic@etf.unsa.ba", "vedranlj", "test"));
        korisnici.add(new Korisnik("Amra", "Delić", "adelic@etf.unsa.ba", "amrad", "test"));
        korisnici.add(new Korisnik("Tarik", "Sijerčić", "tsijercic1@etf.unsa.ba", "tariks", "test"));
        korisnici.add(new Korisnik("Rijad", "Fejzić", "rfejzic1@etf.unsa.ba", "rijadf", "test"));
         */
        // sada ubacujemo podatke iz baze
        korisnici.addAll(korisnici());
        trenutniKorisnik.set(null);
    }
    public void dodajKorisnika(Korisnik k){
        ResultSet rs;
        int id = 0;
        try {
            rs = dajIdKorisnika.executeQuery();
            id = rs.getInt(1);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        try {
            dodajKorisnikaUpit.setInt(1,id);
            dodajKorisnikaUpit.setString(2,k.getIme());
            dodajKorisnikaUpit.setString(3,k.getPrezime());
            dodajKorisnikaUpit.setString(4,k.getEmail());
            dodajKorisnikaUpit.setString(5,k.getUsername());
            dodajKorisnikaUpit.setString(6,k.getPassword());
            dodajKorisnikaUpit.setString(7,k.getSlika());
            dodajKorisnikaUpit.executeUpdate();
            k.setId(id);
            korisnici.add(k);
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
    public void izmijeniKorisnika(Korisnik k){
        try {
            izmijeniKorisnika.setString(1,k.getIme());
            izmijeniKorisnika.setString(2,k.getPrezime());
            izmijeniKorisnika.setString(3,k.getEmail());
            izmijeniKorisnika.setString(4,k.getUsername());
            izmijeniKorisnika.setString(5,k.getPassword());
            izmijeniKorisnika.setString(6,k.getSlika());
            izmijeniKorisnika.setInt(7,k.getId());
            izmijeniKorisnika.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    public void obrisiKorisnika(Korisnik k){
        try {
            obrisiKorisnika.setInt(1,k.getId());
            obrisiKorisnika.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
    public ObservableList<Korisnik> getKorisnici() {
        return korisnici;
    }

    public void setKorisnici(ObservableList<Korisnik> korisnici) {
        this.korisnici = korisnici;
    }

    public Korisnik getTrenutniKorisnik() {
        return trenutniKorisnik.get();
    }

    public SimpleObjectProperty<Korisnik> trenutniKorisnikProperty() {
        return trenutniKorisnik;
    }

    public void setTrenutniKorisnik(Korisnik trenutniKorisnik) {
        this.trenutniKorisnik.set(trenutniKorisnik);
        spremi();
    }
    public void setTrenutniKorisnik(int i) {
        this.trenutniKorisnik.set(korisnici.get(i));
    }
    public ArrayList<Korisnik> korisnici(){
        ArrayList<Korisnik> lista = new ArrayList<>();
        try {
            ResultSet rs = dajSveKorisnike.executeQuery();
            while(rs.next()){
                Korisnik k = dajKorisnikaIzResultSeta(rs);
                lista.add(k);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
     return lista;
    }

    private Korisnik dajKorisnikaIzResultSeta(ResultSet rs) {
        try {
            Korisnik k = new Korisnik(rs.getString(2),rs.getString(3),rs.getString(4),rs.getString(5),rs.getString(6));
            String s = rs.getString(7);
            if(s != null) k.setSlika(s);
            k.setId(rs.getInt(1));
            return k;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    private void spremi(){
        for(Korisnik k: korisnici){
            izmijeniKorisnika(k);
        }
    }

    public void zapisiDatoteku(File file) {
        if(file != null) {
            FileWriter fileWriter = null;
            try {
                fileWriter = new FileWriter(file);
            } catch (IOException e) {
                e.printStackTrace();
            }
            PrintWriter printWriter = new PrintWriter(fileWriter);
            for(Korisnik k: getKorisnici()){
                printWriter.println(passwdConvert(k));
            }
            printWriter.close();
        }
    }
    private String passwdConvert(Korisnik k){
        return k.getUsername() + ":" + k.getPassword() + ":" + k.getId() + ":" + k.getId() + ":" + k.getIme() + " " + k.getPrezime() + "::";
    }

}

package ba.unsa.etf.rpr.t7;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyCodeCombination;
import javafx.scene.input.KeyCombination;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import net.sf.jasperreports.engine.JRException;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URL;
import java.util.Locale;
import java.util.ResourceBundle;

import static javafx.scene.control.PopupControl.USE_COMPUTED_SIZE;

public class KorisnikController {
    public TextField fldIme;
    public TextField fldPrezime;
    public TextField fldEmail;
    public TextField fldUsername;
    public ListView<Korisnik> listKorisnici;
    public PasswordField fldPassword;
    public MenuItem exitItem;
    public MenuItem aboutItem;
    public MenuItem saveItem;
    public MenuItem printItem;
    public MenuItem bosanskiItem;
    public MenuItem englishItem;
    public Button imgKorisnik;




    private KorisniciModel model;

    public KorisnikController(KorisniciModel model) {
        this.model = model;
    }

    @FXML
    public void initialize() {
        listKorisnici.setItems(model.getKorisnici());
        listKorisnici.getSelectionModel().selectedItemProperty().addListener((obs, oldKorisnik, newKorisnik) -> {
            model.setTrenutniKorisnik(newKorisnik);
            listKorisnici.refresh();
         });
        exitItem.setAccelerator(new KeyCodeCombination(KeyCode.X, KeyCombination.CONTROL_DOWN));
        aboutItem.setAccelerator(new KeyCodeCombination(KeyCode.A, KeyCombination.ALT_DOWN));
        saveItem.setAccelerator(new KeyCodeCombination(KeyCode.S, KeyCombination.CONTROL_DOWN));
        printItem.setAccelerator(new KeyCodeCombination(KeyCode.P, KeyCombination.CONTROL_DOWN));
        bosanskiItem.setAccelerator(new KeyCodeCombination(KeyCode.B, KeyCombination.CONTROL_DOWN));
        englishItem.setAccelerator(new KeyCodeCombination(KeyCode.E, KeyCombination.CONTROL_DOWN));
        Image image = new Image(Main.class.getResource("/img/face-smile.png").toExternalForm(), 128, 128, true, true);
        imgKorisnik.setGraphic(new ImageView(image));




        model.trenutniKorisnikProperty().addListener((obs, oldKorisnik, newKorisnik) -> {
            if (oldKorisnik != null) {
                fldIme.textProperty().unbindBidirectional(oldKorisnik.imeProperty() );
                fldPrezime.textProperty().unbindBidirectional(oldKorisnik.prezimeProperty() );
                fldEmail.textProperty().unbindBidirectional(oldKorisnik.emailProperty() );
                fldUsername.textProperty().unbindBidirectional(oldKorisnik.usernameProperty() );
                fldPassword.textProperty().unbindBidirectional(oldKorisnik.passwordProperty() );
                model.izmijeniKorisnika(oldKorisnik);

            }
            if (newKorisnik == null) {
                fldIme.setText("");
                fldPrezime.setText("");
                fldEmail.setText("");
                fldUsername.setText("");
                fldPassword.setText("");
                imgKorisnik.setGraphic(new ImageView(image));
            }
            else {
                fldIme.textProperty().bindBidirectional( newKorisnik.imeProperty() );
                fldPrezime.textProperty().bindBidirectional( newKorisnik.prezimeProperty() );
                fldEmail.textProperty().bindBidirectional( newKorisnik.emailProperty() );
                fldUsername.textProperty().bindBidirectional( newKorisnik.usernameProperty() );
                fldPassword.textProperty().bindBidirectional( newKorisnik.passwordProperty() );
                if(!newKorisnik.getSlika().isEmpty()) {
                    Image img = new Image(newKorisnik.getSlika(),true);
                    ImageView imgw = new ImageView();
                    imgw.setFitWidth(128);
                    imgw.setFitHeight(128);
                    imgw.setImage(img);
                    imgKorisnik.setGraphic(imgw);
                }
                else{
                    imgKorisnik.setGraphic(new ImageView(image));
                }
            }
        });

        fldIme.textProperty().addListener((obs, oldIme, newIme) -> {
            if (!newIme.isEmpty()) {
                fldIme.getStyleClass().removeAll("poljeNijeIspravno");
                fldIme.getStyleClass().add("poljeIspravno");
            } else {
                fldIme.getStyleClass().removeAll("poljeIspravno");
                fldIme.getStyleClass().add("poljeNijeIspravno");
            }
        });

        fldPrezime.textProperty().addListener((obs, oldIme, newIme) -> {
            if (!newIme.isEmpty()) {
                fldPrezime.getStyleClass().removeAll("poljeNijeIspravno");
                fldPrezime.getStyleClass().add("poljeIspravno");
            } else {
                fldPrezime.getStyleClass().removeAll("poljeIspravno");
                fldPrezime.getStyleClass().add("poljeNijeIspravno");
            }
        });

        fldEmail.textProperty().addListener((obs, oldIme, newIme) -> {
            if (!newIme.isEmpty()) {
                fldEmail.getStyleClass().removeAll("poljeNijeIspravno");
                fldEmail.getStyleClass().add("poljeIspravno");
            } else {
                fldEmail.getStyleClass().removeAll("poljeIspravno");
                fldEmail.getStyleClass().add("poljeNijeIspravno");
            }
        });

        fldUsername.textProperty().addListener((obs, oldIme, newIme) -> {
            if (!newIme.isEmpty()) {
                fldUsername.getStyleClass().removeAll("poljeNijeIspravno");
                fldUsername.getStyleClass().add("poljeIspravno");
            } else {
                fldUsername.getStyleClass().removeAll("poljeIspravno");
                fldUsername.getStyleClass().add("poljeNijeIspravno");
            }
        });

        fldPassword.textProperty().addListener((obs, oldIme, newIme) -> {
            if (!newIme.isEmpty()) {
                fldPassword.getStyleClass().removeAll("poljeNijeIspravno");
                fldPassword.getStyleClass().add("poljeIspravno");
            } else {
                fldPassword.getStyleClass().removeAll("poljeIspravno");
                fldPassword.getStyleClass().add("poljeNijeIspravno");
            }
        });
    }

    public void dodajAction(ActionEvent actionEvent) {
        //model.getKorisnici().add(new Korisnik("", "", "", "", ""));
        Korisnik k = new Korisnik("","","","","");
        model.dodajKorisnika(k);
        listKorisnici.getSelectionModel().selectLast();

    }

    public void obrisiAction(ActionEvent actionEvent){
        if(model.getTrenutniKorisnik() != null){
            int index = listKorisnici.getSelectionModel().getSelectedIndex();
            Korisnik k = model.getTrenutniKorisnik();
            model.getKorisnici().remove(k);
            model.obrisiKorisnika(k);
            listKorisnici.getItems().remove(k);
            listKorisnici.refresh();
            listKorisnici.getSelectionModel().select(index);
        }
    }
    public void aboutAction(ActionEvent actionEvent){
        Stage stage = new Stage();
        Parent root = null;
            ResourceBundle bundle = ResourceBundle.getBundle("Translation");
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/fxml/about.fxml"),bundle);
        try {
            root = loader.load();
        } catch (IOException e) {
            e.printStackTrace();
        }
        stage.setTitle("About");
            stage.setScene(new Scene(root, USE_COMPUTED_SIZE, USE_COMPUTED_SIZE));
            stage.setResizable(false);
            stage.show();
    }
    public void actionSave(ActionEvent actionEvent) {
        FileChooser fileChooser = new FileChooser();
        File selectedFile = fileChooser.showOpenDialog(null);

        if (selectedFile != null) {
            String path = selectedFile.getAbsolutePath();
            File file = new File(path);
            if(file.exists()) model.zapisiDatoteku(file);
        } else {

        }
    }

    public void printAction(ActionEvent actionEvent){
        try {
            new PrintReport().showReport(model.getConn());
        } catch (JRException e1) {
            e1.printStackTrace();
        }
    }


    public void krajAction(ActionEvent actionEvent) {
        System.exit(0);
    }
    public void bsAction(ActionEvent actionEvent){
        Locale.setDefault(new Locale("bs","BA","LC_ALL=en_US.UTF-8"));
        restartJezik();

    }
    public void enAction(ActionEvent actionEvent){
        Locale.setDefault(new Locale("en","US","LC_ALL=en_US.UTF-8"));
        restartJezik();

    }
    public void searchAction(ActionEvent actionEvent) throws IOException {
        if(model.getTrenutniKorisnik() == null) return;
        ResourceBundle bundle = ResourceBundle.getBundle("Translation");
        SearchController ctrl = new SearchController();
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/fxml/search.fxml"),bundle);
        loader.setController(ctrl);
        Scene scene = new Scene(loader.load(), USE_COMPUTED_SIZE, USE_COMPUTED_SIZE);
        Stage stage = new Stage();
        stage.setTitle("Pretraga");
        stage.setScene(scene);
        stage.setOnHiding(ev -> {
            String s = ctrl.getUrl();
            if(s != null && !s.isEmpty()){
                model.getTrenutniKorisnik().setSlika(s);
                model.izmijeniKorisnika(model.getTrenutniKorisnik());
                model.setTrenutniKorisnik(model.getTrenutniKorisnik());
                Image img = new Image(model.getTrenutniKorisnik().getSlika());
                ImageView imgw = new ImageView();
                imgw.setFitWidth(128);
                imgw.setFitHeight(128);
                imgw.setImage(img);
                imgKorisnik.setGraphic(imgw);
            }
        });
        stage.show();
    }


    private void restartJezik() {
        ResourceBundle bundle = ResourceBundle.getBundle("Translation");
        Stage scene = (Stage) listKorisnici.getScene().getWindow();
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/fxml/korisnici.fxml"), bundle);
        loader.setController(this);
        try {
            scene.setScene(new Scene(loader.load()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}

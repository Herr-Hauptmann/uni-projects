package ba.unsa.etf.rpr;
import java.net.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import net.sf.jasperreports.engine.JRException;

import javax.swing.text.TabableView;
import javax.swing.text.html.ImageView;
import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Optional;
import java.util.ResourceBundle;
import java.util.logging.Level;
import java.util.logging.Logger;

import static javafx.scene.control.PopupControl.USE_COMPUTED_SIZE;

public class GlavnaController {
    @FXML
    public TableView<Grad> tableViewGradovi;
    @FXML
    public Button btnDodajGrad;
    @FXML
    public Button btnStampa;
    @FXML
    public Button btnDodajDrzavu;
    @FXML
    public Button btnIzmijeniGrad;
    @FXML
    public Button btnObrisiGrad;
    @FXML
    public TableColumn colGradID;
    public TableColumn colGradNaziv;
    public TableColumn colGradStanovnika;
    public TableColumn colGradDrzava;
    private GeografijaDAO dao;
    private Grad selectedGrad;
    @FXML
    public Button btnJezik;



    public GlavnaController(){
        dao = GeografijaDAO.getInstance();
    }

    @FXML
    private void initialize(){
        colGradID.setCellValueFactory(new PropertyValueFactory<>("id"));
        colGradNaziv.setCellValueFactory(new PropertyValueFactory<>("naziv"));
        colGradStanovnika.setCellValueFactory(new PropertyValueFactory<>("brojStanovnika"));
        colGradDrzava.setCellValueFactory(new PropertyValueFactory<>("drzava"));
        tableViewGradovi.setItems(dao.getGradovi());
        tableViewGradovi.refresh();
        tableViewGradovi.getSelectionModel().selectedItemProperty().addListener((obs, oldValue, newValue) ->{
            this.selectedGrad=newValue;
        });

    }


    public void dodajDrzavuAction(ActionEvent actionEvent) throws IOException {
            DrzavaController ctrl = new DrzavaController(null,dao.gradovi());
            FXMLLoader fxmlLoader = new FXMLLoader();
            fxmlLoader.setController(ctrl);
            fxmlLoader.setLocation(getClass().getResource("/fxml/drzava.fxml"));
            Scene scene = new Scene(fxmlLoader.load(), USE_COMPUTED_SIZE, USE_COMPUTED_SIZE);
            Stage stage = new Stage();
            stage.setResizable(false);
            stage.setTitle("Država");
            stage.setScene(scene);
            stage.setOnHiding(ev -> {
            Drzava newDrzava = ctrl.getDrzava();
            if(newDrzava==null){
                System.out.println("Prazna drzava");
            }
            else{
                dao.dodajDrzavu(newDrzava);
                System.out.println(newDrzava);
            }
        });
            stage.show();

    }



    public void dodajGradAction(ActionEvent actionEvent) throws IOException {
        ResourceBundle bundle = ResourceBundle.getBundle("Translation");
        GradController ctrl = new GradController(null,dao.drzave());
            FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("/fxml/grad.fxml"),bundle);
            fxmlLoader.setController(ctrl);
            Scene scene = new Scene(fxmlLoader.load(), USE_COMPUTED_SIZE, USE_COMPUTED_SIZE);
            Stage stage = new Stage();
            //stage.setResizable(false);
            stage.setTitle("Grad");
            stage.setScene(scene);
            stage.setOnHiding(ev -> {
                Grad newGrad = ctrl.getGrad();
                if(newGrad==null){
                    System.out.println("Prazan grad");
                }
                else{
                    dao.dodajGrad(newGrad);
                    System.out.println(newGrad.getNaziv());
                    tableViewGradovi.setItems(dao.getGradovi());
                    tableViewGradovi.refresh();
                }
            });
            stage.show();
    }

    public void izmijeniGradAction(ActionEvent actionEvent) throws IOException {
        this.selectedGrad= tableViewGradovi.getSelectionModel().getSelectedItem();
        if(selectedGrad != null) {
                GradController ctrl = new GradController(selectedGrad,dao.drzave());
                FXMLLoader fxmlLoader = new FXMLLoader();
                fxmlLoader.setController(ctrl);
                fxmlLoader.setLocation(getClass().getResource("/fxml/grad.fxml"));
                Scene scene = new Scene(fxmlLoader.load(), USE_COMPUTED_SIZE, USE_COMPUTED_SIZE);
                Stage stage = new Stage();
                //stage.setResizable(false);
                stage.setTitle("Grad");
                stage.setScene(scene);
                stage.setOnHiding(ev -> {
                    Grad newGrad = ctrl.getGrad();
                    if(newGrad == null){
                        System.out.println("Prazan grad");
                    }
                    else{
                        dao.izmijeniGrad(newGrad);
                        System.out.println(newGrad.getNaziv());
                       // tableViewGradovi.getItems().clear();
                        tableViewGradovi.setItems(dao.getGradovi());
                        tableViewGradovi.refresh();
                    }
                });
                stage.show();
        }
    }
    public void resetujBazu() {
        GeografijaDAO.removeInstance();
        File dbfile = new File("baza.db");
        dbfile.delete();
        dao = GeografijaDAO.getInstance();
    }

    public void stampaAction(ActionEvent actionEvent){
        try {
            new GradoviReport().showReport(dao.getConn());
        } catch (JRException e) {
            e.printStackTrace();
        }
    }
    private void restartJezik(){
        ResourceBundle bundle = ResourceBundle.getBundle("Translation");
        Stage scene = (Stage) tableViewGradovi.getScene().getWindow();
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/fxml/glavna.fxml"), bundle);
        loader.setController(this);
        try {
            scene.setScene(new Scene(loader.load()));
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    public void jezikAction(ActionEvent actionEvent){
        String[] jezici ={"bs_BA","en_US","ger_DE","fra_FR"};
        ChoiceDialog choiceDialog = new ChoiceDialog(jezici[0],jezici);
        choiceDialog.setTitle("Choose wisely");
        choiceDialog.setHeaderText("Is this the real life?");

        Optional<String> result = choiceDialog.showAndWait();
        String selected = "cancelled.";

        if (result.isPresent()) {
            selected = result.get();
            if(selected.equals(jezici[0])){
                Locale.setDefault(new Locale("bs", "BA"));
            }
            else if(selected.equals(jezici[1])){
                Locale.setDefault(new Locale("en", "US"));
            }
            else if(selected.equals(jezici[2])){
                Locale.setDefault(new Locale("ger", "DE"));
            }
            else{
                Locale.setDefault(new Locale("fra", "FR"));
            }
        }
        restartJezik();
    }


    public void obrisiAction(ActionEvent actionEvent) {
        Grad grad = tableViewGradovi.getSelectionModel().getSelectedItem();
        if(grad != null){
            Alert alert = new Alert(Alert.AlertType.WARNING);
            alert.setHeaderText("Pažnja");
            alert.setContentText("Da li želite obrisati odabrani grad?");
            alert.setOnCloseRequest(new EventHandler<DialogEvent>() {
                @Override
                public void handle(DialogEvent event) {
                    ButtonType result=alert.getResult();
                    if(result==null) alert.close();
                    else {
                        String resultText = result.getText();
                        if (resultText.equals("OK")) {
                            dao.obrisiGrad(grad);
                            tableViewGradovi.setItems(dao.getGradovi());
                            tableViewGradovi.refresh();
                            alert.close();
                        }
                    }
                }
            });
            alert.show();
        }
    }
}

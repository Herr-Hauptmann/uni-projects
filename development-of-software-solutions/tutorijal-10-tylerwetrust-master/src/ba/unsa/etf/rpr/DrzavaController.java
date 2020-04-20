package ba.unsa.etf.rpr;

import javafx.beans.Observable;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.util.ArrayList;

public class DrzavaController {
    @FXML
    public TextField fieldNaziv;
    @FXML
    public ChoiceBox<Grad> choiceGrad;
    @FXML
    public Button btnOk;
    @FXML
    public Button btnCancel;

    public Drzava getDrzava() {
        return drzava;
    }

    public void setDrzava(Drzava drzava) {
        this.drzava = drzava;
    }

    private Drzava drzava;
    private ObservableList<Grad> gradovi = FXCollections.observableArrayList();

    @FXML
    public void initialize(){
        choiceGrad.setItems(this.gradovi);
        choiceGrad.getSelectionModel().selectFirst();
    }
    public DrzavaController(Grad grad, ArrayList<Grad> gradovi) {
        this.gradovi.addAll(gradovi);
    }

    public void okAction(ActionEvent actionEvent) {
        Stage stage = (Stage) btnOk.getScene().getWindow();
        if(fieldNaziv.getText().isEmpty()){
            fieldNaziv.getStyleClass().removeAll("poljeIspravno");
            fieldNaziv.getStyleClass().add("poljeNijeIspravno");
        }
        else{
            fieldNaziv.getStyleClass().removeAll("poljeNijeIspravno");
            fieldNaziv.getStyleClass().add("poljeIspravno");
            drzava = new Drzava(0, fieldNaziv.getText(), choiceGrad.getSelectionModel().getSelectedItem());
            stage.close();
        }
    }

    public void cancelAction(ActionEvent actionEvent) {
        Stage stage = (Stage) btnCancel.getScene().getWindow();
        stage.close();
    }
}

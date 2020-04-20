package ba.unsa.etf.rpr;

import javafx.beans.property.SimpleObjectProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.util.converter.NumberStringConverter;

import java.util.ArrayList;

public class GradController {
    public TextField fieldNaziv;
    public ChoiceBox<Drzava> choiceDrzava;
    @FXML
    public Button btnOk;
    @FXML
    public Button btnCancel;
    public TextField fieldBrojStanovnika;
    private boolean postojeciGrad;

    public Grad getGrad() {
        return grad;
    }

    public void setGrad(Grad grad) {
        this.grad = grad;
    }

    private Grad grad;
    private ObservableList<Drzava> drzave = FXCollections.observableArrayList();

    public GradController(Grad grad, ObservableList<Drzava> drzave) {
        if(grad == null){
            postojeciGrad = false;
        }
        else{
            postojeciGrad = true;
        }
        this.grad = grad;
        this.drzave = drzave;
    }
    @FXML
    private void initialize(){
        choiceDrzava.setItems(drzave);
        if(!postojeciGrad) {
            choiceDrzava.getSelectionModel().selectFirst();
        }
        else{
            fieldNaziv.setText(grad.getNaziv());
            fieldBrojStanovnika.setText(Integer.toString(grad.getBrojStanovnika()));
            choiceDrzava.getSelectionModel().select(grad.getDrzava().getId() - 1);
        }
    }
    public void cancelAction(ActionEvent actionEvent) {
        Stage stage = (Stage) btnCancel.getScene().getWindow();
        stage.close();
    }

    public void okAction(ActionEvent actionEvent) {
        boolean nazivFlag = false;
        boolean brojStanovnikaFlag = false;
        Integer i = 1;
        Stage stage = (Stage) btnOk.getScene().getWindow();
        if (fieldNaziv.getText().isEmpty()) {
            fieldNaziv.getStyleClass().removeAll("poljeIspravno");
            fieldNaziv.getStyleClass().add("poljeNijeIspravno");
        } else {
            fieldNaziv.getStyleClass().removeAll("poljeNijeIspravno");
            fieldNaziv.getStyleClass().add("poljeIspravno");
            nazivFlag = true;

        }
        try {
            i = Integer.parseInt(fieldBrojStanovnika.getText());
            if (i > 0) {
                fieldBrojStanovnika.getStyleClass().removeAll("poljeNijeIspravno");
                fieldBrojStanovnika.getStyleClass().add("poljeIspravno");
                brojStanovnikaFlag = true;
            } else {
                fieldBrojStanovnika.getStyleClass().removeAll("poljeIspravno");
                fieldBrojStanovnika.getStyleClass().add("poljeNijeIspravno");
            }
        } catch (Exception e) {
            fieldBrojStanovnika.getStyleClass().removeAll("poljeIspravno");
            fieldBrojStanovnika.getStyleClass().add("poljeNijeIspravno");

        }
        if (nazivFlag && brojStanovnikaFlag && choiceDrzava.getSelectionModel().getSelectedItem() != null) {
            if(!postojeciGrad)  this.grad = new Grad(0,"",0,null);
            grad.setNaziv(fieldNaziv.getText());
            grad.setBrojStanovnika(i);
            if (!postojeciGrad) {
                grad.setId(0);
            }
            Drzava drzava = new Drzava(choiceDrzava.getSelectionModel().getSelectedItem().getId(), choiceDrzava.getSelectionModel().getSelectedItem().getNaziv(), null);
            grad.setDrzava(drzava);
            stage.close();
        }
        else{
            grad = null;
        }
    }
}


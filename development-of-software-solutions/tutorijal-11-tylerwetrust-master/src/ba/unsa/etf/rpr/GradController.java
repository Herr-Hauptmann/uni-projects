package ba.unsa.etf.rpr;

import javafx.application.Platform;
import javafx.beans.property.SimpleObjectProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextField;
import javafx.scene.control.TextInputDialog;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import javafx.util.converter.NumberStringConverter;


import java.io.*;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Optional;

import javafx.scene.image.Image;

public class GradController {
    public TextField fieldNaziv;
    public ChoiceBox<Drzava> choiceDrzava;
    @FXML
    public Button btnOk;
    @FXML
    public Button btnCancel;
    @FXML
    public Button btnSlika;
    public TextField fieldBrojStanovnika;
    private boolean postojeciGrad;
    @FXML
    public ImageView slikaView;
    @FXML
    public TextField fieldPostanski;

    public Grad getGrad() {
        return grad;
    }

    public void setGrad(Grad grad) {
        this.grad = grad;
    }

    private Grad grad;
    private ObservableList<Drzava> drzave = FXCollections.observableArrayList();

    public GradController(Grad grad, ObservableList<Drzava> drzave) {
        if (grad == null) {
            postojeciGrad = false;
        } else {
            postojeciGrad = true;
        }
        this.grad = grad;
        this.drzave = drzave;
    }

    @FXML
    private void initialize() {
        choiceDrzava.setItems(drzave);
        if (!postojeciGrad) {
            choiceDrzava.getSelectionModel().selectFirst();
        } else {
            //String s = Integer.toString(grad.getPostanskiBroj());
            //System.out.println(s);
            fieldPostanski.setText("");
            fieldPostanski.setText(Integer.toString(grad.getPostanskiBroj()));
            fieldNaziv.setText(grad.getNaziv());
            fieldBrojStanovnika.setText(Integer.toString(grad.getBrojStanovnika()));
            choiceDrzava.getSelectionModel().select(grad.getDrzava().getId() - 1);
            if (grad.getSlikaPath() != null && !grad.getSlikaPath().equals("")) {
                postaviSliku(grad.getSlikaPath());

            }
        }
    }

    public void cancelAction(ActionEvent actionEvent) {
        Stage stage = (Stage) btnCancel.getScene().getWindow();
        stage.close();
    }
    public void slikaAction(ActionEvent actionEvent){
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("Odaberi sliku");
        dialog.setHeaderText("Put do slike");
        dialog.setContentText("Path:");
        Optional<String> res = dialog.showAndWait();
        if(res.isPresent()){
            if(res.get() != null && !res.get().isEmpty() && !res.get().equals("")){
                grad.setSlikaPath(res.get());
                postaviSliku(res.get());
            }

        }
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
        validatePostanski();

        if (nazivFlag && brojStanovnikaFlag && choiceDrzava.getSelectionModel().getSelectedItem() != null && isPostanskiValid()) {
            if (!postojeciGrad) this.grad = new Grad(0, "", 0, null,"",0);
            grad.setNaziv(fieldNaziv.getText());
            grad.setBrojStanovnika(i);
            if (!postojeciGrad) {
                grad.setId(0);
            }
            grad.setPostanskiBroj(Integer.parseInt(fieldPostanski.getText()));
            Drzava drzava = new Drzava(choiceDrzava.getSelectionModel().getSelectedItem().getId(), choiceDrzava.getSelectionModel().getSelectedItem().getNaziv(), null);
            grad.setDrzava(drzava);
            stage.close();
        } else {
            grad = null;
        }
    }
    private void validatePostanski(){
        new Thread(()->{
            System.out.println("Krenuo thread ");
            if(isPostanskiValid()) {
                Platform.runLater(() -> {
                    fieldPostanski.getStyleClass().removeAll("poljeNijeIspravno");
                    fieldPostanski.getStyleClass().addAll("poljeIspravno");
                });
                System.out.println("Ispravan ");
            }
            else{
                Platform.runLater(()->{
                    fieldPostanski.getStyleClass().addAll("poljeNijeIspravno");
                });
            }
        }).start();
    }
    private boolean isPostanskiValid()   {
        String apiUrl = "http://c9.etf.unsa.ba/proba/postanskiBroj.php?postanskiBroj=";
        try {
        URL url = new URL(apiUrl + fieldPostanski.getText().trim());
        BufferedReader ulaz = null;
            ulaz = new BufferedReader(new InputStreamReader(url.openStream(), StandardCharsets.UTF_8));
            String res = ulaz.readLine();
            return res.trim().equals("OK");
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
        return false;
    }
    private void postaviSliku(String path) {
        File file = new File(path);
        if (file.exists()) {
            FileInputStream input = null;
            try {
                input = new FileInputStream(path);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
            assert input != null;
            Image img = new Image(input);
            slikaView.setImage(img);
        }
    }
}



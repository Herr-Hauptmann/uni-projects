package sample;

import javafx.scene.control.Button;
import javafx.stage.Stage;

import javax.swing.*;
import java.awt.event.ActionEvent;

public class Controller {
    private Button krajBtn;



    public void krajButton(){
        Stage stage = (Stage) krajBtn.getScene().getWindow();
        // do what you have to do
        stage.close();
    }


}

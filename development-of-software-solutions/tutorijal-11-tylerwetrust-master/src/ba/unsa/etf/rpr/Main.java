package ba.unsa.etf.rpr;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.util.ResourceBundle;
import java.util.Scanner;

import static javafx.scene.layout.Region.USE_COMPUTED_SIZE;


public class Main extends Application {

    public static String ispisiGradove(){
        GeografijaDAO g = GeografijaDAO.getInstance();
        String ret = "";
        for(Grad grad: g.gradovi()){
            ret += grad.getNaziv() + " (" + grad.getDrzava().getNaziv() + ") - " + grad.getBrojStanovnika() + "\n";
        }
        return ret;
    }
    public static void glavniGrad() {
        GeografijaDAO g = GeografijaDAO.getInstance();
        Scanner ulaz = new Scanner(System.in);
        System.out.println("Unesite naziv države: ");
        String naziv = ulaz.nextLine();
        Grad grad = g.glavniGrad(naziv);
        if (grad == null) {
            System.out.println("Unijeli ste nepostojeću državu!");
        } else {
            System.out.println("Glavni grad države " + naziv + " je " + grad.getNaziv());
        }
    }
    @Override
    public void start(Stage primaryStage) throws Exception{
        ResourceBundle bundle = ResourceBundle.getBundle("Translation");
        GlavnaController ctrl = new GlavnaController();
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("/fxml/glavna.fxml"),bundle);
        fxmlLoader.setController(ctrl);
        primaryStage.setTitle("Gradovi svijeta");
      //  primaryStage.setResizable(false);
        primaryStage.setScene(new Scene(fxmlLoader.load(), USE_COMPUTED_SIZE, USE_COMPUTED_SIZE));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);

    }
}
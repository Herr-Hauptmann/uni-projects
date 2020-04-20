package ba.unsa.etf.rpr.t7;

import at.mukprojects.giphy4j.Giphy;
import at.mukprojects.giphy4j.entity.giphy.GiphyImage;
import at.mukprojects.giphy4j.entity.search.SearchFeed;
import at.mukprojects.giphy4j.exception.GiphyException;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.TilePane;
import javafx.stage.Stage;

import java.io.*;
import java.net.MalformedURLException;
import java.net.URL;
import java.nio.charset.StandardCharsets;

public class SearchController {
    public TextField fldSearch;
    public Button btnSearch;
    public Button btnOk;
    public Button btnCancel;
    public TilePane tilePane;
    private SearchFeed feed = null;
    private Giphy giphy = new Giphy("dc6zaTOxFJmzC");
    private String url;

    public String getUrl() {
        return url;
    }



    public void searchAction(javafx.event.ActionEvent actionEvent) throws FileNotFoundException {
        if (!fldSearch.getText().isEmpty()) {
            {
                tilePane.getChildren().clear();
                feed = null;
                try {
                    feed = giphy.search(fldSearch.getText(), 25, 0);
                } catch (GiphyException e) {
                    e.printStackTrace();
                }
                Button b = new Button();
                Button finalB1 = b;
                b.setOnAction(o -> {
                    ImageView im = (ImageView) finalB1.getGraphic();
                    url = im.getImage().getUrl();
                });
                Image image = new Image(Main.class.getResource("/img/loading.gif").toExternalForm(), 128, 128, true, true);
                b.setGraphic(new ImageView(image));
                tilePane.getChildren().add(b);
                dodajSliku(b,0);
                int size = feed.getDataList().size();
                for(int i = 1; i < size; i++){
                    b = new Button();
                    Button finalB = b;
                    b.setOnAction(o -> {
                        ImageView im = (ImageView) finalB.getGraphic();
                        url = im.getImage().getUrl();
                    });
                    b.setGraphic(new ImageView(image));
                    tilePane.getChildren().add(b);
                    dodajSliku(b,i);
                }
            }
        }
    }

    private boolean dodajSliku(Button button, int index){
        if(feed.getDataList().isEmpty()) return false;
        new Thread(() -> {
            GiphyImage i =  feed.getDataList().get(index).getImages().getFixedWidthStill();
            String s = i.getUrl();
            s = s.substring(25, s.length());
            s = "https://i.giphy.com/" + s.replaceAll("[?].*","");
            ImageView imgView = new ImageView();
            imgView.setFitHeight(128);
            imgView.setFitWidth(128);
            Image is = new Image(s);
            imgView.setImage(is);
            Platform.runLater(() -> {  button.setGraphic(imgView); });
        }).start();
        return true;

    }


    public void okAction(javafx.event.ActionEvent actionEvent) {
        if(url.isEmpty()){
            Alert alert = new Alert(Alert.AlertType.WARNING);
            alert.setTitle("Upozorenje");
            alert.setHeaderText("PAŽNJA!");
            alert.setContentText("Niste odabrali sliku!");
            alert.showAndWait();
        }
        else{
            Stage stage = (Stage) btnCancel.getScene().getWindow();
            stage.close();
        }

    }

    public void cancelAction(ActionEvent actionEvent) {
        url = "";
        Stage stage = (Stage) btnCancel.getScene().getWindow();
        stage.close();

    }
}

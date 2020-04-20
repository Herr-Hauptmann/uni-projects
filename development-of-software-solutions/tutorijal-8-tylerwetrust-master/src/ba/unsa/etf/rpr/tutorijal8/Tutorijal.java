package ba.unsa.etf.rpr.tutorijal8;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Tutorijal{
    public static void main(String[] args){
    }

public static ArrayList<Grad> ucitajGradove() {
    ArrayList<Grad> gradovi = new ArrayList<>();
    BufferedReader reader;
    try {
        reader = new BufferedReader(new FileReader(
                "mjerenja.txt"));
        String line = reader.readLine();
        Grad grad;
        while (line != null) {
            String[] parameters = line.split(",");
            grad = new Grad();
            grad.setNaziv(parameters[0]);
            for(int i = 1; i < parameters.length; i++ ){
                if(!grad.dodajTemperaturu(Double.parseDouble(parameters[i]))) break;
            }
            gradovi.add(grad);
            line = reader.readLine();
        }
        reader.close();

    } catch (IOException e) {
        e.printStackTrace();
        return null;
    }
  return gradovi;
}
}

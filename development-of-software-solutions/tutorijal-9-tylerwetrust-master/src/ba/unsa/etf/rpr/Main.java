package ba.unsa.etf.rpr;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static String ispisiGradove(){
        GeografijaDAO g = GeografijaDAO.getInstance();
        String ret = "";
        for(Grad grad: g.gradovi()){
            ret += grad.getNaziv() + " (" + grad.getDrzava().getNaziv() + ") - " + grad.getBrojStanovnika() + "\n";
        }
        return ret;
    }
    public static void glavniGrad(){
        GeografijaDAO g = GeografijaDAO.getInstance();
        Scanner ulaz = new Scanner(System.in);
        System.out.println("Unesite naziv države: ");
        String naziv = ulaz.nextLine();
        Grad grad = g.glavniGrad(naziv);
        if(grad == null){
            System.out.println("Unijeli ste nepostojeću državu!");
        }
        else{
            System.out.println("Glavni grad države " + naziv + " je " + grad.getNaziv());
        }

    }
    public static void main(String[] args) {
        System.out.println("Gradovi su:\n" + ispisiGradove());
        glavniGrad();
    }
}

package ba.unsa.etf.rpr.tutorijal_3;
import java.util.*;
import java.lang.String;


public class Imenik {
    private Map<String, TelefonskiBroj> imena;

     Imenik()
    {
        imena = new HashMap<String, TelefonskiBroj>();

    }


    void dodaj(String ime, TelefonskiBroj broj){
        imena.put(ime, broj);
    }


    String dajBroj(String ime){
        TelefonskiBroj ret = imena.get(ime);
        return ret.ispisi();
    }

     String dajIme(TelefonskiBroj broj){
        for (Map.Entry<String, TelefonskiBroj> mapElement : imena.entrySet()) {
            if(mapElement.getValue().ispisi().equals(broj.ispisi())) return mapElement.getKey();
        }
        return null;
    }

     String naSlovo(char c){
        String ret = "";
        int index = 0;
        for(Map.Entry<String,TelefonskiBroj> mapElelement: imena.entrySet()){
            if(mapElelement.getKey().charAt(0) == c){
              ret = ret + index + ". " + mapElelement.getKey() +  " - " + mapElelement.getValue().ispisi() + "\n";
            }
            index++;
        }
        return ret;
        }

     Set<String> izGrada(Grad g){
        TreeSet<String> skup = new TreeSet<>();
        for(Map.Entry<String, TelefonskiBroj> mapElement: imena.entrySet()){
            if(mapElement.getValue() instanceof FiksniBroj && ((FiksniBroj) mapElement.getValue()).getGrad() == g) skup.add(mapElement.getKey());
        }
        return skup;
     }

     Set<TelefonskiBroj> izGradaBrojevi(Grad g){
        TreeSet<TelefonskiBroj> skup = new TreeSet<>();
        for(Map.Entry<String, TelefonskiBroj> mapElement: imena.entrySet()){
            if(mapElement.getValue() instanceof FiksniBroj && ((FiksniBroj) mapElement.getValue()).getGrad() == g ) skup.add(mapElement.getValue());
        }
        return skup;
     }
        public Map<String, TelefonskiBroj> getBrojKorisnika(){
         return imena;
        }




        }

package ba.unsa.etf.rpr.tutorijal_3;
public enum Grad { TRAVNIK,  ORASJE, ZENICA, SARAJEVO, LIVNO, TUZLA, MOSTAR, BIHAC, GORAZDE, SIROKIBRIJEG, BRCKO;


public static String dajPozivni(Grad grad){
    String pozivni;
    switch(grad){
        case TRAVNIK:
            pozivni = "030";
            return pozivni;
        case ORASJE:
            pozivni = "031";
            return pozivni;
        case ZENICA:
            pozivni = "032";
            return pozivni;
        case SARAJEVO:
            pozivni = "033";
            return pozivni;
        case LIVNO:
            pozivni = "034";
            return pozivni;
        case TUZLA:
            pozivni = "035";
            return pozivni;
        case MOSTAR:
            pozivni = "036";
            return pozivni;
        case BIHAC:
            pozivni = "037";
            return pozivni;
        case GORAZDE:
            pozivni = "038";
            return pozivni;
        case SIROKIBRIJEG:
            pozivni = "039";
            return pozivni;
        case BRCKO:
            pozivni = "049 ";
            return pozivni;
    }
    return null;
}

};
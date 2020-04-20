package ba.unsa.etf.rpr.tutorijal_3;
import java.util.*;

public class Program {
    private  Imenik imenik = new Imenik() ;

    public static void main(String[] args) {
        //imenik = new Imenik();
        Program aplikacija = new Program();
        String commands="";
        commands += "Sljedeće komande možete koristiti pri radu sa ETF imenikom:\n";
        commands +="**dodajMob --> za dodavanje mobilnog broja u imenik\n";
        commands +="**dodajFiks --> za dodavanje fiksnog broja u imenik\n";
        commands +="**dodajMed --> za dodavanje međunarodnog broja u imenik\n";
        commands +="**dajBroj --> za dohvaćanje broja nekog korisnika\n";
        commands +="**izGrada --> za dohvaćanje korisnika jednog grada\n";
        commands +="**izGradaBrojevi --> za dohvaćanje brojeva korisnika iz jednog grada\n";
        commands +="**naSlovo --> za dohvaćanje korisnika čije ime počinje na slovo, i njihovih brojeva\n";
        commands +="**dajIme --> za dohvaćanje imena korisnika na osnovu broja\n";
        commands +="**kraj --> izlaz iz programa\n";
        String myCommand;
        Scanner citac = new Scanner(System.in);
        Vanjska:for(;;){
            System.out.println(commands);
            System.out.print("komanda: ");
            myCommand = citac.next();
            switch (myCommand){
                case "dodajMob":
                    aplikacija.dodajMob();
                    break;
                case "dodajFiks":
                    aplikacija.dodajFiks();
                    break;
                case "izGrada":
                    aplikacija.izGrada();
                    break;
                case "izGradaBrojevi":
                    aplikacija.izGradaBrojevi();
                    break;
                case "naSlovo":
                    aplikacija.naSlovo();
                    break;
                case "dajIme":
                    aplikacija.dajIme();
                    break;
                case "dajBroj":
                    aplikacija.dajBroj();
                    break;
                case "dodajMed":
                    aplikacija.dodajMed();
                    break;
                case "kraj":
                    break Vanjska;
                default:
                    break ;
            }

        }


    }

    private void dajBroj() {
        Scanner citac = new Scanner(System.in);
        System.out.println("Ime i prezime korisnika: ");

        String ime=citac.next();
        String prezime=citac.next();
        System.out.println(imenik.dajBroj(ime+" "+ prezime));
    }
    private void dajIme(){
        HashMap<String,TelefonskiBroj> kopija=  (HashMap<String,TelefonskiBroj>) imenik.getBrojKorisnika();
        System.out.print("Unesite broj korisnika: ");
        Scanner citac = new Scanner(System.in);
        String input = citac.next();
        for(HashMap.Entry<String,TelefonskiBroj> element : kopija.entrySet()){
            if(element.getValue().ispisi().equals(input))
            {
                System.out.println("Ime korisnika s brojem "+input+" je "+element.getKey());
                return;
            }
        }
        System.out.println("Broj ne postoji!");
    }
    private void naSlovo(){
        Scanner citac = new Scanner(System.in);
        char slovo = (citac.next()).charAt(0);
        System.out.println( imenik.naSlovo(slovo));
    }
    private void izGradaBrojevi(){
        System.out.println("Unesite grad:\n"+
                "TRAVNIK\n"+ "ORASJE\n"+ "ZENICA\n"+ "SARAJEVO\n"+ "LIVNO\n"+
                "TUZLA\n"+ "MOSTAR\n"+ "BIHAC\n"+ "GORAZDE\n"+ "SIROKIBRIJEG\n"+
                "MRKONJICGRAD\n"+ "BANJALUKA\n"+ "PRIJEDOR\n"+ "DOBOJ\n"+
                "SAMAC\n"+ "BIJELJINA\n"+ "ZVORNIK\n"+ "PALE\n"+"FOCA\n"+"TREBINJE\n");
        Scanner citac = new Scanner(System.in);
        String grad = citac.next();
        Grad grad1 = Grad.valueOf(grad);
        Set<TelefonskiBroj> brojevi = imenik.izGradaBrojevi(grad1);
        for(TelefonskiBroj element : brojevi){
            System.out.println(element.ispisi());
        }
    }
    private void izGrada(){
        System.out.println("Unesite grad:\n"+
                "TRAVNIK\n"+ "ORASJE\n"+ "ZENICA\n"+ "SARAJEVO\n"+ "LIVNO\n"+
                "TUZLA\n"+ "MOSTAR\n"+ "BIHAC\n"+ "GORAZDE\n"+ "SIROKIBRIJEG\n"+
                "MRKONJICGRAD\n"+ "BANJALUKA\n"+ "PRIJEDOR\n"+ "DOBOJ\n"+
                "SAMAC\n"+ "BIJELJINA\n"+ "ZVORNIK\n"+ "PALE\n"+"FOCA\n"+"TREBINJE\n");
        Scanner citac = new Scanner(System.in);
        String grad = citac.next();
        Grad grad1 = Grad.valueOf(grad);
        Set<String> names = imenik.izGrada(grad1);
        for(String element : names){
            System.out.println("--"+element);
        }
    }
    private void dodajFiks(){
        Scanner citac = new Scanner(System.in);
        System.out.println("Ime i prezime korisnika: ");

        String ime=citac.next();
        String prezime=citac.next();

        System.out.println("Unesite grad:\n"+
                "TRAVNIK\n"+ "ORASJE\n"+ "ZENICA\n"+ "SARAJEVO\n"+ "LIVNO\n"+
                "TUZLA\n"+ "MOSTAR\n"+ "BIHAC\n"+ "GORAZDE\n"+ "SIROKIBRIJEG\n"+
                "MRKONJICGRAD\n"+ "BANJALUKA\n"+ "PRIJEDOR\n"+ "DOBOJ\n"+
                "SAMAC\n"+ "BIJELJINA\n"+ "ZVORNIK\n"+ "PALE\n"+"FOCA\n"+"TREBINJE\n");

        String grad=citac.next();
        Grad grad1 = Grad.valueOf(grad);
        System.out.print("Unesite broj koji dolazi poslije pozivnog(123-456): ");
        String broj=citac.next();
        try {
            imenik.dodaj(ime + " " + prezime, new FiksniBroj(grad1, broj));
        }catch(IllegalArgumentException izuzetak) {
            System.out.println(izuzetak.getMessage());
        }
    }

    private void dodajMob(){
        Scanner citac = new Scanner(System.in);
        System.out.println("Ime i prezime korisnika: ");

        String ime=citac.next();
        String prezime=citac.next();

        System.out.println("Mreže:\n"+
                "BH Mobile : 060, 061, 062\n"+
                "ERONET : 063\n"+
                "Haloo : 064\n"+
                "mtel : 065, 066, 067(Izi mobil)\n");
        System.out.print("Unesite pozivni broj bez 0(primjer 61 za 061): ");
        int pozivni;
        pozivni = citac.nextInt();
        System.out.print("Unesite broj koji dolazi poslije pozivnog(123-456): ");
        String broj=citac.next();
        try {
            imenik.dodaj(ime + " " + prezime, new MobilniBroj(pozivni, broj));
        }catch(IllegalArgumentException izuzetak) {
            System.out.println(izuzetak.getMessage());
        }
    }

    private void dodajMed() {
        Scanner citac = new Scanner(System.in);
        System.out.println("Ime i prezime korisnika: ");

        String ime=citac.next();
        String prezime=citac.next();
        System.out.print("Unesite broj države (+387) : ");
        String pozivni = citac.next();
        System.out.print("Unesite vas broj(33/123-456): ");
        String broj = citac.next();
        imenik.dodaj(ime+" "+prezime, new MedunarodniBroj(pozivni,broj));
    }
}

package ba.unsa.etf.rpr.tutorijal02;

public class Interval {
    private double x1;
    private double x2;
    private boolean inc1;

    public double getX1() {
        return x1;
    }

    public void setX1(double x1) {
        this.x1 = x1;
    }

    public double getX2() {
        return x2;
    }

    public void setX2(double x2) {
        this.x2 = x2;
    }

    public boolean isInc1() {
        return inc1;
    }

    public void setInc1(boolean inc1) {
        this.inc1 = inc1;
    }

    public boolean isInc2() {
        return inc2;
    }

    public void setInc2(boolean inc2) {
        this.inc2 = inc2;
    }

    private boolean inc2;

    public Interval (double a, double b, boolean x, boolean y) throws IllegalArgumentException{
        if( b < a) throw new IllegalArgumentException();
        x1 = a;
        x2 = b;
        inc1 = x;
        inc2 = y;
    }
    public Interval(){
        x1 = 0; x2 = 0; inc1 = false; inc2 = false;
    }
    public boolean isNull(){
        if(this.getX1() == 0 && this.getX2() == 0 && this.isInc1() == false && this.isInc2() == false) return true;
        return false;
    }
    public boolean isIn(double x){
        if(this.isInc1() && this.isInc2()){
            if(x >= this.getX1() && x <= this.getX2()) return true;
            return false;
        }
        else if(this.isInc1() && !this.isInc2()){
            if(x >= this.getX1() && x < this.getX2()) return true;
            return false;
        }
        else if(!this.isInc1() && this.isInc2()){
            if(x > this.getX1() && x <= this.getX2()) return true;
            return false;
        }
        else{
            if(x > this.getX1() && x < this.getX2()) return true;
            return false;
        }
    }

    public Interval intersect(Interval i){
        Interval ret = new Interval();
        double x, y, z, g;
        x = this.getX1(); y = this.getX2();
        z = i.getX1(); g = i.getX2();
        if( y < z || x > g) return ret;
        if(x >= z && y <= g){
            ret.setInc1(this.isInc1()); ret.setInc2(this.isInc2());
            ret.setX1(x); ret.setX2(y);
            return ret;
        }
        if(x <= z && y >= g){
            ret.setInc1(i.isInc1()); ret.setInc2(i.isInc2());
            ret.setX1(z); ret.setX2(g);
            return ret;
        }
        if( x < z &&  g > y && y > z ){
            ret.setInc1(i.isInc1()); ret.setInc2(this.isInc2());
            ret.setX1(z); ret.setX2(y);
            return ret;
        }
        if(z < x && y > g && x < g){
            ret.setInc1(this.isInc1()); ret.setInc2(i.isInc2());
            ret.setX1(x); ret.setX2(g);
            return ret;
        }
        return ret;
    }
    public static Interval intersect(Interval i1, Interval i2){
        Interval ret = new Interval();
        double x, y, z, g;
        x = i1.getX1(); y = i1.getX2();
        z = i2.getX1(); g = i2.getX2();
        if( y < z || x > g) return ret;
        if(x >= z && y <= g){
            ret.setInc1(i1.isInc1()); ret.setInc2(i1.isInc2());
            ret.setX1(x); ret.setX2(y);
            return ret;
        }
        if(x <= z && y >= g){
            ret.setInc1(i2.isInc1()); ret.setInc2(i2.isInc2());
            ret.setX1(z); ret.setX2(g);
            return ret;
        }
        if( x < z &&  g > y && y > z ){
            ret.setInc1(i2.isInc1()); ret.setInc2(i1.isInc2());
            ret.setX1(z); ret.setX2(y);
            return ret;
        }
        if(z < x && y > g && x < g){
            ret.setInc1(i1.isInc1()); ret.setInc2(i2.isInc2());
            ret.setX1(x); ret.setX2(g);
            return ret;
        }
        return ret;
    }

    @Override
    public boolean equals(Object o){
        Interval i = (Interval) o;
        return this.getX1() == i.getX1() && this.getX2() == i.getX2() && this.isInc1() == i.isInc1() && this.isInc2() == i.isInc2();
    }

    @Override
    public String toString(){
        if(this.isNull()) return "()";
        String z1 = "(";
        String z2 = ")";
        if(this.isInc1()) z1 = "[";
        if(this.isInc2()) z2 = "]";
        return (z1 + this.getX1() + "," + this.getX2() + z2);
    }


}

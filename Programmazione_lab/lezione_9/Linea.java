package lezione9;

public class Linea {
    private Vect p1;
    private Vect p2;

    public Linea() {
        this.p1 = new Vect();
        this.p2 = new Vect();
    }

    public Linea(Vect p1, Vect p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    public Vect getP1() {
        return this.p1;
    }

    public Vect getP2() {
        return  this.p2;
    }

    // Ritorna il coefficiente angolare di questa retta
    public double getM() {
        assert !this.p1.equals(this.p2);
        return (this.p2.getY()-this.p1.getY())/(this.p2.getX()-this.p1.getX());
    }

    // Trasla questa lina nello spazio dato un vettore
    public void translate(Vect offset) {
        double x = offset.getX();
        double y = offset.getY();
        this.p1.translate(x, y);
        this.p2.translate(x, y);
    }

    // Controlla se le due Lina sono uguali (stesse cordinate in entrambi i punti)
    public boolean equals(Linea l) {
        return this.p1.equals(l.getP1()) && this.p2.equals(l.getP2());
    }

    // Ritorna una copia di questa lina
    public Linea copy() {
        return new Linea(this.p1, this.p2);
    }

    // Ritorna true se le due Lina si intersecano
    public boolean intersectWith(Linea l) {
        if(this.equals(l)) return false; // se sono due rette uguali scartale

        /*
        se i coefficienti angolari sono diversi allora sono necessariamente
        due rette incidenti che si incontreranno prima o poi
        */
        return this.getM() != l.getM();
    }

    public double lenght() {
        return this.p1.distanceFromOtherVect(this.p2);
    }

}
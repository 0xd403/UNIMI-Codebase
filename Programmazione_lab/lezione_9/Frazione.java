package lezione9;

public class Frazione {
    private double numeratore;
    private double denominatore;

    public Frazione(double numeratore, double denominatore) {
        this.numeratore = numeratore;
        this.denominatore = denominatore;
    }

    public double getNumeratore() {
        return this.numeratore;
    }

    public double getDenominatore() {
        return this.denominatore;
    }

    public boolean isGreaterThan(Frazione f) {
        return (this.numeratore/this.denominatore) > (f.getNumeratore()/f.getDenominatore());
    }

    public boolean isLowerThan(Frazione f) {
        return (this.numeratore/this.denominatore) > (f.getNumeratore()/f.getDenominatore());
    }

    public String toString() {
        return this.numeratore + " / " + this.denominatore;
    }

}

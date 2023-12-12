package lezione9;
public class Cerchio {

  private Vect centro;
  private double raggio;

  public Cerchio() {
    this.centro = new Vect();
    this.raggio = 1;
  }

  // Constructs a new circle with the given raggio with center on (0, 0)
  public Cerchio(double raggio) {
    this.centro = new Vect();
    this.raggio = raggio;
  }

  // Constructs a new circle with the given center and raggio
  public Cerchio(Vect centro, double raggio) {
    this.centro = centro;
    this.raggio = raggio;
  }

  // Returns the center
  public Vect getCentro() { return this.centro; }

  // Returns the raggio
  public double getRaggio() { return this.raggio; }

  // Creates a new circle with the same state as the current one
  // N.B. the new object shares the same centro object
  public Cerchio copy() {
    return new Cerchio(this.centro, this.raggio);
  }

  // Compute the perimeter of the circle
  public double perimetro() {
    return 2.0 * Math.PI * this.raggio;
  }

  // Compute the area of the circle
  public double area() {
    return Math.PI * Math.pow(this.raggio, 2);
  }

  // Returns true if c is concentric to this circle
  public boolean isConcentric(Cerchio c) {
    return this.centro.equals(c.getCentro()) && this.raggio != c.getRaggio();
  }

  // Returns true if c is conincident to this circle
  public boolean isCoincident(Cerchio c) {
    return this.centro.equals(c.getCentro()) && this.raggio == c.getRaggio();
  }

  // Returns true if c is contained inside this circle
  public boolean contains(Cerchio c) {
    return this.raggio >= this.centro.distanceFromOtherVect(c.getCentro()) + c.raggio;
  }

}
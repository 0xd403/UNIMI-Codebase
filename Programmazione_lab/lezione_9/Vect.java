package lezione9;

public class Vect {

    private double x;
    private double y;

    public Vect() {
      this.x = 0;
      this.y = 0;
    }

    public Vect(double x, double y) {
      this.x = x;
      this.y = y;
    }

    public Vect(Vect v) {
      this.x = v.getX();
      this.y = v.getY();
    }

    public double getX() { return this.x; }

    public double getY() { return this.y; }

    // Moves the vect in the space based on the given offsets
    public void translate(double offsetX, double offsetY) {
      this.x += offsetX;
      this.y += offsetY;
    }

    // Checks if two Vect are equals to each others
    public boolean equals(Vect v) {
      return this.x == v.getX() && this.y == v.getY();
    }

    // Returns the distance of this point from the origin of axes
    public double distanceFromOrigin() {
        return Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y, 2));
    }

    // Returns the distance between this vector and another one
    public double distanceFromOtherVect(Vect v) {
      double diffX = this.x - v.getX();
      double diffY = this.y - v.getY();
      return Math.sqrt(Math.pow(diffX, 2) + Math.pow(diffY, 2));
    }

}

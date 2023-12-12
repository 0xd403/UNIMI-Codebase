package lezione9;

public class Complex {

  private double re;
  private double imm;

  public Complex(double realPart, double immaginaryPart) {
    this.re = realPart;
    this.imm = immaginaryPart;
  }

  public double getRealPart() {
    return this.re;
  }

  public double getImmaginaryPart() {
    return this.imm;
  }

  public String getAlgebricForm() {
    return new String(this.re + " + i * " + this.imm);
  }

  public String getTrigonometricForm() {
    return new String();
  }

  public String getExponentialForm() {
    return new String();
  }

}

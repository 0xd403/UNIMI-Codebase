package lezione9;

public class Contatore {

  // internal state of the counter
  private int cnt;

  public Contatore() {
    this.cnt = 0;
  }

  public Contatore(int start) {
    this.cnt = start;
  }

  public int getCnt() {
    return this.cnt;
  }

  public void inc() {
    this.cnt++;
  }

  public void reset() {
    this.cnt = 0;
  }

}

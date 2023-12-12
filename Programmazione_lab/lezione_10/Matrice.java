package lezione10;

import java.util.Arrays;

public class Matrice {
    private int rows;
    private int cols;
    private int[][] mat;

    public Matrice(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        mat = new int[rows][cols];
    }

    public Matrice(int[][] mat) {
        this.rows = mat.length;
        this.cols = mat[0].length;
        this.mat = mat;
    }

    public int getNumberOfRows() {
        return this.rows;
    }

    public int getNumberOfCols() {
        return  this.cols;
    }

    public int getElementByIdx(int row, int col) {
        return mat[row][col];
    }

    public void setElementByIdx(int val, int row, int col) {
        mat[row][col] = val;
    }

    @Override
    public String toString() {
        return Arrays.deepToString(this.mat);
    }

    public boolean haveEqualsRowsAndCools(Matrice m) {
        return this.rows == m.getNumberOfRows() && this.cols == m.getNumberOfCols();
    }

    // Ritorna vero se le due matrici hanno stesse dimensioni e valori
    public boolean areEquals(Matrice m) {
        if(this.equals(m)) return true; // same object references must be equals objects too
        if(this.haveEqualsRowsAndCools(m)) {
            for(int i = 0; i < this.rows; i++) {
                for(int j = 0; j < this.cols; j++) {
                    if(this.mat[i][j] != m.getElementByIdx(i, j)) return false;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }

    // Ritorna una nuova matrice che rappresenta la somma delle due
    public Matrice sum(Matrice m) {
        if(this.haveEqualsRowsAndCools(m)) {
            Matrice sum = new Matrice(this.rows, this.cols);
            int val;
            for(int i = 0; i < this.rows; i++) {
                for(int j = 0; j < this.cols; j++) {
                    val = this.mat[i][j] + m.getElementByIdx(i, j);
                    sum.setElementByIdx(val, i, j);
                }
            }
            return sum;
        }
        else {
            return null;
        }
    }

    // Ritorna una nuova matrice che rappresenta la moltiplicazione riga-colonna delle due
    public Matrice mul(Matrice m) {
        if(this.cols == m.getNumberOfRows()) {
            Matrice mul = new Matrice(this.rows, m.getNumberOfCols());
            int val;
            for(int i = 0; i < this.rows; i++) {
                for(int j = 0; j < m.getNumberOfCols(); j++) {
                    val = 0;
                    for(int k = 0; k < this.cols; k++) {
                        val += this.mat[i][k] * m.getElementByIdx(k, j);
                    }
                    mul.setElementByIdx(val, i, j);
                }
            }
            return mul;
        }
        else {
            return null;
        }
    }

}
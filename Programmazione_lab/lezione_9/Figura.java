package lezione9;
public class Figura {
    private Cerchio c1;
    private Cerchio c2;
    private Linea[] lineas;

    public Figura(Cerchio c1, Cerchio c2, Linea l1, Linea l2, Linea l3) {
        this.c1 = c1;
        this.c2 = c2;
        this.lineas = new Linea[]{l1, l2, l3};
    }

    public Cerchio getC1() {
        return c1;
    }

    public Cerchio getC2() {
        return c2;
    }

    public Linea[] getLineas() {
        return lineas;
    }

    public Linea getLinaByIdx(int idx) {
        return lineas[idx];
    }

    // Ritorna il tipo di triangolo contenuto se presente, null in caso contrario
    public Triangles containsATriangle() {
        int vertices = 0;
        // Cerco i possibili vertici
        for(int i = 1; i < lineas.length; i++) {
            if(lineas[0].getP1().equals(lineas[i].getP1())) vertices++;
            if(lineas[0].getP1().equals(lineas[i].getP2())) vertices++;
            if(lineas[0].getP2().equals(lineas[i].getP2())) vertices++;
            if(lineas[0].getP2().equals(lineas[i].getP1())) vertices++;
        }
        System.out.println(vertices);
        // Potrebbe essere un triangolo
        if(vertices == 2) {
            int eq = 0;
            for(int i = 1; i < lineas.length; i++) {
                if(lineas[0].lenght() == lineas[i].lenght()) eq++;
            }
            System.out.println(eq);
            switch(eq) {
                case 0:
                    return Triangles.Scaleno;
                case 1:
                    return Triangles.Isoscele;
                case 2:
                    return Triangles.Equilatero;
                default:
                    return null;
            }
        }
        else return null;
    }

}
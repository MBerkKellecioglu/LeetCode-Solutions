public class Square extends Shape2D {
    private double _a;

    public Square() {}

    public Square(double a) {
        _a = a;
    }

    public String getName() {
        return "Square";
    }
    public double getArea() {
        return _a * _a;
    }
    public double getCum() {
        return 4 * _a;
    }

    protected void finalize(){
        double i = getArea();
        String anan = Double.toString(i);
        System.out.println(anan);
    }
}
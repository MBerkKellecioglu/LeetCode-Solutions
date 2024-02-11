public class Cube extends Shape3D {
    double _a;

    public Cube() {} // Default constructor
    public Cube(double a) {
        _a = a;
    }

    public String getName() {
        return "Cube";
    }
    public double getArea() {
        return 6 * _a * _a;
    }
    public double getCum() {
        return 12 * _a;
    }

    public double getVolume() {
        return _a * _a * _a;
    }
}
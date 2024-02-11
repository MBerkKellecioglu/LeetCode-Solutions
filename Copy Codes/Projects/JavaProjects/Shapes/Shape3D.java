public abstract class Shape3D implements Shape{
    public abstract double getVolume();

    public String toString() {
        return getName() + "(area: " + getArea() + ", cum: " + getCum() + ", volume: " + getVolume() + ")";
    }
}
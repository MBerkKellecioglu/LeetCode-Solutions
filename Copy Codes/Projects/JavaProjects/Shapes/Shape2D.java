public abstract class Shape2D implements Shape {
    public String getName(){
        return "2D Shape";
    }

    public String toString() {
        return getName() + "(area: " + getArea() + ", cum: " + getCum() + ")";
    }
}
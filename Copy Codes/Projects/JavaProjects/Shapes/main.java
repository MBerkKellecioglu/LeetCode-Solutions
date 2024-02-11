import javax.swing.JOptionPane;
import java.util.Scanner;

public class main {
    public static void main(String[] args) {

        Shape2D obj1 = new Square(2);

        obj1 = null;

        System.gc();
    }
}
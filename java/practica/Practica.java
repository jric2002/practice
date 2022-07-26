/* Author: José Rodolfo (jric2002) */
import java.util.ArrayList;
import java.util.Iterator;
public class Practica {
  int x = 5;
  public static void main(String[] args) {
    ArrayList<String> cars = new ArrayList<String>();
    cars.add("Volvo");
    cars.add("Ford");
    cars.add("Toyota");
    Iterator<String> it = cars.iterator();
    System.out.println(it.next());
  }
}
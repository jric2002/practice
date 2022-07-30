/* Author: José Rodolfo (jric2002) */
import java.util.Scanner;
public class Practica {
  int x = 5;
  public static void main(String[] args) {
    int n1;
    String n2;
    System.out.print("Ingresa n1: ");
    Scanner input = new Scanner(System.in);
    n1 = input.nextInt();
    System.out.print("Ingresa n2: ");
    n2 = input.next();
    System.out.println("sum: " + n1 + n2);
  }
}
/* Author: José Rodolfo (jric2002) */
public class ClasesObjetos {
  public static void main(String[] args) {
    Cookie casino = new Cookie("Casino", 4, "Limon");
    System.out.println("Name: " + casino.getName());
    System.out.println("Amount: " + casino.getAmount());
    System.out.println("Flavor: " + casino.getFlavor());
  }
}

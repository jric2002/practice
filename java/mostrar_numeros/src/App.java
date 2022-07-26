/**
 * @author José Rodolfo
*/
/* Libraries */
import java.util.Scanner;
//import javax.swing.JOptionPane;
public class App {
  /**
   * @param args the command line arguments
   */
  public static int randomNumber(int min, int max) {
  int randon_number = (int)(Math.floor((Math.random()*(max - min + 1)) + min));
  return randon_number;
  }
  public static void main(String[] args) {
  // Testing
  int array_size = 10;
  int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int temp;
  temp = numbers[array_size - 1];
  for (int i = array_size - 2; i >= 0; i--) {
    numbers[i + 1] = numbers[i];
  }
  numbers[0] = temp;
  for (int i = 0; i < array_size; i++) {
    System.out.print(numbers[i] + " - ");
  }
  }
}
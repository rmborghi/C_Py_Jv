import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        try (Scanner nome = new Scanner(System.in)) {
            System.out.println("Hello, World!");
            System.out.print("Digita:");
            String userName = nome.nextLine();
            System.out.println("Nome: " + userName);
        }
    }
}

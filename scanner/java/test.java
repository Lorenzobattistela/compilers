import java.util.Scanner;

public class SampleJava {
    public static void main(String[] args) {
        // Variables
        int num1 = 10;
        int num2 = 20;
        int sum = num1 + num2;

        // Conditional statement
        if (sum > 15) {
            System.out.println("Sum is greater than 15.");
        } else {
            System.out.println("Sum is not greater than 15.");
        }

        // Loop
        for (int i = 0; i < 5; i++) {
            System.out.println("Loop iteration: " + i);
        }

        // String Literal
        String message = "Hello, Java!";
        System.out.println(message);

        // Floating-Point Literal
        double pi = 3.14159;
        System.out.println("The value of pi: " + pi);

        // Scanner to get user input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your name: ");
        String name = scanner.nextLine();
        System.out.println("Hello, " + name + "!");

        // Method call
        displayMessage("This is a method call.");
    }

    // Method definition
    public static void displayMessage(String msg) {
        System.out.println(msg);
    }
}

package g144.krylova;

import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) throws IncorrectInputException{
        try {
            Scanner input = new Scanner(System.in);
            System.out.print("Enter expression in infix form: ");
            String expression = input.nextLine();
            String postfixExpression = Converter.getPostfixNotation(expression);
            System.out.println("Result of calculation: " + Calculator.calculate(postfixExpression));
        }

        catch (IncorrectInputException e) {
            System.out.println("Incorrect exception.");
        }
    }
}
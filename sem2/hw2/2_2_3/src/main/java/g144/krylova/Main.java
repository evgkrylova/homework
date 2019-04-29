package g144.krylova;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        try {
            int[][] matrix = MatrixReader.fillMatrix(input);

            System.out.print("Enter 0 if you want to use console for output and 1 if a file.");
            int outputWay = Integer.parseInt(input.next());

            while ((outputWay != 0) && (outputWay != 1)) {
                System.out.print("Entered symbol is incorrect. Try again.");
                outputWay = Integer.parseInt(input.next());
            }

            SpiralPrinter output;
            if (outputWay == 0) {
                output = new ConsolePrinter();
            } else {
                output = new FilePrinter();
            }

            output.printSpiral(matrix);
        }

        catch (IncorrectSizeException e){
            System.out.println("Incorrect size of matrix.");
        }

        catch (FileNotFoundException e){
            System.out.println(e.getMessage());
        }

        catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}

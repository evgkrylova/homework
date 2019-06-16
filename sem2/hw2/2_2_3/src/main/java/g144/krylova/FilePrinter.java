package g144.krylova;

import java.io.PrintStream;
import java.io.IOException;

public class FilePrinter extends SpiralConverter{
    /**
     * {@inheritDoc}
     */
    @Override
    public void printSpiral(int[][] array) throws IOException, IncorrectSizeException{
        PrintStream output = new PrintStream("output.txt");
        printSpiral(array, output);
        output.close();
    }
}

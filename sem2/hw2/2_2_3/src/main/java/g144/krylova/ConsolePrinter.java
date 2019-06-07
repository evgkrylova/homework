package g144.krylova;

import java.io.IOException;

/**
 * Class containing method for printing the matrix to console.
 */
public class ConsolePrinter extends SpiralConverter{
    /**
     * {@inheritDoc}
     */
    @Override
    public void printSpiral(int[][] array) throws IOException, IncorrectSizeException {
        printSpiral(array, System.out);
    }
}

package g144.krylova;

import java.io.IOException;

/**
 * Interface containing method for printing N*N array as a spiral.
 */
public interface SpiralPrinter {
    /**
     * Method printing square matrix as a spiral.
     * @param matrix is array to print.
     * @throws IncorrectSizeException if it is impossible to read the matrix array as spiral.
     */
    void printSpiral(int[][] matrix) throws IOException, IncorrectSizeException;

}
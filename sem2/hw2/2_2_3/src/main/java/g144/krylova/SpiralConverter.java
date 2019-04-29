package g144.krylova;

import java.io.PrintStream;
import java.io.PrintWriter;

/**
 * Class containing interpreter to spiral for the array in the matrix form.
 */
abstract class SpiralConverter implements SpiralPrinter{
    /**
     * {@inheritDoc}
     */
    void printSpiral(int[][] matrix, PrintStream output) throws IncorrectSizeException{
        String resultString = spiralForm(matrix);
        output.print(resultString);
    }

    /**
     * Method converting matrix to the string of the spiral form.
     * @param matrix is the array to convert.
     * @return spiral string.
     * @throws IncorrectSizeException if it is impossible to read the matrix array as spiral.
     */
    static public String spiralForm(int[][] matrix) throws IncorrectSizeException{
        StringBuffer resultString = new StringBuffer();

        if (matrix.length % 2 == 0 || matrix.length < 1) {
            throw new IncorrectSizeException("Incorrect size of matrix.");
        }

        int horizontalIndex = matrix.length / 2;
        int verticalIndex = matrix.length / 2;
        resultString.append(matrix[horizontalIndex][verticalIndex]);
        resultString.append(" ");

        for (int i = 1; i < matrix.length; i++) {
            for (int k = 0; k < i * 2; k++) {
                if (i % 2 == 1) {
                    if (k < i) {
                        verticalIndex++;
                    } else {
                        horizontalIndex--;
                    }
                }
                else{
                    if (k < i) {
                        verticalIndex--;
                    } else {
                        horizontalIndex++;
                    }
                }

                resultString.append(matrix[horizontalIndex][verticalIndex]);
                resultString.append(" ");
            }
        }

        for (int k = 0; k < matrix.length - 1; k++) {
            verticalIndex++;
            resultString.append(matrix[horizontalIndex][verticalIndex]);
            resultString.append(" ");
        }

        return resultString.toString();
    }
}

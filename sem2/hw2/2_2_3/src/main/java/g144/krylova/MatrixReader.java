package g144.krylova;

import java.util.Scanner;

/**
 * Class containing methods for reading with matrix.
 */
public class MatrixReader{
    /**
     * Method reading the matrix.
     * @param input is source of data storage.
     */
    static public int[][] fillMatrix(Scanner input) {
        int size = input.nextInt();
        int[][] matrix = emptyMatrix(size);
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                matrix[i][j] = Integer.parseInt(input.next());
            }
        }
        return matrix;
    }

    /**
     * Method creating an empty matrix.
     * @param size is the size parameter of matrix.
     * @return empty matrix.
     */
    static private int[][] emptyMatrix(int size){
        int[][] matrix = new int[size][];
        for (int i = 0; i < size; i++){
            matrix[i] =  new int[size];
        }
        return matrix;
    }
}

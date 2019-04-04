package g144.krylova;

/**
 * Exception thrown if it is impossible to read the matrix array as spiral.
 */
public class IncorrectSizeException extends Exception{
    public void message(){
        System.out.print("Size is not odd and positive number.");
    }
}
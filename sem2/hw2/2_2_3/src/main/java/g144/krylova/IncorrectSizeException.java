package g144.krylova;

/**
 * Exception thrown if it is impossible to read the matrix array as spiral.
 */
public class IncorrectSizeException extends Exception{
    public IncorrectSizeException(String message) {
        super(message);
    }
}
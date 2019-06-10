package g144.krylova;

/**
 * Exception thrown if the operator is uncorrected.
 */
public class WrongOperatorException extends Exception{
    public WrongOperatorException(String message) {
        super(message);
    }
}
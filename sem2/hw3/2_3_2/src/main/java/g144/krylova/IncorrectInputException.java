package g144.krylova;

/**
 * Exception throwing if the input expression is impossible to calculate.
 */
public class IncorrectInputException extends Exception{
    public void message(){
        System.out.println("Expression is incorrect.");
    }
}

package g144.krylova;

/**
 * Exception throwing if the removing value is not in table.
 */
public class NotExistingValueException extends Exception{
    public void message(){
        System.out.println("Value is already added.");
    }
}

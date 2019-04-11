package g144.krylova;

/**
 * Exception throwing if the adding value is already in table.
 */
public class NotExistingValueException extends Exception{
    public void message(){
        System.out.println("Value is already added.");
    }
}

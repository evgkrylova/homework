package g144.krylova;

/**
 * Exception thrown when the stack is empty.
 */
public class EmptyStackException extends Exception {
    public void message(){
        System.out.print("Stack is empty.");
    }
}
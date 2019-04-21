package g144.krylova;

/**
 * Exception thrown when the stack is empty.
 */
public class EmptyQueueException extends Exception {
    public void message(){
        System.out.print("Queue is empty.");
    }
}

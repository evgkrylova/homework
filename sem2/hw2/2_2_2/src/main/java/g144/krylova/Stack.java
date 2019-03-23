package g144.krylova;

/**
 * Interface containing main methods for working with stack.
 * @param <ElementType> is type of elements.
 */
public interface Stack<ElementType> {

    /**
     * Method adding an element to the stack.
     * @param value is element to push.
     */
    void push(ElementType value);

    /**
     * Method removing the top element from the stack and returning it.
     * @return the top element of stack.
     * @throws EmptyStackException if stack is empty.
     */
    ElementType pop() throws EmptyStackException;

    /**
     * Method returning the top element of the stack.
     * @return the top element of stack.
     * @throws EmptyStackException if stack is empty.
     */
    ElementType top() throws EmptyStackException;

    /**
     * Method returning the length of the stack.
     * @return how many elements are there in the stack.
     */
    int getLength();

    /**
     * Method returning is the stack empty.
     * @return true if the stack is empty and false otherwise.
     */
    boolean isEmpty();
}
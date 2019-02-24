package g144.krylova;

public class Stack<Type> {

    private class StackElement {
        Type value;
        StackElement next;

        StackElement(Type value, StackElement next) {
            this.value = value;
            this.next = next;
        }

        Type getValue() {
            return this.value;
        }
    }

    private StackElement head = null;
    private int length = 0;

    /**
     * A function returning the length of the stack.
     */
    public int getLength() {
        return length;
    }

    /**
     * A function returning is the stack empty.
     */
    public boolean isEmpty() {
        return (length == 0);
    }

    /**
     * A function putting an element to the stack's top.
     */
    public void push(Type value) {
        head = new StackElement(value, head);
        length++;
    }

    /**
     * A function deleting and returning the top element from the stack.
     */
    public Type pop() {
        if (isEmpty()) {
            return null;
        }
        Type result = head.value;
        head = head.next;
        length--;
        return result;
    }

    /**
     * A function returning the top element from the stack.
     */
    public Type top() {
        if (isEmpty()) {
            return null;
        }
        return head.value;
    }
}










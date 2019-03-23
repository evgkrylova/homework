package g144.krylova;

/**
 * Class containing stack realizing with list.
 */
public class ListStack<ElementType> implements Stack<ElementType> {
    private StackElement top = null;
    private int length = 0;

    /**
     * {@inheritDoc}
     */
    @Override
    public void push(ElementType value) {
        StackElement newTop = new StackElement(value, top);
        top = newTop;
        length++;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ElementType pop() throws EmptyStackException {
        if (length == 0) {
            throw new EmptyStackException();
        }
        ElementType topElement = top.value;
        top = top.next;
        length--;
        return topElement;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ElementType top() throws EmptyStackException {
        if (length == 0){
            throw new EmptyStackException();
        }
        return top.value;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int getLength() {
        return length;
    }

    /**
     * {@inheritDoc}
     */
    public boolean isEmpty(){
        return length == 0;
    }

    /**
     * Class contains some value and pointer to next element
     */
    class StackElement{
        ElementType value;
        StackElement next;

        StackElement(ElementType value, StackElement next){
            this.value = value;
            this.next = next;
        }
    }
}

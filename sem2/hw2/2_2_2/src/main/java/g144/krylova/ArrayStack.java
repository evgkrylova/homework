package g144.krylova;

/**
 * Class containing stack realizing with array.
 */
public class ArrayStack<ElementType> implements Stack<ElementType> {
    private int stackLength = 0;
    protected int arrayLength = 8;
    private ElementType stack[];

    public ArrayStack(){
        this.stack = (ElementType[]) new Object[arrayLength];
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void push(ElementType value) {
        if (stackLength >= arrayLength){
            expandArray();
        }
        stack[stackLength] = value;
        stackLength++;
    }

    /**
     * Method expanding array in case stack is containing more elements.
     */
    private void expandArray(){
        int newArrayLength = arrayLength * 2;
        ElementType newStack[] = (ElementType[]) new Object[newArrayLength];

        for (int i = 0; i < arrayLength; i++){
            newStack[i] = stack[i];
        }

        arrayLength = newArrayLength;
        stack = newStack;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ElementType pop() throws EmptyStackException {
        if (stackLength == 0){
            throw new EmptyStackException("Stack is empty.");
        }
        ElementType topElement = stack[stackLength - 1];
        stack[stackLength - 1] = null;
        stackLength--;
        return topElement;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public ElementType top() throws EmptyStackException {
        if (stackLength == 0){
            throw new EmptyStackException("Stack is empty.");
        }
        return stack[stackLength - 1];
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int getLength() {
        return stackLength;
    }

    /**
     * {@inheritDoc}
     */
    public boolean isEmpty(){
        return stackLength == 0;
    }
}
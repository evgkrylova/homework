package g144.krylova;

/**
 * Class containing main methods for work with a standard priority queue.
 * @param <ElementType> is type of elements.
 */
public class Queue<ElementType> {
    private QueueElement head = null;
    private int length = 0;

    /**
     * Method adding an element to the queue.
     * @param value is an element to add.
     * @param priority is a number meaning priority.
     */
    public void enqueue(ElementType value, int priority) {
        QueueElement newElement = new QueueElement(value, priority, null);
        int index = length;
        QueueElement currentElement = head;
        length++;
        while (index > 0 && currentElement.priority > newElement.priority) {
            if ((currentElement.next != null && currentElement.next.priority <= newElement.priority) || (currentElement.next == null)){
                newElement.next = currentElement.next;
                currentElement.next = newElement;
                return;
            }
            currentElement = currentElement.next;
            index--;
        }

        if (length == 0){
            head = newElement;
        }
        else{
            head = newElement;
            head.next = currentElement;
        }
    }

    /**
     * Method removing the element with the highest priority from the stack and returning it.
     * @return the the highest priority element.
     * @throws EmptyQueueException if queue is empty.
     */
    public ElementType dequeue() throws EmptyQueueException {
        if (length == 0) {
            throw new EmptyQueueException();
        }
        ElementType firstElement = head.value;
        head = head.next;
        length--;
        return firstElement;
    }

    /**
     * Method returning the top element of the stack.
     * @return the top element of stack.
     * @throws EmptyQueueException if stack is empty.
     */
    public ElementType peek() throws EmptyQueueException {
        if (length == 0){
            throw new EmptyQueueException();
        }
        return head.value;
    }

    /**
     * Method returning is the queue empty.
     * @return true if the queue is empty and false otherwise.
     */
    public boolean isEmpty(){
        return length == 0;
    }

    /**
     * Method returning the length of the queue.
     * @return how many elements are there in the queue.
     */
    public int getLength() {
        return length;
    }

    /**
     * Class containing a value, a priority number and a pointer to the next element.
     */
    private class QueueElement{
        ElementType value;
        int priority;
        QueueElement next;

        QueueElement(ElementType value, int priority, QueueElement next){
            this.value = value;
            this.priority = priority;
            this.next = next;
        }
    }
}

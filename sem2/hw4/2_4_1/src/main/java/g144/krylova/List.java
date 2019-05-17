package g144.krylova;

/**
 * Class containing methods for work with a singly linked list.
 * @param <Type> is element type.
 */
public class List<Type> {
    private ListElement head = null;
    private int length = 0;

    /**
     * Method putting an element to the head.
     * @param value is value to add.
     * @throws DuplicateElementException if the adding value is already in table.
     */
    public void addElement(Type value) throws DuplicateElementException {
        head = new ListElement(value, head);
        length++;
    }

    /**
     * Method putting an element to the N-th position.
     * @param value is value to add.
     * @param n is number of adding element index.
     * @throws DuplicateElementException if the adding value is already in table.
     */
    public void addElement(Type value, int n) throws DuplicateElementException {
        if (n > length)
            return;

        ListElement current = head;
        for (int i = 0; i < n; i++) {
            current = current.next;
        }
        current.next = new ListElement(value);
        length++;
    }

    /**
     * Method removing the N-th element from the list.
     * @param n is index of removing element.
     */
    public void removeElement(int n) {
        if (n >= length || n < 0) {
            return;
        }
        length--;

        if (n == 0) {
            head = head.next;
            return;
        }

        ListElement current = head;
        ListElement previous = current;
        while (n != 0) {
            previous = current;
            current = current.next;
            n--;
        }
        previous.next = current.next;
    }

    /**
     * Method checking if the element is already in the list.
     * @param value is value to check.
     * @return true if the element is in the list and false otherwise.
     */
    public boolean isElementInList(Type value) {
        ListElement currentElement = head;
        int index = 0;
        while (currentElement != null && currentElement.getValue() != value){
            index++;
            currentElement = currentElement.getNext();
        }
        if (index == length){
            return false;
        }
        return true;
    }


    /** Method returning the N-th element from the list.
     * @param n is index of getting element.
     */
    public Type getElement(int n) {
        if (n >= length || n < 0) {
            return null;
        }

        ListElement current = head;
        while (n != 0) {
            current = current.next;
            n--;
        }
        return current.value;
    }

    /**
     * Method returning the length of the list.
     */
    public int getLength() {
        return length;
    }

    /**
     * Method returning is the list empty.
     */
    public boolean isEmpty() {
        return (length == 0);
    }

    /**
     * Method printing the list.
     */
    public void print() {
        System.out.print("List: ");
        for (int i = 0; i < getLength(); i++){
            System.out.print(getElement(i) + " ");
        }
    }

    /**
     * Class realizing a list element.
     */
    private class ListElement {
        private Type value;
        private ListElement next;
        private ListElement tail;

        private ListElement(Type value, ListElement next) {
            this.value = value;
            this.next = next;
        }

        private ListElement(Type value) {
            this.value = value;
        }

        private Type getValue() {
            return this.value;
        }

        private ListElement getNext() {
            return this.next;
        }

        private void setValue(Type newValue){
            this.value = newValue;
        }

        private void setNext(ListElement newNext){
            this.next = newNext;
        }
    }
}
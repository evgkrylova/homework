package g144.krylova;

/**
 * A class realizing functions of a singly linked list.
 */
public class List<Type> {

    private ListElement head = null;
    private int length = 0;

    /**
     * A function returning the length of the list.
     */
    public int getLength() {
        return length;
    }

    /**
     * A function returning is the list empty.
     */
    public boolean isEmpty() {
        return (length == 0);
    }

    /**
     * A function putting an element to the head.
     */
    public void addElement(Type value) {
        head = new ListElement(value, head);
        length++;
    }

    /**
     * A function putting an element to the N-th position.
     */
    public void addElement(Type value, int n) {
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
     * A function removing the N-th element from the list.
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
     * A function returning the N-th element from the list.
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
     * A function printing the list.
     */
    public void print() {
        System.out.print("List: ");
        for (int i = 0; i < getLength(); i++){
            System.out.print(getElement(i) + " ");
        }
    }

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
    }
}
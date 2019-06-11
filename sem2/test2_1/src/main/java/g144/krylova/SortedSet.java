package g144.krylova;

import java.util.LinkedList;
import java.util.Set;

/**
 * Class containing a description of linked lists sorted class and methods for work with it.
 */
public class SortedSet {
    private int size;
    private LinkedList<LinkedList> sortedSet;

    /**
     * Constructor of sorted set.
     */
    public SortedSet() {
        size = 0;
        sortedSet = new LinkedList<>();
    }

    /**
     * Method returning the size of the set.
     * @return the number of lists containing in this set.
     */
    public int size(){
        return size;
    }

    /**
     * Method checking if the set empty.
     * @return true if the set is empty and false otherwise.
     */
    public boolean isEmpty(){
        return size == 0;
    }

    /**
     * Method adding a new list to the set.
     * @param element is the lit to add.
     * @return true if the adding was successful and false otherwise.
     */
    public boolean addList(LinkedList element){
        if (containsList(element)){
            return false;
        }
        if (isEmpty()){
            sortedSet.add(element);
            size++;
            return true;
        }
        Comparator comparator = new ListComparator();
        int index = 0;
        while (index < size && comparator.compareLists(element, sortedSet.get(index)) > 0){
            index++;
        }
        sortedSet.add(index, element);
        size++;
        return true;
    }

    /**
     * Method checking if the list is almost in the set.
     * @param element is list to check.
     * @return true if the list is in the set and false otherwise.
     */
    public boolean containsList(LinkedList element) {
        for (LinkedList currentElement : sortedSet) {
            if (currentElement.equals(element)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Method printing the set.
     */
    public void print(){
        for (LinkedList currentElement : sortedSet) {
            for (Object word : currentElement){
                System.out.print(word.toString() + ' ');
            }
            System.out.print('\n');
        }
    }

    /**
     * Method getting the particular element of the set.
     * @param index if the index of needing list.
     * @return the list which is referred by the index.
     */
    public LinkedList getList(int index){
        return sortedSet.get(index);
    }
}

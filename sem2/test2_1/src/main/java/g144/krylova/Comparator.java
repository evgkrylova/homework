package g144.krylova;

import java.util.LinkedList;

/**
 * Interface containing method for compare a pair of elemens.
 */
public interface Comparator {
    /**
     * Method comparing two linked lists based on the sizes.
     * @param firstList is the first list to compare.
     * @param secondList is the second list to compare.
     * @return positive number if the first list contains more elements then other one, negative number in the opposite case and 0 if the lists are equinumerous.
     */
    int compareLists(LinkedList firstList, LinkedList secondList);
}

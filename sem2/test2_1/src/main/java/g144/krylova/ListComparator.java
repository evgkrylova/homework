package g144.krylova;

import java.util.LinkedList;

public class ListComparator implements Comparator{
    /**
     * {@inheritDoc}
     */
    public int compareLists(LinkedList firstList, LinkedList secondList){
        return Integer.compare(firstList.size(), secondList.size());
    }
}

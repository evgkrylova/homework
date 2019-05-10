package g144.krylova;

import org.junit.jupiter.api.Test;
import java.util.LinkedList;

import static org.junit.jupiter.api.Assertions.*;

class ListComparatorTest {

    @Test
    void compareListsFirstTest() {
        LinkedList<String> firstList = new LinkedList<>();
        firstList.add("Three");
        firstList.add("One");
        firstList.add("Four");

        LinkedList<String> secondList = new LinkedList<>();
        secondList.add("Two");

        Comparator comparator = new ListComparator();
        assertTrue(comparator.compareLists(firstList, secondList) > 0);
    }

    @Test
    void compareListsSecondTest() {
        LinkedList<String> secondList = new LinkedList<>();
        secondList.add("Three");
        secondList.add("One");
        secondList.add("Four");

        LinkedList<String> firstList = new LinkedList<>();
        firstList.add("Two");

        Comparator comparator = new ListComparator();
        assertTrue(comparator.compareLists(firstList, secondList) < 0);
    }

    @Test
    void compareListsEqualTest() {
        LinkedList<String> firstList = new LinkedList<>();
        firstList.add("Three");

        LinkedList<String> secondList = new LinkedList<>();
        secondList.add("Two");

        Comparator comparator = new ListComparator();
        assertTrue(comparator.compareLists(firstList, secondList) == 0);
    }
}
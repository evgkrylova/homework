package g144.krylova;

import org.junit.jupiter.api.Test;
import java.util.LinkedList;

import static org.junit.jupiter.api.Assertions.*;

class SortedSetTest {
    @Test
    void addListTest() {
        LinkedList<String> firstList = new LinkedList<>();
        firstList.add("Three");
        firstList.add("One");
        firstList.add("Four");

        LinkedList<String> secondList = new LinkedList<>();
        secondList.add("Two");

        SortedSet set = new SortedSet();
        set.addList(firstList);
        set.addList(secondList);

        assertTrue(set.getList(0).equals(secondList));
        assertTrue(set.getList(1).equals(firstList));
    }

    @Test
    void addDuplicateListTest() {
        LinkedList<String> secondList = new LinkedList<>();
        secondList.add("Two");

        LinkedList<String> thirdList = new LinkedList<>();
        thirdList.add("Two");

        SortedSet set = new SortedSet();
        set.addList(secondList);

        assertFalse(set.addList(thirdList));
    }
}
package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ListTest {

    @Test
    void addElementTest() throws DuplicateElementException {
        List<Integer> list = new List<>();
        list.addElement(1);
        list.addElement(2);
        list.addElement(3);
        assertEquals(3, list.getLength());
    }

    @Test
    void addElementByIndexTest() throws DuplicateElementException {
        List<Integer> list = new List<>();
        list.addElement(1);
        list.addElement(2, 0);
        list.addElement(3, 1);
        assertEquals(3, list.getLength());
    }

    @Test
    void removeElementTest() throws DuplicateElementException {
        List<Integer> list = new List<>();
        list.addElement(1);
        list.addElement(2);
        list.addElement(3);
        list.removeElement(1);
        assertEquals(2, list.getLength());
    }

    @Test
    void isElementInListTest() throws DuplicateElementException {
        List<Integer> list = new List<>();
        list.addElement(1);
        list.addElement(2);
        assertTrue(list.isElementInList(1));
        assertTrue(list.isElementInList(2));
        assertFalse(list.isElementInList(3));
    }

    @Test
    void isEmptyTest() throws DuplicateElementException {
        List<Integer> list = new List<>();
        list.addElement(1);
        assertFalse(list.isEmpty());
        list.removeElement(0);
        assertTrue(list.isEmpty());
    }
}
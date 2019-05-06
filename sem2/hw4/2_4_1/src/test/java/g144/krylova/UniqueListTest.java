package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UniqueListTest {

    @Test
    void addDuplicateElementTest() throws DuplicateElementException {
        List<Integer> list = new UniqueList<>();
        list.addElement(1);
        list.addElement(2);
        list.addElement(3);
        assertThrows(DuplicateElementException.class, () -> list.addElement(3));
    }

    @Test
    void addElementTest() throws DuplicateElementException {
        List<Integer> list = new UniqueList<>();
        list.addElement(1);
        list.addElement(2);
        list.addElement(3);
        assertEquals(3, list.getLength());
    }
}
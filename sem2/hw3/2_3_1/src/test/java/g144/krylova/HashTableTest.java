package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HashTableTest {
    @Test
    void addTest() throws DuplicateValueException{
        HashTable table = new HashTable(10, new PolynomialHasher());
        table.add("first");
        table.add("second");
        assertEquals(2, table.getNumberOfElements());
    }

    @Test
    void containsTest() throws DuplicateValueException{
        HashTable table = new HashTable(10, new PolynomialHasher());
        table.add("first");
        table.add("second");
        assertTrue(table.contains("first"));
        assertFalse(table.contains("third"));
    }

    @Test
    void removeTest() throws NotExistingValueException, DuplicateValueException{
        HashTable table = new HashTable(10, new PolynomialHasher());
        table.add("first");
        table.add("second");
        table.add("third");
        table.remove("second");
        assertEquals(2, table.getNumberOfElements());
        table.remove("first");
        assertEquals(1, table.getNumberOfElements());
        table.remove("third");
        assertEquals(0, table.getNumberOfElements());
    }
}
package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InsertionSorterTest {

    @Test
    void sortClassicArray() {
        int arrayToSort[] = {5, 6, 7, 1, 3, 2, 4};
        int expectedAnswer[] = {1, 2, 3, 4, 5, 6, 7};
        InsertionSorter testSorter = new InsertionSorter();
        testSorter.sort(arrayToSort);
        assertArrayEquals(expectedAnswer, arrayToSort);
    }

    @Test
    void sortOneElementArray() {
        int arrayToSort[] = {5};
        int expectedAnswer[] = {5};
        InsertionSorter testSorter = new InsertionSorter();
        testSorter.sort(arrayToSort);
        assertArrayEquals(expectedAnswer, arrayToSort);
    }

    @Test
    void sortEmptyArray() {
        int arrayToSort[] = {};
        int expectedAnswer[] = {};
        InsertionSorter testSorter = new InsertionSorter();
        testSorter.sort(arrayToSort);
        assertArrayEquals(expectedAnswer, arrayToSort);
    }
}
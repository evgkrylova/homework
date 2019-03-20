package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class QuickSorterTest {

    @Test
    void sortClassicArray() {
        int arrayToSort[] = {5, 6, 7, 1, 3, 2, 4};
        int expectedAnswer[] = {1, 2, 3, 4, 5, 6, 7};
        QuickSorter testSorter = new QuickSorter();
        testSorter.sort(arrayToSort);
        assertArrayEquals(expectedAnswer, arrayToSort);
    }

    @Test
    void sortOneElementArray() {
        int arrayToSort[] = {5};
        int expectedAnswer[] = {5};
        QuickSorter testSorter = new QuickSorter();
        testSorter.sort(arrayToSort);
        assertArrayEquals(expectedAnswer, arrayToSort);
    }

    @Test
    void sortEmptyArray() {
        int arrayToSort[] = {};
        int expectedAnswer[] = {};
        QuickSorter testSorter = new QuickSorter();
        testSorter.sort(arrayToSort);
        assertArrayEquals(expectedAnswer, arrayToSort);
    }
}
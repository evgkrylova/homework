package g144.krylova;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;
import java.util.Random;

public class QuickSorterTest {
    private Random randomNumber = new Random();
    private static int ARRAY_SIZE = 1048576;
    private static int[]array = new int[ARRAY_SIZE];
    private static final int ARRAYS_NUMBER = 30;

    @Test
    public void OneThreadSorterTest() {
        OneThreadSorter oneSorter = new OneThreadSorter();
        oneSorter.sort(array, 0, ARRAY_SIZE - 1);
        boolean isSorted = true;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            if (array[i] > array[i + 1]) {
                isSorted = false;
            }
        }
        assertTrue(isSorted);
    }

    @Test
    public void MultiThreadSorterTest() {
        MultiThreadSorter multiSorter = new MultiThreadSorter();
        multiSorter.sort(array, 0, ARRAY_SIZE - 1);
        boolean isSorted = true;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            if (array[i] > array[i + 1]) {
                isSorted = false;
            }
        }
        assertTrue(isSorted);
    }

    @Test
    public void speedTest() {
        double oneTime = 0;
        double multiTime = 0;
        OneThreadSorter oneSorter = new OneThreadSorter();
        MultiThreadSorter multiSorter = new MultiThreadSorter();
        for (int i = 0; i < ARRAYS_NUMBER; i++) {
            long start = System.currentTimeMillis();
            oneSorter.sort(array, 0, ARRAY_SIZE - 1);
            oneTime += System.currentTimeMillis() - start;
            start = System.currentTimeMillis();
            multiSorter.sort(array, 0, ARRAY_SIZE - 1);
            multiTime += System.currentTimeMillis() - start;
            for (int j = 0; j < ARRAY_SIZE; j++) {
                array[j] = randomNumber.nextInt();
            }
        }
        assertTrue(multiTime < oneTime);
    }
}

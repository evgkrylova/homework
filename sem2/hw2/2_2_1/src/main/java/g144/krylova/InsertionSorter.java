package g144.krylova;

/**
 * A class containing method sorting array with insertion sort.
 */
public class InsertionSorter implements Sorter {
    @Override
    public void sort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int j = i;
            while ((j > 0) && (array[j] < array[j - 1])) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                j--;
            }
        }
    }
}
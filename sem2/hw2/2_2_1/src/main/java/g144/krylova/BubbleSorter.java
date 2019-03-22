package g144.krylova;

/**
 * A class containing method sorting array with bubble sort.
 */
public class BubbleSorter implements Sorter {
    @Override
    public void sort(int[] array) {
        bSort(array, array.length);
    }

    private void bSort(int[] array, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j + 1] < array[j]) {
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }
}

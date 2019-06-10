package g144.krylova;

/**
 * Class containing realization of the one thread algorithm of the quick dorter.
 */
public class OneThreadSorter implements QuickSorter {
    /**
     * {@inheritDoc}
     */
    @Override
    public void sort(int[] array, int left, int right) {
        if (left >= right) {
            return;
        }

        int i = left;
        int j = right;
        int pivot = array[(i + j) / 2];

        while (i <= j) {
            while (array[i] < pivot) {
                i++;
            }
            while (array[j] > pivot) {
                j--;
            }

            if ((i <= j) && (array[i] >= array[j])) {
                swap(array, i, j);
                i++;
                j--;
            }
        }

        if (i < right) {
            sort(array, i, right);
        }
        if (j > left) {
            sort(array, left, j);
        }
    }

    /**
     * Method swapping two elements of the array.
     * @param array is array to change elements.
     * @param i is the first element index.
     * @param j is the second element index.
     */
    private static void swap(final int[] array, final int i, final int j){
        final int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
